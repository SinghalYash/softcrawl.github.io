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

<h2 class="section-title">How to use this website</h2>
<p class="section-lead">This site holds SoftCrawl's interim report, split into short pages. Pick where you want to go.</p>

<div class="card-grid">
  <a class="subsystem-card orange" href="{{ '/about/' | relative_url }}"><span class="tag">ABOUT</span><h3>The project at a glance</h3><p>The problem, the value we add and the system in one page. Start here if you are new to SoftCrawl.</p></a>
  <a class="subsystem-card orange time" href="{{ '/report/' | relative_url }}"><span class="tag">REPORT</span><h3>The interim report</h3><p>The full technical write-up, one page per section, with figures, tables and test results.</p></a>
  <a class="subsystem-card orange money" href="{{ '/contact/' | relative_url }}"><span class="tag">CONTACT</span><h3>The team</h3><p>Who worked on what, and how to reach us.</p></a>
</div>

<h2 class="section-title">Where are things</h2>
<p class="section-lead">Each report section has its own page. Click a name to jump straight there.</p>

| Report section | What you will find there |
|----------------|--------------------------|
| [Context]({{ '/report/context/' | relative_url }}) | The fuel-tank environment, current inspection, stakeholders, existing technologies and system requirements |
| [Robot Body]({{ '/report/body/' | relative_url }}) | The Kresling origami actuator: concept selection, bending model, prototypes V1–V3 and tests |
| [Robot Legs]({{ '/report/legs/' | relative_url }}) | Suction adhesion: passive and active cups, payload and peeling tests, oil contamination |
| [Electronic hardware]({{ '/report/electronics/' | relative_url }}) | Valves, pumps, microcontroller and power |
| [Next Steps]({{ '/report/next-steps/' | relative_url }}) | What are some of our current ideas to tackle future problems |
| [Project Status]({{ '/report/status/' | relative_url }}) | Where are we now |

<h2 class="section-title">Getting around a report page</h2>
<p class="section-lead">Every report page is laid out the same way.</p>

<div class="card-grid">
  <div class="feature-card"><span class="tag">SIDEBAR</span><h3>Flight plan</h3><p>The list on the left shows every section. A small plane marks the page you are on. On a phone it sits above the page.</p></div>
  <div class="feature-card"><span class="tag">TOP</span><h3>Key numbers first</h3><p>Most pages open with a row of headline results, so you see the outcome before the detail.</p></div>
  <div class="feature-card"><span class="tag">BOTTOM</span><h3>Summary and next page</h3><p>Each page ends with Interim Outcomes and references, then a link to the next section.</p></div>
</div>

<!-- <h2 class="section-title">What the coloured boxes mean</h2>
<p class="section-lead">You will see these boxes throughout the report.</p> -->

<!-- <div class="callout"><p>Background or a point worth keeping in mind, such as a design implication.</p></div>
<div class="callout warning"><p>A limitation, assumption or caveat. Read these before relying on a number.</p></div>
<div class="callout result"><p>A key finding or conclusion from testing.</p></div>

<h2 class="section-title">Short on time?</h2>
<p class="section-lead">Pick a reading path.</p>

<div class="stat-row">
  <div class="stat"><span class="value">5 min</span><span class="label">About page + Interim Outcomes</span></div>
  <div class="stat"><span class="value">20 min</span><span class="label">Context, Body and Legs in full</span></div>
  <div class="stat"><span class="value">Deep dive</span><span class="label">Design models and test data</span></div>
</div> -->