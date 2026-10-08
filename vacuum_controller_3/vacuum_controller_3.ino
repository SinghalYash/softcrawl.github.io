// ============================================================
// PULSE-PROPORTIONAL VACUUM CONTROLLER (v2)
// Valve 1 = ATMOSPHERIC VENT   (pin 11)
// Valve 2 = VACUUM             (pin 12)
// Sensor  = XGZP6847A -100..0 kPa on A0
//
// Serial commands (115200 baud):
//   <number 0..40>  set target vacuum in kPa   e.g. 10
//   v               fire ONE test vacuum pulse (TEST_PULSE_MS), print dP
//   e               fire ONE test vent pulse,   print dP
//   x               stop control (all valves off)
//
// Use 'v' and 'e' to measure real plant gain:
//   KP_xxx ~= 0.5 / (kPa per ms measured)   (start conservative)
// ============================================================

const int VALVE_VENT   = 11;
const int VALVE_VACUUM = 12;
const int PRESSURE_PIN = A0;

// ---------------- CALIBRATION ----------------
const float CAL_GAIN   = 1.0;
const float CAL_OFFSET = 0.0;   // overwritten by auto-zero at boot / 'z'
float calOffset = CAL_OFFSET;

// ---------------- CONTROL PARAMETERS ----------------
const float DEADBAND = 2.0;        // kPa

// Separate gains (ms of valve-on time per kPa of error).
// Measure with 'v' / 'e' test pulses, then tune.
const float KP_VAC  = 0.8;
const float KP_VENT = 1.5;

// Leak-trim integral (ms per kPa*second). 0 disables.
const float KI = 0.0;
const float I_MAX = 10.0;          // max integral contribution, ms

// Pulse limits (ms). MIN should be >= your solenoid's reliable response time.
const int MIN_PULSE = 3;
const int MAX_PULSE = 40;

// Wait after each pulse so pressure before next reading.
// This is what replaces a derivative term.
const unsigned long SETTLE_MS = 300;

// Sensor averaging (no delay between samples, ~0.1 ms each on AVR)
const int NUM_SAMPLES = 8;

// Test pulse length for gain measurement
const int TEST_PULSE_MS = 10;

// Status print interval
const unsigned long PRINT_INTERVAL = 100;

// ---------------- STATE ----------------
float targetVacuum = 0;
bool  targetSet = false;
float integralMs = 0;
unsigned long lastActionEnd = 0;
unsigned long lastLoopMs = 0;
unsigned long lastPrint = 0;

// ------------------------------------------------------------
float readPressure()
{
  long sum = 0;
  for (int i = 0; i < NUM_SAMPLES; i++)
    sum += analogRead(PRESSURE_PIN);

  float adc = sum / (float)NUM_SAMPLES;
  float voltage = adc * 5.0 / 1023.0;

  // XGZP6847A -100 to 0 kPa version
  float raw = -100.0 + (voltage - 0.5) * 100.0 / 4.0;
  return CAL_GAIN * raw + calOffset;
}

void allValvesOff()
{
  digitalWrite(VALVE_VACUUM, LOW);
  digitalWrite(VALVE_VENT, LOW);
}

void pulseValve(int valvePin, int duration)
{
  // Opposite valve off (no delay needed, it should already be off)
  if (valvePin == VALVE_VACUUM) {
    digitalWrite(VALVE_VENT, LOW);
  }   
  else {
    digitalWrite(VALVE_VACUUM, LOW);
  }
  digitalWrite(valvePin, HIGH);
  delay(duration);
  digitalWrite(valvePin, LOW);
}

// Fire one test pulse and report pressure change (for measuring plant gain)
void testPulse(int valvePin, const char *name)
{
  allValvesOff();
  delay(300);
  float before = readPressure();

  pulseValve(valvePin, TEST_PULSE_MS);

  delay(150);  // let it settle
  float after = readPressure();

  float dP = after - before;
  Serial.print("TEST ");
  Serial.print(name);
  Serial.print(" ");
  Serial.print(TEST_PULSE_MS);
  Serial.print(" ms | before ");
  Serial.print(before, 2);
  Serial.print(" | after ");
  Serial.print(after, 2);
  Serial.print(" | dP ");
  Serial.print(dP, 2);
  Serial.print(" kPa | gain ");
  Serial.print(fabs(dP) / TEST_PULSE_MS, 3);
  Serial.println(" kPa/ms");
}

// ------------------------------------------------------------
// AUTO-ZERO: vent to atmosphere, average, store offset
// ------------------------------------------------------------
void zeroSensor()
{
  allValvesOff();
  digitalWrite(VALVE_VENT, HIGH);
  delay(1500);
  calOffset = 0;
  float sum = 0;
  for (int i = 0; i < 32; i++) { sum += readPressure(); delay(5); }
  digitalWrite(VALVE_VENT, LOW);
  calOffset = -sum / 32.0;
  Serial.print("Zeroed. Offset = ");
  Serial.print(calOffset, 2);
  Serial.println(" kPa");
}

// ------------------------------------------------------------
// STEP RESPONSE LOGGER
// Fires one pulse and logs vacuum (kPa, positive) every ~5 ms for 800 ms.
// Output is CSV:  label,time_ms,vacuum_kPa
// ------------------------------------------------------------
void logResponse(const char *label, int valvePin, int pulseMs)
{
  unsigned long t0 = millis();
  Serial.print("# "); Serial.print(label);
  Serial.print(" pulse="); Serial.print(pulseMs); Serial.println("ms");

  // log 50 ms of baseline, fire pulse, keep logging
  bool fired = false;
  while (millis() - t0 < 850)
  {
    unsigned long t = millis() - t0;
    if (!fired && t >= 50)
    {
      pulseValve(valvePin, pulseMs);
      fired = true;
    }
    Serial.print(label); Serial.print(",");
    Serial.print((long)t - 50); Serial.print(",");
    Serial.println(-readPressure(), 2);
    delay(4);
  }
}

void resetToAtmosphere()
{
  digitalWrite(VALVE_VACUUM, LOW);
  digitalWrite(VALVE_VENT, HIGH);   // hold vent open
  delay(1500);
  digitalWrite(VALVE_VENT, LOW);
  delay(300);
}

// 's' : vacuum step test from atmosphere at 10, 20, 40 ms
void runVacuumSteps()
{
  targetSet = false;
  const int pulses[] = {10, 15, 25};
  for (int i = 0; i < 3; i++)
  {
    resetToAtmosphere();
    logResponse("VAC", VALVE_VACUUM, pulses[i]);
  }
  allValvesOff();
  Serial.println("# DONE");
}

// 'r' : vent step test from ~pre-pumped state at 10, 20, 40 ms
void runVentSteps()
{
  targetSet = false;
  const int pulses[] = {10, 15, 25};
  for (int i = 0; i < 3; i++)
  {
    resetToAtmosphere();
    pulseValve(VALVE_VACUUM, 60);   // pre-pump
    delay(400);                     // let it settle
    logResponse("VENT", VALVE_VENT, pulses[i]);
  }
  allValvesOff();
  Serial.println("# DONE");
}

// ------------------------------------------------------------
void setup()
{
  pinMode(VALVE_VENT, OUTPUT);
  pinMode(VALVE_VACUUM, OUTPUT);
  allValvesOff();

  Serial.begin(115200);
  Serial.setTimeout(20);   // parseFloat won't block for 1 s

  Serial.println("================================");
  Serial.println("Proportional Pulse Controller v2");
  Serial.println("Enter target vacuum in kPa (0-40)");
  Serial.println("v = test vacuum pulse, e = test vent pulse, x = stop");
  Serial.println("z = re-zero sensor (vents to atmosphere)");
  Serial.println("================================");
  zeroSensor();
}

// ------------------------------------------------------------
void handleSerial()
{
  if (!Serial.available()) return;

  char c = Serial.peek();

  if (c == 'v' || c == 'V') { Serial.read(); testPulse(VALVE_VACUUM, "VAC"); }
  else if (c == 'e' || c == 'E') { Serial.read(); testPulse(VALVE_VENT, "VENT"); }
  else if (c == 'z' || c == 'Z') { Serial.read(); targetSet = false; zeroSensor(); }
  else if (c == 's' || c == 'S') { Serial.read(); runVacuumSteps(); }
  else if (c == 'r' || c == 'R') { Serial.read(); runVentSteps(); }
  else if (c == 'x' || c == 'X')
  {
    Serial.read();
    targetSet = false;
    allValvesOff();
    Serial.println("STOPPED");
  }
  else
  {
    float newTarget = Serial.parseFloat();
    if (newTarget >= 0 && newTarget <= 100)
    {
      targetVacuum = newTarget;
      targetSet = true;
      integralMs = 0;
      allValvesOff();
      Serial.print("Target vacuum set to ");
      Serial.print(targetVacuum);
      Serial.println(" kPa");
    }
  }

  while (Serial.available()) Serial.read();
}

// ------------------------------------------------------------
void loop()
{
  handleSerial();

  if (!targetSet) return;

  unsigned long now = millis();

  // Still settling from the last pulse: don't act on moving pressure
  if (now - lastActionEnd < SETTLE_MS) return;

  float dt = (now - lastLoopMs) / 1000.0;
  lastLoopMs = now;
  if (dt > 0.5) dt = 0.5;  // ignore long gaps

  float pressure = readPressure();
  float vacuum   = -pressure;
  float error    = targetVacuum - vacuum;  // + = need MORE vacuum

  bool doPrint = (now - lastPrint >= PRINT_INTERVAL);

  // ---------------- DEADBAND ----------------
  if (fabs(error) <= DEADBAND)
  {
    allValvesOff();
    // slowly bleed integral inside deadband
    integralMs *= 0.98;

    if (doPrint)
    {
      lastPrint = now;
      Serial.print("t="); Serial.print(now);
      Serial.print(" | Target: "); Serial.print(targetVacuum, 1);
      Serial.print(" | Vacuum: "); Serial.print(vacuum, 2);
      Serial.print(" | Err: "); Serial.print(error, 2);
      Serial.println(" | HOLD");
    }
    return;
  }

  // ---------------- INTEGRAL (anti-windup) ----------------
  integralMs += KI * error * dt;
  integralMs = constrain(integralMs, -I_MAX, I_MAX);

  // ---------------- PULSE CALC ----------------
  float kp = (error > 0) ? KP_VAC : KP_VENT;
  float pulseF = fabs(error) * kp;

  // Integral helps in the direction of the error
  pulseF += (error > 0) ? integralMs : -integralMs;

  int pulseTime = constrain((int)pulseF, MIN_PULSE, MAX_PULSE);

  // Print EVERY action (not rate-limited) so vent pulses are never hidden
  lastPrint = now;
  Serial.print("t="); Serial.print(now);
  Serial.print(" | Target: "); Serial.print(targetVacuum, 1);
  Serial.print(" | Vacuum: "); Serial.print(vacuum, 2);
  Serial.print(" | Err: "); Serial.print(error, 2);
  Serial.print(error > 0 ? " | VAC " : " | VENT ");
  Serial.print(pulseTime);
  Serial.println(" ms");

  // ---------------- ACT ----------------
  if (error > 0) pulseValve(VALVE_VACUUM, pulseTime);
  else           pulseValve(VALVE_VENT,   pulseTime);

  lastActionEnd = millis();
}
