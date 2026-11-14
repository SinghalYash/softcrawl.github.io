---
layout: report
title: Next Steps for SoftCrawl
group: Interim
code: SEC-05
nav_order: 5
permalink: /report/next-steps/
---

## 5. Next Steps for SoftCrawl

### 5.1 Functional Requirements for Future Development

One of the key functional requirements that has not yet been addressed in the interim prototype stages is cross-chamber locomotion and environmental constraints:

<style>
  .req-table {
    width: 100%;
    border-collapse: collapse;
    border: 1.5px solid #000 !important;
    margin: 24px 0;
    font-size: 15px;
    background: #ffffff !important;
    box-shadow: none !important;
  }
  .req-table th {
    background: #0e3557 !important;
    color: #f6eedc !important;
    font-weight: 700;
    text-align: center;
    border: 1.5px solid #000000 !important;
    padding: 14px 16px;
    letter-spacing: 0.05em !important;
  }
  .req-table td {
    background: #ffffff !important;
    color: #000000 !important;
    border: 1.5px solid #000000 !important;
    padding: 12px 16px;
  }
  .req-table tr:nth-child(even) td {
    background: #ffffff !important;
  }
  .req-table td.highlight-target {
    background-color: #55ff22 !important;
    color: #000000 !important;
  }
  .callout-note {
    position: relative;
    border-radius: 12px;
    padding: 18px 22px;
    margin: 28px 0;
    background: rgba(217, 120, 24, 0.08);
    border-left: 6px solid #d97818;
  }
  .callout-note .note-label {
    display: block;
    font-family: "Poppins", "Segoe UI", sans-serif;
    font-size: 14px;
    font-weight: 700;
    color: #c65400;
    margin-bottom: 6px;
    letter-spacing: 0.02em;
  }
  .callout-note p {
    margin: 0;
    font-size: 15px;
    line-height: 1.6;
    color: #1b2733;
  }
</style>

<table class="req-table" style="width: 100%; border-collapse: collapse; border: 1.5px solid #000 !important; margin: 24px 0; font-size: 15px; background: #ffffff !important;">
  <thead>
    <tr>
      <th style="width: 25%; text-align: center; font-weight: 700; color: #f6eedc !important; border: 1.5px solid #000 !important; padding: 14px 16px; background: #0e3557 !important; letter-spacing: 0.05em;">Category</th>
      <th style="text-align: center; font-weight: 700; color: #f6eedc !important; border: 1.5px solid #000 !important; padding: 14px 16px; background: #0e3557 !important; letter-spacing: 0.05em;">Requirement</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="2" style="border: 1.5px solid #000 !important; padding: 12px 16px; vertical-align: middle; color: #000; background: #ffffff !important;">Geometry</td>
      <td style="border: 1.5px solid #000 !important; padding: 12px 16px; color: #000; background: #ffffff !important;">Fit within a 300 × 200 mm access opening</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000 !important; padding: 12px 16px; color: #000; background: #ffffff !important;">Actuator never expands beyond the body, avoiding snags</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000 !important; padding: 12px 16px; vertical-align: middle; color: #000; background: #ffffff !important;">Electronics</td>
      <td style="border: 1.5px solid #000 !important; padding: 12px 16px; color: #000; background: #ffffff !important;">No electronics in the tank except camera and light</td>
    </tr>
    <tr>
      <td rowspan="2" style="border: 1.5px solid #000 !important; padding: 12px 16px; vertical-align: middle; color: #000; background: #ffffff !important;">Adhesion</td>
      <td style="border: 1.5px solid #000 !important; padding: 12px 16px; color: #000; background: #ffffff !important;">Actuate with a 0.75 kg robot mass with safety factor 2 on vertical surfaces</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000 !important; padding: 12px 16px; color: #000; background: #ffffff !important;">Adhesion on thin oil film over aluminium sheet</td>
    </tr>
    <tr>
      <td rowspan="3" style="border: 1.5px solid #000 !important; padding: 12px 16px; vertical-align: middle; color: #000; background: #ffffff !important;">Locomotion</td>
      <td style="border: 1.5px solid #000 !important; padding: 12px 16px; color: #000; background: #ffffff !important;">Control each leg individually</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000 !important; padding: 12px 16px; color: #000; background: #ffffff !important;">Climb 90 degree corners</td>
    </tr>
    <tr>
      <td class="highlight-target" style="border: 1.5px solid #000 !important; padding: 12px 16px; background-color: #55ff22 !important; color: #000 !important;">Pass through 30cm x 30cm access hole to next fuel tank chamber</td>
    </tr>
    <tr>
      <td rowspan="2" style="border: 1.5px solid #000 !important; padding: 12px 16px; vertical-align: middle; color: #000; background: #ffffff !important;">Material compatibility</td>
      <td style="border: 1.5px solid #000 !important; padding: 12px 16px; color: #000; background: #ffffff !important;">No damage to fuel tank internal surfaces</td>
    </tr>
    <tr>
      <td style="border: 1.5px solid #000 !important; padding: 12px 16px; color: #000; background: #ffffff !important;">No swelling/damage due to prolonged oil exposure</td>
    </tr>
  </tbody>
</table>


<div class="callout-note">
  <span class="note-label">Note:</span>
  <p><strong>Identified Design Gap.</strong> While locomotion on open surfaces has been validated, traversing between adjacent fuel-tank chambers through 30 × 30 cm rib access openings remains an unaddressed limitation across all current subsystems. Enabling cross-chamber mobility is the primary objective for the next development phase.</p>
</div>

### 5.2 Traversal Concept: Double-Sided Suction

To overcome this limitation, a potential solution involves incorporating suction cups on both sides of the robot body. 

During traversal, the robot bends through the opening, allowing the suction cups on the opposite side to attach to the adjacent wall. Once adhesion is established, the robot contracts to pull its body through the opening before continuing locomotion.

This concept remains to be developed and experimentally validated as part of next semester's work.

#### 5.2.1 Traversal Sequence

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
