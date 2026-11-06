---
layout: default
title: Home
---

<section class="hero">
  <span class="hero-plane" aria-hidden="true"></span>
  <h1 class="hero-title">Soft<br>Crawl</h1>
  <p class="hero-sub">A soft pneumatic climbing robot that crawls inside aircraft fuel tanks, so inspectors don't have to.</p>
  <a class="btn" href="{{ '/report/' | relative_url }}">Read the report</a>
  <a class="btn btn-ghost" href="{{ '/about/' | relative_url }}">Why we built it</a>
  <p class="hero-meta">ASI-404 · Aakash, Akash, Avaneesh, Mohit, Yash</p>
</section>

<h2 class="section-title">What value can we add</h2>
<p class="section-lead">Replace with your one-line pitch.</p>

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

<h2 class="section-title">The system</h2>
<p class="section-lead">Replace these with your real features.</p>

<div class="card-grid">
  <div class="feature-card"><span class="tag">SYS-01</span><h3>Soft pneumatic body</h3><p>Describe the actuators and how the robot moves.</p></div>
  <div class="feature-card"><span class="tag">SYS-02</span><h3>Adhesion</h3><p>How it stays on vertical and curved tank walls.</p></div>
  <div class="feature-card"><span class="tag">SYS-03</span><h3>Inspection payload</h3><p>Camera and sensors used to detect defects.</p></div>
</div>

<div class="stat-row">
  <div class="stat"><span class="value">0</span><span class="label">Humans in tank</span></div>
  <div class="stat"><span class="value">XX cm/s</span><span class="label">Climb speed</span></div>
  <div class="stat"><span class="value">XX g</span><span class="label">Robot mass</span></div>
  <div class="stat"><span class="value">XX kPa</span><span class="label">Working pressure</span></div>
</div>

<h2 class="section-title">Subsystems</h2>
<p class="section-lead">Explore each part of the interim report.</p>

<div class="card-grid four">
  <a class="subsystem-card" href="{{ '/report/structure/' | relative_url }}"><span class="tag">SYS-01</span><h3>Robot structure</h3><p>Body, actuators and materials.</p></a>
  <a class="subsystem-card" href="{{ '/report/electronics/' | relative_url }}"><span class="tag">SYS-02</span><h3>Electronic hardware</h3><p>Valves, pumps, MCU and power.</p></a>
  <a class="subsystem-card" href="{{ '/report/controls/' | relative_url }}"><span class="tag">SYS-03</span><h3>Controls</h3><p>Gait sequencing and pressure control.</p></a>
  <a class="subsystem-card" href="{{ '/report/perception/' | relative_url }}"><span class="tag">SYS-04</span><h3>Perception</h3><p>Camera, localisation and defect detection.</p></a>
</div>
