---
layout: report
title: Robot Legs
group: Interim
code: SEC-03
nav_order: 3
permalink: /report/perception/
---

The Robot Legs provide SoftCrawl's grip. They anchor the robot to oily aluminium surfaces so the Kresling body can push it forward, up walls and around 90 degree corners.

<div class="stat-row"> <div class="stat"><span class="value">40 N</span><span class="label">Vertical hold, 4 cups</span></div> <div class="stat"><span class="value">−60%</span><span class="label">Shear loss with oil</span></div> <div class="stat"><span class="value">17.2 N</span><span class="label">2-cup oily shear</span></div> <div class="stat"><span class="value">Ø40 mm</span><span class="label">Festo PU cup</span></div> </div>
2. Locomotion Requirements and Concept Selection
2.1 Required Locomotion Modes

Aircraft fuel-tank inspection requires the robot to navigate internal surfaces with varying orientations and structural obstacles. Soft robots can move in different ways, but two locomotion modes are particularly relevant to our use case:

Crawling: movement along the horizontal surfaces of the tank.
Climbing: movement along vertical or inclined surfaces, enabling access to walls and other elevated inspection regions.

The robot must also be able to move between the different chambers of the fuel tank by climbing a 90 degree corner onto the walls and passing through the openings. These requirements create two coupled design challenges: generating controlled body movement, and maintaining reliable surface attachment on oily surfaces throughout the locomotion sequence.

2.2 Evaluation of Adhesion Mechanisms

Our climbing and crawling soft robot achieves movement through the deformation of the compliant Kresling actuator, so the main focus for the robot legs is the gripping mechanism itself. Depending on the design, locomotion may be produced through pneumatic actuation, tendon-driven mechanisms, shape-memory materials, electroactive actuators or other deformation-based methods. The adhesion mechanism must anchor the robot to the surface and support its weight and any additional payload, grip on oily surfaces, and not damage the robot itself.

Four principal adhesion approaches were considered.

Mechanism	Advantage	Limitation for SoftCrawl
Magnetic adhesion	Strong, controllable attachment on ferromagnetic surfaces	Ineffective on non-ferromagnetic aluminium structures
Electroadhesion	Electrically controllable adhesion and proprioceptive	Requires high-voltage circuitry; electrical safety and contamination sensitivity are concerns
Gecko-inspired dry adhesion	Lightweight, potentially passive attachment that exploits van der Waals forces	Difficult to control; prone to wear and tear
Vacuum suction	Industry standard, high axial payload capacity, controllable attachment	Requires reliable sealing; vulnerable to leakage, oil-related shear reduction and moment-induced peeling

Table 1. Adhesion mechanisms considered. {: .caption}

Vacuum suction was selected as the primary adhesion mechanism for SoftCrawl because it provides controllable attachment to suitable non-ferromagnetic surfaces, including smooth aluminium and acrylic. It avoids the high-voltage actuation associated with electroadhesion. Gecko-inspired dry adhesion was considered but presents challenges related to effective control and durability.

However, vacuum suction remains sensitive to leakage and eccentric loading, which calls for experimental investigation of sealing, shear resistance and peeling under representative operating conditions. This led to the investigation of two ideas for the subsystem.

3. Robot Legs: Adhesion Subsystem
3.1 Subsystem Requirements

Based on the overall system requirements for the robot, the key functional specifications of the robot legs subsystem are listed in Table 2.

Rank	Constraint	Specification
1	Geometry	Fit within the 30 cm × 20 cm access panel
2	Adhesion	Support the 0.75 kg robot mass with a safety factor of 2 on a vertical surface
Adhere on a thin oil film over aluminium sheet
3	Locomotion	Control each leg individually
Climb 90 degree corners
4	Material	No damage to fuel tank internal surfaces
No swelling or damage due to prolonged oil exposure

Table 2. Robot Legs requirements. {: .caption}

3.2 Morphological Matrix

Based on the subsystem requirements and the adhesion mechanism selected, we listed the specific functions the robot legs need to fulfil, ranked in order of importance, and explored different solution principles for each in the form of a morphological chart.

Rank	Function	Principle 1	Principle 2	Principle 3
1	Maintain surface adhesion	Passive suction cups	Active suction cups	Mechanically actuated suction cups
2	Seal on oily surface	Bellows suction cup	Deep concave suction cup	Flat suction cup
3	Resist oil exposure	Nitrile butadiene rubber	Fluorosilicone and Viton	Polyurethane
4	Release cup on command	Solenoid valve	Manual valve	Plunging skeleton
5	Protect vacuum line from oil ingestion	Liquid oil separator	Oil coalescing filter	Vacuum filter

Table 3. Morphological matrix for the Robot Legs. {: .caption}

Two ideas were taken forward from the matrix:

Function	Idea 1: Passive suction (Section 3.3)	Idea 2: Active vacuum (Sections 3.4–3.12)
Maintain surface adhesion	Passive suction cups	Active suction cups
Seal on oily surface	Bellows suction cup	Flat suction cup
Resist oil exposure	Fluorosilicone	Polyurethane
Release cup on command	Plunging skeleton	Solenoid valve
Protect vacuum line from oil ingestion	Not needed (no vacuum line)	Vacuum filter

Table 4. The two concepts selected from the morphological matrix. {: .caption}

3.3 Passive Suction-Cup Development
3.3.1 Literature Review and Selection of Passive Suction

Idea 1 combined a passive bellows cup, a fluorosilicone final material and a plunging-skeleton release mechanism. This section documents the development and evaluation of that concept.

Passive suction has an established track record in small climbing robots. Kawasaki and Kikuchi (2014) demonstrated a 34 g hexapod that climbed walls on passive cups, attaching by pushing and releasing by pulling a string that peeled the cup edge. Wang et al. (2020) showed that suction-based adhesion continues to hold on wet surfaces where gecko-style dry adhesives lose grip, which is directly relevant to a tank coated with residual fuel film. Most recently, He et al. (2026) used internal ribs to achieve mechanically programmable, controllable passive suction, enabling the ORACLE robot to climb walls and ceilings.

<figure> <div class="figure-row"> <div class="img-placeholder">(a) Kawasaki and Kikuchi (2014)</div> <div class="img-placeholder">(b) Wang et al. (2020)</div> <div class="img-placeholder">(c) He et al. (2026)</div> </div> <figcaption>Figure 1. Development of passive suction-cup climbing robots: (a) Kawasaki and Kikuchi (2014), (b) Wang et al. (2020), (c) He et al. (2026).</figcaption> </figure>

Compared with active vacuum, a passive cup draws zero power once sealed, needs only the cup and a mechanical trigger rather than a pump, valves, air lines and filters, carries no risk of drawing fuel into a vacuum line, and avoids the weight and drag of on-robot air lines.

3.3.2 Design Principles and Success Criteria

The cup operates on Boyle's law. Pressing the cup expels air ($$V_1 \approx 0$$, $$P_1 = P_{atm}$$). When released, the walls spring back and the enclosed volume grows to $$V_2$$, so $$P_2 < P_{atm}$$. The resulting holding force is:

$$F = P_{atm}\left(1 - \frac{V_1}{V_2}\right) A$$
<figure> <div class="img-placeholder">Passive cup operating principle: press, release, hold</div> <figcaption>Figure 2. Operating principle of a passive suction cup: press, release and hold.</figcaption> </figure>

The design therefore requires a cup that collapses almost completely (small $$V_1$$), recovers strongly (large $$V_2$$) and has a large sealed area $$A$$.

On a vertical wall, the foot must satisfy two conditions. Slip is resisted by friction, requiring $$W \le \mu N$$. Peel is the more critical mode: the robot's weight $$W$$ acting at an offset $$d$$ creates a moment $$M = W d$$ that lifts the top edge of the cup first, so the cup must satisfy:

$$W d \le N r$$

where $$r$$ is the seal radius.

<figure> <div class="img-placeholder">Free-body diagram of a suction foot on a vertical wall: peel and slip</div> <figcaption>Figure 3. Forces on a suction foot on a vertical wall, showing the peel and slip conditions.</figcaption> </figure>

Wall stiffness was controlled through plate flexural rigidity:

$$D = \frac{E\,t^3}{12(1 - \nu^2)}$$

Because $$D$$ scales with $$t^3$$, doubling the wall thickness makes it eight times stiffer. A wall that is too thin folds easily but cannot spring back, while one that is too thick holds its shape but will not fold flat.

<figure> <div class="img-placeholder">Flexural rigidity and where a thin wall folds</div> <figcaption>Figure 4. Plate flexural rigidity and its effect on where a thin wall folds.</figcaption> </figure>
3.3.3 Geometric and Material Design

The final passive cup (V3) was built around four geometric parameters, summarised in Table 5.

Parameter	Value	Rationale
Seal bore	Ø46 mm	Peel resistance scales with r; limited by end-plate size and flat area in the tank
Lip	7 mm wide, 3 mm thick	Longer leakage path and more shear friction; 27× stiffer than the wall, so it stays flat and resists peel
Folds	2	One fold gives too little springback; three or more increase height and therefore d in M = W·d; the upper fold nests inside the lower for V₁ ≈ 0
Wall and hinges	1.0 mm panels, 0.55 mm hinges	Hinges are about 6× softer (t³), so the cup folds only at the hinge lines

Table 5. V3 passive cup geometry. {: .caption}

Prototypes were cast in a 1:1 blend of Ecoflex 00-30 and Dragon Skin 10, poured into 3D-printed moulds and cured at room temperature. Ecoflex (Shore 00-30) conforms and seals, while Dragon Skin 10 (Shore 10A, 102 pli tear strength) springs back and resists tearing. Ecoflex alone was too floppy to recover, and Dragon Skin alone was too stiff to fold flat. The blend sets the modulus so that a castable 1 mm wall folds at the hinges and springs back after release. Fuel-resistant fluorosilicone (FVMQ) is reserved for the final version.

<figure> <div class="img-placeholder">V3 bellows cup: seal bore, lip, folds, hinges</div> <figcaption>Figure 5. V3 bellows cup geometry: seal bore, lip, folds and hinges.</figcaption> </figure>

Each cup was cast in a two-part 3D-printed mould, with an inner core forming the bellows cavity and the outer halves clamped together with M4 fasteners. The thin bellows walls made casting difficult. Air bubbles trapped in the 1 mm walls and 0.55 mm hinges were a recurring problem, leaving voids that weakened the walls and created leak paths through the seal. Uncured silicone also seeped out through the gaps between the mould parts, so Vaseline was applied along the parting lines as a sealant to prevent leakage during curing.

<figure> <div class="img-placeholder">Two-part 3D-printed mould</div> <figcaption>Figure 6. Two-part 3D-printed mould used to cast the passive cups.</figcaption> </figure>

To resist shear on a vertical wall and provide controlled attach and release, the cup is mounted in a four-part skeleton plunger comprising a collar, frame, plunger and handle. Pushing the plunger seals the cup, and pulling it lifts the centre to break the seal.

<figure> <div class="img-placeholder">Skeleton plunger: collar, frame, plunger, handle</div> <figcaption>Figure 7. Skeleton plunger assembly: collar, frame, plunger and handle.</figcaption> </figure>
3.3.4 Prototype Development (V1–V3)
<figure> <div class="figure-row"> <div class="img-placeholder">V1</div> <div class="img-placeholder">V2</div> <div class="img-placeholder">V3</div> </div> <figcaption>Figure 8. Passive suction-cup prototypes V1–V3.</figcaption> </figure>
V1 replicated the proportions of He et al. (2026) at a large scale. It carried the highest load (250 g), but the thick, rigid sealing lip gradually folded up and lost the seal.
V2 was scaled down and held about five times its own weight. It did not collapse fully, so trapped air bubbles deformed the cup and caused leakage.
V3 implemented the geometry in Section 3.3.3: a Ø46 mm seal bore, two folds, 1.0 mm wall panels and 0.55 mm hinges. The bellows collapsed completely but did not rise back up, and the thin wall collapsed internally when pulled.
3.3.5 Load Capacity and Seal-Retention Testing

Each cup was loaded and timed until the seal failed. Hold time is used as a proxy for seal quality, since a passive cup always leaks slowly and the pressure difference $$\Delta p$$ decays over time.

Version	Load	Hold time
V1	250 g	30 s
V2	100 g	80 s (longest)
V3	Limited	10 s

Table 6. Load and hold time of each passive cup. {: .caption}

<figure> <div class="img-placeholder">Bar chart: hold time of V1, V2, V3</div> <figcaption>Figure 9. Hold time of each prototype before seal failure.</figcaption> </figure>

A single gait step takes only a few seconds, so even a 20 s hold could support locomotion. Stationary camera inspection, however, requires the foot to stay attached far longer, which would require the plunger to repeatedly re-press and re-seal the cup.

<figure> <div class="figure-row"> <div class="img-placeholder">V1 lip fold-up</div> <div class="img-placeholder">V2 trapped air</div> <div class="img-placeholder">V3 internal collapse</div> </div> <figcaption>Figure 10. Representative failures: V1 lip fold-up, V2 trapped air, V3 internal collapse.</figcaption> </figure>
3.3.6 Limitations and Transition to Active Vacuum Suction

Testing exposed four limitations:

No spring-back: V3's 1.0 mm walls folded flat but could not recover to generate $$V_2$$.
No pump, so leaks are fatal: any leak path lets $$\Delta p$$ decay with nothing to restore it.
Wall loads peel: the peel moment $$W d$$ lifted the top edge before the cup's capacity was reached.
Small diameter limits load: the Ø46 mm bore, constrained by end-plate size, caps both $$A$$ and $$r$$.

A further system-level constraint emerged: the Kresling actuators act parallel to the surface and cannot supply the normal preload needed to press a passive cup into a seal. An active vacuum cup generates its own preload, continuously replaces leaked air and releases on command through a solenoid valve. The trade-off is reintroducing a vacuum line and the associated oil-ingestion risk, addressed in Section 3.11. On this basis, the design moved to active vacuum suction, described in Section 3.4.

3.4 Active Vacuum Suction: Design Adaptation

Following the investigation of passive suction, active vacuum suction (Idea 2 in Table 4) was explored as an alternative attachment approach.

3.4.1 Suction-Cup Geometry Selection

Three suction-cup geometries were considered: flat, bellows and deep-concave cups. Bellows cups provide greater axial compliance and can accommodate surface misalignment, whereas flat cups offer a compact profile and relatively direct force transmission. Since SoftCrawl is intended to operate primarily on comparatively smooth aluminium surfaces, extensive axial compliance was not considered a primary requirement. Instead, compactness, stable mounting and resistance to excessive deformation under lateral loading were prioritised.

A flat suction cup with a compliant sealing lip was therefore selected for preliminary development. The flexible lip allows local conformity to the substrate, while the relatively compact body makes integration with the robot's mounting structure easier. However, subsequent testing revealed that eccentric loading could still cause significant deformation and peeling. This finding motivated the proposed development of a reinforced suction-cup support structure to improve attachment stability.

3.4.2 Design Approach

Rather than developing an entirely new suction-cup geometry, the approach was to adapt a commercially available industrial suction cup for a specialised robotic locomotion application. Commercial suction cups are commonly designed for handling and gripping applications, where vacuum pressure is used to attach to objects during lifting or transfer.

SoftCrawl introduces a different set of operating conditions. The suction cups must support a mobile robotic structure, undergo repeated attachment and release, tolerate changes in loading direction and maintain adhesion under possible oil contamination. In addition, the robot's body deformation can introduce eccentric forces and moments that are not adequately represented by simple axial suction-force calculations.

The active suction subsystem was therefore developed through four principal activities:

Selection and preliminary sizing of commercially available suction cups.
Design of mechanical interfaces for integration with the deformable robot body.
Experimental characterisation of attachment performance under different loading conditions.
Identification of failure mechanisms and development of modifications for the next design iteration.

The design contribution lies in adapting, evaluating and improving the attachment system for the intended operating environment.

3.5 Vacuum Source and Suction-Cup Selection

A centralised rotary-vane vacuum pump was selected to provide the pressure differential required for active adhesion. The selected pump has a nominal flow capacity of approximately 57 L/min and a stated ultimate vacuum level approaching −90 kPa gauge pressure. A centralised source allows vacuum generation to remain external to the robot, so the pump does not have to be carried inside the fuel tank.

For the attachment interface, the Festo VAS-40-1/4-PUR-B polyurethane suction cup was selected. The cup has a nominal diameter of 40 mm, a reported mass of approximately 26 g and a manufacturer's rated axial holding force of approximately 60 N under specified conditions.

Polyurethane was selected as the cup material based on the available component configuration and its potential suitability for repeated compliant contact. Compatibility with the actual fuel or oil environment requires further validation. The suction cup was evaluated not only for its nominal holding force but also for its effective suction area, sealing behaviour and suitability for integration with the robotic body.

3.6 Suction-Cup Sizing Calculations

A preliminary sizing model was developed to determine the effective suction-cup diameter required to support the robot during vertical locomotion. The suction force generated by one cup is approximated by:

$$F_s = P A$$

where $$P$$ is the vacuum pressure differential and $$A$$ is the effective sealed area. Assuming Coulomb-type frictional resistance, the combined shear capacity is:

$$F_{shear} = \mu\, n\, f\, P A$$

where $$\mu$$ is the assumed friction coefficient, $$n$$ is the number of cups per foot and $$f$$ is the number of supporting feet. To incorporate a safety factor $$s$$:

$$\mu\, n\, f\, P A \ge s\, m g$$

Using the effective suction area of a circular cup:

$$A = \frac{\pi d^2}{4}$$

the minimum required diameter is:

$$d_{min} = \sqrt{\frac{4\, s\, m g}{\pi\, \mu\, n\, f\, P}}$$

Here $$d$$ is the effective diameter of the suction cup, not its nominal diameter. The preliminary design parameters are:

Parameter	Value
Robot mass, m	0.75 kg
Vacuum pressure differential, P	90 kPa
Friction coefficient (oil), μ	0.1
Supporting feet, f	2
Cups per foot, n	1
Safety factor, s	2

Table 7. Suction-cup sizing parameters. {: .caption}

Substitution gives $$d_{min} = 32.26$$ mm.

Based on this requirement, cost and delivery time, we chose the Festo 40 mm polyurethane suction cup VAS-40-1/4-PUR-B (G ¼). It has a reported effective diameter of 34.4 mm, so it marginally satisfies the preliminary sliding-based design requirement.

However, this model assumes uniform pressure, equal load sharing and a simplified friction relationship. It does not account for suction-cup peeling, deformation or loss of sealing under eccentric loading. These limitations motivated the experimental validation that follows.

3.7 Mechanical Integration with the Robot Body

A custom mounting interface was developed to attach the selected suction cups to the deformable robotic body. The assembly incorporates profiled locating features and suction-cup holders to position the cups and maintain alignment during loading. Interference-fit features, countersunk screws and embedded nuts provide mechanical retention while reducing exposed metallic components. The design also accommodates the pneumatic tubing connections that supply vacuum to the cups.

<figure> <div class="img-placeholder">Suction-cup mounting interface on the robot body</div> <figcaption>Figure 11. Suction-cup mounting interface.</figcaption> </figure>
3.8 Experimental Evaluation of Payload Capacity

A configurable testing jig was developed to investigate the load-bearing performance of the selected suction cups. The jig allowed the number and arrangement of active suction cups to be varied while external loads were applied.

<figure> <div class="img-placeholder">Configurable payload testing jig</div> <figcaption>Figure 12. Payload testing jig.</figcaption> </figure>

Tests were conducted at approximately −80 kPa on dry surfaces in horizontal and vertical orientations. Three attachment configurations were evaluated: all four suction cups engaged, front two engaged and rear two engaged.

Attachment configuration	Horizontal failure load	Vertical failure load
Four cups engaged	110 N	40 N
Front two engaged	68 N	30 N
Rear two engaged	70 N	10 N

Table 8. Failure load by attachment configuration (dry, about −80 kPa). {: .caption}

The results show that the attachment configuration strongly influences the measured failure load. Although the front and rear two-foot arrangements had similar load capacities on horizontal surfaces, their vertical performance differed substantially. The rear-two-foot configuration was the limiting case, with a measured vertical failure load of approximately 10 N.

This suggests that the system's performance cannot be predicted solely from the total theoretical suction force or the number of engaged cups. The orientation and distribution of the applied loads must also be considered.

3.9 Peeling Failure Under Eccentric Loading

During vertical-wall testing, suction-cup deformation and peeling were identified as critical failure behaviours. When the supported load acts at a distance from the attachment surface, it generates an overturning moment:

$$M = F e$$

where $$F$$ is the applied load and $$e$$ is its perpendicular offset from the attachment surface. This moment produces nonuniform loading across the suction-cup interface, so portions of the sealing lip may deform or begin lifting from the surface. If the seal is compromised, air leakage can reduce the pressure differential and cause detachment.

<figure> <div class="img-placeholder">Suction cup peeling under eccentric load on a vertical surface</div> <figcaption>Figure 13. Peeling of a suction cup under eccentric loading.</figcaption> </figure>

This behaviour differs from pure tangential sliding, where failure is governed primarily by the available frictional resistance. The importance of combined force and moment loading in suction-cup performance has been discussed by Mantriota and Messina (2011). The experimental findings therefore indicate that moment-induced detachment must be assessed independently of the simplified friction-based sizing model.

3.9.1 Effect of Suction-Cup Spacing

Additional tests investigated the relationship between suction-cup spacing and maximum supported load.

Cup spacing	Failure load
23 mm	4 N
69 mm	5 N
115 mm	7 N
161 mm	10 N

Table 9. Failure load against suction-cup spacing. {: .caption}

Increasing the spacing from 23 mm to 161 mm increased the measured failure load from 4 N to 10 N, a 2.5-fold increase across the tested configurations.

This trend is consistent with the general principle established by Rutkowski et al. (2009) that suction-cup arrangement geometry influences moment resistance. However, the loading conditions differ between the two studies. Rutkowski et al. investigated resistance to axial torque, whereas SoftCrawl's experiments involved eccentric loading on a vertical surface, where suction-cup deformation and peeling were observed.

The results show that attachment geometry influences load-bearing performance under the experimental conditions. However, the relationship depends on the loading arrangement, cup orientation and deformation behaviour. Further testing is required before establishing a general predictive model.

3.10 Shear Testing Under Oil Contamination

According to research on suction cups on dry surfaces by Wolff <span class="todo">[Add year]</span>, as peeling begins the suction cup deforms, converting part of its contact area into additional suction area. This increases adhesion and resistance to peeling, making sliding the more likely failure mode. On an oily surface, which drastically reduces the coefficient of friction, sliding becomes even more probable.

Since residual fuel or oil may be present on aircraft fuel-tank surfaces, the effect of contamination on suction-cup attachment was investigated. Single-cup shear tests were conducted on aluminium surfaces under dry and oil-coated conditions. A tangential force was applied until the suction cup reached its measured shear limit. Two vacuum pressure differentials were investigated: 30 kPa and 80 kPa.

<figure> <div class="img-placeholder">Single-cup shear test on oil-coated aluminium</div> <figcaption>Figure 14. Shear test setup.</figcaption> </figure>
Vacuum pressure	Without oil	With oil
−30 kPa	15.0 N	6.0 N
−80 kPa	21.0 N	8.6 N

Table 10. Single-cup shear limit, dry and oil-coated. {: .caption}

Oil contamination reduced the measured shear resistance by approximately 60% at both pressures. Using the measured shear force at −80 kPa and the effective suction area, the apparent friction ratio is:

$$\mu_{app} = \frac{F_{shear}}{\Delta P\, A_{eff}} = \frac{8.6}{80\,000 \times \frac{\pi (0.0344)^2}{4}} \approx 0.116$$

which is reasonably consistent with the initial design assumption of 0.1. Assuming two supporting cups contribute equally:

$$F_{shear,total} = 2 \times 8.6 = 17.2\ \text{N}$$

For a robot mass of 750 g and a target safety factor of 2:

$$F_{required} = 2 \times 0.75 \times 9.81 = 14.72\ \text{N}$$
<div class="callout result"> <p>17.2 N &gt; 14.72 N: the estimated two-cup shear capacity on an oily surface exceeds the preliminary sliding requirement.</p> </div> <div class="callout warning"> <p>This result is extrapolated from individual suction-cup tests and assumes equal load sharing. It does not establish the performance of the complete assembly under combined shear and peeling on an oil-contaminated vertical surface.</p> </div>
3.11 Oil Ingestion into the Vacuum System

An additional challenge was identified during oil-contaminated suction testing. Liquid oil was observed entering the vacuum tubing when suction was applied to the contaminated surface. This presented a risk of contamination or damage to downstream pneumatic components, including solenoid valves and the vacuum pump, so testing was stopped to prevent oil from reaching them.

Three protection strategies were considered:

Protection method	Advantage	Limitation
Liquid-oil separator	Collects bulk liquid oil	Additional volume and integration requirements
Oil-mist coalescing filter	Designed to capture entrained oil droplets	Greater size, cost or maintenance requirements
Inline vacuum filter	Compact and straightforward to integrate	Filtration capability depends on media and contamination type

Table 11. Vacuum-line protection options. {: .caption}

A compact inline vacuum filter was selected for preliminary evaluation. The filter was installed in the vacuum line, and liquid oil was introduced upstream. During the test, no visible liquid-oil breakthrough was observed downstream of the filter. The measured change in suction response time was less than one second.

<figure> <div class="img-placeholder">Inline vacuum filter installed in the vacuum line</div> <figcaption>Figure 15. Inline vacuum filter test.</figcaption> </figure>

These observations provide preliminary evidence that the filter can reduce visible liquid-oil carryover under the tested conditions. However, they do not establish complete protection against fine oil mist, long-term contamination or filter saturation. Further testing is required to characterise pressure losses, filtration efficiency and reliability during repeated suction cycles.

3.12 Proposed Design Improvements

The experimental programme identified two primary limitations: moment-induced suction-cup peeling and oil ingestion into the vacuum system.

3.12.1 Reinforced Suction-Cup Structure

To address peeling, a reinforced suction-cup support structure is proposed. The concept incorporates a rigid or semi-rigid skeleton to limit excessive deformation of the suction-cup body under eccentric loading. The intended function is to improve load transfer between the mounting structure and the suction cup while retaining enough sealing-lip flexibility to conform to the substrate. Research on mechanically reinforced suction cups provides inspiration for this approach (He et al., 2026).

The proposed reinforcement has not yet been fabricated or validated for the selected Festo suction cup. Future work will investigate its influence on deformation, sealing performance and critical peeling load.

3.12.2 Improved Vacuum-Line Protection

Further development will focus on characterising the inline filter's performance under repeated oil-contamination cycles. Key considerations include filtration efficiency, pressure loss, contamination capacity and replacement requirements. Where necessary, the system may incorporate additional liquid separation or oil-mist filtration stages.

3.12.3 Integrated Adhesion Validation

The next phase will evaluate the suction-cup subsystem when mounted to the deformable Kresling body. This is necessary because the loading conditions experienced during locomotion may differ from those generated using the rigid testing jig.

Particular attention will be given to the rear-two-foot configuration, which had the lowest vertical failure load. Testing will also investigate repeated attachment and release, uneven load sharing, oil-contaminated vertical surfaces and the effects of body deformation on sealing.

3.13 Interim Outcomes

The Robot Legs subsystem has progressed from preliminary concept evaluation to laboratory-level prototype testing. The principal outcomes include:

Development and evaluation of passive suction-cup concepts.
Selection and preliminary sizing of an active vacuum suction system.
Design of custom suction-cup mounting interfaces.
Quantitative payload testing across multiple attachment configurations.
Identification of moment-induced peeling as a critical failure mechanism.
Experimental characterisation of oil-related shear reduction.
Preliminary evaluation of inline vacuum filtration.
<div class="callout result"> <p>The findings demonstrate the feasibility of generating controlled attachment forces using the selected components, while identifying limitations that must be resolved before integrated robotic climbing can be considered validated. The next development phase will focus on improving peeling resistance, validating the suction-cup assembly under representative loading conditions and integrating the subsystem with SoftCrawl's pneumatic locomotion architecture.</p> </div>
References
Festo SE & Co. KG. (2023). Suction cup complete VAS-40-1/4-PUR-B (Part No. 1396092) [Data sheet]. https://ftp.festo.com/public/PNEUMATIC/SOFTWARE_SERVICE/DataSheet/EN_US/1396092.pdf
He, Y., Pfeifer, P. L., Feng, R., & Li, S. (2026). Controllable passive suction cups with mechanical programmability for soft robotics. Advanced Functional Materials, 36(56), Article e75782. https://doi.org/10.1002/adfm.75782
Kawasaki, S., & Kikuchi, K. (2014). Development of a small legged wall climbing robot with passive suction cups. In Proceedings of the 3rd International Conference on Design Engineering and Science (ICDES 2014) (pp. 112–116).
Mantriota, G., & Messina, A. (2011). Theoretical and experimental study of the performance of flat suction cups in the presence of tangential loads. Mechanism and Machine Theory, 46(5), 607–617. https://doi.org/10.1016/j.mechmachtheory.2011.01.003
Rutkowski et al. (2009). <span class="todo">[Add full citation.]</span>
Wang, L., Ha, K.-H., Rodin, G. J., Liechti, K. M., & Lu, N. (2020). Mechanics of crater-enabled soft dry adhesives: A review. Frontiers in Mechanical Engineering, 6, Article 601510. https://doi.org/10.3389/fmech.2020.601510
Wolff <span class="todo">[Add full citation.]</span>