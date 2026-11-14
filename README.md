# SoftCrawl

**🌐 Live site: https://singhalyash.github.io/softcrawl.github.io/**

A soft pneumatic climbing robot that crawls inside aircraft fuel tanks, so inspectors don't have to.

This repository holds the website for **SoftCrawl** (ASI-404, National University of Singapore). The site presents the project's interim report as a set of short, linked pages covering the problem, the robot's body and legs, the electronics, test results and next steps.

## Contributors

| Name | Subsystem |
|------|-----------|
| Aakash Jayadeep | Robot Body |
| Akash Mukherjee | Robot Legs |
| Avaneesh Kalyanasundaram | Electronics |
| Mohit Kulkarni | Robot Legs |
| Yash Singhal | Robot Body |

Contact details for each team member are on the site's [Contact page](https://singhalyash.github.io/softcrawl.github.io/contact/).

## How to use the website

The site has four main pages, all reachable from the menu in the top bar: **Home**, **About**, **Report** and **Contact**.

**New to SoftCrawl?** Start with **About**. It explains the problem, why we chose a soft robot and how the system fits together, all on one page. Then open the **Report** for the technical detail.

**Want the full write-up?** Go to **Report**. It shows a card for each of the six report sections. Click a card or use the sidebar to open a section.

**Looking for a specific result?** Use the [Where to find what](#where-to-find-what) table below to jump straight to the right page.

### Getting around a report page

Every report page has the same layout:

- **"Flight plan" sidebar (left).** Lists every report section in order. A small plane marks the page you are on. On a phone, the sidebar sits above the page instead.
- **"On this page" list.** Below the flight plan, this lists the headings of the current page. Click one to jump to it.
- **Key numbers first.** Most pages open with a row of headline results, so you see the outcome before the detail.
- **Coloured boxes.** Callout boxes flag notes and caveats. Read the warning boxes before relying on a number.
- **Videos and interactive figures.** Test videos play inline. The 3D wall-crossing figure on Next Steps can be dragged to rotate.
- **End of page.** Each page ends with its outcomes, references and appendices (detailed calculations, test data, comparisons), followed by a link to the next section.

### Suggested reading paths

| Time you have | Read |
|---------------|------|
| 5 minutes | About page, then the Project Status page |
| 20 minutes | Context, Robot Body and Robot Legs (skip the appendices) |
| Deep dive | Every section, including appendices with design models and raw test data |

## What is where

### Site map

| Page | URL path | What's on it |
|------|----------|--------------|
| Home | `/` | Introduction, links to every section, and a short guide to the site |
| About | `/about/` | The value SoftCrawl adds, the problem, why a soft robot, the system and our approach, subsystems overview |
| Report | `/report/` | Cards linking to all six report sections |
| SEC-01 Context | `/report/context/` | The fuel-tank environment and why inspecting it is hard |
| SEC-02 Robot Body | `/report/body/` | The Kresling origami actuator that bends and extends the robot |
| SEC-03 Robot Legs | `/report/legs/` | The suction cups that let the robot stick to tank walls |
| SEC-04 Electronic Hardware | `/report/electronics/` | Valves, pumps, microcontroller, power and pressure control |
| SEC-05 Next Steps | `/report/next-steps/` | Future requirements and how the robot could pass through openings between tank bays |
| SEC-06 Project Status | `/report/status/` | Crawling and climbing test results and upcoming milestones |
| Contact | `/contact/` | Team photos, roles, emails and LinkedIn profiles |

### Where to find what

| If you want… | Go to |
|--------------|-------|
| How fuel tanks are inspected today and what goes wrong | Context, §1.2–1.4 |
| Who the users and stakeholders are, and the proposed user journey | Context, §1.6–1.8 |
| How SoftCrawl compares with existing inspection technologies | Context, §1.9 |
| The system requirements and overall architecture | Context, §1.11 |
| How the body actuator was chosen | Robot Body, §2.2 and Appendix A |
| The Kresling unit design and bending model | Robot Body, §2.3–2.4 |
| Body prototypes V1–V3, with videos | Robot Body, §2.5 and Appendix C (paper prototype) |
| Body test results and planned improvements | Robot Body, §2.7–2.8 |
| Why suction was chosen for the legs | Robot Legs, §3.1–3.2 and Appendix C |
| Suction-cup sizing calculations | Robot Legs, §3.6 and Appendix E |
| Payload, peeling and oil-contamination tests | Robot Legs, §3.8–3.11 and Appendices F–J |
| The pneumatic and electronics architecture | Electronic Hardware, §4.2 and Appendix B (schematic) |
| The pressure control strategy and controller code | Electronic Hardware, §4.3 and Appendix D |
| Pressure control test results | Electronic Hardware, §4.5 and Appendices C, E, G |
| How the robot could cross between tank bays (interactive 3D) | Next Steps, §5.2 |
| Videos of the robot crawling and climbing | Project Status, §6.1 |
| What the team plans to do next, and when | Project Status, §6.2 |
| Who worked on what, and how to reach them | Contact |

## Repository structure

```
.
├── _config.yml          # Jekyll site settings (title, theme, baseurl, header pages)
├── _layouts/
│   └── report.html      # Report layout with the "Flight plan" sidebar and in-page TOC
├── assets/
│   ├── main.scss        # Site styles (built on the Minima theme)
│   └── toc.js           # Builds the "On this page" table of contents
├── index.md             # Home page
├── about.md             # About page
├── contact.md           # Team / contact page
├── report/              # One Markdown file per report section
├── images/              # Figures, grouped by section (context, legs, electronics, team, …)
├── videos/              # Test and prototype videos
├── build_and_serve.py   # Optional Jekyll-free local preview script
├── Gemfile              # Ruby dependencies (github-pages gem)
└── Gemfile.lock
```

## Running the site locally

### Option 1: Jekyll (matches GitHub Pages)

Requires Ruby and Bundler.

```bash
bundle install
bundle exec jekyll serve
```

Then open `http://localhost:4000/softcrawl.github.io/`.

### Option 2: Python preview (no Ruby needed)

`build_and_serve.py` renders the Markdown pages into `_site/` and serves them on port 8000.

```bash
pip install pyyaml markdown libsass
python build_and_serve.py              # build and serve at http://localhost:8000/
python build_and_serve.py --build-only # build only
```

This is a quick preview only. It approximates the Jekyll layouts and ignores `baseurl`, so always check the final result with Jekyll or on the live site.

## Adding a report page

Create a Markdown file in `report/` with this front matter, and it will appear automatically in the report sidebar:

```yaml
---
layout: report
title: My New Section
group: Interim       # sidebar heading the page sits under
code: SEC-07
nav_order: 7         # position in the sidebar
permalink: /report/my-new-section/
---
```

## Deployment

The site is built and hosted by GitHub Pages from this repository using the `github-pages` gem and the Minima theme. Because it is a project site, `baseurl` in `_config.yml` is set to `/softcrawl.github.io`. Always link internally with `{{ '/path/' | relative_url }}` so links keep working under that path.

`_site/` is build output and is ignored by Git.
