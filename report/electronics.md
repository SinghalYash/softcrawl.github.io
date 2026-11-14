---
layout: report
title: Electronic Hardware
group: Interim
code: SEC-04
nav_order: 4
permalink: /report/electronics/
---

## 1. Introduction and Design Requirements

### 1.1 Role of the electronics and pneumatic subsystem

The electronics and pneumatic subsystem generates and distributes vacuum to the robot's Kresling actuators and suction cups. It performs two functions: independently regulating vacuum in the three Kresling actuators to achieve different bending configurations, and providing binary ON/OFF vacuum control for the four suction cups, arranged in two independently controlled pairs.

### 1.2 Design Requirements and constraints

The subsystem must satisfy the following system-level requirements:

| Category | Relevant requirement |
| --- | --- |
| Electronics | No electronic components inside the fuel tank, except the camera and lighting |
| Control | Independent control of each leg |
| Pneumatics | Independently adjustable vacuum levels for the Kresling actuators and binary suction-cup operation |

These requirements necessitate an externally located control and vacuum-generation system, connected to the robot through pneumatic tubing.

### 1.3 Design Objectives and Success Criteria

The subsystem is evaluated against four objectives:

1. **Accuracy:** Maintain steady-state pressure error within ±1.5 kPa across the target operating range of 10–80 kPa.
2. **Stability:** Avoid sustained pressure oscillations and excessive overshoot during setpoint tracking.
3. **Repeatability:** Achieve consistent pressure regulation across repeated trials.
4. **Integration:** Independently regulate all three Kresling actuators while maintaining reliable binary operation of the suction cups.

## 2. System Architecture and Concept selection

### 2.1 Overall Pneumatic Architecture

A central vacuum pump supplies the pneumatic components through independently controlled channels. Three pressure sensors monitor the Kresling actuator channels and provide feedback to the microcontroller. The four suction cups are controlled in two pairs using separate binary ON/OFF valves, without individual pressure feedback (Fig. 1).

The architecture therefore supports closed-loop vacuum regulation for the Kresling actuators and binary vacuum switching for the suction cups.

<figure>
<img src="{{ '/images/electronics/figure-01.png' | relative_url }}" alt="Fig. 1 Overall Pneumatic Architecture">
<figcaption>Fig. 1 Overall Pneumatic Architecture</figcaption>
</figure>

### 2.2 Evaluation of Control Architectures

Three approaches were considered:

**Bang-bang solenoid valves:** Electrically actuated ON/OFF valves regulate vacuum through feedback-based switching and pulse-duration control (Németh et al., 2004) (Parker Hannifin, 2023).

<figure>
<img src="{{ '/images/electronics/figure-02.png' | relative_url }}" alt="Fig. 2 Solenoid Valve">
<figcaption>Fig. 2 Solenoid Valve</figcaption>
</figure>

**Electropneumatic vacuum regulators:** Electronically controlled regulators provide proportional vacuum adjustment and finer pressure regulation (Petit et al., 2024).

<figure>
<img src="{{ '/images/electronics/figure-03.png' | relative_url }}" alt="Fig. 3 Electrovacuum pressure regulator">
<figcaption>Fig. 3 Electrovacuum pressure regulator</figcaption>
</figure>

**Vacuum generators:** Venturi-based devices generate vacuum using compressed air, requiring an external compressed-air supply.

<figure>
<img src="{{ '/images/electronics/figure-04.png' | relative_url }}" alt="Fig. 4 Vacuum Generator">
<figcaption>Fig. 4 Vacuum Generator</figcaption>
</figure>

A weighted decision matrix was used to compare the concepts.

| Evaluation criterion | Weight | Bang-bang | E/P regulator | Vacuum generator |
| --- | --- | --- | --- | --- |
| Pressure-control capability | 35% | 3 | 5 | 2 |
| Cost | 25% | 5 | 2 | 3 |
| Hardware requirements | 25% | 4 | 4 | 1 |
| Scalability/modularity | 15% | 4 | 4 | 3 |
| Weighted score / 5 | 100% | 3.9 | 3.85 | 2.15 |

The bang-bang architecture achieved the highest weighted score due to its lower cost, modularity and compatibility with the available hardware. Although electropneumatic regulators offer superior inherent pressure-control capability, their higher cost made them less suitable for the initial implementation. Vacuum generators were less favourable due to their dependence on an external compressed-air supply and additional infrastructure. Detailed scoring justifications are provided in [Appendix A](#appendix-a-evaluation-criteria-and-weighted-decision-matrix).

### 2.3 Selected Architecture

Each Kresling actuator uses two solenoid valves: a vacuum valve connecting it to the vacuum supply and a vent valve connecting it to atmospheric pressure. The microcontroller compares measured pressure against the target and actuates the appropriate valve. Both valves close when the target is reached (Lake et al., 2017).

<figure>
<img src="{{ '/images/electronics/figure-05.png' | relative_url }}" alt="Fig. 5 Bang Bang valve control arrangement">
<figcaption>Fig. 5 Bang Bang valve control arrangement</figcaption>
</figure>

The suction-cup pairs use separate binary valve control to establish or release suction. Figure 6 illustrates the resulting pneumatic and electrical architecture. Pink lines indicate air tubes while orange lines are data lines.

<figure>
<img src="{{ '/images/electronics/figure-06.png' | relative_url }}" alt="Fig. 6 Electrical and Pneumatic schematic">
<figcaption>Fig. 6 Electrical and Pneumatic schematic</figcaption>
</figure>

A detailed schematic is attached below.

<figure>
<img src="{{ '/images/electronics/figure-07.png' | relative_url }}" alt="Fig.7 Detailed Electronic diagram">
<figcaption>Fig.7 Detailed Electronic diagram</figcaption>
</figure>

### 2.4 Key components

| Component | Quantity | Function |
| --- | --- | --- |
| Arduino Mega | 1 | Main controller |
| Pressure sensors | 3 | Monitor Kresling actuator pressure |
| Vacuum solenoid valves | 3 | Supply vacuum to actuators |
| Vent solenoid valves | 3 | Release actuator vacuum |
| Suction-cup valves | 2 | Binary suction control |
| MOSFET driver channels | 8 | Switch solenoid valves |
| Vacuum pump | 1 | Generate vacuum |
| Flyback diodes | 8 | Suppress inductive voltage transients |

MOSFET drivers switch the solenoid valves without drawing coil current directly from the microcontroller. Flyback diodes suppress voltage transients when the coils are de-energised.

<figure>
<img src="{{ '/images/electronics/figure-08.png' | relative_url }}" alt="Fig. 8 Flyback diode array">
<figcaption>Fig. 8 Flyback diode array</figcaption>
</figure>

## 3. Control Strategy and Theoretical Basis

### 3.1 Pressure sensing and Calibration

The XGZP6847A pressure sensor measures gauge pressure over a nominal range of 0 to −100 kPa and provides analogue voltage signals to the Arduino Mega. Atmospheric pressure is treated as 0 kPa gauge. For reporting and control purposes, vacuum magnitude is expressed as a positive value, corresponding to the negative gauge-pressure measurement from the sensor. Data is attached in [Appendix B](#appendix-b-pressure-calibration-data).

<figure>
<img src="{{ '/images/electronics/figure-09.png' | relative_url }}" alt="Fig. 9 Setup illustration for pressure sensor calibration">
<figcaption>Fig. 9 Setup illustration for pressure sensor calibration</figcaption>
</figure>

Ten measurements across 0 to -80 kPa were compared against a reference pressure gauge to obtain a linear calibration relationship:

<div class="legs-equation">\[ P_{\mathrm{cal}}=1.00298P_{\mathrm{raw}}-2.671 \]</div>

The calibration achieved an <span markdown="0">\$R^2$</span> value of 0.99968 and an RMSE of 0.37 kPa. The resulting equation was applied to subsequent pressure measurements to reduce systematic measurement error.

<figure>
<img src="{{ '/images/electronics/figure-10.png' | relative_url }}" alt="Fig. 10 Pressure Calibration Curve">
<figcaption>Fig. 10 Pressure Calibration Curve</figcaption>
</figure>

### 3.2 Bang Bang Control Strategy

Vacuum regulation uses feedback-based bang-bang control. The controller compares measured pressure against the target setpoint and calculates the error. Depending on the error, either the vacuum valve or vent valve is actuated. Both valves remain closed when the error falls within the defined deadband. Although the solenoid valves operate in discrete ON/OFF states, their effective influence on pressure can be adjusted through pulse duration.

### 3.3 Governing Pneumatic Relationship

The pressure response of a pneumatic volume can be approximated by:

<div class="legs-equation">\[ \frac{dP}{dt}=\frac{RT}{V}\left(\dot{m}_{\mathrm{in}}-\dot{m}_{\mathrm{out}}\right) \]</div>

where <span markdown="0">\(\dot{m}_{\mathrm{in}}\)</span> and <span markdown="0">\(\dot{m}_{\mathrm{out}}\)</span> are the incoming and outgoing air mass flow rates, <span markdown="0">\(dP/dt\)</span> is the rate of change of pressure, <span markdown="0">\(R\)</span> is the specific gas constant (287 J/(kg·K)), <span markdown="0">\(T\)</span> is absolute temperature (~293 K), and <span markdown="0">\(V\)</span> is the volume of the system. The relationship assumes approximately constant temperature and volume (UCSB Physics Department, 2007) (Xavier et al., 2020).

This relationship shows that pressure changes depend on net airflow and system volume. Shorter valve pulses can therefore produce smaller pressure changes, improving achievable control resolution. However, the minimum practical pulse duration is limited by the solenoid valve response characteristics.

## 4. Experimental Methodology

### 4.1 Overview of experimental tests

Three experiments were conducted to progressively evaluate the pneumatic control system, from initial valve characterisation to actuator-integrated operation.

| Test | Configuration | Objective |
| --- | --- | --- |
| Test 1 | Initial valve arrangement, without actuator | Characterise valve response and evaluate basic pressure control |
| Test 2 | Improved valve arrangement, without actuator | Evaluate closed-loop pressure regulation after hardware improvements |
| Test 3 | Improved valve arrangement with Kresling actuator | Investigate actuator-integrated pressure control and identify integration limitations |

The baseline configuration used 6 mm outer-diameter tubing. An additional 4 mm tubing configuration was investigated during Test 1 to evaluate flow restriction.

### 4.2 Control Parameters

The controller uses a 2 kPa pressure deadband to prevent unnecessary valve switching near the target. Proportional gains determine vacuum and vent valve pulse durations based on pressure error, subject to a minimum pulse duration. Following each pulse, the controller allows the pneumatic system to respond before evaluating pressure again.

The controller evaluation interval was set to 300 ms in Test 2. Detailed parameter definitions, controller implementation, and experimental code are provided in [Appendix C](#appendix-c-controller-implementation-and-source-code).

## 5. Results and Discussion

### 5.1 Test 1- Initial Valve control

Initial testing evaluated the pressure response of the vacuum and vent valves without a Kresling actuator. Fixed-duration pulses were first applied, followed by proportional control with gains swept from 1 to 6.

<figure>
<img src="{{ '/images/electronics/figure-11.png' | relative_url }}" alt="Fig. 11 Test 1 Setup">
<figcaption>Fig. 11 Test 1 Setup</figcaption>
</figure>

Even short pulses produced substantial pressure changes. Proportional control also exhibited significant overshoot and sustained oscillations across tested setpoints ([Appendix D](#appendix-d-proportional-gain-controller-test-results)). Vacuum decay after actuation indicated leakage within the pneumatic setup.

| Pulse duration | Peak pressure change |
| --- | --- |
| 6 ms | 4.42 kPa |
| 10 ms | 41.4 kPa |
| 20 ms | 46.5 kPa |
| 40 ms | 52.2 kPa |

These results suggested that the initial hardware configuration provided insufficiently controllable airflow, which could not be resolved through controller gain adjustment alone.

### 5.2 Flow Restriction and Hardware Improvements

The large pressure changes observed in Test 1 suggested that excessive airflow contributed to poor controllability. Since compressible flow equations ([Appendix E](#appendix-e-compressible-flow-equations)) tell us mass flow depends on pressure differential and flow restriction, tubing modifications were investigated to moderate pressure transients.

An additional 4 mm tube configuration was introduced alongside the existing 6 mm tubing. The pressure change measured 300 ms after a 10 ms pulse decreased from 34.3 kPa to 16.1 kPa, a reduction of approximately 53%. Peak pressure change also decreased from 41.4 kPa to 19.6 kPa. ([Appendix F](#appendix-f-4-mm-tube-configuration-results))

However, vacuum leakage remained. Three hardware improvements were subsequently implemented:

- Vacuum-rated solenoid valves to reduce leakage.
- Needle valves to restrict airflow (Pustjens, 2024).
- Check valves to prevent reverse airflow through the pump (RS, 2024).

<figure>
<div class="figure-row">
<img src="{{ '/images/electronics/figure-12.png' | relative_url }}" alt="Fig. 12 Vacuum rated solenoid valve, Needle Valve and check valve">
<img src="{{ '/images/electronics/figure-13.png' | relative_url }}" alt="Fig. 12 Vacuum rated solenoid valve, Needle Valve and check valve">
<img src="{{ '/images/electronics/figure-14.png' | relative_url }}" alt="Fig. 12 Vacuum rated solenoid valve, Needle Valve and check valve">
</div>
<figcaption>Fig. 12 Vacuum rated solenoid valve, Needle Valve and check valve</figcaption>
</figure>

### 5.3 Test 2 - Improved Valve Control

The improved hardware was evaluated using proportional control, with a gain of 0.5 selected following parameter tuning. Testing was conducted without a Kresling actuator to isolate the pneumatic system's pressure-regulation performance.

<figure>
<img src="{{ '/images/electronics/figure-15.png' | relative_url }}" alt="Fig. 13 Improved Test 2 Pneumatic setup">
<figcaption>Fig. 13 Improved Test 2 Pneumatic setup</figcaption>
</figure>

Seven vacuum setpoints between 10 and 70 kPa were tested. All were maintained within ±1.5 kPa of their targets, achieving a mean absolute steady-state error of 0.81 kPa and a maximum absolute error of 1.48 kPa. The controller evaluated pressure at 300 ms intervals.

<figure>
<img src="{{ '/images/electronics/figure-16.png' | relative_url }}" alt="Fig. 14 Test 2 setpoint tracking">
<figcaption>Fig. 14 Test 2 setpoint tracking</figcaption>
</figure>

<figure>
<img src="{{ '/images/electronics/figure-17.png' | relative_url }}" alt="Fig. 15 Test 2 Steady state error">
<figcaption>Fig. 15 Test 2 Steady state error</figcaption>
</figure>

However, the vacuum and vent valves exhibited asymmetric responses. A 20 ms vacuum pulse produced approximately 1-4 kPa of pressure change, whereas a vent pulse produced approximately 15-30 kPa. Consequently, vacuum could be increased in relatively small increments, but releasing vacuum remained comparatively aggressive. This asymmetry limits the achievable pressure-control resolution and motivates further investigation into flow restriction and pneumatic volume.

<figure>
<img src="{{ '/images/electronics/figure-18.png' | relative_url }}" alt="Fig. 16 Vacuum and vent valve pulse-response characteristics">
<figcaption>Fig. 16 Vacuum and vent valve pulse-response characteristics</figcaption>
</figure>

### 5.4 Test 3 - Actuator-Integrated Control

Test 3 connected a Kresling actuator to the improved valve arrangement from Test 2. A four-way push-in cross fitting joined the vacuum valve, the vent valve, the pressure sensor and the actuator (Fig. 17).

<figure>
<img src="{{ '/images/electronics/figure-20.png' | relative_url }}" alt="Fig. 17 Actuator-integrated Test 3 arrangement">
<figcaption>Fig. 17 Actuator-integrated Test 3 arrangement</figcaption>
</figure>

Six vacuum setpoints between 10 and 60 kPa were tested, starting at 60 kPa and stepping down in 10 kPa increments. Fig. 18 shows the measured vacuum against the target at each setpoint, with the shaded band marking the oscillation range.

<figure>
<img src="{{ '/images/electronics/figure-21.png' | relative_url }}" alt="Fig. 18 Test 3 setpoint tracking with the Kresling actuator">
<figcaption>Fig. 18 Test 3 setpoint tracking with the Kresling actuator</figcaption>
</figure>

| Target vacuum | Oscillation band | Within ±1.5 kPa target? |
| --- | --- | --- |
| 60 kPa | ±0.4 kPa | Yes |
| 50 kPa | ±4.4 kPa | No |
| 40 kPa | ±5.3 kPa | No |
| 30 kPa | ±5.9 kPa | No |
| 20 kPa | ±6.2 kPa | No |
| 10 kPa | ±6.6 kPa | No |

Only the 60 kPa setpoint met the ±1.5 kPa accuracy objective. At every lower setpoint, the pressure oscillated continuously around the target instead of settling. The oscillation grew steadily as the target vacuum decreased, from ±4.4 kPa at 50 kPa to ±6.6 kPa at 10 kPa.

#### 5.4.1 Actuator leakage replaced the vent valve

With the actuator connected, the vent valve never triggered during testing. The 3D-printed Kresling actuator leaks air through its walls and layer boundaries, so vacuum decays on its own after every pulse. Each pulse slightly overshot the target, the leak then pulled the pressure back down past it, and the controller responded with another vacuum pulse before the error ever grew large enough to need venting. The actuator therefore acted as a continuous, uncontrolled vent, and the controller regulated pressure using vacuum pulses alone (Fig. 19).

<figure>
<img src="{{ '/images/electronics/figure-22.png' | relative_url }}" alt="Fig. 19 Test 3 arrangement with actuator leakage acting as the vent">
<figcaption>Fig. 19 Test 3 arrangement with actuator leakage acting as the vent</figcaption>
</figure>

#### 5.4.2 Low hardware resolution

The oscillations come from the limited resolution of the solenoid valves. A valve cannot open for less than its minimum reliable response time, so even the shortest pulse admits more vacuum than is needed to correct a small error, and the pressure overshoots past the deadband. Leakage then pulls it back across the target, the controller fires another minimum pulse, and the cycle repeats.

From the governing relationship in Section 3.3, the pressure change from one pulse is approximately:

<div class="legs-equation">\[ \Delta P \approx \frac{RT\,\dot{m}\,\Delta t_{\min}}{V} \]</div>

At low target vacuum, the pressure difference across the vacuum valve is largest, so the mass flow <span markdown="0">\(\dot{m}\)</span> during each pulse is largest and each minimum pulse produces a larger jump. This is consistent with the oscillation band widening as the target decreases. Near 60 kPa, the pressure difference across the valve is small, each pulse adds only a small increment, and the controller holds the target closely. The small internal volume <span markdown="0">\(V\)</span> of a single actuator magnifies this effect.

<div class="callout warning">
<p>Test 3 shows that the solenoid-based controller cannot yet meet the ±1.5 kPa accuracy objective once an actuator is connected, except near 60 kPa. The minimum valve pulse delivers too much vacuum for the small actuator volume, and actuator leakage keeps the system cycling.</p>
</div>

These findings directly motivate the proposed vacuum reservoir, which increases <span markdown="0">\(V\)</span> so that each pulse produces a smaller pressure change, and further flow restriction in the vacuum line (Section 6.2). Sealing the actuator, as proposed in the Robot Body report, would also reduce the uncontrolled venting.

## 6. Limitations and Future Work

### 6.1 Current Limitations

Although Test 2 demonstrated closed-loop pressure regulation on a standalone bench setup, several limitations remain. Discrete solenoid actuation limits pressure resolution, while asymmetric valve responses contribute to overshoot and control difficulties. Furthermore, the bench configuration does not fully represent the additional pneumatic volume, tubing resistance and actuator dynamics expected during integration. Repeatability and simultaneous independent regulation of all three Kresling actuators also require further validation.

### 6.2 Proposed Improvements

1. **Vacuum reservoir integration:** Investigate an external vacuum reservoir to increase effective pneumatic volume. For a given mass of air transferred, a larger volume produces a smaller pressure change, potentially reducing pressure transients caused by individual valve pulses. Reservoir size must, however, be balanced against evacuation time and system response. Supporting calculations are provided in [Appendix G](#appendix-g-choked-flow-equations).
2. **Tubing characterisation:** Evaluate longer pneumatic lines representative of deployment, with the pump and electronics located outside the fuel tank.
3. **Flow restriction optimisation:** Investigate suitable restrictions in the vacuum and vent lines to moderate pressure changes without excessively slowing the system.
4. **Controller refinement:** Optimise pulse durations, control gains and response intervals. An electropneumatic vacuum regulator may be considered if solenoid-based control cannot achieve the required resolution.

### 6.3 Future Milestones and Validation Criteria

The improved subsystem should be evaluated against the following targets:

| Criterion | Proposed target |
| --- | --- |
| Pressure accuracy | Steady-state error within ±1.5-2 kPa |
| Pressure resolution | Distinguish adjacent 1-2 kPa setpoints |
| Stability | No sustained pressure oscillations |
| Repeatability | Consistent tracking across repeated trials |
| Independent control | Simultaneous regulation of all three actuators |
| Integration | Reliable operation with representative tubing and actuators |
| Suction cup operation | Reliable binary vacuum and vent control |

Successful validation would demonstrate the subsystem's readiness for further integration into the complete SoftCrawl platform.

## References

- Lake, J. R., Heyde, K. C., & Ruder, W. C. (2017). Low-cost feedback-controlled syringe pressure pumps for microfluidics applications. PLOS ONE, 12(4), Article e0175089. <https://doi.org/10.1371/journal.pone.0175089>
- Nandagopal, N. S. (2025). Compressible flow through pipes and pipelines: Isothermal compressible flow. In Compressible flow (pp. 305–363). Springer. <https://doi.org/10.1007/978-3-031-84752-3_7>
- NASA Glenn Research Center. (2024, April 26). Thrust equations summary. <https://www1.grc.nasa.gov/beginners-guide-to-aeronautics/thrust-equations-summary/>
- Németh, H., Palkovics, L., & Hangos, K. M. (2004). Feedforward bang-bang control design for electro-pneumatic protection valves. Periodica Polytechnica Transportation Engineering, 32(1–2), 3–20
- Parker Hannifin. (2023, October 10). Solenoid valves 101. <https://www.parker.com/us/en/divisions/fluid-control-division/resources/solenoid-valves-101.html>
- Petit, P., Plebuch, A., Guenther, M., Kiefel, D., Cazin, B., & Reichstadt, S. (2024). Development of a closed-loop electromechanical pressure regulator for an orbital spacecraft [Conference paper]. Deutscher Luft- und Raumfahrtkongress 2024. <https://doi.org/10.25967/630409dglr>
- Pustjens, J.-W. (2024, August 18). Needle valve—How they work. Tameson. <https://tameson.com/pages/needle-valve>
- RS. (2024, March 15). A complete guide to check valves. <https://ph.rs-online.com/web/content/discovery/ideas-and-advice/check-valves-guide>
- Thermopedia. (2011, March 16). Critical flow. <https://www.thermopedia.com/content/267>
- University of California, Santa Barbara, Physics Department. (n.d.). Vacuum techniques [Laboratory manual]. <https://web.physics.ucsb.edu/~phys128/experiments/vacuum/VacuumRev07.pdf>
- Xavier, M. S., Fleming, A. J., & Yong, Y. K. (2020). Modelling and simulation of pneumatic sources for soft robotic applications. In 2020 IEEE/ASME International Conference on Advanced Intelligent Mechatronics (AIM) (pp. 916–921). IEEE. <https://doi.org/10.1109/AIM43001.2020.9158802>

## Appendix

### Appendix A: Evaluation Criteria and Weighted Decision Matrix

Pressure-control capability received the highest weighting because independently adjustable vacuum levels are essential for controlling the Kresling actuators. Cost and hardware requirements were also weighted significantly because the subsystem must be implemented within the available project resources and infrastructure. Scalability was considered to accommodate the three actuator channels and two suction-cup pairs. The concepts were scored on a scale of 1-5, with higher scores representing more favourable performance against the respective criterion.

The weighted score was calculated using:

<div class="legs-equation">\[ \mathrm{Total\ Score}=\sum(\mathrm{Score}\times\mathrm{Weight}) \]</div>

The following summarises the engineering considerations behind the assigned scores.

| Criterion | Bang-bang solenoid valves | E/P regulator | Vacuum generator |
| --- | --- | --- | --- |
| Pressure control | Moderate inherent resolution; achievable control depends on valve response and pulse-duration tuning | Highest inherent proportional control capability | Limited direct control of output vacuum without additional regulation hardware |
| Cost | Low-cost and readily implementable components | Higher cost, approximately US$500 per channel in the original assessment | Moderate component cost, but requires supporting compressed-air infrastructure |
| Hardware requirements | Requires solenoid valves, drivers and pressure feedback | Requires electronic regulators and associated control interfaces | Requires compressed-air supply and additional pressure-regulation hardware |
| Scalability | Modular arrangement of independently controlled valve channels | Modular regulator-based arrangement | Expansion requires additional pneumatic infrastructure |

### Appendix B: Pressure calibration data

| Actual pressure (kPa) | Arduino average (kPa) | Error |
| --- | --- | --- |
| 0 | +2.278 | +2.278 |
| −16 | −13.216 | +2.784 |
| −24 | −21.348 | +2.652 |
| −34 | −30.325 | +3.675 |
| −36 | −33.386 | +2.614 |
| −44 | −41.126 | +2.874 |
| −52 | −49.594 | +2.406 |
| −56 | −53.217 | +2.783 |
| −60 | −56.846 | +3.154 |
| −73 | −70.412 | +2.588 |

### Appendix C: Controller Implementation and Source Code

The controller was implemented using an Arduino Mega and two independently actuated solenoid valves: a vacuum valve and an atmospheric vent valve. Pressure feedback was obtained from the XGZP6847A sensor connected to analogue input A0.

The controller operates using proportional pulse-duration control. The measured pressure is converted into positive vacuum magnitude, which is compared against the target vacuum setpoint. Depending on the resulting error, the controller activates either the vacuum or vent valve for a calculated duration.

A deadband is implemented to prevent unnecessary valve switching when the measured pressure is sufficiently close to the target. Following each valve actuation, the controller waits for the pneumatic response to settle before evaluating the pressure again.

The controller averages eight consecutive analogue-to-digital converter readings to reduce measurement noise. The resulting ADC value is converted into voltage and then into pressure using the sensor's nominal voltage-pressure relationship.

An automatic zeroing routine is executed during initialisation. The vent valve is opened to expose the sensor to atmospheric pressure, after which the average measured pressure is used to calculate an offset correction.

This provides an atmospheric reference for subsequent measurements.

The complete Arduino source file supplied for this report is retained as:

```cpp
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
const int VALVE_VENT   = 12;
const int VALVE_VACUUM = 7;
const int PRESSURE_PIN = A0;
// ---------------- CALIBRATION ----------------
const float CAL_GAIN   = 1.0;
const float CAL_OFFSET = 0.0;   // overwritten by auto-zero at boot / 'z'
float calOffset = CAL_OFFSET;
// ---------------- CONTROL PARAMETERS ----------------
const float DEADBAND = 2.0;        // kPa
// Separate gains (ms of valve-on time per kPa of error).
// Measure with 'v' / 'e' test pulses, then tune.
const float KP_VAC  = 0.5;
const float KP_VENT = 0.5;
// Leak-trim integral (ms per kPa*second). 0 disables.
const float KI = 0.0;
const float I_MAX = 10.0;          // max integral contribution, ms
// Pulse limits (ms). MIN should be >= your solenoid's reliable response time.
const int MIN_PULSE = 20;
const int MAX_PULSE = 200;
// Wait after each pulse so pressure equilibrates before next reading.
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
    digitalWrite(valvePin == VALVE_VACUUM ? VALVE_VENT : VALVE_VACUUM, LOW);
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
    Serial.println(integralMs);
    integralMs = constrain(integralMs, -I_MAX, I_MAX);
    Serial.println(integralMs);
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
```

| Parameter | What it does |
| --- | --- |
| DEADBAND | Defines the acceptable error range within which both valves remain closed. Consistently set to 2kPa across experiments |
| KP_VAC | Determines vacuum valve pulse duration based on the magnitude of the pressure error. |
| KP_VENT | Determines vent valve pulse duration based on the magnitude of the pressure error. |
| MIN_PULSE | Minimum permitted valve actuation duration (decided by the hardware limitation of the valve itself) |
| SETTLE_MS | Waiting period after each pulse before the controller evaluates pressure and acts again. |

### Appendix D: Proportional Gain controller test results

A proportional gain controller was also implemented where the pulse width was directly scaled to the measured error using  <span markdown="0">\(t_{\mathrm{pulse}}=K_P e\)</span>  and was tested with Kp swept from 1-6.

| Target Vacuum | Experimental Observation |
| --- | --- |
| 10kPa | Oscillations between 0 and ~20kPa |
| 30kPa | Oscillations between ~13kPa and 57kPa |
| 70kPa | Oscillations between ~47kPa and 75kPa |

### Appendix E: Compressible Flow Equations

The compressible flow equation states  <span markdown="0">\(\dot{m}=\frac{\pi}{4}\frac{(P_1^2-P_2^2)MD^5}{fLRT}\)</span>  where  <span markdown="0">\(\dot{m}\)</span>  is air flow rate, P1 and P2 are pressures in and out, M is molar mass of gas (constant), R is universal gas constant (constant), T is absolute temperature of gas (constant), f is the friction factor which is constant for the same gas, and D is the diameter of the tube and L is the length of the tube (Nandagopal, 2025). This indicates that the flow rate is very sensitive to tubing diameter and less, but still sensitive to tubing length.

### Appendix F: 4 mm Tube Configuration Results

A quick fix was implemented where 1.5m long, 4mm outer diameter tubes were added to both the vacuum and vent valves alongside the 6mm tubes. Test 1 with proportional error controller was repeated and the following key observations were made.

| Metric | 6mm only configuration | Added 4mm tube configuration |
| --- | --- | --- |
| Peak Pressure Change (10kPa pulse) | 41.4kPa | 19.6kPa |
| Pressure change at 300ms after pulse | 34.3kPa | 16.1kPa |
| Post pulse vacuum decay rate | 24kPa/s | 14.7kPa/s |

### Appendix G: Choked Flow Equations

Air flow rate is also inversely proportional to the actuator volume. In fact, critical flow equations (Thermopedia, 2011)  tell us that when the ratio of the air pressure out of the needle valve P2 to air pressure into the needle valve P1 exceeds 0.528, air velocity hits Mach 1 at the narrowest point.

<div class="legs-equation">\[ \frac{P_2}{P_1}\leq 0.528 \]</div>

This means for our vent valve, when P2~101.3kPa absolute (atmosphere), the critical threshold of 0.528 is hit when our actuator has reached 53.5kPa absolute or -47.8kPa gauge vacuum. This means that if the actuator is < -48kPa, air flow is sonic. Under these conditions, the choked flow equations (NASA Glenn Research Center, 2024) say

<div class="legs-equation">\[ \dot{m}_{\mathrm{choked}}=C_d A P_1\sqrt{\frac{\gamma}{RT}}\left(\frac{2}{\gamma+1}\right)^{\frac{\gamma+1}{2(\gamma-1)}} \]</div>

where <span markdown="0">$\gamma=1.4$</span> and <span markdown="0">$R=287\ \mathrm{J/(kg\cdot K)}$</span>.

And from <span markdown="0">$\Delta P_{\min}=\frac{RT\dot{m}\Delta t_{\min}}{V}$</span> , we can calculate <span markdown="0">$\Delta V_{\mathrm{atm}}\approx 2.58\times A\;(\mathrm{m^3})$</span> . Theoretically, for a 2mm diameter orifice (orifice is the set needle valve gap) and a 20ms pulse, for our current setup with an estimated volume of <span markdown="0">$14.5\ \mathrm{mL}\;(14500\ \mathrm{mm^2})$</span> , the theoretical max pressure change we can see is <span markdown="0">$\Delta P=56.7\ \mathrm{kPa}$</span> . However, if we increase the actuator volume to <span markdown="0">$500\ \mathrm{mL}\;(500000\ \mathrm{mm^2})$</span> , the theoretical max pressure change we can see is <span markdown="0">$\Delta P=1.6\ \mathrm{kPa}$</span> .

The reservoir would provide a larger pre-evacuated volume, reducing the relative pressure disturbance caused by individual valve pulses. This could improve pressure stability and reduce the sensitivity of the system to discrete valve actuation. Its effectiveness must be experimentally evaluated, since reservoir size also affects evacuation time and overall system response.

<!-- Page-local MathJax setup: required when the report layout does not load a math renderer. -->
<script>
window.MathJax = window.MathJax || {
  tex: {inlineMath: [['\\(', '\\)']], displayMath: [['\\[', '\\]']]},
  options: {skipHtmlTags: ['script', 'noscript', 'style', 'textarea', 'pre', 'code']}
};
</script>
<script defer src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-chtml.js"></script>
<style>
.legs-equation {text-align:center; overflow-x:auto; margin:1.15rem 0; padding:.35rem 0;}
.legs-equation mjx-container[display="true"] {margin:.3em 0 !important;}
a[href^="http"] {overflow-wrap:anywhere; word-break:break-word;}
table {width:100%;}
</style>
