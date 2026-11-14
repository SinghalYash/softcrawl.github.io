---
layout: report
title: Project Status and Milestones
group: Interim
code: SEC-06
nav_order: 6
permalink: /report/status/
---

## Current Status: Where We Are Now

The Robot Body subsystem has completed its initial design and proof-of-concept phase. To date, the project has achieved the following milestones:

### 1. Horizontal Crawling Demonstration

Successfully demonstrated horizontal locomotion, achieving **3 cm of forward displacement per stroke**. The effective stroke is currently limited by passive suction cup friction dragging against the floor, as synchronized inchworm gait control (which dynamically bends the body to lift the feet off the surface) has not yet been implemented.

<figure>
  <video id="crawlVideo" controls autoplay loop muted playsinline style="width: 100%; max-height: 440px; border-radius: 8px; background: #000;">
    <source src="{{ '/videos/crawl.mp4' | relative_url }}" type="video/mp4">
    Your browser does not support the video tag.
  </video>
  <figcaption>Horizontal crawling demonstration (1.5× playback speed) showing 3 cm displacement per stroke.</figcaption>
</figure>
<script>
  (function() {
    var v = document.getElementById("crawlVideo");
    if (v) {
      v.playbackRate = 1.5;
      v.addEventListener("play", function() { v.playbackRate = 1.5; });
    }
  })();
</script>

### 2. Vertical Climbing Feasibility

Validated initial vertical climbing capability on vertical surfaces, confirming that the soft spine can transfer sufficient adhesion forces to sustain and advance the vehicle against gravity. Executing continuous crawl-to-climb transitions will be carried out in the next semester.

<figure>
  <video controls autoplay loop muted playsinline style="width: 100%; max-height: 440px; border-radius: 8px; background: #000;">
    <source src="{{ '/videos/climb.mp4' | relative_url }}" type="video/mp4">
    Your browser does not support the video tag.
  </video>
  <figcaption>Vertical climbing feasibility test validating soft spine adhesion against gravity.</figcaption>
</figure>

## Project Milestones: What We Plan to Do

The developmental roadmap for subsequent phases encompasses synchronized inchworm locomotion, automated gait sequencing, cross-chamber opening traversal, and fuel-tank environment testing:

<figure style="text-align: center;">
  <a href="{{ '/images/status/milestones.png' | relative_url }}" target="_blank" title="Click to open full high-resolution roadmap">
    <img src="{{ '/images/status/milestones.png' | relative_url }}" alt="Project Milestones Roadmap" style="width: 100%; max-height: none; height: auto; border-radius: 8px; box-shadow: 0 4px 16px rgba(14,53,87,0.12);">
  </a>
  <figcaption>Project milestone roadmap and scheduled deliverables for next semester. <em>(Click image to view in full high resolution)</em></figcaption>
</figure>
