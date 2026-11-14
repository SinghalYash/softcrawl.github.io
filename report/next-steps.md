---
layout: report
title: Next Steps for SoftCrawl
group: Interim
code: SEC-05
nav_order: 5
permalink: /report/next-steps/
---

## Functional Requirements for Future Development

One of the key functional requirements that has not yet been addressed in the interim prototype stages is cross-chamber locomotion and environmental constraints:

<table style="width: 100%; border-collapse: collapse; border: 1.5px solid #000; background: #fff; margin: 24px 0; font-size: 15px;">
  <thead>
    <tr>
      <th style="width: 25%; text-align: center; font-weight: 700; color: #000; border: 1.5px solid #000; padding: 14px 16px; background: #fff;">Category</th>
      <th style="text-align: center; font-weight: 700; color: #000; border: 1.5px solid #000; padding: 14px 16px; background: #fff;">Requirement</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="2" style="border: 1.5px solid #000; padding: 12px 16px; vertical-align: middle; color: #000;">Geometry</td>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">Fit within a 300 × 200 mm access opening</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">Actuator never expands beyond the body, avoiding snags</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000; padding: 12px 16px; vertical-align: middle; color: #000;">Electronics</td>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">No electronics in the tank except camera and light</td>
    </tr>
    <tr>
      <td rowspan="2" style="border: 1.5px solid #000; padding: 12px 16px; vertical-align: middle; color: #000;">Adhesion</td>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">Actuate with a 0.75 kg robot mass with safety factor 2 on vertical surfaces</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">Adhesion on thin oil film over aluminium sheet</td>
    </tr>
    <tr>
      <td rowspan="3" style="border: 1.5px solid #000; padding: 12px 16px; vertical-align: middle; color: #000;">Locomotion</td>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">Control each leg individually</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">Climb 90 degree corners</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000; padding: 12px 16px; background-color: #55ff22; color: #000;">Pass through 30cm x 30cm access hole to next fuel tank chamber</td>
    </tr>
    <tr>
      <td rowspan="2" style="border: 1.5px solid #000; padding: 12px 16px; vertical-align: middle; color: #000;">Material compatibility</td>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">No damage to fuel tank internal surfaces</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000; padding: 12px 16px; color: #000;">No swelling/damage due to prolonged oil exposure</td>
    </tr>
  </tbody>
</table>


<div class="callout warning">
<p><strong>Identified Design Gap.</strong> While locomotion on open surfaces has been validated, traversing between adjacent fuel-tank chambers through 30 × 30 cm rib access openings remains an unaddressed limitation across all current subsystems. Enabling cross-chamber mobility is the primary objective for the next development phase.</p>
</div>

## Traversal Concept: Double-Sided Suction

To overcome this limitation, a potential solution involves incorporating suction cups on both sides of the robot body. 

During traversal, the robot bends through the opening, allowing the suction cups on the opposite side to attach to the adjacent wall. Once adhesion is established, the robot contracts to pull its body through the opening before continuing locomotion.

This concept remains to be developed and experimentally validated as part of next semester's work.

### Traversal Sequence

<figure>
<img src="{{ '/images/nextsteps/image1.png' | relative_url }}" alt="Configuration 1: Before crossing the hole">
<figcaption>Configuration 1 — Initial robot position before entering the chamber access opening.</figcaption>
</figure>

<figure>
<img src="{{ '/images/nextsteps/image2.png' | relative_url }}" alt="Configuration 2: Crossing the hole">
<figcaption>Configuration 2 — Traversal through opening using double-sided suction adhesion.</figcaption>
</figure>

<figure>
<img src="{{ '/images/nextsteps/image3.png' | relative_url }}" alt="Configuration 3: After crossing the hole">
<figcaption>Configuration 3 — Body contraction through opening and resumption of crawling locomotion.</figcaption>
</figure>
