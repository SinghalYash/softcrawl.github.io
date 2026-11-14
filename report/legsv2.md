---
layout: report
title: Robot Legs
group: Interim
code: SEC-03
nav_order: 3
permalink: /report/legs/
---

<div class="stat-row"> <div class="stat"><span class="value">40 N</span><span class="label">Vertical hold, 4 cups</span></div> <div class="stat"><span class="value">17.2 N</span><span class="label">2-cup oily shear</span></div> <div class="stat"><span class="value">Ø40 mm</span><span class="label">Festo PU cup</span></div> </div>

## 3. Robot Legs: Locomotion and Adhesion Subsystem

### 3.1 Locomotion Requirements and Concept Selection

#### 3.1.1 Required Locomotion Modes

Aircraft fuel-tank inspection requires the robot to navigate internal surfaces with varying orientations and structural obstacles.

<figure>
<img src="{{ '/images/legs/image1.png' | relative_url }}">
<figcaption>Figure 1. Types of locomotion methods (Yuan et al., 2026).</figcaption>
</figure>

Soft robots can move in many ways, but two locomotion modes are particularly relevant to our use case:

- **Crawling:** movement along the horizontal surfaces of the tank.
- **Climbing:** movement along vertical or inclined surfaces, enabling access to walls and other elevated inspection regions.

The robot must also be able to navigate between the different chambers of the fuel tank by climbing up a 90 degree corner onto the walls and passing through the openings. These requirements create two coupled design challenges: generating controlled body movement and maintaining reliable surface attachment on oily surfaces throughout the locomotion sequence.

#### 3.1.2 Evaluation of Adhesion Mechanisms

The compliant Kresling actuator produces body movement, while the Robot Legs subsystem provides surface adhesion. The attachment mechanism must support the robot and its payload, maintain grip on oil-contaminated surfaces and avoid damaging the contacted structures.

Four principal adhesion approaches were considered (see [Appendix C](#appendix-c-comparison-of-adhesion-mechanisms)).

Vacuum suction was selected as the primary adhesion mechanism for SoftCrawl because it provides controllable attachment to suitable non-ferromagnetic surfaces, including smooth aluminium and acrylic. It avoids the high-voltage actuation associated with electroadhesion. Gecko-inspired dry adhesion was also considered, but contamination and durability are concerns.

However, vacuum suction remains sensitive to leakage and eccentric loading, necessitating experimental investigation of sealing, shear resistance and peeling under representative operating conditions. This motivated parallel investigation of passive and active suction concepts.

#### 3.1.3 Subsystem Requirements

Based on the overall system requirements for our robot, we have highlighted the key functional specifications of the robot legs subsystem.

<table class="styled-table">
  <thead>
    <tr>
      <th style="width: 25%;">Category</th>
      <th>Requirement</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="2" style="vertical-align: middle;">Geometry</td>
      <td class="highlight-green">Fit within a 300 × 200 mm access opening</td>
    </tr>
    <tr>
      <td>Actuator never expands beyond the body, avoiding snags</td>
    </tr>
    <tr>
      <td style="vertical-align: middle;">Electronics</td>
      <td>No electronics in the tank except camera and light</td>
    </tr>
    <tr>
      <td rowspan="2" style="vertical-align: middle;">Adhesion</td>
      <td class="highlight-green">Support a provisional 0.75 kg robot mass with a target safety factor of 2 on vertical surfaces</td>
    </tr>
    <tr>
      <td class="highlight-green">Adhesion on thin oil film over aluminium sheet</td>
    </tr>
    <tr>
      <td rowspan="3" style="vertical-align: middle;">Locomotion</td>
      <td>Control each leg individually</td>
    </tr>
    <tr>
      <td>Climb 90 degree corners</td>
    </tr>
    <tr>
      <td>Pass through 30 cm × 30 cm access hole to next fuel tank chamber</td>
    </tr>
    <tr>
      <td rowspan="2" style="vertical-align: middle;">Material compatibility</td>
      <td class="highlight-green">No damage to fuel tank internal surfaces</td>
    </tr>
    <tr>
      <td class="highlight-green">No swelling/damage due to prolonged oil exposure</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table 1. Robot Legs requirements</p>

### 3.2 Morphological Matrix

A morphological matrix was developed to compare solution principles for the ranked Robot Legs functions. Two concepts—passive and active suction—were selected for parallel development.

<table class="styled-table">
  <thead>
    <tr>
      <th>Rank</th>
      <th>Function</th>
      <th>Solution 1</th>
      <th>Solution 2</th>
      <th>Solution 3</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>Maintain surface adhesion</td>
      <td>Passive suction cups</td>
      <td>Active suction cups</td>
      <td>Mechanically actuated suction cups</td>
    </tr>
    <tr>
      <td>2</td>
      <td>Seal on oily surface</td>
      <td>Bellows suction cups</td>
      <td>Deep concave suction cup</td>
      <td>Flat suction cup</td>
    </tr>
    <tr>
      <td>3</td>
      <td>Resist oil exposure</td>
      <td>Nitrile Butadiene Rubber</td>
      <td>Fluorosilicone & Viton</td>
      <td>Polyurethane</td>
    </tr>
    <tr>
      <td>4</td>
      <td>Release cup on command</td>
      <td>Solenoid valve</td>
      <td>Manual valve</td>
      <td>Plunging skeleton</td>
    </tr>
    <tr>
      <td>5</td>
      <td>Protect vacuum line from oil ingestion</td>
      <td>Liquid oil separator</td>
      <td>Oil coalescing filter</td>
      <td>Vacuum filter</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table 2. Morphological matrix for the robot legs</p>

---

### 3.3 Passive Suction-Cup Development

#### 3.3.1 Literature Review and Selection of Passive Suction

<table class="styled-table">
  <thead>
    <tr>
      <th>Rank</th>
      <th>Function</th>
      <th>Idea 1 selection</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>Maintain surface adhesion</td>
      <td><strong>Passive suction cups</strong></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Seal on oily surface</td>
      <td><strong>Bellows suction cups</strong></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Resist oil exposure</td>
      <td><strong>Fluorosilicone & Viton</strong></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Release cup on command</td>
      <td><strong>Plunging skeleton</strong></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Protect vacuum line from oil ingestion</td>
      <td>Not needed (no vacuum line)</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table 3. Passive suction concept (Idea 1) selected from the morphological matrix.</p>

Within the morphological matrix in Section 3.2, Idea 1 combined a passive bellows cup, a fluorosilicone final material and a plunging-skeleton release mechanism.

Passive suction has an established track record in small climbing robots. Kawasaki and Kikuchi (2014) demonstrated a 34 g hexapod that climbed walls on passive cups, attaching by pushing and releasing by pulling a string that peeled the cup edge. Wang et al. (2020) showed that suction-based adhesion continues to hold on wet surfaces where gecko-style dry adhesives lose grip, which is directly relevant to a tank coated with residual fuel film. Most recently, He et al. (2026) used internal ribs to achieve mechanically programmable, controllable passive suction, enabling the ORACLE robot to climb walls and ceilings.

<figure>
<img src="{{ '/images/legs/image2.png' | relative_url }}">
<figcaption>Figure 2. Development of passive suction-cup climbing robots: Kawasaki and Kikuchi (2014), Wang et al. (2020) and He et al. (2026).</figcaption>
</figure>

Compared with active vacuum, a passive cup:

- draws zero power once sealed
- needs only the cup and a mechanical trigger, with no pump, valves, air lines or filters
- carries no risk of drawing fuel into a vacuum line
- avoids the weight and drag of air lines on the robot

#### 3.3.2 Success Criteria

The design requires a cup that collapses almost completely (small *V*₁), recovers strongly (large *V*₂) and has a large sealed area *A* (see [Appendix A](#appendix-a-passive-suction-cup-design-principles)).

On a vertical wall, the foot must satisfy two conditions. **Slip** is resisted by friction, requiring *W* ≤ *μN*. **Peel** is the more critical mode: the robot's weight *W* acting at an offset *d* creates a moment *M* = *W·d* that lifts the top edge of the cup first, so the cup must satisfy *W·d* ≤ *N·r*, where *r* is the seal radius.

<figure>
<img src="{{ '/images/legs/image3.png' | relative_url }}" alt="Forces on a suction foot">
<figcaption>Figure 3. Forces on a suction foot on a vertical wall, showing the peel and slip conditions.</figcaption>
</figure>

#### 3.3.3 Geometric and Material Design

The final passive cup (V3) was built around four geometric parameters, summarised below.

<table class="styled-table">
  <thead>
    <tr>
      <th>Parameter</th>
      <th>Value</th>
      <th>Rationale</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Seal bore</td>
      <td>Ø46 mm</td>
      <td>Larger <em>r</em> resists peel; capped by end-plate size</td>
    </tr>
    <tr>
      <td>Lip</td>
      <td>7 × 3 mm</td>
      <td>Seals and resists shear; 27× stiffer than the wall</td>
    </tr>
    <tr>
      <td>Folds</td>
      <td>2</td>
      <td>Enough springback without raising <em>d</em>; nests flat for <em>V</em>₁ ≈ 0</td>
    </tr>
    <tr>
      <td>Wall / hinges</td>
      <td>1.0 / 0.55 mm</td>
      <td>Hinges ~6× softer, so folding stays at the hinges</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table 4. Geometric parameters of the V3 passive cup.</p>

Prototypes were cast in a 1:1 blend of Ecoflex 00-30 and Dragon Skin 10, poured into 3D-printed moulds and cured at room temperature. Ecoflex (Shore 00-30) conforms and seals, while Dragon Skin 10 (Shore 10A, 102 pli tear strength) springs back and resists tearing. Ecoflex alone was too floppy to recover, and Dragon Skin alone was too stiff to fold flat. The blend sets the modulus so that a castable 1 mm wall folds at the hinges and springs back after release. Fuel-resistant fluorosilicone (FVMQ) is reserved for the final version due to cost.

<figure>
<img src="{{ '/images/legs/image4.png' | relative_url }}" alt="V3 bellows cup geometry">
<figcaption>Figure 4. V3 bellows cup geometry: seal bore, lip, folds and hinges.</figcaption>
</figure>

Each cup was cast in a two-part 3D-printed mould, with an inner core forming the bellows cavity.

<figure>
<img src="{{ '/images/legs/image5.png' | relative_url }}" alt="Two-part mould">
<figcaption>Figure 5. Two-part 3D-printed mould used to cast the passive cups.</figcaption>
</figure>

To resist shear on a vertical wall and provide pre-load for attach and release, the cup is mounted in a four-part skeleton plunger comprising a collar, frame, plunger and handle. Pushing the plunger seals the cup, and pulling it lifts the centre to break the seal.

<figure>
<img src="{{ '/images/legs/image6.png' | relative_url }}" alt="Skeleton plunger assembly">
<figcaption>Figure 6. Skeleton plunger assembly: collar, frame, plunger and handle.</figcaption>
</figure>

#### 3.3.4 Prototype Development (V1–V3)

<figure>
<img src="{{ '/images/legs/image7.png' | relative_url }}" alt="Passive cup prototypes V1 to V3">
<figcaption>Figure 7. Passive suction-cup prototypes V1–V3.</figcaption>
</figure>

<table class="styled-table">
  <thead>
    <tr>
      <th>Version</th>
      <th>Design</th>
      <th>Outcome</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>V1</td>
      <td>Proportions of He et al. (2026) at a large scale</td>
      <td>Highest load (250 g), but the thick, rigid lip gradually folded up and lost the seal</td>
    </tr>
    <tr>
      <td>V2</td>
      <td>Scaled down</td>
      <td>Held about five times its own weight; incomplete collapse trapped air, deforming the cup and causing leakage</td>
    </tr>
    <tr>
      <td>V3</td>
      <td>Section 3.3.3 geometry: Ø46 mm bore, two folds, 1.0 mm walls, 0.55 mm hinges</td>
      <td>Collapsed fully but did not spring back; the thin wall collapsed internally when pulled</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table 5. Passive suction-cup prototype iterations V1–V3.</p>

#### 3.3.5 Load Capacity and Seal-Retention Testing

Each prototype was loaded and timed until its seal failed (see [Appendix B](#appendix-b-passive-cup-hold-time-testing)). V2 held longest at 80 s with 100 g, V1 held 250 g for 30 s, and V3 lasted only 10 s with limited load.

A single gait step takes only a few seconds, so even a 20 s hold could support locomotion. Stationary camera inspection, however, requires the foot to stay attached far longer, which would require the plunger to repeatedly re-press and re-seal the cup.

#### 3.3.6 Limitations and Transition to Active Vacuum Suction

Testing exposed four limitations:

1. No spring-back
2. No pump, so leaks are fatal
3. Wall loads cause peeling
4. Small diameter limits load

---

### 3.4 Active Vacuum Suction: Design Adaptation

Active vacuum suction was investigated in parallel with passive suction development to enable early testing using commercially available components.

<table class="styled-table">
  <thead>
    <tr>
      <th>Rank</th>
      <th>Function</th>
      <th>Idea 2 selection</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>Maintain surface adhesion</td>
      <td><strong>Active suction cups</strong></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Seal on oily surface</td>
      <td><strong>Flat suction cup</strong></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Resist oil exposure</td>
      <td><strong>Polyurethane</strong></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Release cup on command</td>
      <td><strong>Solenoid valve</strong></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Protect vacuum line from oil ingestion</td>
      <td><strong>Vacuum filter</strong></td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table 6. Active suction concept (Idea 2) selected from the morphological matrix.</p>

Commercial suction cups were adapted for robotic locomotion, allowing early evaluation of load capacity, mechanical integration, oil contamination and failure mechanisms. The selected solution principles and their justifications are summarised in [Appendix D](#appendix-d-suction-cup-geometry-comparison).

#### 3.4.1 Suction-Cup Geometry Selection

Three suction-cup geometries were evaluated (see [Appendix D](#appendix-d-suction-cup-geometry-comparison)). Flat suction cups were selected for their compact profile, positional stability and suitability for smooth aluminium and acrylic surfaces, in line with SoftCrawl's priority of minimising its footprint.

#### 3.4.2 Design Approach

Unlike conventional industrial suction cups primarily used for gripping and lifting, SoftCrawl's suction cups must withstand changing load directions, repeated attachment cycles and potential oil contamination. Development therefore focused on suction-cup sizing, mechanical integration with the deformable body, experimental characterisation under different loading conditions, and identification of failure mechanisms to guide subsequent design improvements.

### 3.5 Failure Modes of Suction Cups

Three loading conditions were considered to guide experimental validation: axial (normal), tangential (shear) and eccentric (moment) loading (Mantriota & Messina, 2011).

<table class="styled-table">
  <thead>
    <tr>
      <th></th>
      <th>Axial / Normal Load</th>
      <th>Shear / Tangential Load</th>
      <th>Peeling / Moment Load</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>Free body diagram</strong></td>
      <td><img src="{{ '/images/legs/image8.png' | relative_url }}" alt="Axial load FBD"></td>
      <td><img src="{{ '/images/legs/image9.png' | relative_url }}" alt="Shear load FBD"></td>
      <td><img src="{{ '/images/legs/image10.png' | relative_url }}" alt="Peel load FBD"></td>
    </tr>
    <tr>
      <td><strong>Estimation method</strong></td>
      <td>Manufacturer datasheet</td>
      <td>Friction model using an assumed or measured coefficient</td>
      <td>Experimental validation (hard to model)</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table 7. Suction-cup loading conditions and assessment methods.</p>

### 3.6 Suction-Cup Sizing Calculation & Selection

Based on the payload requirements, surface conditions and robot configuration, the minimum effective diameter was calculated as *d*<sub>min</sub> = 32.26 mm (see [Appendix E](#appendix-e-suction-cup-sizing-calculations)). The Festo VAS-40-1/4-PUR-B polyurethane suction cup was selected based on cost, availability and geometry, with a nominal diameter of 40 mm, an effective diameter of 34.4 mm as used in the design calculations and a rated axial holding force of approximately 60 N. Polyurethane was chosen for its reported resistance to oils and lubricants (AMES Direct, 2025); compatibility with the specific tank contaminants remains to be verified.

The simplified model assumes uniform pressure and equal load sharing, excluding peeling and seal deformation. Experimental validation was therefore necessary.

### 3.7 Mechanical Integration with the Robot Body

A 3D-printed mounting interface was developed to integrate the suction cups with the deformable body. Profiled locating features and interference-fit holders maintain alignment, while countersunk screws and embedded nuts provide retention with minimal exposed metal. The assembly also accommodates pneumatic tubing connections.

<figure>
<img src="{{ '/images/legs/image11.png' | relative_url }}" alt="Suction cup mounting interface">
<figcaption>Figure 8. CAD model of the suction-cup-to-body mounting interface.</figcaption>
</figure>

### 3.8 Experimental Evaluation of Payload Capacity

A configurable testing jig was used to measure failure loads at approximately −80 kPa under horizontal and vertical loading, with all four cups active, the front two active and the rear two active.

<figure>
<img src="{{ '/images/legs/image12.png' | relative_url }}" alt="Payload testing jig CAD">
<figcaption>Figure 9. CAD model of the configurable payload testing jig.</figcaption>
</figure>

<figure>
<div class="figure-row">
<img src="{{ '/images/legs/image13.png' | relative_url }}" alt="Horizontal loading test">
<img src="{{ '/images/legs/image14.png' | relative_url }}" alt="Vertical loading test">
</div>
<figcaption>Figure 10. Experimental setup for suction-cup payload testing under horizontal and vertical loading.</figcaption>
</figure>

<figure>
<img src="{{ '/images/legs/image15.png' | relative_url }}" alt="Free-body diagram of the payload test">
<figcaption>Figure 11. Free-body diagram of the robot on a vertical surface, showing weight resisted by suction-cup friction.</figcaption>
</figure>

The rear-two-foot configuration was the limiting case, failing at only 10 N vertically. This demonstrates that attachment geometry and load distribution significantly influence capacity beyond theoretical suction force (see [Appendix F](#appendix-f-suction-cup-payload-testing)).

### 3.9 Peeling Failure Under Eccentric Loading

Vertical-wall testing identified moment-induced peeling as a critical failure mechanism. When the load acts away from the attachment surface, an overturning moment is generated:

<div class="legs-equation">\[
M = F \cdot e
\]</div>

This moment causes uneven suction-cup deformation, potentially lifting the sealing edge and allowing air leakage, ultimately resulting in detachment.

<figure>
<img src="{{ '/images/legs/image16.png' | relative_url }}" alt="Peeling under eccentric load">
<figcaption>Figure 12. Illustration of suction-cup peeling under eccentric loading.</figcaption>
</figure>

This explains why the measured vertical load capacity was lower than predicted by the initial friction-based sizing model (see [Appendix G](#appendix-g-suction-cup-peeling-math)).

#### 3.9.1 Effect of Suction-Cup Spacing

Additional tests investigated the relationship between suction-cup spacing and maximum supported load.

<figure>
<img src="{{ '/images/legs/image17.png' | relative_url }}" alt="Failure load against cup spacing">
<figcaption>Figure 13. Test setup for varying suction-cup spacing.</figcaption>
</figure>

Increasing the suction-cup spacing from 23 mm to 161 mm increased the maximum failure load from 4 N to 10 N, a 2.5-fold improvement. This trend is consistent with Rutkowski et al. (2009), demonstrating the influence of attachment geometry on moment resistance and informing SoftCrawl's footprint design (see [Appendix H](#appendix-h-suction-cup-configuration-testing)).

### 3.10 Shear Testing Under Oil Contamination

De Wolff (2017) suggests that suction-cup deformation during peeling can favour sliding. Oil contamination further reduces shear resistance, making sliding a potential failure mode.

At −80 kPa, slippage on the oily surface was observed at 8.6 N per cup. Back-calculating gives an apparent friction ratio of approximately 0.116, which is reasonably consistent with the initial design assumption of 0.1 (see [Appendix I](#appendix-i-suction-cup-oil-testing)).

Assuming two supporting cups contribute equally:

<div class="legs-equation">\[
F_{shear,total} = 2 \times 8.6 = 17.2\ \text{N}
\]</div>

For a robot mass of 750 g and a target safety factor of 2:

<div class="legs-equation">\[
F_{required} = 2 \times 0.75 \times 9.81 = 14.72\ \text{N}
\]</div>

Although the estimated two-cup shear capacity exceeds the preliminary sliding requirement, the measured 10 N failure load under eccentric vertical loading corresponds to an actual safety factor of only 1.36, below the target of 2. This highlights the need to improve peeling resistance and load distribution in subsequent design iterations.

### 3.11 Oil Ingestion into the Vacuum System

Oil entered the vacuum tubing during contaminated-surface testing, posing a risk to the solenoid valves and pump. Three forms of oil ingress and their protection strategies were evaluated (see [Appendix J](#appendix-j-oil-ingestion)). A compact inline vacuum filter was selected for preliminary testing based on ease of integration, rather than proven superiority over alternative solutions.

<figure>
<img src="{{ '/images/legs/image18.png' | relative_url }}" alt="Inline vacuum filter">
<figcaption>Figure 14. Inline vacuum filter installed during oil-ingress testing.</figcaption>
</figure>

Preliminary testing showed no visible oil breakthrough and approximately one second of additional suction response time. Fine oil-mist filtration and long-term reliability remain unverified.

---

### 3.12 Proposed Design Improvements

#### 3.12.1 Reinforced Suction-Cup Structure

To mitigate peeling, a rigid or semi-rigid support skeleton is proposed to restrict excessive suction-cup deformation under eccentric loading while preserving sealing-edge flexibility. Research on mechanically reinforced suction cups provides inspiration for this approach (He et al., 2026).

<figure>
<img src="{{ '/images/legs/image19.png' | relative_url }}" alt="Reinforced suction cup concept">
<figcaption>Figure 15. Mechanically reinforced suction-cup concept (He et al., 2026).</figcaption>
</figure>

<figure>
<img src="{{ '/images/legs/image20.png' | relative_url }}" alt="Reinforced suction cup concept">
<figcaption>Figure 16. Schematic of the proposed support skeleton limiting suction-cup deformation during peeling.</figcaption>
</figure>

#### 3.12.2 Integrated Adhesion Validation

Future testing will evaluate integrated locomotion with the Kresling body, focusing on the critical rear-two-cup configuration, repeated attachment cycles, uneven load sharing and sealing on oil-contaminated vertical surfaces.

#### 3.12.3 Custom Suction-Cup Geometry and Variable Stiffness

An alternative approach is to redesign the suction cup itself to improve resistance to detachment. Hernandez et al. (2024) demonstrated that elliptical and teardrop-shaped suction cups can outperform circular designs under certain shear-loading conditions. Additionally, Goshtasbi and Sadeghi (2023) developed a suction cup incorporating granular jamming, allowing the structure to remain compliant during attachment before stiffening under vacuum. Combining these principles, SoftCrawl could explore a custom active suction cup with optimised geometry and variable stiffness to reduce deformation and improve resistance to moment-induced peeling while retaining a compliant sealing edge.

<figure>
<img src="{{ '/images/legs/jamming-sucker.jpg' | relative_url }}" alt="Bio-inspired suction cup with granular jamming">
<figcaption>Figure 17. Bio-inspired suction cup with a granular-jamming mechanism for variable stiffness during attachment (Goshtasbi &amp; Sadeghi, 2023).</figcaption>
</figure>

<figure>
<img src="{{ '/images/legs/cup-geometries.jpg' | relative_url }}" alt="Suction-cup geometries with varying stiffness">
<figcaption>Figure 18. Comparison of bio-inspired suction-cup geometries with varying shapes and stiffness distributions (Hernandez et al., 2024).</figcaption>
</figure>

---

## Appendix

### Appendix A: Passive Suction-Cup Design Principles

The cup operates on Boyle's law. Pressing the cup expels air (*V*₁ ≈ 0, *P*₁ = *P*<sub>atm</sub>). When released, the walls spring back and the enclosed volume grows to *V*₂, so *P*₂ < *P*<sub>atm</sub>. The resulting holding force is:

<div class="legs-equation">\[
F = P_{atm}\left(1 - \frac{V_1}{V_2}\right) A
\]</div>

<figure>
<img src="{{ '/images/legs/image21.png' | relative_url }}" alt="Passive suction cup operating principle">
<figcaption>Figure A1. Passive suction-cup operation: compression, recovery and adhesion.</figcaption>
</figure>

Wall stiffness was controlled through plate flexural rigidity:

<div class="legs-equation">\[
D = \frac{E t^3}{12(1 - \nu^2)}
\]</div>

Because *D* scales with *t*³, doubling the wall thickness makes it eight times stiffer. A wall that is too thin folds easily but cannot spring back, while one that is too thick holds its shape but will not fold flat.

<figure>
<img src="{{ '/images/legs/image22.png' | relative_url }}" alt="Plate flexural rigidity">
<figcaption>Figure A2. Influence of wall thickness on flexural rigidity and bellows folding.</figcaption>
</figure>

### Appendix B: Passive Cup Hold-Time Testing

Each cup was loaded and timed until the seal failed. Hold time is used as a proxy for seal quality, since a passive cup always leaks slowly and the pressure difference Δ*p* decays over time.

<table class="styled-table">
  <thead>
    <tr>
      <th>Version</th>
      <th>Load</th>
      <th>Hold time</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>V1</td>
      <td>250 g</td>
      <td>30 s</td>
    </tr>
    <tr>
      <td>V2</td>
      <td>100 g</td>
      <td>80 s (longest)</td>
    </tr>
    <tr>
      <td>V3</td>
      <td>Limited</td>
      <td>10 s</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table B1. Load and hold time for each passive prototype.</p>

<figure>
<img src="{{ '/images/legs/image23.png' | relative_url }}" alt="Hold time of each prototype">
<figcaption>Figure B1. Measured seal-retention times of passive suction-cup prototypes V1–V3.</figcaption>
</figure>

### Appendix C: Comparison of Adhesion Mechanisms

<table class="styled-table">
  <thead>
    <tr>
      <th>Mechanism</th>
      <th>Advantage</th>
      <th>Limitation for SoftCrawl</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Magnetic adhesion</td>
      <td>Strong, controllable attachment on ferromagnetic surfaces</td>
      <td>Ineffective on non-ferromagnetic aluminium structures</td>
    </tr>
    <tr>
      <td>Electroadhesion</td>
      <td>Electrically controllable adhesion and proprioceptive</td>
      <td>Requires high-voltage circuitry; electrical safety and contamination sensitivity are concerns</td>
    </tr>
    <tr>
      <td>Gecko-inspired dry adhesion</td>
      <td>Lightweight, potentially passive attachment based on van der Waals forces</td>
      <td>Surface contamination and durability can reduce performance</td>
    </tr>
    <tr>
      <td>Vacuum suction</td>
      <td>Industry standard, high axial payload capacity, controllable attachment</td>
      <td>Requires reliable sealing; vulnerable to leakage, oil-related shear reduction and moment-induced peeling</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table C1. Comparison of adhesion mechanisms considered for SoftCrawl.</p>

### Appendix D: Suction-Cup Geometry Comparison

<table class="styled-table">
  <thead>
    <tr>
      <th>Geometry</th>
      <th>Advantages</th>
      <th>Limitations</th>
      <th>Suitability for SoftCrawl</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Flat suction cup</td>
      <td>Compact, stable positioning; suitable for flat surfaces</td>
      <td>Limited axial compliance and surface misalignment compensation</td>
      <td><strong>High</strong> — suitable for smooth surfaces and compact integration</td>
    </tr>
    <tr>
      <td>Bellows suction cup</td>
      <td>Greater axial compliance; accommodates height differences and misalignment</td>
      <td>Taller profile; less precise positioning</td>
      <td><strong>Moderate</strong> — additional compliance not prioritised</td>
    </tr>
    <tr>
      <td>Deep-concave suction cup</td>
      <td>Conforms to curved or highly contoured workpieces</td>
      <td>Greater cup depth; less suitable for compact mounting</td>
      <td><strong>Low</strong> — unnecessary for primarily flat surfaces</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table D1. Comparison of suction-cup geometries for SoftCrawl.</p>

Flat, bellows and deep-concave geometries were compared using manufacturer guidance (Festo, n.d.; J. Schmalz GmbH, n.d.). Bellows cups provide height compensation, while deep-concave cups suit curved workpieces. A flat cup with a compliant sealing edge was selected for its compact profile and suitability for relatively smooth aluminium and acrylic surfaces.

The selected solution principles from the morphological matrix (Section 3.2) were evaluated against SoftCrawl's requirements for controllable adhesion, compactness, oil compatibility and ease of integration. The rationale for each selection is summarised below.

<table class="styled-table">
  <thead>
    <tr>
      <th style="width: 25%;">Selected solution</th>
      <th>Selection rationale</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Active suction cups</td>
      <td>Externally supplied vacuum enables controllable adhesion and compensates for minor leakage, unlike passive suction cups.</td>
    </tr>
    <tr>
      <td>Flat suction cup</td>
      <td>Compact geometry and stable positioning on relatively smooth aluminium and acrylic surfaces, minimising the robot's footprint.</td>
    </tr>
    <tr>
      <td>Polyurethane (PU)</td>
      <td>Selected for its reported resistance to petroleum-based oils and suitability for the commercially available Festo suction cup.</td>
    </tr>
    <tr>
      <td>Solenoid valve</td>
      <td>Enables electrically controlled vacuum switching for individual suction-cup attachment and release.</td>
    </tr>
    <tr>
      <td>Inline vacuum filter</td>
      <td>Compact and straightforward to integrate; selected for preliminary oil-ingress testing rather than proven superiority over alternative separators.</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table D2. Selection rationale for the active suction concept (Idea 2).</p>

These selections formed the initial active suction subsystem, allowing early experimental validation while passive suction development continued in parallel. Subsequent testing identified limitations associated with eccentric loading, oil-induced shear reduction and vacuum-line contamination, informing future design refinements.

### Appendix E: Suction-Cup Sizing Calculations

A preliminary sizing model was developed to determine the effective suction-cup diameter required to support the robot during vertical locomotion. The parameters are as follows:

<table class="styled-table">
  <thead>
    <tr>
      <th style="width: 25%;">Parameter</th>
      <th>Value</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Robot mass, <em>m</em></td>
      <td>0.75 kg</td>
    </tr>
    <tr>
      <td>Vacuum pressure differential, <em>P</em></td>
      <td>90 kPa</td>
    </tr>
    <tr>
      <td>Friction coefficient (oil), <em>μ</em></td>
      <td>0.1</td>
    </tr>
    <tr>
      <td>Supporting feet, <em>f</em></td>
      <td>2</td>
    </tr>
    <tr>
      <td>Cups per foot, <em>n</em></td>
      <td>1</td>
    </tr>
    <tr>
      <td>Safety factor, <em>s</em></td>
      <td>2</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table E1. Parameters used for preliminary suction-cup sizing.</p>

The suction force generated by one cup is approximated by:

<div class="legs-equation">\[
F_{suction} = P A
\]</div>

where *P* is the vacuum pressure differential and *A* is the effective sealed area. Assuming Coulomb-type frictional resistance, the combined shear capacity is:

<div class="legs-equation">\[
F_{shear} = \mu\, n\, f\, P A
\]</div>

where *μ* is the assumed friction coefficient, *n* is the number of cups per foot and *f* is the number of supporting feet. To incorporate a safety factor *s*:

<div class="legs-equation">\[
\mu\, n\, f\, P A \geq s\, m g
\]</div>

Using the effective suction area of a circular cup:

<div class="legs-equation">\[
A = \frac{\pi d^2}{4}
\]</div>

The minimum required diameter is:

<div class="legs-equation">\[
d_{min} = \sqrt{\frac{4\, s\, m g}{\pi\, \mu\, n\, f\, P}} = \sqrt{\frac{4 \times 2 \times 0.75 \times 9.81}{\pi \times 0.1 \times 1 \times 2 \times 90\,000}} = 32.26\ \text{mm}
\]</div>

> **Note:** The diameter *d* denotes the effective suction diameter, not the nominal outer diameter (J. Schmalz GmbH, 2016). The 90 kPa design assumption differs from the approximately 80 kPa used in subsequent tests.

<figure>
<img src="{{ '/images/legs/image24.png' | relative_url }}" alt="Free-body diagram of suction cups supporting robot weight">
<figcaption>Figure E1. Free-body diagram used for preliminary suction-cup sizing.</figcaption>
</figure>

### Appendix F: Suction-Cup Payload Testing

<table class="styled-table">
  <thead>
    <tr>
      <th>Attachment configuration</th>
      <th>Horizontal failure load</th>
      <th>Vertical failure load</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Four cups engaged</td>
      <td>110 N</td>
      <td>40 N</td>
    </tr>
    <tr>
      <td>Front two engaged</td>
      <td>68 N</td>
      <td>30 N</td>
    </tr>
    <tr>
      <td>Rear two engaged</td>
      <td>70 N</td>
      <td>10 N</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table F1. Failure loads at approximately −80 kPa.</p>

<figure>
<img src="{{ '/images/legs/image25.png' | relative_url }}" alt="Payload testing configurations">
<figcaption>Figure F1. Suction-cup payload testing with different active-cup configurations.</figcaption>
</figure>

### Appendix G: Suction-Cup Peeling Math

The simplified suction-force model used for preliminary sizing assumes that the effective suction area and pressure differential remain constant. However, under eccentric loading, suction-cup deformation introduces additional complexities that affect the detachment mechanism.

De Wolff (2017, pp. 90–92) investigated peeling resistance using a mechanical loading model and a detachment-force conversion mechanism.

#### G.1 Peeling-Force Model

De Wolff formulated a peeling-force relationship based on the geometry of the loaded structure and the applied gravitational and external forces. One of the expressions presented is:

<div class="legs-equation">\[ F_{\mathrm{peeling},A}=\frac{2l_3\left(F_{\mathrm{gravity}}+F_{\mathrm{pull}}\right)x}{l_2^2} \]</div>

where the geometric parameters are defined by the specific mechanical configuration investigated in the thesis.

This shows that the predicted peeling force depends not only on the applied load but also on the geometry of the attachment structure.

#### G.2 Detachment-Force Conversion

De Wolff further proposed that partial detachment can convert a portion of the original contact area into additional suction area, provided the sealing boundary remains intact. The corresponding additional suction contribution is expressed as:

<div class="legs-equation">\[ F_{\mathrm{conversion}}=A_{\mathrm{contact}}\left(P_{\mathrm{ambient}}-P_{\mathrm{detachment}}\right) \]</div>

Under the model's assumptions, the total suction force during detachment becomes:

<div class="legs-equation">\[ F_{\mathrm{suction}}=A_{\mathrm{pad}}\left(P_{\mathrm{ambient}}-P_{\mathrm{detachment}}\right) \]</div>

The analysis also identifies a second effect: deformation can increase the enclosed suction volume, temporarily changing the internal pressure. This pressure response depends on detachment speed, surface topography and leakage behaviour.

#### G.3 Implications for SoftCrawl

These models show that peeling resistance cannot be determined solely from the initial suction force (*F* = *PA*). A more complete prediction would require information about suction-cup geometry, material characteristics, deformation, effective contact area, pressure evolution and leakage.

Furthermore, the geometry and material properties of SoftCrawl's commercial Festo suction cups differ from the biomimetic device investigated by De Wolff. The model accounts for suction-cup deformation during peeling, where stretching and partial detachment alter the contact and suction areas, but the material's detailed elastic behaviour is not explicitly modelled in these simplified force-conversion equations. Consequently, the equations cannot be directly applied to calculate SoftCrawl's peeling failure load without additional modelling and experimental characterisation. For this reason, experimental load testing was used to evaluate the actual attachment performance under eccentric loading, with particular attention to suction-cup deformation and loss of sealing.

### Appendix H: Suction-Cup Configuration Testing

To investigate the effect of suction-cup spacing on attachment stability under eccentric loading, the distance between the cups was varied and the maximum load before failure was measured.

<table class="styled-table">
  <thead>
    <tr>
      <th style="width: 25%;">Cup spacing</th>
      <th>Failure load</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>23 mm</td>
      <td>4 N</td>
    </tr>
    <tr>
      <td>69 mm</td>
      <td>5 N</td>
    </tr>
    <tr>
      <td>115 mm</td>
      <td>7 N</td>
    </tr>
    <tr>
      <td>161 mm</td>
      <td>10 N</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table H1. Failure load against cup spacing.</p>

Increasing the spacing from 23 mm to 161 mm increased the measured failure load from 4 N to 10 N, a 2.5-fold increase across the tested configurations.

This trend is consistent with the general principle established by Rutkowski et al. (2009) that suction-cup arrangement geometry influences moment resistance. However, the loading conditions differ between the two studies: Rutkowski et al. investigated resistance to axial torque, whereas SoftCrawl's experiments involved eccentric loading on a vertical surface, where suction-cup deformation and peeling were observed.

<figure>
<img src="{{ '/images/legs/image26.png' | relative_url }}" alt="Force versus suction-cup spacing plot">
<figcaption>Figure H1. Failure load versus suction-cup spacing under the tested eccentric loading configuration.</figcaption>
</figure>

### Appendix I: Suction-Cup Oil Testing

Shear tests were conducted at −30 kPa and −80 kPa, with and without oil contamination, to evaluate the effects of vacuum pressure and surface lubrication on suction-cup shear resistance.

<table class="styled-table">
  <thead>
    <tr>
      <th>Vacuum pressure</th>
      <th>Without oil</th>
      <th>With oil</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>−30 kPa</td>
      <td>15.0 N</td>
      <td>6.0 N</td>
    </tr>
    <tr>
      <td>−80 kPa</td>
      <td>21.0 N</td>
      <td>8.6 N</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table I1. Shear resistance with and without oil contamination.</p>

Oil contamination reduced the measured shear resistance by approximately 60% at both vacuum pressures, indicating a consistent proportional reduction over the tested range. However, shear resistance did not increase proportionally with vacuum pressure, suggesting that factors beyond the simplified friction model, such as suction-cup deformation and contact conditions, may influence performance.

Taking *F*<sub>shear,max</sub> from the experimental results and reverse-calculating with the 34.4 mm effective diameter gives the apparent friction coefficient of the oily surface:

<div class="legs-equation">\[
\mu_{app} = \frac{F_{shear,max}}{P A} = \frac{8.6}{80\,000 \times \frac{\pi (0.0344)^2}{4}} \approx 0.116
\]</div>

Assuming two supporting cups contribute equally:

<div class="legs-equation">\[
F_{shear,total} = 2 \times 8.6 = 17.2\ \text{N}
\]</div>

For a robot mass of 750 g and a target safety factor of 2:

<div class="legs-equation">\[
F_{required} = 2 \times 0.75 \times 9.81 = 14.72\ \text{N}
\]</div>

Since 17.2 N > 14.72 N, the estimated two-cup shear capacity exceeds the preliminary sliding requirement.

### Appendix J: Oil Ingestion

Oil contamination was grouped into three illustrative categories (Raschig GmbH, 2018):

<table class="styled-table">
  <thead>
    <tr>
      <th>Type of oil contamination</th>
      <th>Approximate size</th>
      <th>Typical formation / occurrence</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Bulk liquid oil</td>
      <td>≥ 100 µm</td>
      <td>Liquid oil drawn directly into the vacuum line</td>
    </tr>
    <tr>
      <td>Entrained oil droplets</td>
      <td>10–100 µm</td>
      <td>Droplets carried by airflow during suction</td>
    </tr>
    <tr>
      <td>Fine oil mist / aerosol</td>
      <td>1–10 µm</td>
      <td>Fine atomisation caused by high-velocity airflow, turbulence or spraying</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table J1. Illustrative forms of oil contamination and their occurrence; size ranges are not strict boundaries.</p>

<table class="styled-table">
  <thead>
    <tr>
      <th>Protection method</th>
      <th>Advantage</th>
      <th>Limitation</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Liquid-oil separator</td>
      <td>Collects bulk liquid oil</td>
      <td>Additional volume and integration requirements</td>
    </tr>
    <tr>
      <td>Oil-mist coalescing filter</td>
      <td>Captures entrained oil droplets and aerosol mist</td>
      <td>Greater size, cost or maintenance requirements</td>
    </tr>
    <tr>
      <td>Inline vacuum filter</td>
      <td>Compact and straightforward to integrate</td>
      <td>Filtration capability depends on media and contamination type</td>
    </tr>
  </tbody>
</table>
<p class="table-caption">Table J2. Comparison of vacuum-line protection options (SMC Corporation, n.d.-a, n.d.-b, n.d.-c).</p>

---

## References

- AMES Direct. (2025, July 15). *Polyurethane or rubber? What top manufacturing plants choose*. <https://amesdirect.com.au/2025/07/15/polyurethane-or-rubber-what-top-manufacturing-plants-choose/>
- de Wolff, T. (2017). *The design and fabrication of a biomimetic lifting aid* [Master's thesis, University of Twente]. University of Twente Student Theses. <https://essay.utwente.nl/fileshare/file/71802/Wolff%2C%20de_MA_Engineering%20Technology.pdf>
- Festo AG & Co. KG. (2020). *Suction cup VAS-40-1/4-PUR-B (Part No. 1396092)* [Technical data sheet]. <https://docs.rs-online.com/aeed/A700000006937653.pdf>
- Festo. (n.d.). *Basic principles of vacuum technology: Brief overview*. <https://media.festo.com/media/114150_documentation.pdf>
- Goshtasbi, A., & Sadeghi, A. (2023). A bioinspired stiffness tunable sucker for passive adaptation and firm attachment to angular substrates. *Frontiers in Robotics and AI, 10*, Article 1080015. <https://doi.org/10.3389/frobt.2023.1080015>
- Hernandez, A. M., Sandoval, J. A., Yuen, M. C., & Wood, R. J. (2024). Stickiness in shear: Stiffness, shape, and sealing in bioinspired suction cups affect shear performance on diverse surfaces. *Bioinspiration & Biomimetics, 19*(3). <https://doi.org/10.1088/1748-3190/ad2c21>
- He, Y., Pfeifer, P. L., Feng, R., & Li, S. (2026). Controllable passive suction cups with mechanical programmability for soft robotics. *Advanced Functional Materials, 36*(56), Article e75782. <https://doi.org/10.1002/adfm.75782>
- J. Schmalz GmbH. (n.d.). *Suction cup shapes*. <https://www.schmalz.com/en-us/support/know-how/vacuum-knowledge/the-vacuum-system-and-its-components/vacuum-suction-cups/suction-cup-shapes>
- J. Schmalz GmbH. (2016). *Vacuum training-set manual: World of vacuum technology*. <https://pimmedia.schmalz.com/MAM_Library/Dokumente/Bedienungsanleitung/30/3030/303001/30300100961/8171d43fa32f_BAL_30.30.01.00961_en-EN.pdf>
- Kawasaki, S., & Kikuchi, K. (2014). Development of a small legged wall climbing robot with passive suction cups. In *Proceedings of the 3rd International Conference on Design Engineering and Science (ICDES 2014)* (pp. 112–116).
- Mantriota, G., & Messina, A. (2011). Theoretical and experimental study of the performance of flat suction cups in the presence of tangential loads. *Mechanism and Machine Theory, 46*(5), 607–617. <https://doi.org/10.1016/j.mechmachtheory.2011.01.003>
- Raschig GmbH. (2018). *Mass transfer products* (Product Bulletin 101). <https://www.christianberner.fi/globalassets/leverantorer/raschig/dokument/raschig-mass-transfer-products-101.pdf>
- Rutkowski, M. M., Smolinski, P. J., & Miller, M. C. (2009). The geometry of vacuum assisted interface adhesion: Resistance to axial moment. *Vacuum, 83*(5), 869–872. <https://doi.org/10.1016/j.vacuum.2008.09.004>
- SMC Corporation. (n.d.-a). *AMJ: Drain separator for vacuum* [Product specifications]. <https://www.smcusa.com/products/amj-drain-separator-for-vacuum~177107>
- SMC Corporation. (n.d.-b). *AM series: Mist separator* [Product specifications]. <https://www.smcworld.com/products/solutions/en-sg/filter/filter_am.html>
- SMC Corporation. (n.d.-c). *ZFC: In-line air filter with one-touch fitting* [Product specifications]. <https://www.smcusa.com/products/zfc-in-line-air-filter-with-one-touch-fitting~161860>
- Wang, D., Liu, H., Li, Y., Lan, T., Shao, Y., Wei, R., Fu, S., Yi, R., Ren, Y., Ye, S., Zheng, Z., Wang, X., Hu, H., Tian, H., & Shao, J. (2026). Bioinspired dry adhesives: From challenging surface adhesion to controllable release. *Advanced Bionics, 2*(2), 195–217. <https://doi.org/10.1016/j.abs.2026.08.001>
- Wang, L., Ha, K.-H., Rodin, G. J., Liechti, K. M., & Lu, N. (2020). Mechanics of crater-enabled soft dry adhesives: A review. *Frontiers in Mechanical Engineering, 6*, Article 601510. <https://doi.org/10.3389/fmech.2020.601510>
- Yuan, Z., Ji, H., Huang, K., Chen, F., & Gu, G. (2026). Multimodal locomotion of soft robots. *Advanced Intelligent Systems, 8*(2), Article e202500782. <https://doi.org/10.1002/aisy.202500782>
- Zhu, J., Zhu, Y., & Zhang, P. (2024). Review of advancements in wall climbing robot techniques. *Franklin Open, 8*, Article 100148. <https://doi.org/10.1016/j.fraope.2024.100148>

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
