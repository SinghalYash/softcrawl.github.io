---
layout: report
title: Robot Body
group: Interim
code: SEC-02
nav_order: 2
permalink: /report/structure/
---


## 2. Robot Body: Soft Actuation Subsystem

The Robot Body is the soft actuated spine of SoftCrawl. It contracts and bends so that the legs can step, climb vertical walls and turn 90 degree corners inside the wing tank.

<div class="stat-row"> <div class="stat"><span class="value">51.4%</span><span class="label">Axial contraction ratio</span></div> <div class="stat"><span class="value">&gt;3.3 kg</span><span class="label">Load held</span></div> <div class="stat"><span class="value">72.7°</span><span class="label">Best bend</span></div> <div class="stat"><span class="value">506 g</span><span class="label">Body mass</span></div> </div>

### 2.1 Subsystem Requirements

The objective is a soft, spark-free body that fits through standard access panels and can contract and bend to move the robot. The scope covers the actuated spine, its end plates, and the leg mounts. To ensure fuel tank safety, the body contains zero internal electronics and is powered via external pneumatic lines and a vacuum pump.

To translate these operational goals into actionable engineering constraints, the overall mission requirements were flowed down into four core mechanical specifications, detailed in Table 1:

<div class="table-fillet" style="border: 1.5px solid #000; border-radius: 12px; overflow: hidden; margin: 24px 0 10px; background: #fff;">
<table style="width: 100%; border-collapse: collapse; border: none; margin: 0; font-size: 15px; background: #fff;">
  <thead>
    <tr>
      <th style="width: 25%; text-align: center; font-weight: 700; color: #f6eedc; border: 1.5px solid #000; padding: 14px 16px; background: #0e3557; letter-spacing: 0.05em;">Category</th>
      <th style="text-align: center; font-weight: 700; color: #f6eedc; border: 1.5px solid #000; padding: 14px 16px; background: #0e3557; letter-spacing: 0.05em;">Requirement</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="2" style="border: 1.5px solid #000; padding: 12px 16px; vertical-align: middle; color: #000;">Geometry</td>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">Fit within a 300 × 200 mm access opening</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000; padding: 12px 16px; background-color: #55ff22; color: #000;">Actuator never expands beyond the body, avoiding snags</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000; padding: 12px 16px; vertical-align: middle; color: #000;">Electronics</td>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">No electronics in the tank except camera and light</td>
    </tr>
    <tr>
      <td rowspan="2" style="border: 1.5px solid #000; padding: 12px 16px; vertical-align: middle; color: #000;">Adhesion</td>
      <td style="border: 1.5px solid #000; padding: 12px 16px; background-color: #55ff22; color: #000;">Actuate with a 0.75 kg robot mass with safety factor 2 on vertical surfaces</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">Adhesion on thin oil film over aluminium sheet</td>
    </tr>
    <tr>
      <td rowspan="3" style="border: 1.5px solid #000; padding: 12px 16px; vertical-align: middle; color: #000;">Locomotion</td>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">Control each leg individually</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000; padding: 12px 16px; background-color: #55ff22; color: #000;">Climb 90 degree corners</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">Pass through 30cm x 30cm access hole to next fuel tank chamber</td>
    </tr>
    <tr>
      <td rowspan="2" style="border: 1.5px solid #000; padding: 12px 16px; vertical-align: middle; color: #000;">Material compatibility</td>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">No damage to fuel tank internal surfaces</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000; padding: 12px 16px; background-color: #55ff22; color: #000;">No swelling/damage due to prolonged oil exposure</td>
    </tr>
  </tbody>
</table>
</div>
<p class="table-caption">Table 1. Robot Body requirements</p>

---

### 2.2 Concept Generation

#### 2.2.1 Actuation Mechanism Selection

The body must contract and bend the robot using only air supplied from outside the tank. Three pneumatic actuation approaches were considered (Hoque et al., 2023; Wang et al., 2024).

<figure>
  <div class="figure-row three">
    <img src="{{ '/images/body/image1.png' | relative_url }}">
    <img src="{{ '/images/body/image2.png' | relative_url }}">
    <img src="{{ '/images/body/image3.png' | relative_url }}">
  </div>
  <figcaption>Figure 1. Pneumatic actuation options considered for the Robot Body: (a) artificial muscle, (b) bellows, (c) origami.</figcaption>
</figure>

Following a comparative evaluation of candidate actuation concepts against our design requirements (see [Appendix A](#appendix-a-detailed-actuation-mechanism-comparison)), we selected origami-based actuators. The primary deciding factor was **zero radial expansion**: unlike artificial muscles and bellows, which balloon outward when pressurized, an origami actuator remains strictly within the robot's body envelope. Furthermore, it operates reliably at low pressure, which is ideal for long pneumatic lines.

Because mechanical behavior varies substantially across different origami crease patterns, the next step is selecting the optimal pattern under load.

#### 2.2.2 Origami Pattern Selection

Three origami patterns are commonly used for tubular actuators: Accordion, Yoshimura and Kresling (Wickeler et al., 2023; Melancon et al., 2022). They were compared on load capacity, stability and speed.

<div class="table-fillet" style="border: 1.5px solid #000; border-radius: 12px; overflow: hidden; margin: 24px 0 10px; background: #fff;">
<table style="width: 100%; border-collapse: collapse; border: none; margin: 0; font-size: 15px; background: #fff;">
  <thead>
    <tr>
      <th style="width: 25%;">Criterion</th>
      <th>Accordion</th>
      <th>Yoshimura</th>
      <th>Kresling</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>Load capacity and deformation mode</strong></td>
      <td>Lowest load capacity</td>
      <td>Highest peak load, but fails by buckling</td>
      <td>High load capacity and controlled crease folding</td>
    </tr>
    <tr>
      <td><strong>Stability</strong></td>
      <td>Monostable</td>
      <td>Monostable</td>
      <td>Tunable multistability</td>
    </tr>
    <tr>
      <td><strong>Speed and energy release</strong></td>
      <td>Slow</td>
      <td>Slow</td>
      <td>Fast, rapid snap rebound</td>
    </tr>
  </tbody>
</table>
</div>
<p class="table-caption">Table 2. Comparison of candidate origami crease patterns</p>

<figure> 
<div class="figure-row three"> 
<img src="{{ '/images/body/image4.png' | relative_url }}">
<img src="{{ '/images/body/image5.png' | relative_url }}">
<img src="{{ '/images/body/image6.png' | relative_url }}">
</div>
<figcaption>Figure 2. Accordion, Yoshimura and Kresling origami patterns: (a) patterns, (b) crease folding, (c) force against deformation (adapted from Wickeler et al., 2023).</figcaption> 
</figure>

- **Higher Load-Bearing without Buckling:** While the Accordion tube exhibits the lowest load capacity and the Yoshimura suffers wall buckling after reaching peak load, the Kresling achieves nearly 3 times the compressive strength of the Accordion by channeling deformation along controlled, repeatable hinge lines.
- **Rapid Snap-Through Dynamics:** As a non-rigid origami morphology, Kresling facets deform elastically during contraction. This out-of-plane compliance stores strain energy that releases rapidly during snap-through, accelerating contraction and rebound without structural buckling.
- **Tunable Multistability for Zero-Power Holding:** Unlike monostable Accordion and Yoshimura structures, Kresling geometries possess multiple stable states. By tuning cell geometry or bonding rigid facet stiffeners, intermediate stable states can be created (Melancon et al., 2022), enabling the robot to passively maintain bending angles without continuous pneumatic draw.

<figure>
<img src="{{ '/images/body/image7.png' | relative_url }}">
<figcaption>Figure 3. Tunable multistability of the Kresling pattern (Melancon et al., 2022).</figcaption>
</figure>

---

### 2.3 Kresling Unit Design

The baseline Kresling unit cell geometry was parameterized following the kinematic framework established by Fan et al. (2025), utilizing a 6-sided regular polygonal base (*N* = 6). The design parameters were derived from a geometric optimization study for soft robot actuators.

A critical finding in Kresling mechanics is that structural stiffness decreases as the number of polygon sides increases; across all materials, a 6-sided hexagonal configuration is significantly stiffer than an 8-sided octagonal one. Selecting a hexagonal configuration reduces actuation resistance, allowing the structure to fold smoothly.

<figure>
<img src="{{ '/images/body/image8.png' | relative_url }}">
<figcaption>Figure 4. Kresling unit geometry and parameters.</figcaption> 
</figure>

---

### 2.4 Mechanical Design: From Unit Cell to an Actuator

A single Kresling cell provides insufficient stroke for effective crawling. To scale stroke into a functional pneumatic actuator, the following design modifications were implemented:

#### 2.4.1 Series Stacking for Stroke Multiplication

To achieve the linear displacement required for locomotion, individual Kresling units are stacked in series along a continuous central axis. Stacking multiplies the net contraction displacement proportionally.

Through multiple prototyping iterations, the actuator evolved from an initial 5-link to a 7-link stack. This increased the uncompressed actuator height to 214 mm, providing an unconstrained axial stroke exceeding 104 mm (51.4% contraction). This increased stroke length provides the necessary clearance for the robot's feet to advance during crawling and facilitates transitions when climbing obstacles.

<figure>
<div class="figure-row">
<img src="{{ '/images/body/image9.png' | relative_url }}" alt="5-link stack">
<img src="{{ '/images/body/image10.png' | relative_url }}" alt="7-link stack">
</div>
<figcaption>Figure 5. Kresling actuator stacks: (a) 5-link (V2) and (b) 7-link (V3).</figcaption>
</figure>

#### 2.4.2 Embedded Rigid PLA Boundary Rings & Print-in-Place

Three complementary design decisions enabled a functional, sealed actuator:

- **Rigid Boundary Rings:** Embedded PLA rings enforce polygon boundaries, preventing the radial inward collapse seen in all-elastomer bodies under vacuum.
- **Fuel-Resistant Elastomer:** eSUN TPE 83A was selected for compliant, low-fatigue hinge folding and oil resistance in fuel tank environments.
- **Support-Free Print-in-Place:** Because internal supports cannot be removed from a sealed chamber, all facet angles were constrained to less than 45 degrees, enabling single-step multi-material printing with zero post-processing.

<figure>
  <img src="{{ '/images/body/image11.png' | relative_url }}">
  <figcaption>Figure 6. Embedded rigid PLA boundary rings preventing radial inward collapse under vacuum.</figcaption>
</figure>

#### 2.4.3 Compliant Flexure Hinges via 0.4 mm Facet Offset

To resolve chaotic panel buckling observed in uniform-thickness prototypes, the triangular facet bodies were offset outward by 0.4 mm in CAD. This established a sharp thickness gradient: the thinned crease lines act as low-resistance flexure hinges, while the thicker facets stay rigid, forcing predictable folding along programmed crease lines without wrinkling.

<figure>
  <img src="{{ '/images/body/image12.png' | relative_url }}">
  <figcaption>Figure 7. Triangular facet geometry with 0.4 mm outward offset establishing compliant flexure hinges.</figcaption>
</figure>

---

### 2.5 Prototype Development (V1–V3)

- **V1:** Tested the initial baseline geometry. The stack collapsed under vacuum due to thin internal rings, and suffered from poor print quality and suboptimal print parameters.

<figure>
<div class="figure-row">
<img src="{{ '/images/body/image13.png' | relative_url }}">
<img src="{{ '/images/body/image14.png' | relative_url }}">
</div>
<figcaption>Figure 8. Prototype V1: (a) printed baseline stack and (b) inward radial collapse under vacuum.</figcaption>
</figure>

- **V2:** Improved manufacturing quality, optimized print parameters, and introduced thicker PLA boundary rings. These structural reinforcements prevented inward collapse and successfully scaled the actuator up to a stable 5-link stack. Additionally added a twist-cap mechanism for assembly onto the robot body.

<figure>
  <img src="{{ '/images/body/image15.png' | relative_url }}">
  <figcaption>Figure 9. Prototype V2: reinforced 5-link stack with thickened PLA boundary rings and twist-cap mechanism.</figcaption>
</figure>

- **V3:** Increased overall structural stiffness to scale the stack further to 7 links (maximizing stroke length), and introduced 0.4 mm facet thickening. This created localized compliant hinges that eliminated chaotic wrinkling and ensured smooth, repeatable folding.

<figure>
<div class="figure-row">
<img src="{{ '/images/body/image16.png' | relative_url }}">
<img src="{{ '/images/body/image9.png' | relative_url }}">
</div>
<figcaption>Figure 10. Prototype V3: 7-link stack with localized 0.4 mm facet thickening for smooth folding.</figcaption>
</figure>
---

### 2.6 Mechanical Integration: From Actuator to Robot Body

Kresling origami achieves contraction by inherently twisting as it compresses. For a crawling robot, however, this rotation would twist the chassis and peel the adhering suction feet off the tank surface. The primary challenge was therefore decoupling this rotational motion to extract purely linear axial displacement.

This was resolved at the assembly level by integrating:

- **1608 Ball Bearing:** Decouples rotation from translation, allowing the actuator to twist freely through its full angle while channeling 100% of its contraction force into pure axial pulling.
- **Twist-Lock:** Allows actuator swaps, making the design modular, aiding prototyping and saving our precious Kresling actuators. An integrated detent bump provides a tactile "click" to confirm full locking.
- **Shaft, Bearing & E-Clip:** The end cap houses a print-in-place bearing, through which a central PLA shaft is captured by an E-clip to resist axial pull-out.
- **Pneumatic Seal:** An M5-to-6 mm OD push-in fitting is screwed into a threaded insert in the end cap, creating an airtight vacuum path into the actuator.

To complete the assembly, three identical actuators are mounted in a 120 degree equilateral triangle between rigid front and rear plates. This parallel arrangement constrains the remaining degrees of freedom, producing controllable 3D bending when the pressure in each Kresling actuator is controlled independently, and therefore linear crawling (see [Appendix B](#appendix-b-design-principles)).

Before printing, the actuator spacing was chosen using the team's SoftCrawl 3D simulator. The simulator showed that the bend angle is inversely proportional to the distance between the Kresling actuators: placing them closer together gives a larger bend for the same contraction, but lowers the bending stiffness. The simulation and the resulting spacing trade-off are described in [Appendix B.3](#b3-simulation).

<figure>
  <img src="{{ '/images/body/image30.png' | relative_url }}">
  <figcaption>Figure 11. Exploded view of twist-lock end cap assembly showing ball bearing, central shaft, and pneumatic seal.</figcaption>
</figure>

<figure>
  <img src="{{ '/images/body/image18.png' | relative_url }}">
  <figcaption>Figure 12. Complete SoftCrawl robot assembly featuring three parallel Kresling actuators and integrated leg mounts.</figcaption>
</figure>

---

### 2.7 Experimental Evaluation

Three tests checked the V3 body against its specifications: contraction under no load, contraction under load and bending angle.

<div class="table-fillet" style="border: 1.5px solid #000; border-radius: 12px; overflow: hidden; margin: 24px 0 10px; background: #fff;">
<table style="width: 100%; border-collapse: collapse; border: none; margin: 0; font-size: 15px; background: #fff;">
  <thead>
    <tr>
      <th style="width: 30%;">Test</th>
      <th>Purpose</th>
      <th>Specification Tested</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>Contraction under no load</strong></td>
      <td>Measure the stroke available to the legs</td>
      <td>Locomotion; geometry</td>
    </tr>
    <tr>
      <td><strong>Contraction under load</strong></td>
      <td>Confirm the body carries the robot with margin</td>
      <td>0.75 kg with safety factor 2</td>
    </tr>
    <tr>
      <td><strong>Bending angle</strong></td>
      <td>Measure how far the body can turn</td>
      <td>Climb 90 degree corners</td>
    </tr>
  </tbody>
</table>
</div>
<p class="table-caption">Table 3. Experimental testing matrix and corresponding specifications</p>

#### 2.7.1 Contraction under no load

Under zero external load, the actuator's axial stroke was characterized across five repeated trials using a vacuum pump. The actuator was driven with no load and its length was measured before and after. It contracted from 214 mm to 104 mm, achieving a 51.4% contraction ratio.

<figure>
<img src="{{ '/images/body/image19.png' | relative_url }}">
<figcaption>Figure 13. Unloaded contraction of the V3 actuator from 214 mm to 104 mm (51.4% stroke).</figcaption>
</figure>

#### 2.7.2 Contraction under load

A load was attached to check actuator contraction while carrying weight. The weight was progressively increased and the contraction was measured, as shown in the graph below. We stopped our test at 3.3 kg.

<figure>
<img src="{{ '/images/body/image20.png' | relative_url }}">
<figcaption>Figure 14. Experimental test setup for contraction under 3.3 kg load with V3 actuator.</figcaption>
</figure>

<figure>
<img src="{{ '/images/body/image21.png' | relative_url }}">
<figcaption>Figure 15. Measured actuator contraction versus applied external load.</figcaption>
</figure>

#### 2.7.3 Bending angle

The actuator was held in place with two G-clamps and an angle sheet was placed underneath it. A phone on a stand filmed each bend from a fixed position so that every trial used the same view, and a pressure regulator controlled the pressure. The best bend reached 72.7 degrees, with the actuator snapping during bending. Other measurements were 68.9 and 53.4 degrees. At about 55 kPa in each run, "snapping" occurred, when the Kresling actuator would bend completely on its fold line.

For comparison, the simulator predicted 82.3° for the same 25.5 mm actuator spacing (see [Appendix B.3](#b3-simulation)). The measured 72.7° is about 10° lower. This is likely because the simulator ignores air leakage, friction in the end plates and the early snap at about 55 kPa.

<figure>
<img src="{{ '/images/body/image22.png' | relative_url }}">
<figcaption>Figure 16. Bending test setup with angular measurement grid and pressure regulator.</figcaption>
</figure>

<figure>
<div class="figure-row three">
<img src="{{ '/images/body/image31.png' | relative_url }}">
<img src="{{ '/images/body/image32.png' | relative_url }}">
<img src="{{ '/images/body/image33.png' | relative_url }}">
</div>
<figcaption>Figure 17. Actuator bending trials: reaching a peak bend angle of 72.7°.</figcaption>
</figure>



<div class="table-fillet" style="border: 1.5px solid #000; border-radius: 12px; overflow: hidden; margin: 24px 0 10px; background: #fff;">
<table style="width: 100%; border-collapse: collapse; border: none; margin: 0; font-size: 15px; background: #fff;">
  <thead>
    <tr>
      <th style="width: 35%;">Measure</th>
      <th>Result</th>
      <th>Requirement</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>Length, relaxed to contracted</strong></td>
      <td>185 mm to 80 mm (56.8% shorter)</td>
      <td>Not specified</td>
    </tr>
    <tr>
      <td><strong>Load held near full contraction</strong></td>
      <td>More than 3.3 kg</td>
      <td>1.5 kg (0.75 kg × 2)</td>
    </tr>
    <tr>
      <td><strong>Best bend angle</strong></td>
      <td>72.7 degrees</td>
      <td>90 degrees</td>
    </tr>
  </tbody>
</table>
</div>
<p class="table-caption">Table 4. Summary of test results against requirements</p>

---

### 2.8 Shortcomings and Proposed Improvements

Testing exposed two limitations of the current body:

1. **Air leakage:** the printed actuator loses pressure quickly.
2. **Tubing:** air lines can snag on the tank ribs and add drag.

#### 2.8.1 Airtight Sealing

Due to micro-porosity along thin printed walls and layer interfaces, the actuator experiences a leak rate of 0.059 kPa per millisecond. This rapid loss makes precise control difficult, especially at lower operating pressures: the actuator loses pressure faster than it can settle into position, preventing passive shape-holding without continuous pump compensation.

<figure>
<img src="{{ '/images/body/image23.png' | relative_url }}">
<figcaption>Figure 18. Measured pressure loss over time showing leak rate from printed wall porosity.</figcaption>
</figure>

The proposed improvement is to coat the actuator with a flexible polymer, such as Loctite fabric adhesive or Sil-Poxy, and to increase the number of printed walls from two to three. Success will be judged by repeating the pressure-loss measurement on the coated actuator against a target agreed with the controls team.

<figure>
<div class="figure-row">
<img src="{{ '/images/body/image24.png' | relative_url }}">
<img src="{{ '/images/body/image25.png' | relative_url }}">
</div>
<figcaption>Figure 19. Proposed sealing solutions: flexible polymer coating and three-wall perimeter printing.</figcaption>
</figure>

#### 2.8.2 Tubing

The air and data lines can snag on the internal tank ribs, and heavy tubing adds resistive force that the body and legs must overcome.

The proposed improvement is to bundle all lines into a single low-friction umbilical sleeve that prevents snagging. It will be tested by crossing a rib mock-up while towing the umbilical.

<figure>
<img src="{{ '/images/body/image26.png' | relative_url }}">
<figcaption>Figure 20. Pneumatic and electrical umbilical tubing running alongside the robot body.</figcaption>
</figure>

---

### 2.9 Next Steps

#### 2.9.1 Programmable Multistability for Zero-Power Angle Holding

Current actuators are monostable, snapping abruptly between 0% and 100% contraction and requiring continuous vacuum to hold position. To resolve this, in the next phase we want to explore programmable multistability (Melancon et al., 2022):

- **Passive Angle Locking:** Bonding rigid PLA plates to selected facets introduces intermediate energy states, allowing the robot to passively lock into discrete bend angles without constant vacuum draw.
- **Snap-Assisted Bending:** Rather than viewing snap-through instability as a control hurdle, we want to harness this rapid energy release to overcome structural resistance at large deflections. This could help us achieve obstacle-climbing bends of greater than 90 degrees, which can help with hole traversal in the tank.

<figure>
<div class="figure-row">
<img src="{{ '/images/body/image27.png' | relative_url }}">
<img src="{{ '/images/body/image7.png' | relative_url }}">
</div>
<figcaption>Figure 21. Programmable multistability concept using rigid facet stiffeners for zero-power angle holding.</figcaption>
</figure>

#### 2.9.2 Varying Unit Shapes for Tuned Bending

While identical 7-link Kresling units provide uniform contraction, tailoring the bending trajectory requires exploring hybrid and non-uniform stack architectures:

- **Alternating Unit Geometries:** Rather than using identical links, future iterations will explore hybrid stacks combining Kresling units with Accordion or Yoshimura folds. By grading wall thicknesses and facet angles (α), individual units can snap sequentially at different pressure thresholds, concentrating curvature precisely where needed to clear obstacle corners.
- **Varying Parameters within a Single Stack:** Modifying Kresling parameters along the spine, such as wall thickness or facet angles, can create a stiffness gradient. This triggers units to fold at different vacuum thresholds, concentrating curvature at specific joints for sharper, sequential bending.

<figure>
<img src="{{ '/images/body/image29.png' | relative_url }}">
<figcaption>Figure 22. Hybrid actuator concept combining alternating origami fold geometries.</figcaption>
</figure>
---

## References

- Fan, J., Zhang, L., & Wang, Y. (2025). Design and kinematics of deployable Kresling origami actuators. *Advanced Science, 12*(4), Article 2401182. <https://doi.org/10.1002/advs.202401182>
- Hoque, M. A., Petersen, E., & Fang, X. (2023). Effect of material properties on fiber-shaped pneumatic actuators performance. *Actuators, 12*(3), Article 129. <https://doi.org/10.3390/act12030129>
- Melancon, D., Gorissen, B., García-Mora, C. J., Hoberman, C., & Bertoldi, K. (2022). Inflatable origami: Multimodal deformation via multistability. *Advanced Functional Materials, 32*(15), Article 2110116. <https://doi.org/10.1002/adfm.202110116>
- Santoso, J., & Onal, C. D. (2017). An origami-inspired continuum robotic arm with large workspace and high payload capacity. In *2017 IEEE/RSJ International Conference on Intelligent Robots and Systems (IROS)* (pp. 1298–1304). IEEE. <https://doi.org/10.1109/IROS.2017.8202306>
- Wang, Z., Li, X., & Chen, H. (2024). Kinematic modeling and deflection analysis of soft pneumatic bellows actuators. *Sensors, 24*(5), Article 1542. <https://doi.org/10.3390/s24051542>
- Webster, R. J., & Jones, B. A. (2010). Design and kinematic modeling of constant curvature continuum robots: A review. *The International Journal of Robotics Research, 29*(13), 1661–1683. <https://doi.org/10.1177/0278364910368147>
- Wickeler, A. L., McLellan, K., Sun, Y.-C., & Naguib, H. E. (2023). 4D printed origami-inspired accordion, Kresling, and Yoshimura tubes: A comparative study. *Journal of Intelligent Material Systems and Structures, 34*(11), 1285–1298. <https://doi.org/10.1177/1045389X221144005>
- eSUN. (n.d.). *What is TPU? Flexible 3D printing guide & eSUN TPU*. eSUN Wiki. Retrieved November 12, 2026, from <https://www.esun3d.com/wiki/tpu-material>
- U.S. Bellows, Inc. (n.d.). *Bellows deflections: Axial, lateral & angular*. Retrieved November 13, 2026, from <https://usbellows.com/bellows-deflections-axial-lateral-angular/>
- Sviridenko, M., & Berinskii, I. E. (2026). Dynamical simulation of origami-based elastic structures using discrete models. *Smart Materials and Structures*. <https://github.com/Sv1r/ORYGDYN>

---

## Appendix

### Appendix A: Detailed Actuation Mechanism Comparison

<div class="table-fillet" style="border: 1.5px solid #000; border-radius: 12px; overflow: hidden; margin: 24px 0 10px; background: #fff;">
<table style="width: 100%; border-collapse: collapse; border: none; margin: 0; font-size: 15px; background: #fff;">
  <thead>
    <tr>
      <th style="width: 28%;">Mechanism</th>
      <th>Advantage</th>
      <th>Limitation for SoftCrawl</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>(a) Pneumatic artificial muscle</strong></td>
      <td>High tensile force-to-weight ratio</td>
      <td>Balloons radially, so it expands beyond the body bounding area and needs a high operating pressure</td>
    </tr>
    <tr>
      <td><strong>(b) Bellows actuator</strong></td>
      <td>Well established in industry and works at low pressure</td>
      <td>Poor lateral stiffness and prone to buckling or ballooning</td>
    </tr>
    <tr>
      <td><strong>(c) Origami actuator</strong></td>
      <td>Low pressure, zero radial ballooning and low material use</td>
      <td>Strength and stiffness depend on the fold pattern chosen; prone to air leakage</td>
    </tr>
  </tbody>
</table>
</div>
<p class="table-caption">Table A1. Detailed actuation mechanism comparison</p>

### Appendix B: Design Principles

#### B.1 Bending model

A single Kresling only contracts, so bending needs several actuators working together. The model follows the constant-curvature approach of Webster and Jones (2010), checked experimentally for multi-chamber soft arms by Santoso and Onal (2017). For two actuators offset by *d* from the centreline of length *L*, the two lengths and the plate angle *θ* are related by:

$$
l_1 = L - d\theta, \qquad l_2 = L + d\theta, \qquad \theta = \frac{l_2 - l_1}{2d}
$$

A wider spacing *d* therefore gives less bend for the same length difference. For *n* identical actuators of axial stiffness *k*, turning the front plate by *α* stretches or squashes each actuator by (arm × *α*), where arm is its distance to the neutral axis. Summing the moments is the same idea as the second moment of area in beam theory:

$$
K_{bend} = \frac{M}{\alpha} = k \sum \text{arm}^2 = \frac{n\,k\,d^2}{2}
$$

The model assumes identical actuators, small turns and axial loads only.

#### B.2 Number and layout of actuators

Two actuators give two degrees of freedom: one contraction and one bend in a single plane. Three actuators at 120 degrees bend in any direction. A fourth actuator was also considered.

<div class="table-fillet" style="border: 1.5px solid #000; border-radius: 12px; overflow: hidden; margin: 24px 0 10px; background: #fff;">
<table style="width: 100%; border-collapse: collapse; border: none; margin: 0; font-size: 15px; background: #fff;">
  <thead>
    <tr>
      <th style="width: 25%;">Criterion</th>
      <th>Triangle (3 Actuators)</th>
      <th>Rectangle (4 Actuators)</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>Bending stiffness</strong></td>
      <td>1.5 <em>k d</em>²</td>
      <td>2 <em>k d</em>² (33% higher)</td>
    </tr>
    <tr>
      <td><strong>Load capacity</strong></td>
      <td>Baseline</td>
      <td>33% higher</td>
    </tr>
    <tr>
      <td><strong>Valves and tubes</strong></td>
      <td>3</td>
      <td>4; pump flow requirement uncertain</td>
    </tr>
    <tr>
      <td><strong>Weight and footprint</strong></td>
      <td>Lighter, smaller</td>
      <td>Heavier, larger</td>
    </tr>
    <tr>
      <td><strong>Control</strong></td>
      <td>Independent</td>
      <td>Coupled; over-constrained (<em>l</em>₁ + <em>l</em>₃ = <em>l</em>₂ + <em>l</em>₄)</td>
    </tr>
    <tr>
      <td><strong>Redundancy</strong></td>
      <td>None</td>
      <td>Yes</td>
    </tr>
  </tbody>
</table>
</div>
<p class="table-caption">Table B1. Evaluation of actuator arrangement concepts</p>

The triangle was selected because three actuators are the minimum for full 3D bending, it needs fewer valves and tubes, and it keeps control of each actuator independent. The rectangle is stiffer and has redundancy, but its control is coupled and over-constrained.

An equilateral triangle was preferred over an isosceles one. It has the same bending stiffness (1.5 *k d*²) in every direction. An isosceles layout is stiff in one direction (2.3 *k d*²) but three times weaker in the other (0.5 *k d*²), and its load centre sits 0.24 *d* off the plate centre, so it droops under a nose load. Mounting the triangle apex up or apex down gives the same bending moment, so this is a packaging decision: apex up needs one valve to bend upward, while apex down shares a nose load between two actuators.

<!-- TODO: End views of the two-actuator and three-actuator layouts showing l1, l2, d, θ and the 120 degree spacing, with the equilateral and isosceles comparison. Use slides 54, 55, 176 and 177. -->

*Figure B1. Two-actuator and three-actuator layouts and their stiffness.*

#### B.3 Simulation

The layout was also checked in the team's SoftCrawl 3D simulator, which implements the Webster and Jones model. Its purpose was to see how leg spacing affects the bend angle before printing. It confirmed that a wider spacing gives a smaller bend for the same length difference.
##### B.3.1 Tools

Two simulation tools were used. At the unit-cell level, ORYGDYN, an open-source MATLAB package by Sviridenko and Berinskii (2026), was explored. It simulates the dynamics of origami structures using a bar-and-hinge model and includes a Kresling example. At the body level, the team built the SoftCrawl 3D simulator. It models the 7-link actuators and the rigid shared plates, and it calculates bending with the piecewise-constant-curvature (PCC) model of Webster and Jones (2010).

<figure>
<div class="figure-row">
<img src="{{ '/images/body/image34.png' | relative_url }}">
<img src="{{ '/images/body/image35.png' | relative_url }}">
</div>
<figcaption>Figure B2. Simulation tools: (a) ORYGDYN bar-and-hinge origami package (Sviridenko and Berinskii, 2026) and (b) SoftCrawl 3D simulator.</figcaption>
</figure>

##### B.3.2 Simulator set-up

<div class="table-fillet" style="border: 1.5px solid #000; border-radius: 12px; overflow: hidden; margin: 24px 0 10px; background: #fff;">
<table style="width: 100%; border-collapse: collapse; border: none; margin: 0; font-size: 15px; background: #fff;">
  <thead>
    <tr>
      <th style="width: 50%;">Parameter</th>
      <th>Value</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Actuator</td>
      <td>Kresling, 7 links</td>
    </tr>
    <tr>
      <td>Unit resting height</td>
      <td>20 mm (140 mm per actuator)</td>
    </tr>
    <tr>
      <td>Maximum contraction ratio</td>
      <td>40%</td>
    </tr>
    <tr>
      <td>Twist per unit contraction</td>
      <td>12° per unit</td>
    </tr>
    <tr>
      <td>Triangular pitch circle radius, <em>d</em></td>
      <td>25.5 mm</td>
    </tr>
    <tr>
      <td>Top plate</td>
      <td>Rigid, shared</td>
    </tr>
    <tr>
      <td>1608 bearing decoupling</td>
      <td>On</td>
    </tr>
    <tr>
      <td>Suction standoff height</td>
      <td>16 mm</td>
    </tr>
  </tbody>
</table>
</div>
<p class="table-caption">Table B2. SoftCrawl 3D simulator settings</p>

##### B.3.3 Bending model for three actuators

For three actuators of lengths *l*₁, *l*₂ and *l*₃ placed at 120° on a pitch circle of radius *d*, the PCC model gives the curvature *κ* and the bend angle *θ* as:

$$
\kappa = \frac{2\sqrt{l_1^2 + l_2^2 + l_3^2 - l_1 l_2 - l_2 l_3 - l_1 l_3}}{d\,(l_1 + l_2 + l_3)}, \qquad
\theta = \kappa\,\bar{l} = \frac{2\sqrt{l_1^2 + l_2^2 + l_3^2 - l_1 l_2 - l_2 l_3 - l_1 l_3}}{3d}
$$

Here *l̄* is the mean actuator length. For any given set of actuator lengths, the bend angle is therefore **inversely proportional to the spacing *d***. This is the three-actuator form of the two-actuator relation in B.1.

##### B.3.4 Result: bend angle against spacing

In the simulator, one actuator was fully contracted (140 mm to 84 mm) and the other two were left relaxed. With *d* = 25.5 mm, the simulator reported a curvature of 11.91 m⁻¹ and a bend angle of **82.3°**. This agrees with the hand calculation from the equation above (83.9°). Keeping the same contraction and changing only *d* gives:

<div class="table-fillet" style="border: 1.5px solid #000; border-radius: 12px; overflow: hidden; margin: 24px 0 10px; background: #fff;">
<table style="width: 100%; border-collapse: collapse; border: none; margin: 0; font-size: 15px; background: #fff;">
  <thead>
    <tr>
      <th style="width: 50%;">Spacing <em>d</em> (mm)</th>
      <th>Bend angle <em>θ</em> (°)</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>20.0</td>
      <td>106.9</td>
    </tr>
    <tr>
      <td>25.5 (current)</td>
      <td>83.9</td>
    </tr>
    <tr>
      <td>30.0</td>
      <td>71.3</td>
    </tr>
    <tr>
      <td>35.0</td>
      <td>61.1</td>
    </tr>
    <tr>
      <td>40.0</td>
      <td>53.5</td>
    </tr>
  </tbody>
</table>
</div>
<p class="table-caption">Table B3. Predicted bend angle against actuator spacing for one actuator fully contracted</p>

<figure>
<img src="{{ '/images/body/image36.png' | relative_url }}">
<figcaption>Figure B3. Simulated bend angle against actuator spacing (SoftCrawl 3D simulator).</figcaption>
</figure>

When the spacing is doubled, the bend angle halves. The reason is that the same difference in length is spread over a longer lever arm, so the plate rotates less. This sets up a trade-off with B.1. Bending stiffness grows with *d*² (*K*_bend = 1.5 *k d*²), while the bend angle falls with 1/*d*. A smaller spacing gives the larger bends needed for 90° corners. A larger spacing gives a stiffer body that droops less under load. Under the simulator's assumptions, reaching 90° with the 40% contraction would need *d* ≤ 23.8 mm.
