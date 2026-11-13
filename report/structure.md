---
layout: report
title: Robot Body
group: Interim
code: SEC-02
nav_order: 2
permalink: /report/old_structure/
---

The Robot Body is the soft actuated spine of SoftCrawl. It contracts and bends so that the legs can step, climb vertical walls and turn 90 degree corners inside the wing tank.

<div class="stat-row"> <div class="stat"><span class="value">43.2%</span><span class="label">Contraction</span></div> <div class="stat"><span class="value">&gt;3.3 kg</span><span class="label">Load held</span></div> <div class="stat"><span class="value">72.7°</span><span class="label">Best bend</span></div> <div class="stat"><span class="value">506 g</span><span class="label">Body mass</span></div> </div>
2.1 Subsystem Requirements

The objective is a soft, spark-free body that fits through standard access panels and can contract and bend to move the robot. The scope covers the actuated spine, its end plates, and the leg mounts. To ensure fuel tank safety, the body contains zero internal electronics and is powered via external pneumatic lines.

To translate these operational goals into actionable engineering constraints, the overall mission requirements were flowed down into four core mechanical specifications, detailed in Table 1.

| Category | Requirement |
|---|---|
| **Geometry** | Fit within a 300 × 200 mm access opening |
| | Actuator never expands beyond the body, avoiding snags |
| **Electronics** | No electronics in the tank except camera and light |
| **Adhesion** | Actuate with a 0.75 kg robot mass with safety factor 2 on oily vertical surfaces |
| | Adhesion on thin oil film over aluminium sheet |
| **Locomotion** | Control each leg individually |
| | Climb 90 degree corners |
| | Pass through 30 cm × 30 cm access hole to next fuel tank chamber |
| **Material compatibility** | No damage to fuel tank internal surfaces |
| | No swelling/damage due to prolonged oil exposure |

*Table 1. Robot body requirements*
{: style="text-align: center;"}


2.2 Concept Generation
2.2.1 Morphological Matrix

Based on the subsystem requirements, we listed the functions the body needs to fulfil, ranked in order of importance, and explored different solution principles for each in the form of a morphological chart. The actuation mechanism had not been decided at this stage, so the chart first lists the mechanisms. If origami is chosen, a second decision follows on which fold pattern to use, so the pattern options are nested under it as row 1a.

Rank	Function	Principle 1	Principle 2	Principle 3
1	Contract the body	Pneumatic artificial muscle	Bellows actuator	Origami actuator
1a	Fold pattern (only if origami is chosen)	Accordion	Yoshimura	Kresling
2	Bend in any direction	Two actuators	Three actuators (triangle)	Four actuators (rectangle)

Table 2. Morphological matrix for the Robot Body. {: .caption}

The actuation mechanism is selected in Section 2.3, with the origami pattern as a follow-on decision in Section 2.3.1. The number and layout of actuators follow from the bending model in Section 2.4.

2.3 Actuation Mechanism Selection

The body must contract and bend the robot using only air supplied from outside the tank. Three pneumatic actuation approaches were considered (Hoque et al., 2023; Wang et al., 2024).

Mechanism	Advantage	Limitation for SoftCrawl
Pneumatic artificial muscle (a)	High tensile force-to-weight ratio	Balloons radially, so it expands beyond the body bounding area and needs a high operating pressure
Bellows actuator (b)	Well established in industry and works at low pressure	Poor lateral stiffness and prone to buckling or ballooning
Origami actuator (c)	Low pressure, zero radial ballooning and low material use	Strength and stiffness depend on the fold pattern chosen; prone to air leakage

Table 3. Pneumatic actuation mechanisms considered. {: .caption}

<figure>
  <div class="figure-row">
    <img src="{{ '/images/body/image1.png' | relative_url }}">
    <img src="{{ '/images/body/image2.png' | relative_url }}">
    <img src="{{ '/images/body/image3.png' | relative_url }}">
  </div>
  <figcaption>Figure 1. Pneumatic actuation options considered for the Robot Body: (a) artificial muscle, (b) bellows, (c) origami</figcaption>
</figure>

Origami actuators were selected. The first requirement is that the actuator never expands beyond the body, which rules out artificial muscles and bellows because both balloon. An origami actuator also works at low pressure, which suits long air lines from outside the tank, and uses little material.

However, origami is a family of fold patterns, and each behaves differently under load. The next question is therefore which pattern to use.

2.3.1 Origami Pattern Selection

Three origami patterns are commonly used for tubular actuators: Accordion, Yoshimura and Kresling (Wickeler et al., 2023; Melancon et al., 2022). They were compared on load capacity, stability and speed.

Criterion	Accordion	Yoshimura	Kresling
Load capacity and deformation mode	Lowest load capacity	Highest peak load, but fails by buckling	High load capacity and controlled crease folding
Stability	Monostable	Monostable	Tunable multistability
Speed and energy release	Slow	Slow	Fast, rapid snap rebound

Table 4. Comparison of origami patterns. {: .caption}

<figure> <div class="figure-row"> <div class="img-placeholder">(a) Origami patterns</div> <div class="img-placeholder">(b) Crease folding patterns</div> </div> <div class="img-placeholder">(c) Force against deformation and compression sequence</div> <figcaption>Figure 2. Accordion, Yoshimura and Kresling origami patterns: (a) patterns, (b) crease folding, (c) force against deformation (adapted from Wickeler et al., 2023).</figcaption> </figure>

Compression testing by Wickeler et al. (2023) highlights why the Kresling pattern was selected. While the Accordion tube folds smoothly, its load capacity is lowest. Conversely, while the Yoshimura tube reaches a high initial peak, it immediately fails via catastrophic, uncontrollable wall buckling (marked in red). The Kresling pattern provides the ideal balance: it delivers nearly three times the load capacity of the Accordion while maintaining controlled, repeatable crease folding without the abrupt buckling seen in the Yoshimura.

Additionally, Kresling is a non-rigid origami pattern, so its facets also deform elastically as it folds. This elastic deformation stores strain energy, and releasing it gives the rapid snap rebound. Because the folding stays controlled along the creases, Kresling avoids the buckling seen in Yoshimura.

Finally, Kresling also has the feature of tunable multistability, where its geometry can be adjusted, or rigid plates bonded to selected facets, to create multiple stable states between the fully extended and fully contracted positions (Melancon et al., 2022). This could potentially be used to hold pre-set bend angles without continuous pressure.

<figure> <div class="img-placeholder">Tunable multistability of Kresling</div> <figcaption>Figure 3. Tunable multistability of the Kresling pattern (Melancon et al., 2022).</figcaption> </figure>
2.4 Design Principles
2.4.1 Bending Model

A single Kresling only contracts, so bending needs several actuators working together. The model follows the constant-curvature approach of Webster and Jones (2010), checked experimentally for multi-chamber soft arms by Santoso and Onal (2017). For two actuators offset by $$d$$ from the centreline of length $$L$$, the two lengths and the plate angle $$\theta$$ are related by:

$$l_1 = L - d\theta, \qquad l_2 = L + d\theta, \qquad \theta = \frac{l_2 - l_1}{2d}$$

A wider spacing $$d$$ therefore gives less bend for the same length difference. For $$n$$ identical actuators of axial stiffness $$k$$, turning the front plate by $$\alpha$$ stretches or squashes each actuator by (arm × $$\alpha$$), where arm is its distance to the neutral axis. Summing the moments is the same idea as the second moment of area in beam theory:

$$K_{bend} = \frac{M}{\alpha} = k \sum \text{arm}^2 = \frac{n\,k\,d^2}{2}$$

The model assumes identical actuators, small turns and axial loads only.

2.4.2 Number and Layout of Actuators

Two actuators give two degrees of freedom: one contraction and one bend in a single plane. Three actuators at 120 degrees bend in any direction. A fourth actuator was also considered.

Criterion	Triangle (3 actuators)	Rectangle (4 actuators)
Bending stiffness	1.5 k d²	2 k d² (33% higher)
Load capacity	Baseline	33% higher
Valves and tubes	3	4; pump flow requirement uncertain
Weight and footprint	Lighter, smaller	Heavier, larger
Control	Independent	Coupled; over-constrained (l₁ + l₃ = l₂ + l₄)
Redundancy	None	Yes

Table 5. Three-actuator against four-actuator layout. {: .caption}

The triangle was selected because three actuators are the minimum for full 3D bending, it needs fewer valves and tubes, and it keeps control of each actuator independent. The rectangle is stiffer and has redundancy, but its control is coupled and over-constrained.

An equilateral triangle was preferred over an isosceles one. It has the same bending stiffness (1.5 k d²) in every direction. An isosceles layout is stiff in one direction (2.3 k d²) but three times weaker in the other (0.5 k d²), and its load centre sits 0.24 d off the plate centre, so it droops under a nose load. Mounting the triangle apex up or apex down gives the same bending moment, so this is a packaging decision: apex up needs one valve to bend upward, while apex down shares a nose load between two actuators.

<figure> <div class="img-placeholder">End views of two- and three-actuator layouts (l₁, l₂, d, θ, 120° spacing) and equilateral vs isosceles — slides 54, 55, 176, 177</div> <figcaption>Figure 4. Two-actuator and three-actuator layouts and their stiffness.</figcaption> </figure>
2.4.3 Simulation

The layout was also checked in the team's SoftCrawl 3D simulator, which implements the Webster and Jones model. Its purpose was to see how leg spacing affects the bend angle before printing. It confirmed that a wider spacing gives a smaller bend for the same length difference.

<figure> <div class="img-placeholder">Simulator output: bend angle against leg spacing — slides 56–58, add axis labels and units</div> <figcaption>Figure 5. Simulated bend angle against leg spacing.</figcaption> </figure>

{% comment %} Older draft paragraph — the same content now lives in 2.5.2 and 2.5.3. Kept here, hidden, in case you want any of it back.

The actuator is printed in place as a series stack on a Bambu Lab printer. Flexible TPE 83A forms the folding walls, and rigid PLA rings keep each unit's shape. Wall stiffness was controlled through plate flexural rigidity, D = E t³ / 12(1 − ν²). Because D scales with t³, doubling the wall thickness makes it eight times stiffer. A wall that is too thin folds easily but cannot spring back, while one that is too thick holds its shape but will not fold. [Add: printer model, nozzle size, layer height, print speed, TPE 83A filament brand and print time per link.] Print quality was poor in the first stacks and was improved by tuning the printing parameters. [Add: which parameters were changed and what defects were seen.] Each actuator ends in a twist-lock end cap ... The completed robot measures about 270 × 185 × 170 mm and has a mass of about 506 g. {% endcomment %}

2.5 Geometric, Material and Assembly Design
2.5.1 Unit Cell Geometric Parameterization and Kinematic Optimization

The baseline Kresling unit cell geometry was parameterized following the kinematic framework established by Fan et al. (2025), using a 6-sided regular polygonal base ($$N = 6$$). The design parameters were derived from a geometric optimization study aimed at balancing structural stiffness, axial contraction stroke, and aircraft fuel tank packaging constraints.

A critical finding in Kresling mechanics is that structural stiffness decreases as the number of polygon sides increases; across all materials, a 6-sided hexagonal configuration is significantly stiffer than an 8-sided octagonal one. Selecting a hexagonal configuration ($$N = 6$$) reduces actuation resistance, allowing the structure to fold smoothly at our nominal −60 kPa supply. <span class="todo">[Check: if N = 6 is stiffer than N = 8, it should raise actuation resistance, not reduce it.]</span>

Coupled with an optimized circumscribed radius of $$r = 15$$ mm and facet angle of $$\alpha = 30^\circ$$, this geometry ensures the 3-actuator body clears the 300 × 200 mm access panel with zero radial expansion while maximizing stroke efficiency.

<figure> <div class="img-placeholder">Kresling unit geometry and parameters (N, r, α)</div> <figcaption>Figure 6. Kresling unit geometry and parameters.</figcaption> </figure>
2.5.2 Mechanical Design: From Unit Cell to Multi-Link Series Actuator

While a single Kresling unit cell establishes the core folding kinematics, an individual cell provides insufficient stroke to propel a crawling robot. To transform the unit cell into a practical, high-displacement pneumatic actuator, four primary mechanical design features were integrated.

1. Series stacking for stroke multiplication

To achieve the large linear displacement required for peristaltic locomotion, individual Kresling units are stacked in series along a continuous central axis. Stacking multiplies the net contraction displacement proportionally:

$$\Delta h_{stack} = n \, \Delta h_{unit}$$

Scaling the initial 5-link configuration to the final 7-link architecture increased the uncompressed actuator height to 185 mm, providing an unconstrained axial stroke exceeding 80 mm (43.24% contraction). <span class="todo">[Check: Section 2.7.1 gives 185 → 80 mm, i.e. a 105 mm stroke (56.8%); 80 mm / 43.2% is the contracted length.]</span> This increased stroke length provides the necessary clearance for the robot's feet to advance during crawling and facilitates transitions when climbing obstacles.

2. Embedded rigid PLA boundary rings

In theoretical origami structures, fold lines rotate around an idealised, undeformable polygonal boundary. However, if the actuator were fabricated entirely from a soft elastomer, the stresses generated under vacuum loading could cause the unit-cell boundaries to deform radially inward. Such deformation would compromise the intended crease geometry and potentially induce premature radial collapse.

To prevent this failure mode, rigid PLA reinforcement rings were embedded at every unit-cell boundary. By constraining radial deformation, the reinforcement rings promote the intended kinematic folding of the triangular facets rather than uncontrolled radial constriction.

3. Compliant flexure hinges via 0.4 mm facet offset

The mechanical folding behaviour is governed by plate flexural rigidity:

$$D = \frac{E\,t^3}{12(1 - \nu^2)}$$

where $$E$$ is Young's modulus, $$t$$ is section thickness, and $$\nu$$ is Poisson's ratio. Because rigidity scales cubically with thickness ($$D \propto t^3$$), doubling the wall thickness increases stiffness eightfold ($$2^3 = 8$$).

This cubic sensitivity was exploited to solve the chaotic buckling observed in early prototypes. In CAD, the triangular facet bodies were thickened and offset outward by 0.4 mm relative to the crease lines. This thickness gradient creates natural compliant flexure hinges: the thinned crease lines act as low-resistance hinges, while the thicker facet plates remain planar, forcing the actuator to fold cleanly and predictably along its intended origami lines without out-of-plane panel wrinkling.

4. Self-supporting overhang geometry (print-in-place)

To function as a vacuum actuator, the multi-unit stack must form a continuous, enclosed pneumatic chamber. Conventional multi-piece assemblies require glued seams or mechanical fasteners that introduce leakage paths and stress concentrations.

To overcome this, the Kresling facets and hinge angles were engineered with a strict <span class="todo">[Add: angle]</span> overhang threshold. This geometric constraint allows the entire 7-link multi-material stack (flexible TPE facets, embedded rigid PLA rings and compliant flexure hinges) to be fabricated monolithically in a single print-in-place operation, eliminating internal support material and post-assembly joint seams.

The actuator is manufactured as a single series stack via dual-material Fused Deposition Modelling (FDM) on a Bambu Lab X1-Carbon 3D printer. Flexible eSUN TPE 83A forms the morphing facet walls, while rigid PLA rings printed at each link interface preserve the polygon's radial boundary.

2.5.3 Modular Twist-Lock Assembly and Rotational Decoupling

Because Kresling contraction inherently couples axial displacement (h) with rotational twist (ϕ), rigidly affixing the actuator to the chassis would transmit parasitic torsional moments, twisting the robot's feet off the tank surface.

To isolate axial force from rotational twist, each actuator terminates in a specialised twist-lock end-cap assembly (Figure 7):

Twist-lock flange and rail interface: enables modular replacement of individual Kresling stacks in under 30 seconds without disassembling the chassis. Integrated retention rails ensure the actuator cannot unseat or blow out under pressure.
Rotational decoupling (1608 miniature ball bearing): a deep-groove 1608 radial ball bearing is seated directly into the cap via a dedicated insertion slot, allowing the Kresling stack to rotate freely through its full ϕ twist angle while transmitting 100% of its axial contraction force directly to the chassis frame.
Shaft, E-clip and tactile detent: a ground central steel shaft is axially locked via a precision E-clip notch, while an integrated mechanical detent bump provides positive tactile feedback when the twist-lock engages.
Pneumatic manifold: an integrated compliant dowel insert and M5 to 6 mm push-in fitting provide an airtight fluidic seal directly to the actuator's internal vacuum core.

Three actuators are mounted in parallel between a rigid back plate and a modular front plate in the 120° equilateral triangle layout. The completed robot body measures 270 × 185 × 170 mm with an all-up dry mass of 506 g, fully compliant with aircraft ingress and payload requirements.

<figure> <div class="img-placeholder">Exploded view: twist-lock end cap, bearing, shaft, E-clip, dowel + assembled three-actuator body — slides 52, 143, 173, label each part</div> <figcaption>Figure 7. Twist-lock end cap and three-actuator body assembly.</figcaption> </figure>
2.6 Prototype Development (V1–V3)
<figure> <div class="img-placeholder">Print iterations: V1 collapsed stack and current stack with thickened PLA rings and 0.4 mm facets — slides 45–47, add a scale bar</div> <figcaption>Figure 8. Kresling actuator prototypes V1–V3.</figcaption> </figure>
V1 used the initial 0.8 mm geometry. The stack collapsed, had no guiding fold lines and printed poorly.
V2 thickened the PLA rings and scaled the stack to seven links to keep each unit's shape and guide the folds. <span class="todo">[Add what V2 showed.]</span>
V3 tuned the printing parameters and added 0.4 mm facet thickening. It is the version used for all tests in Section 2.7.
2.7 Experimental Evaluation

Three tests checked the V3 body against its specifications: contraction under no load, contraction under load and bending angle.

Test	Purpose	Specification tested
Contraction under no load	Measure the stroke available to the legs	Locomotion; geometry
Contraction under load	Confirm the body carries the robot with margin	0.75 kg with safety factor 2
Bending angle	Measure how far the body can turn	Climb 90 degree corners

Table 6. Tests performed on the V3 body. {: .caption}

2.7.1 Contraction Under No Load

The actuator was driven with no load and its length was measured before and after. It contracted from 185 mm to 80 mm, a reduction of 56.8%, so the contracted length is 43.2% of the original. <span class="todo">[Add: whether vacuum or positive pressure was used, the pressure applied, how length was measured and the number of trials.]</span>

<figure> <div class="img-placeholder">Unloaded actuator, relaxed (185 mm) and contracted (80 mm), ruler visible — slides 60, 61</div> <figcaption>Figure 9. Unloaded contraction of the V3 actuator.</figcaption> </figure>
2.7.2 Contraction Under Load

A load was attached to check that the actuator still contracts while carrying weight. It lifted and held more than 3.3 kg while still reaching near its maximum contraction. <span class="todo">[Add: how the load was applied, pressure used and number of trials.]</span>

<figure> <div class="img-placeholder">Actuator holding more than 3.3 kg while contracted — slides 62–64, 183</div> <figcaption>Figure 10. Contraction under load.</figcaption> </figure>
2.7.3 Bending Angle

The actuator was held in place with two G-clamps and an angle sheet was placed underneath it. A phone on a stand filmed each bend from a fixed position so that every trial used the same view, and a pressure regulator controlled the pressure. The best bend reached 72.7 degrees, with the actuator snapping during bending. Other measurements were 68.9 and 53.4 degrees. <span class="todo">[State the condition behind each angle and how many trials were run.]</span>

<figure> <div class="img-placeholder">Bending rig: G-clamps, angle sheet, phone on stand, pressure regulator — slide 65, annotate each item</div> <figcaption>Figure 11. Bending test setup.</figcaption> </figure> <figure> <div class="figure-row"> <div class="img-placeholder">72.7°</div> <div class="img-placeholder">68.9°</div> <div class="img-placeholder">53.4°</div> </div> <figcaption>Figure 12. Measured bend angles against the angle sheet (slides 66, 67, 185).</figcaption> </figure>
Measure	Result	Requirement
Length, relaxed to contracted	185 mm to 80 mm (56.8% shorter)	Not specified
Load held near full contraction	More than 3.3 kg	1.5 kg (0.75 kg × 2)
Best bend angle	72.7 degrees	90 degrees

Table 7. Summary of test results against requirements. {: .caption}

2.7.4 Analysis of Results

Contraction. The 105 mm stroke is large because a Kresling unit folds and twists along its creases rather than stretching its walls. It gives the legs room to step, and it also limits bending, as shown below.

Load capacity. The design load is 0.75 kg × 2 = 1.5 kg. The actuator held more than 3.3 kg, more than 2.2 times the design load, so the body is unlikely to be the limiting part of the load path. The suction legs are, with vertical failure loads of 10 N to 40 N.

Bending angle. The best bend of 72.7 degrees is 81% of the 90 degree requirement. For the three-actuator layout, the maximum angle is limited by the stroke $$S$$ of one actuator:

$$\theta_{max} \approx \frac{S}{1.5\,d} \quad\Rightarrow\quad d \le \frac{S}{1.5 \times (\pi/2)} = \frac{105}{2.36} \approx 44\ \text{mm for } 90^\circ$$

So with a 105 mm stroke, the actuators must sit within about 44 mm of the plate centre to reach 90 degrees in the ideal case. A smaller $$d$$ also lowers bending stiffness (1.5 k d²), so $$d$$ and stiffness must be balanced. <span class="todo">[Check against the actual d in the CAD model.]</span> The snapping at 72.7 degrees is the Kresling unit jumping between its two stable states. It gives a fast, large bend but makes intermediate angles hard to hold.

<figure> <div class="img-placeholder">Plot: maximum bend angle against leg offset d for S = 105 mm, with 90° requirement and measured 72.7° marked — to be made</div> <figcaption>Figure 13. Maximum bend angle against leg offset.</figcaption> </figure> <div class="callout warning"> <p><strong>Validity.</strong> The results come from one prototype and are measured by hand and by video. They show that the concept works but do not yet give repeatable numbers. The next phase needs repeated trials with a mean and spread, the pressure at each data point, a comparison of measured bend against the model, and an estimate of the angle reading error.</p> </div>
2.8 Limitations and Proposed Improvements

Testing exposed four limitations of the current body:

Air leakage: the printed actuator loses pressure quickly.
Tubing: air lines can snag on the tank ribs and add drag.
Bend below the requirement: the best bend is 72.7 degrees against 90 degrees, and snapping makes intermediate angles hard to hold.
Oil compatibility untested: the printed parts have not yet been soaked in oil.
2.8.1 Airtight Sealing

The printed actuator loses pressure at roughly 0.059 kPa per millisecond, or about 59 kPa per second. A pressurised actuator therefore cannot hold its shape for long without the pump or valves topping it up, which makes control harder. The loss is believed to come through the thin printed walls and layer boundaries. <span class="todo">[Confirm the leak path.]</span>

<figure> <div class="img-placeholder">Pressure decay of a pressurised actuator — slide 68, add axes with units</div> <figcaption>Figure 14. Pressure loss of the V3 actuator.</figcaption> </figure>

The proposed improvement is to coat the actuator with a flexible polymer, such as Loctite fabric adhesive or a flexible epoxy resin, and to increase the number of printed walls from two to three. Success will be judged by repeating the pressure-loss measurement on the coated actuator against a target agreed with the controls team. <span class="todo">[Set target.]</span>

2.8.2 Tubing

The air and data lines can snag on the internal tank ribs, and heavy tubing adds resistive force that the body and legs must overcome.

<figure> <div class="img-placeholder">Tubing routed alongside the robot — slide 70</div> <figcaption>Figure 15. Tubing running alongside the robot.</figcaption> </figure>

The proposed improvement is to bundle all lines into a single low-friction umbilical sleeve that prevents snagging. It will be tested by crossing a rib mock-up while towing the umbilical. <span class="todo">[Define mock-up.]</span>

2.8.3 Bend Angle and Programmable Multistability

The best bend of 72.7 degrees is below the 90 degree requirement. The actuators are monostable, so they snap between two states and cannot hold intermediate bend angles without continuous pressure.

<figure> <div class="img-placeholder">Multistability by selectively bonding rigid facets (Melancon et al., 2022) — slides 71, 187</div> <figcaption>Figure 16. Programmable multistability using rigid facets (Melancon et al., 2022).</figcaption> </figure>

The proposed improvement has two parts. First, tune the leg offset $$d$$ against the stroke (Section 2.7.4). Second, bond rigid PLA plates onto selected triangular facets to create intermediate stable states, so that the actuator can lock into pre-set bend angles for cornering and rib climbing without continuous pressure (Melancon et al., 2022). The target is a repeatable bend of 90 degrees or more.

2.8.4 Oil Compatibility

The specification requires no swelling or damage from prolonged oil exposure, but the printed TPE and PLA parts have not yet been soaked in oil. The proposed test is to soak printed samples in the tank oil and compare their dimensions and contraction stroke before and after. <span class="todo">[Set soak duration.]</span> If the TPE swells, the alternative is to coat or replace the flexible material.

2.9 Interim Outcomes

The Robot Body subsystem has progressed from concept evaluation to laboratory-level prototype testing. The principal outcomes include:

Selection of an origami actuator over artificial muscles and bellows, and of the Kresling pattern over Accordion and Yoshimura.
Selection of a three-actuator equilateral layout over a four-actuator layout, supported by a bending and stiffness model and a simulator check.
A printed TPE and PLA Kresling stack with modular twist-lock end caps, developed over three versions.
Measured contraction of 56.8% (185 mm to 80 mm), a load capacity above 3.3 kg and a bend of up to 72.7 degrees.
Identification of air leakage, tubing, a bend below 90 degrees and untested oil compatibility as the limitations to resolve.
<div class="callout result"> <p>The findings demonstrate the feasibility of the body concept and show that it meets the contraction and load specifications with margin. The next development phase will focus on sealing, repeatable bend angles through leg-offset tuning and programmable multistability, and integrating the body with the suction legs and SoftCrawl's pneumatic control system.</p> </div>
References
Fan et al. (2025). Advanced Science. Kresling geometry. <span class="todo">[Add full citation.]</span>
Hoque, M. A., Petersen, E., and Fang, X. (2023). Effect of material properties on fiber-shaped pneumatic actuators performance. Actuators, 12(3), 129.
Melancon, D. et al. (2022). Inflatable origami: multimodal deformation via multistability. Advanced Functional Materials.
Santoso, J. and Onal, C. (2017). IROS. <span class="todo">[Add full citation.]</span>
Wang et al. (2024). Sensors. Bellows deflection. <span class="todo">[Add full citation.]</span>
Webster, R. J. and Jones, B. A. (2010). International Journal of Robotics Research, 29(13).
Wickeler, A. L., McLellan, K., Sun, Y.-C., and Naguib, H. E. (2023). 4D printed origami-inspired accordion, Kresling and Yoshimura tubes. Journal of Intelligent Material Systems and Structures.