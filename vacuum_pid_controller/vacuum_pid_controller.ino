// ============================================================
// PID PULSE VACUUM CONTROLLER (v3)
//
// Valve VENT   = atmospheric vent  (pin 11)  King Sheng, NORMALLY OPEN
// Valve VACUUM = to vacuum pump    (pin 12)  King Sheng, NORMALLY CLOSED
// Sensor       = XGZP6847A -100..0 kPa on A0
//
// HOW IT WORKS
//   Every periodMs the controller computes a signed output u (in ms):
//       u = P + I + D
//   u > 0  -> vacuum valve opens for u ms
//   u < 0  -> vent valve opens for |u| ms (only if vacuum is more than
//             ventErrMin ABOVE target; small overshoots are left to the leak)
//   Both valves are held CLOSED for the rest of the period.
//   Because the vent is NO, "closed" means its coil is ENERGISED.
//
//   P : separate gains for vacuum side (kpv) and vent side (kpe)
//   I : integral of error -> learns the steady leak and removes the
//       constant offset you saw with P-only
//   D : on the (filtered) measurement, not the error, so changing the
//       target does not cause a kick
//
// SERIAL (115200, line ending "Newline" or "No line ending" both work)
//   <number>      set target vacuum in kPa and start control, e.g. 35
//   kpv <x>       P gain, vacuum side      (ms per kPa)
//   kpe <x>       P gain, vent side        (ms per kPa)
//   ki  <x>       I gain                   (ms per kPa*s)   ki 0 also clears I
//   kd  <x>       D gain                   (ms per kPa/s)
//   db  <x>       deadband for P and I     (kPa)
//   vmin <x>      only vent when vacuum is > x kPa above target
//   per <ms>      control period           (ms)
//   pmin <ms>     shortest pulse the valve reliably responds to
//   pmax <ms>     longest pulse (auto-limited to period - 20)
//   imax <ms>     clamp on the integral contribution
//   iz  <kPa>     error fed to the integral is clamped to +/- iz (stops windup on big steps)
//   gs 0|1        gain scheduling off/on (compensates for pressure-dependent flow)
//   pump <kPa>    best vacuum your pump reaches (used by gain scheduling)
//   tp <ms>       test pulse length for 'v' / 'e'
//   log 0|1       per-period CSV logging off/on
//   ir            reset integral
//   ?             print all parameters
//   v / e         ONE vacuum / vent test pulse at the CURRENT pressure,
//                 prints dVac and gain (kPa/ms). Do this at several targets.
//   l             leak test: seal both valves for 5 s, print leak rate
//   h             hold: stop control, seal both valves
//   x             stop: all coils off (vent opens -> system goes to atmosphere)
//   z             re-zero sensor (vents to atmosphere)
//   s / r         vacuum / vent step-response logs (from v2)
//
// LOG LINE (every period while control is on):
//   D,t_ms,target,vacuum,err,P,I,D,u,valve,pulse_ms
//   valve: V = vacuum, E = vent, - = none
// ============================================================

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// ---------------- PINS ----------------
const int VALVE_VENT   = 11;
const int VALVE_VACUUM = 12;
const int PRESSURE_PIN = A0;

// ---------------- VALVE POLARITY ----------------
// Normally open valve: coil OFF (LOW) = OPEN, coil ON (HIGH) = CLOSED.
// CHECK THIS ON YOUR BENCH: power the board, send 'h' (seal both), and
// try to suck through the vent port. It must be closed. If it is open,
// set VENT_NORMALLY_OPEN to false.
const bool VENT_NORMALLY_OPEN   = true;
const bool VACUUM_NORMALLY_OPEN = false;

// ---------------- CALIBRATION ----------------
const float CAL_GAIN = 1.0;
float calOffset = 0.0;            // set by auto-zero at boot / 'z'

// ---------------- TUNABLE (defaults, change live over serial) ----------------
float kpVac      = 10.0;   // ms per kPa
float kpVent     = 3.0;    // ms per kPa
float ki         = 0.0;    // ms per (kPa*s)
float kd         = 0.0;    // ms per (kPa/s)
float deadband   = 0.5;    // kPa
float ventErrMin = 2.0;    // kPa
unsigned int periodMs = 250;
int   pulseMin   = 5;      // ms
int   pulseMax   = 100;    // ms
float iMax       = 60.0;   // ms
float iZone      = 5.0;    // kPa; error fed to the integral is clamped to +/- iZone
bool  gsOn       = false;
float pumpVac    = 80.0;   // kPa
int   testPulseMs = 10;
bool  logOn      = true;

// ---------------- FIXED ----------------
const float GS_REF_DP  = 40.0;  // gains behave "as if" the driving dP were 40 kPa
const float GS_MIN_DP  = 5.0;
const float CHOKE_DP   = 47.0;  // vent inflow is choked above ~47 kPa vacuum
const unsigned long SAMPLE_MS = 2;
const float FILT_ALPHA = 0.15;  // sensor low-pass per 2 ms sample (~13 ms time constant)
const float D_ALPHA    = 0.4;   // derivative low-pass per control step
const int   NUM_SAMPLES = 4;

// ---------------- STATE ----------------
float target    = 0;
bool  controlOn = false;
float vacFilt   = 0;
float prevVac   = 0;
float dFilt     = 0;
float integ     = 0;
float carry     = 0;            // sub-minimum vacuum pulses accumulate here
float lastLeakRate = 0;
unsigned long lastSample  = 0;
unsigned long lastControl = 0;
unsigned long pulseEnd    = 0;
int activeValve = -1;           // -1 = none

char serBuf[32];
byte serLen = 0;
unsigned long lastCharMs = 0;

// ============================================================
// SENSOR
// ============================================================
float readPressure()               // gauge kPa, negative = vacuum
{
  long sum = 0;
  for (int i = 0; i < NUM_SAMPLES; i++) sum += analogRead(PRESSURE_PIN);
  float adc = sum / (float)NUM_SAMPLES;
  float voltage = adc * 5.0 / 1023.0;
  float raw = -100.0 + (voltage - 0.5) * 100.0 / 4.0;
  return CAL_GAIN * raw + calOffset;
}

float readVacuum() { return -readPressure(); }

float readVacuumAvg(int n)
{
  float s = 0;
  for (int i = 0; i < n; i++) s += readVacuum();
  return s / n;
}

void updateSensor()
{
  unsigned long now = millis();
  if (now - lastSample < SAMPLE_MS) return;
  lastSample = now;
  vacFilt += FILT_ALPHA * (readVacuum() - vacFilt);
}

// ============================================================
// VALVES
// ============================================================
void setValve(int pin, bool open, bool normallyOpen)
{
  bool energise = normallyOpen ? !open : open;
  digitalWrite(pin, energise ? HIGH : LOW);
}
void vacOpen(bool o)  { setValve(VALVE_VACUUM, o, VACUUM_NORMALLY_OPEN); }
void ventOpen(bool o) { setValve(VALVE_VENT,   o, VENT_NORMALLY_OPEN); }

void sealBoth()          // both valves CLOSED (vent coil energised)
{
  vacOpen(false);
  ventOpen(false);
  activeValve = -1;
}

void coilsOff()          // de-energise everything (vent OPEN, vacuum CLOSED)
{
  digitalWrite(VALVE_VACUUM, LOW);
  digitalWrite(VALVE_VENT, LOW);
  activeValve = -1;
}

void startPulse(int valve, int ms)   // non-blocking
{
  sealBoth();
  if (valve == VALVE_VACUUM) vacOpen(true);
  else                       ventOpen(true);
  activeValve = valve;
  pulseEnd = millis() + ms;
}

void updatePulse()
{
  if (activeValve < 0) return;
  if ((long)(millis() - pulseEnd) >= 0) sealBoth();
}

void blockingPulse(int valve, int ms)  // for tests only
{
  sealBoth();
  if (valve == VALVE_VACUUM) vacOpen(true);
  else                       ventOpen(true);
  delay(ms);
  sealBoth();
}

// ============================================================
// GAIN SCHEDULING
// Flow through a valve depends on the pressure difference across it.
// Vacuum valve: dP = pumpVac - vacuum  (big at 20 kPa, small at 50 kPa)
// Vent valve:   dP = vacuum            (small at 20 kPa, choked above ~47)
// Scaling pulse length by sqrt(REF/dP) keeps the loop gain roughly
// constant across targets.
// ============================================================
float gsVac(float vac)
{
  if (!gsOn) return 1.0;
  float dp = pumpVac - vac;
  if (dp < GS_MIN_DP) dp = GS_MIN_DP;
  return sqrt(GS_REF_DP / dp);
}

float gsVent(float vac)
{
  if (!gsOn) return 1.0;
  float dp = vac;
  if (dp > CHOKE_DP) dp = CHOKE_DP;
  if (dp < GS_MIN_DP) dp = GS_MIN_DP;
  return sqrt(GS_REF_DP / dp);
}

// ============================================================
// CONTROL
// ============================================================
void printLogHeader()
{
  Serial.println(F("#H,t_ms,target,vacuum,err,P,I,D,u,valve,pulse_ms"));
}

void startControl(float t)
{
  target = t;
  if (!controlOn)
  {
    integ = 0;
    carry = 0;
    dFilt = 0;
    prevVac = vacFilt;
    sealBoth();
    lastControl = millis();
    controlOn = true;
  }
  Serial.print(F("Target vacuum set to "));
  Serial.print(target, 1);
  Serial.println(F(" kPa"));
  if (logOn) printLogHeader();
}

void controlStep()
{
  if (activeValve >= 0) sealBoth();   // safety: never carry a pulse over

  float dt  = periodMs / 1000.0;
  float vac = vacFilt;
  float err = target - vac;                         // + = need MORE vacuum
  float e   = (fabs(err) <= deadband) ? 0.0 : err;  // deadband for P and I

  // derivative on measurement (filtered)
  float dvdt = (vac - prevVac) / dt;
  prevVac = vac;
  dFilt += D_ALPHA * (dvdt - dFilt);

  float P = (e >= 0 ? kpVac : kpVent) * e;
  float D = -kd * dFilt;

  // conditional integration: don't wind up while saturated in the same direction
  float uTry = P + integ + D;
  bool satHi = (uTry >=  pulseMax && e > 0);
  bool satLo = (uTry <= -pulseMax && e < 0);
  if (!satHi && !satLo)
  {
    integ += ki * constrain(e, -iZone, iZone) * dt;   // limited learning rate on big steps
    integ = constrain(integ, -iMax, iMax);
  }
  float u = P + integ + D;

  // choose valve
  int   valve = -1;
  float ms = 0;
  if (u > 0)
  {
    valve = VALVE_VACUUM;
    ms = u * gsVac(vac);
  }
  else if (u < 0 && err < -ventErrMin)
  {
    valve = VALVE_VENT;
    ms = -u * gsVent(vac);
  }
  if (ms > pulseMax) ms = pulseMax;

  int pulse = 0;
  if (valve == VALVE_VACUUM && ms < pulseMin)
  {
    // small leak-compensation requests add up until they make one min pulse
    carry += ms;
    if (carry >= pulseMin) { pulse = pulseMin; carry -= pulseMin; }
  }
  else
  {
    carry = 0;
    if (ms >= pulseMin) pulse = (int)(ms + 0.5);
  }

  char vChar = '-';
  if (pulse > 0)
  {
    startPulse(valve, pulse);
    vChar = (valve == VALVE_VACUUM) ? 'V' : 'E';
  }

  if (logOn)
  {
    Serial.print(F("D,"));
    Serial.print(millis());       Serial.print(',');
    Serial.print(target, 1);      Serial.print(',');
    Serial.print(vac, 2);         Serial.print(',');
    Serial.print(err, 2);         Serial.print(',');
    Serial.print(P, 1);           Serial.print(',');
    Serial.print(integ, 1);       Serial.print(',');
    Serial.print(D, 1);           Serial.print(',');
    Serial.print(u, 1);           Serial.print(',');
    Serial.print(vChar);          Serial.print(',');
    Serial.println(pulse);
  }
}

// after any blocking routine, re-sync filter and timers
void resumeAfterBlocking(bool wasOn)
{
  vacFilt = readVacuumAvg(16);
  prevVac = vacFilt;
  dFilt = 0;
  lastSample = millis();
  lastControl = millis();
  if (wasOn) { sealBoth(); controlOn = true; if (logOn) printLogHeader(); }
}

// ============================================================
// TESTS
// ============================================================
void zeroSensor()
{
  bool was = controlOn; controlOn = false;
  vacOpen(false);
  ventOpen(true);
  delay(1500);
  calOffset = 0;
  float sum = 0;
  for (int i = 0; i < 32; i++) { sum += readPressure(); delay(5); }
  calOffset = -sum / 32.0;
  coilsOff();
  Serial.print(F("Zeroed. Offset = "));
  Serial.print(calOffset, 2);
  Serial.println(F(" kPa"));
  resumeAfterBlocking(false);
  (void)was;
}

// One pulse at the CURRENT operating point. Run at several targets to
// map how the plant gain changes with pressure.
void testPulse(int valve, const char *name)
{
  // The leak keeps pulling vacuum down during the test, so measure it in the
  // 300 ms BEFORE the pulse and subtract it from the pulse's effect.
  bool was = controlOn; controlOn = false;
  sealBoth();
  delay(100);
  unsigned long ta = millis();
  float va = readVacuumAvg(32);
  delay(300);
  unsigned long tb = millis();
  float before = readVacuumAvg(32);
  blockingPulse(valve, testPulseMs);
  delay(300);
  float after = readVacuumAvg(32);
  unsigned long tc = millis();

  float leak = (va - before) / ((tb - ta) / 1000.0);      // kPa/s lost to leak
  float dV   = after - before;                            // raw change
  float dVc  = dV + leak * ((tc - tb) / 1000.0);          // leak-corrected
  float gain = fabs(dVc) / testPulseMs;

  Serial.print(F("TEST,")); Serial.print(name);
  Serial.print(F(",at_kPa="));    Serial.print(before, 2);
  Serial.print(F(",pulse_ms="));  Serial.print(testPulseMs);
  Serial.print(F(",dVac_raw="));  Serial.print(dV, 2);
  Serial.print(F(",leak_kPa_s=")); Serial.print(leak, 2);
  Serial.print(F(",dVac_corr=")); Serial.print(dVc, 2);
  Serial.print(F(",gain_kPa_per_ms=")); Serial.print(gain, 3);
  Serial.print(F(",kp_suggest="));
  Serial.println(gain > 0.0001 ? 0.5 / gain : 0.0, 1);
  resumeAfterBlocking(was);
}

// Seal both valves and watch the vacuum decay for 5 s.
void leakTest()
{
  bool was = controlOn; controlOn = false;
  sealBoth();
  delay(200);
  Serial.println(F("#LEAK,t_ms,vacuum"));
  unsigned long t0 = millis();
  float v0 = readVacuumAvg(32);
  float v = v0;
  for (int i = 0; i <= 50; i++)
  {
    v = readVacuumAvg(16);
    Serial.print(F("L,")); Serial.print(millis() - t0);
    Serial.print(','); Serial.println(v, 2);
    if (i < 50) delay(100);
  }
  float secs = (millis() - t0) / 1000.0;
  lastLeakRate = (v0 - v) / secs;
  Serial.print(F("LEAK,start=")); Serial.print(v0, 2);
  Serial.print(F(",end="));       Serial.print(v, 2);
  Serial.print(F(",secs="));      Serial.print(secs, 2);
  Serial.print(F(",rate_kPa_per_s=")); Serial.println(lastLeakRate, 3);
  resumeAfterBlocking(was);
}

void logResponse(const char *label, int valvePin, int pulseMs)
{
  unsigned long t0 = millis();
  Serial.print(F("# ")); Serial.print(label);
  Serial.print(F(" pulse=")); Serial.print(pulseMs); Serial.println(F("ms"));
  bool fired = false;
  while (millis() - t0 < 850)
  {
    unsigned long t = millis() - t0;
    if (!fired && t >= 50) { blockingPulse(valvePin, pulseMs); fired = true; }
    Serial.print(label); Serial.print(',');
    Serial.print((long)t - 50); Serial.print(',');
    Serial.println(readVacuum(), 2);
    delay(4);
  }
}

void resetToAtmosphere()
{
  vacOpen(false);
  ventOpen(true);
  delay(1500);
  ventOpen(false);
  delay(300);
}

void runVacuumSteps()
{
  controlOn = false;
  const int pulses[] = {10, 15, 25};
  for (int i = 0; i < 3; i++) { resetToAtmosphere(); logResponse("VAC", VALVE_VACUUM, pulses[i]); }
  coilsOff();
  Serial.println(F("# DONE (control stopped)"));
  resumeAfterBlocking(false);
}

void runVentSteps()
{
  controlOn = false;
  const int pulses[] = {10, 15, 25};
  for (int i = 0; i < 3; i++)
  {
    resetToAtmosphere();
    blockingPulse(VALVE_VACUUM, 60);  // pre-pump
    delay(400);
    logResponse("VENT", VALVE_VENT, pulses[i]);
  }
  coilsOff();
  Serial.println(F("# DONE (control stopped)"));
  resumeAfterBlocking(false);
}

// ============================================================
// SERIAL
// ============================================================
void printParams()
{
  Serial.print(F("# kpv=")); Serial.print(kpVac, 2);
  Serial.print(F(" kpe="));  Serial.print(kpVent, 2);
  Serial.print(F(" ki="));   Serial.print(ki, 3);
  Serial.print(F(" kd="));   Serial.print(kd, 3);
  Serial.print(F(" db="));   Serial.print(deadband, 2);
  Serial.print(F(" vmin=")); Serial.print(ventErrMin, 2);
  Serial.print(F(" per="));  Serial.print(periodMs);
  Serial.print(F(" pmin=")); Serial.print(pulseMin);
  Serial.print(F(" pmax=")); Serial.print(pulseMax);
  Serial.print(F(" imax=")); Serial.print(iMax, 1);
  Serial.print(F(" iz="));   Serial.print(iZone, 1);
  Serial.print(F(" gs="));   Serial.print(gsOn ? 1 : 0);
  Serial.print(F(" pump=")); Serial.print(pumpVac, 1);
  Serial.print(F(" tp="));   Serial.print(testPulseMs);
  Serial.print(F(" | target=")); Serial.print(target, 1);
  Serial.print(F(" control=")); Serial.print(controlOn ? F("ON") : F("OFF"));
  Serial.print(F(" I="));    Serial.println(integ, 2);
}

void processLine(char *s)
{
  while (*s == ' ') s++;
  for (char *p = s; *p; p++) *p = tolower(*p);
  if (!*s) return;

  // bare number = new target
  if ((*s >= '0' && *s <= '9') || *s == '.')
  {
    float t = atof(s);
    if (t >= 0 && t <= 95) startControl(t);
    else Serial.println(F("! target must be 0..95 kPa"));
    return;
  }

  char *arg = strchr(s, ' ');
  bool hasVal = false;
  float val = 0;
  if (arg)
  {
    *arg++ = 0;
    while (*arg == ' ') arg++;
    if (*arg) { val = atof(arg); hasVal = true; }
  }

  bool changed = true;
  if      (!strcmp(s, "kpv")  && hasVal) kpVac  = max(0.0f, val);
  else if (!strcmp(s, "kpe")  && hasVal) kpVent = max(0.0f, val);
  else if (!strcmp(s, "ki")   && hasVal) { ki = max(0.0f, val); if (ki == 0) integ = 0; }
  else if (!strcmp(s, "kd")   && hasVal) kd = max(0.0f, val);
  else if (!strcmp(s, "db")   && hasVal) deadband   = max(0.0f, val);
  else if (!strcmp(s, "vmin") && hasVal) ventErrMin = max(0.0f, val);
  else if (!strcmp(s, "per")  && hasVal)
  {
    periodMs = constrain((int)val, 50, 2000);
    if (pulseMax > (int)periodMs - 20) pulseMax = periodMs - 20;
  }
  else if (!strcmp(s, "pmin") && hasVal) pulseMin = constrain((int)val, 1, 100);
  else if (!strcmp(s, "pmax") && hasVal) pulseMax = constrain((int)val, pulseMin, (int)periodMs - 20);
  else if (!strcmp(s, "imax") && hasVal) iMax = max(0.0f, val);
  else if (!strcmp(s, "iz")   && hasVal) iZone = max(0.0f, val);
  else if (!strcmp(s, "gs")   && hasVal) gsOn = (val != 0);
  else if (!strcmp(s, "pump") && hasVal) pumpVac = constrain(val, 10.0f, 99.0f);
  else if (!strcmp(s, "tp")   && hasVal) testPulseMs = constrain((int)val, 1, 500);
  else if (!strcmp(s, "log")  && hasVal) logOn = (val != 0);
  else if (!strcmp(s, "ir")) integ = 0;
  else
  {
    changed = false;
    if      (!strcmp(s, "?")) printParams();
    else if (!strcmp(s, "v")) testPulse(VALVE_VACUUM, "VAC");
    else if (!strcmp(s, "e")) testPulse(VALVE_VENT, "VENT");
    else if (!strcmp(s, "l")) leakTest();
    else if (!strcmp(s, "z")) zeroSensor();
    else if (!strcmp(s, "s")) runVacuumSteps();
    else if (!strcmp(s, "r")) runVentSteps();
    else if (!strcmp(s, "h")) { controlOn = false; sealBoth(); Serial.println(F("HOLD (both sealed, control off)")); }
    else if (!strcmp(s, "x")) { controlOn = false; coilsOff(); Serial.println(F("STOPPED (coils off, vent open)")); }
    else Serial.println(F("? unknown command (send ? for parameters)"));
  }
  if (changed) printParams();
}

void handleSerial()
{
  while (Serial.available())
  {
    char c = Serial.read();
    lastCharMs = millis();
    if (c == '\n' || c == '\r')
    {
      if (serLen) { serBuf[serLen] = 0; processLine(serBuf); serLen = 0; }
    }
    else if (serLen < sizeof(serBuf) - 1) serBuf[serLen++] = c;
  }
  // "No line ending" in Serial Monitor: treat a 60 ms pause as end of line
  if (serLen && millis() - lastCharMs > 60)
  {
    serBuf[serLen] = 0; processLine(serBuf); serLen = 0;
  }
}

// ============================================================
void setup()
{
  pinMode(VALVE_VENT, OUTPUT);
  pinMode(VALVE_VACUUM, OUTPUT);
  coilsOff();

  Serial.begin(115200);
  Serial.println(F("================================"));
  Serial.println(F("PID Pulse Vacuum Controller v3"));
  Serial.println(F("<kPa> target | kpv kpe ki kd db vmin per pmin pmax imax iz gs pump tp log ir"));
  Serial.println(F("? params | v/e test pulse | l leak | h hold | x stop | z zero | s/r steps"));
  Serial.println(F("================================"));
  zeroSensor();
  printParams();
}

void loop()
{
  handleSerial();
  updateSensor();
  updatePulse();

  if (!controlOn) return;

  if (millis() - lastControl >= periodMs)
  {
    lastControl += periodMs;
    if (millis() - lastControl > periodMs) lastControl = millis();  // fell behind
    controlStep();
  }
}
