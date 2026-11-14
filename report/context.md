---
layout: report
title: Context
group: Interim
code: SEC-01
nav_order: 1
permalink: /report/context/
---

## 1. Context and Problem Definition

### 1.1 Aircraft Fuel-Tank Environment

Aircraft fuel tanks are essential components of the aircraft fuel storage and distribution systems. In commercial aircraft, fuel is commonly stored within the wings and centre wing box, where internal structural components also contribute to the aircraft's load-bearing capability.

Unlike conventional storage tanks, aircraft wing tanks contain complex internal structures, including ribs, spars, stringers, pipes and sealant joints. These components divide the interior into restricted compartments, creating challenges for inspection and maintenance.

Access is typically provided through maintenance panels located along the aircraft structure. For large commercial aircraft such as the Airbus A350, these access points may be several metres above ground level, introducing additional requirements for maintenance equipment and personnel (Airbus, 2024).

The confined geometry, restricted access and presence of residual fuel make aircraft fuel tanks a challenging environment for inspection.

<figure>
<img src="{{ '/images/context/image1.png' | relative_url }}" alt="Aircraft fuel-tank layout">
<figcaption>Figure 1. Aircraft fuel-tank layout and access locations (adapted from Airbus, 2024).</figcaption>
</figure>

### 1.2 Current Inspection Methods

Conventional aircraft fuel-tank inspection frequently requires maintenance personnel to enter the tank through access openings.

Before entry, the tank must undergo appropriate safety preparation, including fuel removal where required, ventilation, atmospheric testing and confined-space entry procedures.

Once inside, technicians manually inspect internal structures using visual inspection equipment and other nondestructive testing methods.

The confined working environment limits movement and requires personnel to navigate around structural obstacles while avoiding damage to sensitive components.

These conditions make inspection physically demanding and introduce occupational safety concerns associated with fuel vapours, restricted access and confined-space work.

<figure>
<img src="{{ '/images/context/image2.png' | relative_url }}" alt="Technician inside a fuel tank">
<figcaption>Figure 2. Technician performing maintenance inside an aircraft fuel tank (Shanks, 2018).</figcaption>
</figure>

### 1.3 What Are We Looking For?

Aircraft fuel-tank inspection aims to identify defects that may affect structural integrity, fuel containment and operational safety. Three important categories of defects are considered in this project:

#### 1.3.1 Sealant Failure

Aircraft fuel tanks rely on sealants to prevent fuel leakage through structural joints, fasteners and interfaces. Over time, sealant deterioration, cracking or separation may compromise the integrity of these joints, resulting in fuel leakage and maintenance requirements.

#### 1.3.2 Structural and Composite Damage

Aircraft structures may experience damage caused by impact, fatigue or environmental exposure. Such damage may be difficult to identify through conventional visual inspection, particularly when it occurs in restricted locations or beneath the surface. Where composite structures are present, barely visible impact damage and delamination may require specialised nondestructive inspection methods.

#### 1.3.3 Crack Propagation

Repeated mechanical loading can initiate and propagate cracks in structural components. Detecting visible cracks and other signs of structural deterioration is important for identifying locations requiring further inspection or maintenance.

<figure>
<img src="{{ '/images/context/image3.png' | relative_url }}" alt="Sealant failure">
<figcaption>Figure 3. Representative aircraft defects: sealant failure, structural damage and crack propagation (Polimeno &amp; Meo, 2009; Evans, 2010; Federal Aviation Administration, 2025).</figcaption>
</figure>

> **Design implication:** SoftCrawl must ultimately support inspection of internal structural surfaces and sealant joints. The initial platform focuses on mobility and access; its final defect-detection capabilities will depend on the inspection sensors integrated in subsequent development.

### 1.4 Problems with Conventional Inspection

The challenges associated with conventional aircraft fuel-tank inspection can be divided into three categories.

#### 1.4.1 Safety Challenges

Technicians may be exposed to hazardous confined-space conditions, including residual fuel vapours, restricted ventilation and limited emergency access. These risks necessitate strict safety procedures and personnel monitoring.

#### 1.4.2 Operational Challenges

The complex internal geometry restricts technician movement and makes certain inspection locations difficult to access. Inspection can also require substantial preparation, including tank access, atmospheric testing and equipment setup. These activities contribute to labour-intensive maintenance procedures.

#### 1.4.3 Business Impact

Aircraft maintenance can result in periods during which the aircraft is unavailable for commercial operations. Extended downtime may affect airline schedules, maintenance expenditure and aircraft utilisation. Consequently, reducing the need for personnel to enter confined fuel-tank regions could provide both operational and economic benefits.

#### 1.4.4 Problem Statement

> Aircraft fuel-tank inspection exposes maintenance personnel to hazardous confined environments while requiring time-consuming and labour-intensive procedures. The restricted geometry also limits inspection accessibility, contributing to operational inefficiencies and aircraft downtime.
>
> SoftCrawl seeks to investigate whether a compact, remotely operated soft robotic platform can improve inspection accessibility while reducing the need for human entry.

### 1.5 Value Proposition

The proposed value of SoftCrawl is evaluated across three dimensions: safety, time and cost (Aviation Pros, 2012; FL Technics, 2026; Heilemann et al., 2021, pp. 5, 23; IBA, 2024; Sargent et al., 2026).


#### 1.5.1 Safety

Conventional fuel-tank maintenance may require multiple personnel for inspection, equipment operation and safety monitoring. For example, published maintenance accounts describe leak-testing procedures involving a technician inside the tank, an external equipment operator and a safety attendant. A remotely operated inspection robot could potentially reduce the need for personnel to enter the tank for selected inspection tasks.

#### 1.5.2 Time

Fuel-tank inspection involves preparation, access, inspection and restoration activities. SoftCrawl aims to improve accessibility by allowing a robot to navigate towards inspection locations while being controlled externally. This could reduce selected inspection-related activities, although actual time savings must be established through future operational studies.

#### 1.5.3 Cost

Reducing inspection-related aircraft downtime could provide financial benefits to airlines and MRO providers. However, potential savings depend on the aircraft type, maintenance procedure, labour requirements and actual reduction in downtime. Accordingly, the financial value of SoftCrawl is currently a projected benefit rather than a demonstrated outcome.

<figure>
<svg class="value-figure" viewBox="0 0 900 300" xmlns="http://www.w3.org/2000/svg" role="img" aria-label="Value proposition: safety, time and money" style="width:100%;height:auto;max-width:900px;display:block;margin:0 auto;font-family:inherit">
  <defs>
    <marker id="vp-arrow" viewBox="0 0 10 10" refX="5" refY="5" markerWidth="7" markerHeight="7" orient="auto"><path d="M0,0 L10,5 L0,10 z" fill="#444"/></marker>
  </defs>
  <g>
    <rect x="15" y="10" width="270" height="280" rx="8" fill="#fff" stroke="#d9d4cc" stroke-width="1.5"/>
    <path d="M23 10 h254 a8 8 0 0 1 8 8 v34 h-270 v-34 a8 8 0 0 1 8 -8 z" fill="#B3693A"/>
    <text x="150" y="40" text-anchor="middle" font-size="20" font-weight="700" fill="#fff">Safety</text>
    <text x="150" y="98" text-anchor="middle" font-size="15" fill="#333">3 specialists per</text>
    <text x="150" y="118" text-anchor="middle" font-size="15" fill="#333">inspection</text>
    <line x1="150" y1="140" x2="150" y2="192" stroke="#444" stroke-width="2" marker-end="url(#vp-arrow)"/>
    <text x="150" y="228" text-anchor="middle" font-size="16" font-weight="700" fill="#1f2a44">Reduced number of</text>
    <text x="150" y="249" text-anchor="middle" font-size="16" font-weight="700" fill="#1f2a44">operators</text>
  </g>
  <g>
    <rect x="315" y="10" width="270" height="280" rx="8" fill="#fff" stroke="#d9d4cc" stroke-width="1.5"/>
    <path d="M323 10 h254 a8 8 0 0 1 8 8 v34 h-270 v-34 a8 8 0 0 1 8 -8 z" fill="#C98E44"/>
    <text x="450" y="40" text-anchor="middle" font-size="20" font-weight="700" fill="#fff">Time</text>
    <text x="450" y="108" text-anchor="middle" font-size="15" fill="#333">High downtime</text>
    <line x1="450" y1="140" x2="450" y2="192" stroke="#444" stroke-width="2" marker-end="url(#vp-arrow)"/>
    <text x="450" y="238" text-anchor="middle" font-size="16" font-weight="700" fill="#1f2a44">Low downtime</text>
  </g>
  <g>
    <rect x="615" y="10" width="270" height="280" rx="8" fill="#fff" stroke="#d9d4cc" stroke-width="1.5"/>
    <path d="M623 10 h254 a8 8 0 0 1 8 8 v34 h-270 v-34 a8 8 0 0 1 8 -8 z" fill="#B5604B"/>
    <text x="750" y="40" text-anchor="middle" font-size="20" font-weight="700" fill="#fff">Money</text>
    <text x="750" y="98" text-anchor="middle" font-size="15" fill="#333">A grounded A350-900:</text>
    <text x="750" y="118" text-anchor="middle" font-size="15" fill="#333">$37.5k/day in lease alone</text>
    <line x1="750" y1="140" x2="750" y2="192" stroke="#444" stroke-width="2" marker-end="url(#vp-arrow)"/>
    <text x="750" y="220" text-anchor="middle" font-size="16" font-weight="700" fill="#1f2a44">4–5 days avoided:</text>
    <text x="750" y="241" text-anchor="middle" font-size="16" font-weight="700" fill="#1f2a44">$150k–$750k saved</text>
    <text x="750" y="262" text-anchor="middle" font-size="16" font-weight="700" fill="#1f2a44">per event</text>
  </g>
</svg>
<figcaption>Figure 4. Proposed value of SoftCrawl across safety, time and cost (Aviation Pros, 2012; FL Technics, 2026; Heilemann et al., 2021, pp. 5, 23; IBA, 2024; Sargent et al., 2026).</figcaption>
</figure>

### 1.6 Stakeholder Analysis

The development and implementation of SoftCrawl involve several stakeholders with different levels of influence and interest. A power–interest matrix was used to identify the stakeholders most relevant to the project.

<div class="table-fillet">
<table>
  <thead>
    <tr>
      <th>Stakeholder</th>
      <th>Interest</th>
      <th>Power</th>
      <th>Engagement strategy</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>MRO teams and airlines</strong></td>
      <td>High</td>
      <td>High</td>
      <td>Manage closely</td>
    </tr>
    <tr>
      <td><strong>Aircraft maintenance technicians and inspection crews</strong></td>
      <td>High</td>
      <td>Low</td>
      <td>Keep informed and involved</td>
    </tr>
    <tr>
      <td><strong>Aviation regulators and industry bodies</strong></td>
      <td>Low</td>
      <td>High</td>
      <td>Keep satisfied</td>
    </tr>
    <tr>
      <td><strong>Passengers</strong></td>
      <td>Low</td>
      <td>Low</td>
      <td>Monitor</td>
    </tr>
  </tbody>
</table>
</div>
<p class="table-caption">Table 1. Stakeholder interest, influence and engagement strategy.</p>

<figure>
<img src="{{ '/images/context/image4.png' | relative_url }}" alt="Stakeholder power-interest matrix">
<figcaption>Figure 5. Stakeholder power–interest matrix.</figcaption>
</figure>

### 1.7 Primary User: Aircraft Maintenance Technicians

The primary intended users of SoftCrawl are aircraft maintenance technicians and inspection personnel. The robot is designed to support these users rather than replace their technical judgement.

Through remote operation, technicians could potentially inspect difficult-to-access locations without physically entering every region of the fuel tank. This would allow maintenance personnel to focus on interpreting inspection information, identifying defects and determining appropriate maintenance actions.

Consequently, the robot's design must prioritise accessibility, controllability, inspection visibility and reliable attachment to internal tank surfaces.

### 1.8 Proposed User Journey

A proposed user journey was developed to illustrate how SoftCrawl could be incorporated into aircraft fuel-tank inspection.

The existing workflow may include fuel draining, ventilation, atmospheric testing, personnel entry, manual inspection and subsequent restoration activities.

Under the proposed robotic workflow, a technician would deploy SoftCrawl through an existing access opening and remotely control its movement towards inspection locations. Inspection information would be transmitted to the operator for analysis, allowing potential defects to be identified without requiring direct human access to every inspection location. This approach could reduce selected manual entry and repositioning activities.

However, fuel removal, ventilation, atmospheric testing and other safety procedures cannot automatically be eliminated merely because inspection is performed remotely. Any changes would require assessment of the robot's electrical safety, fuel-vapour compatibility and applicable maintenance procedures.

<figure>
<img src="{{ '/images/context/image5.png' | relative_url }}" alt="Conventional inspection workflow">
<img src="{{ '/images/context/image6.png' | relative_url }}" alt="Proposed SoftCrawl inspection workflow">
<figcaption>Figure 6. Conventional (top) and proposed SoftCrawl (bottom) inspection workflows.</figcaption>
</figure>

### 1.9 Existing Inspection Technologies

Several inspection technologies have been investigated to address the accessibility challenges associated with aircraft fuel tanks (Federal Aviation Administration, 1997; Jordan, 2017; Heilemann et al., 2021; Dhoot &amp; Fan, 2022).

<div class="table-fillet">
<table>
  <thead>
    <tr>
      <th>Technology</th>
      <th>Approach</th>
      <th>Strength</th>
      <th>Limitation</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>Borescope</strong></td>
      <td>Rigid or flexible camera probe inserted through access openings</td>
      <td>Established and simple to operate</td>
      <td>Reach and manoeuvrability limited by probe length and operator control</td>
    </tr>
    <tr>
      <td><strong>RANDE</strong></td>
      <td>Snake-like robotic arm carrying inspection equipment (Jordan, 2017)</td>
      <td>Navigates around obstacles; reported to save about 29 h of inspection time (Panzino, 2017)</td>
      <td>External base and finite arm length limit the workspace</td>
    </tr>
    <tr>
      <td><strong>Eeloscope 1</strong></td>
      <td>Endoscope propelled through fuel by fluid jets</td>
      <td>Self-propelled inside the tank</td>
      <td>Tether friction, insufficient propulsion and poor visibility through fuel</td>
    </tr>
    <tr>
      <td><strong>Eeloscope 2</strong></td>
      <td>Externally controlled robotic arm with an inspection extension</td>
      <td>Reaches internal fuel-tank regions</td>
      <td>Reach depends on the arm and access geometry</td>
    </tr>
    <tr>
      <td><strong>Caterpillar robot</strong></td>
      <td>Tracked locomotion along internal tank surfaces</td>
      <td>Targets independent movement within the tank</td>
      <td>Full operational validation not yet established</td>
    </tr>
  </tbody>
</table>
</div>
<p class="table-caption">Table 2. Existing fuel-tank inspection technologies.</p>

#### 1.9.1 Identified Design Gap

Existing approaches demonstrate different trade-offs between inspection reach, mobility, structural compliance and system complexity. Externally supported inspection tools remain constrained by their workspace, while independently mobile robotic concepts face challenges associated with navigation and validation.

This motivates the investigation of a compact robotic platform combining compliant body deformation with controlled attachment to internal surfaces.

<figure>
<img src="{{ '/images/context/image7.png' | relative_url }}" alt="Competitive landscape">
<figcaption>Figure 7. Competitive landscape of existing fuel-tank inspection technologies (Federal Aviation Administration, 1997; Jordan, 2017; Panzino, 2017; Heilemann et al., 2021; Dhoot &amp; Fan, 2022; Ricárdez Ortigosa et al., 2025).</figcaption>
</figure>

### 1.10 Why Soft Robotics?

Soft robotics uses compliant materials and deformable structures to achieve movement and interaction with the environment. Unlike conventional rigid robots, soft robotic structures can deform in response to geometric constraints and contact forces. These characteristics make soft robotics a promising approach for navigating confined environments containing irregular surfaces and obstacles.

Soft robots can achieve movement through several locomotion strategies, including crawling, climbing, growing and swimming.

<figure>
<img src="{{ '/images/context/image8.png' | relative_url }}" alt="Soft robotic locomotion strategies">
<figcaption>Figure 8. Soft robotic locomotion strategies (Hao et al., 2023, Fig. 2).</figcaption>
</figure>

For aircraft fuel-tank inspection, crawling and climbing were identified as the most relevant locomotion modes. Crawling enables movement along horizontal surfaces, while climbing provides access to vertical walls and other elevated inspection regions.

SoftCrawl adopts a pneumatically actuated Kresling-origami body to generate controlled deformation, combined with suction-cup adhesion to support locomotion.

### 1.11 System Requirements and Proposed Architecture

The proposed system must satisfy the following preliminary design requirements:

<div class="table-fillet">
<table>
  <thead>
    <tr>
      <th style="width: 25%;">Category</th>
      <th>Requirement</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="2" style="vertical-align: middle;">Geometry</td>
      <td>Fit within a 300 × 200 mm access opening</td>
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
      <td>Actuate with a 0.75 kg robot mass with safety factor 2 on oily vertical surfaces</td>
    </tr>
    <tr>
      <td>Adhesion on thin oil film over aluminium sheet</td>
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
      <td>No damage to fuel tank internal surfaces</td>
    </tr>
    <tr>
      <td>No swelling/damage due to prolonged oil exposure</td>
    </tr>
  </tbody>
</table>
</div>
<p class="table-caption">Table 3. SoftCrawl system requirements.</p>

The proposed architecture consists of a pneumatically actuated robot body, a suction-cup attachment subsystem, external pneumatic and control hardware, and an inspection interface.

<figure>
<img src="{{ '/images/context/image9.png' | relative_url }}" alt="SoftCrawl system architecture">
<figcaption>Figure 9. Proposed SoftCrawl system architecture.</figcaption>
</figure>

Sensitive control hardware and vacuum generation are intended to remain outside the fuel tank, with pneumatic lines supplying the robot. This architecture provides the basis for subsequent subsystem development, including the Kresling body and Robot Legs adhesion mechanism.

The first-semester project focuses on validating the principal mechanical and pneumatic functions before attempting fully integrated locomotion and inspection.

---

## References

- Airbus. (2024). *A350 aircraft characteristics: Airport and maintenance planning* (Rev. 14, December 1, 2024). <https://aircraft.airbus.com/sites/g/files/jlcbta126/files/2024-12/AC_A350_1224.pdf>
- Aviation Pros. (2012). *MRO operation: Finding and fixing fuel system leaks*. <https://www.aviationpros.com/aircraft-maintenance-technology/engines-parts/aircraft-airframe-accessories/fuel-systems/article/10618623/mro-operation-finding-and-fixing-fuel-system-leaks>
- Baxter, J. (2016). *Fuel tank entry* [Video]. YouTube. <https://youtu.be/l7HcajWEBNw>
- Dhoot, M. K., & Fan, I.-S. (2022). Design and development of a mobile robotic system for aircraft wing fuel tank inspection. *SAE International Journal of Advances and Current Practices in Mobility, 4*(4), 1126–1137. <https://doi.org/10.4271/2022-01-0042>
- Evans, G. (2010, July 21). An easier fix for fuel leaks. *Airport Technology*. <https://www.airport-technology.com/analysis/feature90365/>
- Federal Aviation Administration. (1997). *Visual inspection for aircraft* (Advisory Circular No. 43-204). U.S. Department of Transportation. <https://www.faa.gov/documentLibrary/media/Advisory_Circular/43-204.pdf>
- Federal Aviation Administration. (2025, November 25). Airworthiness directives; Airbus SAS airplanes (AD 2025-20-05). *Federal Register, 90*, 53200–53203. <https://www.federalregister.gov/d/2025-20910>
- FL Technics. (2026, August 6). *Why faster diagnostics are becoming critical for aircraft heavy maintenance*. <https://fltechnics.com/why-faster-diagnostics-are-becoming-critical-for-aircraft-heavy-maintenance/>
- Hao, T., Xiao, H., Ji, M., Liu, Y., & Liu, S. (2023). Integrated and intelligent soft robots. *IEEE Access, 11*, 99862–99877. <https://doi.org/10.1109/ACCESS.2023.3314513>
- Heilemann, F., Dadashi, A., & Wicke, K. (2021). Eeloscope—Towards a novel endoscopic system enabling digital aircraft fuel tank maintenance. *Aerospace, 8*(5), Article 136. <https://doi.org/10.3390/aerospace8050136>
- IBA. (2024, February). *Aircraft values & lease rates update: February 2024*. <https://www.iba.aero/insight/aircraft-values-lease-rates-update-february-2024/>
- Jordan, H. (2017, February 19). Robotic arm tool poised to save costly inspection time. U.S. Air Force. <https://www.af.mil/News/Article-Display/Article/1088209/robotic-arm-tool-poised-to-save-costly-inspection-time/>
- Panzino, C. (2017, September 20). Robotic snake can save airmen 29 hours of aircraft inspection time. *Defense News*. <https://www.defensenews.com/digital-show-dailies/air-force-association/2017/09/20/robotic-snake-can-save-airmen-29-hours-of-aircraft-inspection-time/>
- Polimeno, U., & Meo, M. (2009). Detecting barely visible impact damage detection on aircraft composites structures. *Composite Structures, 91*(4), 398–402. <https://doi.org/10.1016/j.compstruct.2009.04.014>
- Ricárdez Ortigosa, A., Bestmann, M., Heilemann, F., Halbe, J., Christiansen, L., Rodeck, R., & Wende, G. (2025). Foundations for teleoperation and motion planning towards robot-assisted aircraft fuel tank inspection. *Aerospace, 12*(2), Article 156. <https://doi.org/10.3390/aerospace12020156>
- Sargent, S., Prentice, B., & Costanza, D. (2026, April 13). *The new MRO supply paradigm: Labor and material constraints offset by AI and tech*. Oliver Wyman. <https://www.oliverwyman.com/our-expertise/insights/2026/apr/aviation-mro-labor-and-material-supply-chain-paradigm.html>
- Shanks, A. R. (2018, May 30). *Dangerous and dirty—MacDill "Tank Divers" power the fight* [Photograph]. U.S. Air Force. <https://www.macdill.af.mil/News/Photos/igphoto/2001925707/>
