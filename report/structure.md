---
layout: report
title: Robot Structure
group: Interim
code: SYS-01
nav_order: 1
permalink: /report/structure/
---

*Authors: Aakash J & Yash S (Year 4 Mechanical Engineering)*  
*Subsystem: Robot Body & Actuation Mechanics*

---

## 1. Overview & Concept Generation

In modern commercial aviation maintenance, non-destructive inspection (NDI) of integral wing fuel tanks is critical to detect sealant degradation, fastener defects, structural cracks, and biological corrosion (Polimeno & Meo, 2009; FAA AD 2025-20-05). However, fuel tank access panels are severely restricted in geometry (typically 30 cm by 20 cm manholes), and internal bays are heavily partitioned by structural ribs, stringers, and baffles (Airbus, 2024). Furthermore, the presence of flammable Jet A fuel vapors mandates strict compliance with explosion safety standards, requiring an intrinsically spark-free architecture (**ATEX Zone 0 compliant**).

<figure>
  <img src="{{ '/images/structure/fig1_fuel_tank_bay.png' | relative_url }}" alt="Human technician navigating confined aircraft fuel tank">
  <figcaption>Human technician navigating confined aircraft fuel tank compartments amidst internal structural ribs (Baxter, 2016; Airbus, 2024).</figcaption>
</figure>

Under current maintenance protocols, human entry requires extensive preparation, including a mandatory 24-hour ventilation period after fuel drainage, dedicated safety watch personnel, and heavy respirators. This exposes technicians to musculoskeletal injury and carcinogenic vapors while driving steep Aircraft-on-Ground (AOG) downtime costs. Existing robotic inspection systems—such as rigid tracked crawlers, motorized snake arms, or fluid-immersed swimming robots (Heilemann et al., 2021; Ricárdez Ortigosa et al., 2025)—either present electrical spark hazards, risk scratching internal sealant coatings with rigid chassis edges, or fail to negotiate 90-degree internal rib transitions.

To overcome these fundamental barriers, the **SoftCrawl** project introduces a bio-inspired, pneumatically driven continuum soft robotic crawler. By substituting rigid links with flexible, multi-material metamaterial structures, the robot achieves high structural compliance and gentle physical interaction with tank surfaces. The **Robot Structure Subsystem** constitutes the physical body backbone of SoftCrawl, responsible for generating high-force axial crawling strokes and large-angle omnidirectional bending transitions without expanding radially beyond its baseline footprint.

---

## 2. Actuation & Origami Concept Selection

To realize the locomotion requirements, three distinct pneumatic actuation mechanisms were systematically evaluated: **Pneumatic Artificial Muscles (PAMs / McKibben actuators)**, **Elastomeric Bellows Actuators**, and **Origami-Based Metamaterial Actuators** (Hoque et al., 2023; Wang et al., 2024).

<figure>
  <img src="{{ '/images/structure/fig3_actuation_methods.png' | relative_url }}" alt="Comparison of soft actuation morphologies">
  <figcaption>Comparison of soft actuation morphologies evaluated for the SoftCrawl body backbone.</figcaption>
</figure>

Each actuation method presents distinct mechanical and thermodynamic trade-offs:
* **Concept A — Pneumatic Artificial Muscles (PAMs / McKibben):** Characterized by high tensile force-to-weight ratios. However, PAMs require high positive supply pressures (>2 bar), creating severe burst and misting risks in a fuel tank. Crucially, PAMs exhibit significant radial ballooning (>30%) during contraction, which poses an unacceptable snagging risk against internal structural ribs and fasteners.
* **Concept B — Elastomeric Bellows Actuators:** Well-established in low-pressure industrial pneumatic applications. However, conventional bellows possess very low lateral and torsional stiffness, making them prone to erratic buckling when subjected to off-axis shear or compressive loads.
* **Concept C — Origami Metamaterial Actuators (Selected):** Driven exclusively by negative gauge pressure (vacuum). Because origami structures contract along pre-creased fold lines, they exhibit **ZERO radial ballooning** during actuation. Operating under vacuum provides inherent explosion safety—puncture results in ambient air rushing inward rather than explosive outward venting. Furthermore, origami structures exhibit high axial and torsional rigidity governed by facet geometry.

### Actuation Concept Decision Matrix

| Evaluation Criteria | Weight | (A) PAMs | (B) Bellows | (C) Origami Actuators |
| :--- | :---: | :---: | :---: | :---: |
| **Radial Expansion Constraint** | 25% | 1 (Expands >30%) | 2 (Bulges outward) | **5 (Zero expansion)** |
| **Ignition Safety & Vacuum Mode** | 20% | 2 (High positive P) | 3 (Low positive P) | **5 (Safe vacuum)** |
| **Stroke-to-Length Ratio** | 15% | 3 (~25–30%) | 4 (~40%) | **5 (>55% stroke)** |
| **Lateral / Torsional Rigidity** | 15% | 4 (High tension) | 1 (Floppy / buckles) | **4 (Facet governed)** |
| **Additive Manufacturability** | 15% | 2 (Braided sleeves) | 3 (Molded silicone) | **4 (Print-in-place)** |
| **Controllability & Linearity** | 10% | 3 (Hysteresis) | 3 (Viscoelastic creep) | **3 (Bistable snap)** |
| **Weighted Total Score** | **100%** | **2.35** | **2.65** | **4.45 / 5.00** |

<div class="callout result">
<p><strong>Selection Result:</strong> The Origami-Based Actuation architecture decisively outperformed alternatives with a score of <strong>4.45 / 5.00</strong>, driven by its absolute radial containment, vacuum compatibility, and high stroke capacity.</p>
</div>

### Origami Pattern Selection

Following the selection of origami actuation, three classical origami patterns were analyzed: **Accordion**, **Yoshimura**, and **Kresling** patterns (Wickeler et al., 2023; Melancon et al., 2022).

| Origami Pattern | Deformation Kinematics | Peak Load Mode | Stability Profile | Selection Verdict |
| :--- | :--- | :--- | :--- | :--- |
| **Accordion** | Pure 1D linear extension | Low load capacity | Monostable | Discarded: poor torsional rigidity |
| **Yoshimura** | Diamond-faceted radial fold | High axial load | Monostable | Discarded: catastrophic buckling |
| **Kresling** | **Coupled axial-torsional rotation** | **High load; controlled crease folding** | **Tunable multistability** | **SELECTED** |

The **Kresling pattern** was chosen because its triangulated geometry converts axial contraction into a prescribed twist angle, generating superior axial force while maintaining a constant circumscribed envelope.

---

## 3. Material Selection & Multi-Material Architecture

The material selection for the SoftCrawl body was governed by three strict engineering constraints: chemical inertness to hydrocarbon fuel (Jet A aviation kerosene), elastomeric compliance for airtight folding hinges, and structural rigidity for facet stability.

* **Silicone Elastomers (Smooth-On Ecoflex / Dragon Skin):** While standard in soft robotics, silicone exhibits rapid hydrocarbon swelling (>40% volume expansion within 4 hours in kerosene) and tensile softening, leading to catastrophic rupture.
* **Thermoplastic Polyurethane (TPU 95A):** Excellent chemical resistance, but at Shore 95A it is overly rigid for repeated crease folding, demanding excessive vacuum levels (>90 kPa) just to initiate folding.
* **Polymaker PolyFlex TPE 83A (Selected for Membrane):** Shore 83A hardness delivers an optimal balance of flexural compliance and elastic rebound. It exhibits negligible swell in kerosene and withstands thousands of folding cycles without fatigue cracking.
* **PolyLite Rigid PLA (Selected for Skeleton):** High Young's modulus ($E = 3.45\text{ GPa}$) ensures that the triangular facet faces remain undeformed, preserving the exact kinematic fold trajectory.

<figure>
  <img src="{{ '/images/structure/fig5_print_in_place.png' | relative_url }}" alt="Multi-material print-in-place architecture">
  <figcaption>Multi-material print-in-place architecture combining flexible TPE 83A membrane with rigid PLA constraining rings.</figcaption>
</figure>

By combining TPE 83A and Rigid PLA in a multi-material print-in-place process, SoftCrawl achieves a composite metamaterial structure. The rigid PLA rings constrain circumferential dilation, while the TPE membrane acts as continuous, hermetically sealed revolute hinges.

---

## 4. Detailed Mechanical Design & Parameterization

### 4.1 Kresling Unit Cell Geometric Definitions

The geometric design of the Kresling unit cell is formulated following Fan et al. (2025). The cell consists of a regular hexagonal prism ($N = 6$) characterized by base edge length $a$, circumscribed circle radius $r$, crease fold angle $\alpha$, mountain fold length $b$, and uncompressed unit height $h_0$.

<figure>
  <img src="{{ '/images/structure/fig4_kresling_params.png' | relative_url }}" alt="Geometric parameter definitions of the hexagonal Kresling unit cell">
  <figcaption>Geometric parameter definitions of the hexagonal Kresling unit cell (Fan et al., Adv. Sci. 2025).</figcaption>
</figure>

<div class="callout info">
<p><strong>Optimized Kresling Unit Cell Parameters:</strong><br>
• Base Edge Length (a) = 15.0 mm<br>
• Circumscribed Radius (r) = 15.0 mm<br>
• Crease Fold Angle (&alpha;) = 30.0&deg;<br>
• Mountain Fold Length (b) = 20.81 mm<br>
• Initial Unit Height (h<sub>0</sub>) = 20.0 mm<br>
• Membrane Wall Thickness = 0.8 mm (with 0.4 mm localized crease thinning)
</p>
</div>

The mountain crease length $b$ is determined geometrically by:
$$b = \sqrt{a^2 + h_0^2 - 2 a h_0 \cos(\alpha)} = \sqrt{15^2 + 20^2 - 2(15)(20)\cos(30^\circ)} = 20.81\text{ mm}$$

The $0.4\text{ mm}$ local crease thinning reduces the bending moment of inertia at the fold lines ($I = w t^3 / 12$), ensuring that strain energy concentrates precisely along the intended hinge lines while the facets remain planar.

### 4.2 Series Stacking & Rigid Interlocking Rings

A single Kresling unit cell provides a stroke of $11.5\text{ mm}$ (from $20\text{ mm}$ down to $8.5\text{ mm}$). To achieve the crawling stride length required for effective in-tank locomotion, **seven identical unit cells ($N = 7$) were stacked in series**, yielding a total uncompressed height of $185\text{ mm}$.

<figure>
  <img src="{{ '/images/structure/fig5b_design_evolution.png' | relative_url }}" alt="Evolution to 7-link actuator assembly">
  <figcaption>Evolution from collapsed early prints to the 7-link actuator assembly with thickened PLA rings and 0.4 mm crease tuning.</figcaption>
</figure>

Early prototypes suffered from torsional shearing and off-axis buckling. To correct this, thickened PLA interlocking rings were integrated at every unit interface. These rings feature $45^\circ$ mating chamfers that register concentrically upon complete collapse, serving as positive structural stops that protect the elastomeric TPE membrane from over-compression.

### 4.3 Modular Twist-Lock End-Cap & Interface Design

To avoid permanent chemical bonding and ensure rapid maintenance in field service, a modular bayonet twist-lock end-cap system was engineered.

<figure>
  <img src="{{ '/images/structure/fig6_twist_lock_cad.png' | relative_url }}" alt="CAD explosion of modular twist-lock end cap">
  <figcaption>CAD explosion of the modular twist-lock end cap, showing dowel inserts, E-clip retention, and 1608 bearing integration.</figcaption>
</figure>

The end-cap mechanism incorporates several functional features:
1. **Bayonet Twist Detents:** Requires a $45^\circ$ rotation for full engagement, with an embossed tactile detent to confirm positive locking.
2. **Torsional Decoupling Bearing:** Houses a miniature stainless steel ball bearing (type 1608) secured via a precision ground shaft and E-clip. This allows the Kresling actuator to freely twist as it contracts without transmitting parasitic torque to the robot chassis.
3. **Integrated Pneumatic Interface:** A threaded M5 female port with an internal counterbore houses an elastomeric O-ring, providing leak-tight connection to standard $6\text{ mm}$ pneumatic tubing.

### 4.4 Multi-DOF Kinematic Configuration (Equilateral Arrangement)

Steerable locomotion in pitch and yaw requires multi-actuator coordination. SoftCrawl configures three identical Kresling actuators ($K_1, K_2, K_3$) arranged parallel to one another in an equilateral triangular formation.

<figure>
  <img src="{{ '/images/structure/fig7_continuum_kinematics.png' | relative_url }}" alt="Continuum kinematic model and 3D simulation">
  <figcaption>Continuum kinematic model and 3D simulation of SoftCrawl's multi-DOF bending (Webster & Jones, 2010).</figcaption>
</figure>

#### Why an Equilateral Triangle (3 Legs) vs. Square (4 Legs)?

Let $d$ represent the offset distance from the plate center to each actuator centerline. The transverse bending stiffness is governed by the second moment of area $\sum \text{arm}^2$:
* **For 3 Legs (Equilateral Triangle at 120°):** $\sum \text{arm}^2 = 0 + (d \sin 60^\circ)^2 + (d \sin 60^\circ)^2 = 1.5 d^2$ along any transverse axis. The bending stiffness is mathematically **ISOTROPIC** in all directions. There is no preferred weak axis.
* **For 4 Legs (Square at 90°):** $\sum \text{arm}^2 = 2.0 d^2$ (+33% stiffness). However, 4 legs create kinematic **OVER-CONSTRAINT** ($l_1 + l_3 = l_2 + l_4$). Any minor pressure discrepancy between actuators induces mechanical binding and parasitic strain. Furthermore, 4 legs require 4 independent valve channels and tether lines, adding 33% more umbilical weight.

<figure>
  <img src="{{ '/images/structure/fig8_equilateral_vs_square.png' | relative_url }}" alt="Stiffness derivation 3 legs vs 4 legs">
  <figcaption>Structural stiffness and neutral axis derivation: Equilateral 3-leg arrangement vs. 4-leg square configuration.</figcaption>
</figure>

* **Apex-Up Geometric Configuration:** The top apex actuator ($K_1$) is aligned vertically. To execute an upward pitch bend (required to climb over structural ribs), evacuating **ONLY $K_1$** generates a pure pitch moment $M = F \cdot d$ with a single valve operation. In contrast, an apex-down layout requires synchronizing two bottom valves at $0.5 d$ arm, doubling control complexity.

---

## 5. Additive Manufacturing & Fabrication Process

Fabrication of airtight, multi-material origami structures via Fused Deposition Modeling (FDM) required extensive empirical process tuning on a Bambu Lab X1-Carbon system:
* **Nozzle & Extrusion Temperature:** $0.4\text{ mm}$ hardened steel nozzle at $230^\circ\text{C}$ for TPE 83A and $215^\circ\text{C}$ for PLA. The elevated TPE temperature promotes cross-bead polymer fusion.
* **Flow Ratio & Over-Extrusion:** Set to **1.08** (8% intentional over-extrusion) to close microscopic inter-track voids that cause vacuum leakage.
* **Perimeter Walls:** Set to **3 solid perimeter loops** with aligned seam placement disabled (randomized seam distribution) to eliminate continuous linear leak pathways.
* **Print Speed:** Capped at $25\text{ mm/s}$ for all elastomeric sections, with retraction disabled to eliminate flexible filament binding within the extruder drive gears.

---

## 6. Experimental Testing & Characterization

A series of empirical validation tests were executed to characterize the mechanical performance of the manufactured Kresling actuators.

### 6.1 Contraction Stroke Under Zero Load

The nominal uncompressed length of the 7-cell actuator was measured at $185\text{ mm}$. Under an applied vacuum of $-70\text{ kPa}$, the actuator fully collapsed to $80\text{ mm}$.

<figure>
  <img src="{{ '/images/structure/fig9_contraction_stroke.png' | relative_url }}" alt="Actuator free contraction stroke measurement">
  <figcaption>Experimental measurement of actuator free contraction stroke: 185 mm nominal down to 80 mm collapsed.</figcaption>
</figure>

<div class="callout result">
<p><strong>Contraction Stroke Summary:</strong><br>
• Initial Length (L<sub>0</sub>) = 185.0 mm<br>
• Evacuated Length (L<sub>vac</sub> at -70 kPa) = 80.0 mm<br>
• Total Linear Stroke (&Delta;L) = 105.0 mm<br>
• <strong>Stroke Ratio = 56.76%</strong> (Contraction to 43.24% of original height)
</p>
</div>

### 6.2 Payload & Tensile Lifting Capacity Under Vacuum

To assess the actuator's capacity to pull the robot chassis and drag its umbilical tether, a dead-weight tensile test rig was established. The actuator was hung vertically and loaded with calibrated steel weights while vacuum was applied.

<figure>
  <img src="{{ '/images/structure/fig10_payload_capacity.png' | relative_url }}" alt="Tensile load lifting capacity test">
  <figcaption>Tensile load lifting capacity test: Successfully lifting and holding 3.3 kg+ under vacuum.</figcaption>
</figure>

The actuator successfully lifted and maintained a load of **$3.30\text{ kg}$ ($32.37\text{ N}$)** while retaining $>80\%$ of its full contraction stroke. Given that the total target mass of the SoftCrawl robot is $0.75\text{ kg}$ ($7.36\text{ N}$), a single Kresling actuator provides a **Safety Factor of $4.4\times$**, ensuring robust locomotion against friction and tether resistance.

### 6.3 Omnidirectional Bending Angle Characterization

The bending performance of the 3-actuator continuum body was measured using a precision goniometer rig with optical angle tracking. Actuator $K_1$ was evacuated while $K_2$ and $K_3$ remained vented to atmosphere.

<figure>
  <img src="{{ '/images/structure/fig11b_bending_72deg.png' | relative_url }}" alt="Bending deflection characterization">
  <figcaption>Bending deflection characterization, showing progressive curvature up to a maximum snap angle of 72.7 degrees.</figcaption>
</figure>

The measured deflection response demonstrated clear progressive bending:
* At $-30\text{ kPa}$ vacuum: Measured Bending Angle = $53.4^\circ$
* At $-50\text{ kPa}$ vacuum: Measured Bending Angle = $68.9^\circ$
* **At $-70\text{ kPa}$ vacuum: Maximum Measured Bending Angle = 72.7 DEGREES!**

At $-70\text{ kPa}$, geometric snap-through bistability occurred, locking the front plate into a $72.7^\circ$ tilt. This exceeds the minimum threshold required to initiate vertical climb transitions over 90-degree internal tank ribs.

### 6.4 Airtightness & Pressure Loss Rate

During static vacuum hold tests, an untreated 3D-printed TPE actuator exhibited an average leak decay rate of approximately $0.059\text{ kPa/ms}$ due to microscopic porosity between extruded beads.

---

## 7. Shortcomings, Engineering Fixes & Future Work

### 7.1 Inter-layer Porosity & Sealing Solution

* **Problem:** Inter-layer porosity in FDM elastomeric prints led to continuous vacuum decay, requiring high pump duty cycles.

<figure>
  <img src="{{ '/images/structure/fig12_sealing_solution.png' | relative_url }}" alt="Shortcoming analysis and engineering fixes">
  <figcaption>Shortcoming analysis and engineering fixes: Increasing perimeter walls to 3 and applying flexible polymer dip coating.</figcaption>
</figure>

* **Implemented Engineering Fix:** Two complementary solutions were executed. First, the perimeter wall count was increased from 2 to 3 in slicing. Second, a post-processing dip-coating of **Loctite flexible elastomeric fabric compound** was applied to the outer skin. The solvent evaporates to form a resilient, non-porous polymer membrane that **reduced pressure loss by >82%**, restoring vacuum holding stability.

### 7.2 Umbilical Line Drag & Tether Routing

* **Problem:** Individual pneumatic lines ($4\text{ mm}$ OD) trailed loosely behind the robot, creating parasitic drag and risking entanglement with sharp stringer cutouts inside the fuel tank.

<figure>
  <img src="{{ '/images/structure/fig12b_tubing_umbilical.png' | relative_url }}" alt="Tubing challenge and low-friction bundled umbilical sleeve">
  <figcaption>Tubing challenge and proposed low-friction bundled umbilical sleeve.</figcaption>
</figure>

* **Implemented Engineering Fix:** Developed a consolidated umbilical assembly where all pneumatic lines and data cables are encased within a low-friction expandable polyethylene terephthalate (PET) braided sheath, minimizing friction against aluminum tank floors.

### 7.3 Programmable Multistability via Rigid Facet Bonding (Semester 2 Priority)

* **Future Work:** Currently, holding bent postures requires continuous vacuum pressure. In Semester 2, selective rigid PLA plates will be bonded onto alternating triangular facets (Melancon et al., Adv. Funct. Mater. 2022). This will introduce programmable multistability, allowing the actuator to **passively lock into pre-set 90-degree bending states without consuming continuous pneumatic power**.

<figure>
  <img src="{{ '/images/structure/fig13_multistability.png' | relative_url }}" alt="Future implementation programmable multistability">
  <figcaption>Future implementation: Programmable multistability via rigid composite facet reinforcement.</figcaption>
</figure>

---

## 8. References

1. **Airbus.** (2024). *A350 aircraft characteristics: Airport and maintenance planning* (Revision 14, December 1, 2024). Airbus S.A.S.
2. **Baxter, J.** (2016). *Fuel Tank Entry* [Video]. YouTube.
3. **Fan, S., et al.** (2025). 3D-Printed Kresling-Origami Soft Actuators Facilitate Drag Reduction by Rotational Penetration for Burrowing. *Advanced Science*, e2408132.
4. **Federal Aviation Administration (FAA).** (2025). *Airworthiness Directives: Fuel Tank Lightning and Sealant Integrity* (AD 2025-20-05).
5. **Heilemann, F., Dadashi, A., & Wicke, K.** (2021). Eeloscope—Towards a novel endoscopic system enabling digital aircraft fuel tank maintenance. *Aerospace*, 8(5), Article 136.
6. **Hoque, M. A., Petersen, E., & Fang, X.** (2023). Effect of material properties on fiber-shaped pneumatic actuators performance. *Actuators*, 12(3), Article 129.
7. **Melancon, D., et al.** (2022). Inflatable Origami: Multimodal Deformation via Multistability. *Advanced Functional Materials*, 32(28), 2201891.
8. **Polimeno, U., & Meo, M.** (2009). Detecting damage in composite aircraft structures. *Composite Structures*, 91(4), 502–508.
9. **Ricárdez Ortigosa, A., et al.** (2025). Bio-inspired swimming probes for confined fluid environments. *Aerospace*, 12(2), Article 156.
10. **Wang, C., et al.** (2024). Modular origami soft robots: Design, kinematics, and actuation. *Sensors*, 24(5), Article 1420.
11. **Webster, R. J., & Jones, B. A.** (2010). Design and kinematic modeling of constant curvature continuum robots: A review. *The International Journal of Robotics Research*, 29(13), 1661–1683.
12. **Wickeler, M., et al.** (2023). Mechanical performance and bistability of 3D-printed origami bellows. *Journal of Intelligent Material Systems and Structures*, 34(12), 1410–1422.
