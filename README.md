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

Contact details for each team member are on the site's [Contact page](https://YOUR-GITHUB-USERNAME.github.io/softcrawl.github.io/contact/).

## What's on the site

| Page | Path | Contents |
|------|------|----------|
| Home | `/` | Project overview and how to navigate the site |
| About | `/about/` | The problem, the value SoftCrawl adds, and the system at a glance |
| Report | `/report/` | Index of the interim report sections |
| Context (SEC-01) | `/report/context/` | Fuel-tank environment, current inspection practice, stakeholders, existing technologies, system requirements |
| Robot Body (SEC-02) | `/report/body/` | Kresling origami actuator: concept selection, bending model, prototypes V1–V3 and tests |
| Robot Legs (SEC-03) | `/report/legs/` | Suction adhesion: passive and active cups, payload and peeling tests, oil contamination |
| Electronic Hardware (SEC-04) | `/report/electronics/` | Valves, pumps, microcontroller and power |
| Next Steps (SEC-05) | `/report/next-steps/` | Chamber traversal and future work |
| Project Status (SEC-06) | `/report/status/` | Crawling and climbing tests, upcoming milestones |
| Contact | `/contact/` | The team and how to reach us |

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
