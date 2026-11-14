---
layout: page
title: About
permalink: /about/
---

<p class="section-lead">SoftCrawl is a soft robot that climbs around inside aircraft fuel tanks, so inspectors can see hard-to-reach structures without crawling in themselves.</p>

<h2 class="section-title">What value can we add</h2>
<p class="section-lead">Fewer people in the tank, less time on the ground, lower cost per inspection.</p>

<div class="card-grid">
  <div class="value-card">
    <span class="card-icon"><svg viewBox="0 0 24 24" fill="none" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M14.7 6.3a1 1 0 0 0 0 1.4l1.6 1.6a1 1 0 0 0 1.4 0l3.77-3.77a6 6 0 0 1-7.94 7.94l-6.91 6.91a2.12 2.12 0 0 1-3-3l6.91-6.91a6 6 0 0 1 7.94-7.94l-3.76 3.76z"/></svg></span>
    <h3>Safety</h3>
    <p class="before">3 specialists per inspection</p>
    <p class="arrow">↓</p>
    <p class="after">Reduced number of operators</p>
  </div>
  <div class="value-card time">
    <span class="card-icon"><svg viewBox="0 0 24 24" fill="none" stroke-width="2" stroke-linecap="round"><circle cx="12" cy="12" r="10"/><path d="M12 6v6l4 2"/></svg></span>
    <h3>Time</h3>
    <p class="before">High downtime</p>
    <p class="arrow">↓</p>
    <p class="after">Low downtime</p>
  </div>
  <div class="value-card money">
    <span class="card-icon"><svg viewBox="0 0 24 24" fill="none" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M9 3h6l-1.5 4h-3z"/><path d="M10.5 7C6 9 4 13 4 16a5 5 0 0 0 5 5h6a5 5 0 0 0 5-5c0-3-2-7-6.5-9"/></svg></span>
    <h3>Money</h3>
    <p class="before">A grounded A350-900: $37.5k/day in lease alone</p>
    <p class="arrow">↓</p>
    <p class="after">4–5 days avoided, $150k–$750k saved per event</p>
  </div>
</div>

<h2 class="section-title">The problem</h2>
<p class="section-lead">Fuel-tank inspection is slow, cramped and hazardous.</p>

Aircraft fuel-tank inspection exposes maintenance personnel to hazardous confined environments while requiring time-consuming and labour-intensive procedures. The ribs, spars and stringers inside the wing also limit how much of the tank can be reached, which adds to aircraft downtime.

<div class="stat-row">
  <div class="stat"><span class="value">3</span><span class="label">Specialists per inspection</span></div>
  <div class="stat"><span class="value">$37.5k</span><span class="label">Lease cost per grounded day</span></div>
  <div class="stat"><span class="value">4–5</span><span class="label">Days of downtime</span></div>
</div>

> SoftCrawl investigates whether a compact, remotely operated soft robot can improve inspection access while reducing the need for people to enter the tank.

<h2 class="section-title">Why a soft robot?</h2>
<p class="section-lead">Soft bodies bend around obstacles instead of fighting them.</p>

Soft robots are made of compliant materials that deform around obstacles and contact forces, which suits a cramped tank full of irregular surfaces. Of the ways soft robots move (crawling, climbing, growing and swimming), two matter most here: crawling covers the tank floor, and climbing reaches the walls and the openings between bays.

<div class="callout">
<p>All sensitive electronics and the vacuum pump stay outside the tank. The robot is driven only by air lines, which keeps sparks and electrical hazards away from fuel vapour.</p>
</div>

<h2 class="section-title">The system</h2>
<p class="section-lead">Three parts work together: a body that moves, legs that grip and a payload that looks.</p>

<div class="card-grid">
  <div class="feature-card"><h3>Soft pneumatic body</h3><p>Three 3D-printed Kresling origami actuators in a triangle. They contract by 56.8% and bend the body to step, climb and turn corners.</p></div>
  <div class="feature-card"><h3>Adhesion</h3><p>Vacuum suction cups grip oily aluminium walls and release on command through solenoid valves.</p></div>
  <div class="feature-card"><h3>Inspection payload</h3><p>A camera and sensors to find sealant failure, structural damage and cracks.</p></div>
</div>

<div class="stat-row">
  <div class="stat"><span class="value">0</span><span class="label">Humans in tank (goal)</span></div>
  <div class="stat"><span class="value">2 mm/s</span><span class="label">Climb speed</span></div>
  <div class="stat"><span class="value">506 g</span><span class="label">Body mass</span></div>
  <div class="stat"><span class="value">−80 kPa</span><span class="label">Suction vacuum</span></div>
</div>

<h2 class="section-title">Our approach</h2>
<p class="section-lead">The requirements every part of the design is checked against.</p>

| Requirement | Target | Why it matters |
|-------------|--------|----------------|
| Fits the access hole | Within 300 × 200 mm | Tanks are entered through small maintenance panels |
| Spark-free | No electronics inside the tank | Fuel vapour |
| Climbs walls | Holds the 0.75 kg robot with a safety factor of 2 | Inspection points are on vertical surfaces |
| Turns corners | 90° surface transitions | Moving between floor and walls |
| Grips when oily | Adheres on a thin oil film | Residual fuel stays on surfaces |

<h2 class="section-title">Subsystems</h2>
<p class="section-lead">Explore each part of the interim report.</p>

<div class="card-grid">
  <a class="subsystem-card" href="{{ '/report/context/' | relative_url }}"><span class="tag">SEC-01</span><h3>Context</h3><p>Fuel-tank environment, problem and requirements.</p></a>
  <a class="subsystem-card" href="{{ '/report/structure/' | relative_url }}"><span class="tag">SEC-02</span><h3>Robot Body</h3><p>Kresling actuators, bending model and tests.</p></a>
  <a class="subsystem-card" href="{{ '/report/legs/' | relative_url }}"><span class="tag">SEC-03</span><h3>Robot Legs</h3><p>Suction cups, payload and oil testing.</p></a>
  <a class="subsystem-card" href="{{ '/report/electronics/' | relative_url }}"><span class="tag">SEC-04</span><h3>Electronic hardware</h3><p>Valves, pumps, MCU and power.</p></a>
