---
layout: report
title: Context
group: Interim
code: SEC-01
nav_order: 1
permalink: /report/context/
---

This section sets out the aircraft fuel-tank environment, why current inspection is difficult, who SoftCrawl is for, and the requirements that drive the Robot Body and Robot Legs subsystems.

## 1. Context and Problem Definition

### 1.1 Aircraft Fuel-Tank Environment

Aircraft fuel tanks are essential components of the aircraft fuel storage and distribution system. In commercial aircraft, fuel is commonly stored within the wings and centre wing box, where internal structural components also contribute to the aircraft's load-bearing capability.

Unlike conventional storage tanks, aircraft wing tanks contain complex internal structures, including ribs, spars, stringers, pipes and sealant joints. These components divide the interior into restricted compartments, creating challenges for inspection and maintenance.

Access is typically provided through maintenance panels located along the aircraft structure. For large commercial aircraft such as the Airbus A350, these access points may be several metres above ground level, introducing additional requirements for maintenance equipment and personnel (Airbus, 2024).

The confined geometry, restricted access and presence of residual fuel make aircraft fuel tanks a challenging environment for inspection.

<figure>
<img src="{{ '/images/context/image1.png' | relative_url }}" alt="Aircraft fuel-tank layout and access locations">
<figcaption>Figure 1. Aircraft fuel-tank layout and access locations (adapted from Airbus, 2024).</figcaption>
</figure>

### 1.2 Current Inspection Methods

Conventional aircraft fuel-tank inspection frequently requires maintenance personnel to enter the tank through access openings. Before entry, the tank must undergo appropriate safety preparation, including fuel removal where required, ventilation, atmospheric testing and confined-space entry procedures.

Once inside, technicians manually inspect internal structures using visual inspection equipment and other nondestructive testing methods. The confined working environment limits movement and requires personnel to navigate around structural obstacles while avoiding damage to sensitive components.

These conditions make inspection physically demanding and introduce occupational safety concerns associated with fuel vapours, restricted access and confined-space work.

<figure>
<img src="{{ '/images/context/image2.png' | relative_url }}" alt="Technician performing maintenance inside an aircraft fuel tank">
<figcaption>Figure 2. Technician performing maintenance inside an aircraft fuel tank (Shanks, 2018).</figcaption>
</figure>

### 1.3 What Are We Looking For?

Aircraft fuel-tank inspection aims to identify defects that may affect structural integrity, fuel containment and operational safety. Three important categories of defects are considered in this project.

<div class="card-grid"> <div class="feature-card"> <h3>Sealant failure</h3> <p>Aircraft fuel tanks rely on sealants to prevent fuel leakage through structural joints, fasteners and interfaces. Over time, sealant deterioration, cracking or separation may compromise the integrity of these joints, resulting in fuel leakage and maintenance requirements.</p> </div> <div class="feature-card"> <h3>Structural and composite damage</h3> <p>Aircraft structures may experience damage caused by impact, fatigue or environmental exposure. Such damage may be difficult to identify through conventional visual inspection, particularly in restricted locations or beneath the surface. Where composite structures are present, barely visible impact damage and delamination may require specialised nondestructive inspection methods.</p> </div> <div class="feature-card"> <h3>Crack propagation</h3> <p>Repeated mechanical loading can initiate and propagate cracks in structural components. Detecting visible cracks and other signs of structural deterioration is important for identifying locations requiring further inspection or maintenance.</p> </div> </div>

<figure>
<img src="{{ '/images/context/image3.png' | relative_url }}" alt="Representative aircraft defects: sealant failure, structural damage and crack propagation">
<figcaption>Figure 3. Representative aircraft defects: sealant failure, structural damage and crack propagation (Polimeno &amp; Meo, 2009; Evans, 2010; Federal Aviation Administration, 2025).</figcaption>
</figure>

<div class="callout"> <p><strong>Design implication.</strong> SoftCrawl must ultimately support inspection of internal structural surfaces and sealant joints. The initial platform focuses on mobility and access; its final defect-detection capabilities will depend on the inspection sensors integrated in subsequent development.</p> </div>

### 1.4 Problems with Conventional Inspection

The challenges associated with conventional aircraft fuel-tank inspection can be divided into three categories.

**Safety challenges.** Technicians may be exposed to hazardous confined-space conditions, including residual fuel vapours, restricted ventilation and limited emergency access. These risks necessitate strict safety procedures and personnel monitoring.

**Operational challenges.** The complex internal geometry restricts technician movement and makes certain inspection locations difficult to access. Inspection can also require substantial preparation, including tank access, atmospheric testing and equipment setup. These activities contribute to labour-intensive maintenance procedures.

**Business impact.** Aircraft maintenance can result in periods during which the aircraft is unavailable for commercial operations. Extended downtime may affect airline schedules, maintenance expenditure and aircraft utilisation. Consequently, reducing the need for personnel to enter confined fuel-tank regions could provide both operational and economic benefits.

#### Problem Statement

Aircraft fuel-tank inspection exposes maintenance personnel to hazardous confined environments while requiring time-consuming and labour-intensive procedures. The restricted geometry also limits inspection accessibility, contributing to operational inefficiencies and aircraft downtime.

<div class="callout result"> <p><strong>SoftCrawl seeks to investigate whether a compact, remotely operated soft robotic platform can improve inspection accessibility while reducing the need for human entry.</strong></p> </div>

### 1.5 Value Proposition

The proposed value of SoftCrawl is evaluated across three dimensions: safety, time and cost (Aviation Pros, 2012; FL Technics, 2026; Heilemann et al., 2021, pp. 5, 23; IBA, 2024; Sargent et al., 2026).

<div class="card-grid"> <div class="value-card"> <h3>Safety</h3> <p>Conventional fuel-tank maintenance may require multiple personnel for inspection, equipment operation and safety monitoring. For example, published maintenance accounts (Aviation Pros, 2012) describe leak-testing procedures involving a technician inside the tank, an external equipment operator and a safety attendant. A remotely operated inspection robot could potentially reduce the need for personnel to enter the tank for selected inspection tasks.</p> </div> <div class="value-card time"> <h3>Time</h3> <p>Fuel-tank inspection involves preparation, access, inspection and restoration activities. SoftCrawl aims to improve accessibility by allowing a robot to navigate towards inspection locations while being controlled externally. This could reduce selected inspection-related activities, although actual time savings must be established through future operational studies.</p> </div> <div class="value-card money"> <h3>Cost</h3> <p>Reducing inspection-related aircraft downtime could provide financial benefits to airlines and MRO providers. However, potential savings depend on the aircraft type, maintenance procedure, labour requirements and actual reduction in downtime. Accordingly, the financial value of SoftCrawl is currently a projected benefit rather than a demonstrated outcome.</p> </div> </div>

<figure>
<img src="{{ '/images/context/image4.png' | relative_url }}" alt="Proposed value of SoftCrawl across safety, time and cost">
<figcaption>Figure 4. Proposed value of SoftCrawl across safety, time and cost (Aviation Pros, 2012; FL Technics, 2026; Heilemann et al., 2021, pp. 5, 23; IBA, 2024; Sargent et al., 2026).</figcaption>
</figure>

### 1.6 Stakeholder Analysis

The development and implementation of SoftCrawl involve several stakeholders with different levels of influence and interest. A power–interest matrix was used to identify the stakeholders most relevant to the project.

| Stakeholder | Interest | Influence | Engagement strategy |
|---|---|---|---|
| MRO teams and airlines | High | High | Manage closely |
| Aircraft maintenance technicians and inspection crews | High | Lower organisational influence | Keep informed and involved |
| Aviation regulators and industry bodies | Lower direct project interest | High | Keep satisfied |
| Passengers | Lower direct interest | Low | Monitor |

*Table 1. Stakeholder interest, influence and engagement strategy.*

- **MRO teams and airlines** are key decision-makers because they are responsible for maintenance operations, resource allocation and potential technology adoption.
- **Technicians and inspection crews** are the primary intended users of the system. Their requirements influence the robot's usability, deployment process and inspection capabilities.
- **Regulatory authorities and industry bodies** influence the safety and compliance requirements associated with aircraft maintenance technologies.
- **Passengers** are indirect beneficiaries through potential improvements in aircraft maintenance and operational safety.

<figure>
<img src="{{ '/images/context/image5.png' | relative_url }}" alt="Stakeholder power–interest matrix">
<figcaption>Figure 5. Stakeholder power–interest matrix.</figcaption>
</figure>

### 1.7 Primary User: Aircraft Maintenance Technicians

The primary intended users of SoftCrawl are aircraft maintenance technicians and inspection personnel. The robot is designed to support these users rather than replace their technical judgement.

Through remote operation, technicians could potentially inspect difficult-to-access locations without physically entering every region of the fuel tank. This would allow maintenance personnel to focus on interpreting inspection information, identifying defects and determining appropriate maintenance actions.

Consequently, the robot's design must prioritise accessibility, controllability, inspection visibility and reliable attachment to internal tank surfaces.

### 1.8 Proposed User Journey

A proposed user journey was developed to illustrate how SoftCrawl could be incorporated into aircraft fuel-tank inspection.

The existing workflow may include fuel draining, ventilation, atmospheric testing, personnel entry, manual inspection and subsequent restoration activities. Under the proposed robotic workflow, a technician would deploy SoftCrawl through an existing access opening and remotely control its movement towards inspection locations. Inspection information would be transmitted to the operator for analysis, allowing potential defects to be identified without requiring direct human access to every inspection location. This approach could reduce selected manual entry and repositioning activities.

<div class="callout warning"> <p>Fuel removal, ventilation, atmospheric testing and other safety procedures cannot automatically be eliminated merely because inspection is performed remotely. Any changes would require assessment of the robot's electrical safety, fuel-vapour compatibility and applicable maintenance procedures.</p> </div>

<figure>
<img src="{{ '/images/context/image7.png' | relative_url }}" alt="Conventional inspection workflow">
<img src="{{ '/images/context/image6.png' | relative_url }}" alt="Proposed SoftCrawl inspection workflow">
<figcaption>Figure 6. Conventional (top) and proposed SoftCrawl (bottom) inspection workflows.</figcaption>
</figure>

### 1.9 Existing Inspection Technologies

Several inspection technologies have been investigated to address the accessibility challenges associated with aircraft fuel tanks (Federal Aviation Administration, 1997; Jordan, 2017; Heilemann et al., 2021; Dhoot &amp; Fan, 2022).

| Technology | Approach | Strength | Limitation |
|---|---|---|---|
| Borescope | Rigid or flexible camera probe inserted through access openings | Established and simple to operate | Reach and manoeuvrability limited by probe length and operator control |
| RANDE | Snake-like robotic arm carrying inspection equipment (Jordan, 2017) | Navigates around obstacles; reported to save about 29 h of inspection time (Panzino, 2017) | External base and finite arm length limit the workspace |
| Eeloscope 1 | Endoscope propelled through fuel by fluid jets | Self-propelled inside the tank | Tether friction, insufficient propulsion and poor visibility through fuel |
| Eeloscope 2 | Externally controlled robotic arm with an inspection extension | Reaches internal fuel-tank regions | Reach depends on the arm and access geometry |
| Caterpillar robot | Tracked locomotion along internal tank surfaces | Targets independent movement within the tank | Full operational validation not yet established |

*Table 2. Existing fuel-tank inspection technologies.*

<figure>
<img src="{{ '/images/context/image8.png' | relative_url }}" alt="Competitive landscape of existing fuel-tank inspection technologies">
<figcaption>Figure 7. Competitive landscape of existing fuel-tank inspection technologies (Federal Aviation Administration, 1997; Jordan, 2017; Panzino, 2017; Heilemann et al., 2021; Dhoot &amp; Fan, 2022; Ricárdez Ortigosa et al., 2025).</figcaption>
</figure>

<div class="callout"> <p><strong>Identified design gap.</strong> Existing approaches demonstrate different trade-offs between inspection reach, mobility, structural compliance and system complexity. Externally supported inspection tools remain constrained by their workspace, while independently mobile robotic concepts face challenges associated with navigation and validation. This motivates the investigation of a compact robotic platform combining compliant body deformation with controlled attachment to internal surfaces.</p> </div>

### 1.10 Why Soft Robotics?

Soft robotics uses compliant materials and deformable structures to achieve movement and interaction with the environment. Unlike conventional rigid robots, soft robotic structures can deform in response to geometric constraints and contact forces. These characteristics make soft robotics a promising approach for navigating confined environments containing irregular surfaces and obstacles.

Soft robots can achieve movement through several locomotion strategies, including crawling, climbing, growing and swimming.

<figure>
<img src="{{ '/images/context/image9.png' | relative_url }}" alt="Soft robotic locomotion strategies">
<figcaption>Figure 8. Soft robotic locomotion strategies (Hao et al., 2023, Fig. 2).</figcaption>
</figure>

For aircraft fuel-tank inspection, **crawling and climbing** were identified as the most relevant locomotion modes. Crawling enables movement along horizontal surfaces, while climbing provides access to vertical walls and other elevated inspection regions.

SoftCrawl adopts a pneumatically actuated Kresling-origami body to generate controlled deformation, combined with suction-cup adhesion to support locomotion.

### 1.11 System Requirements and Proposed Architecture

The proposed system must satisfy the following preliminary design requirements.

| Category | Requirement |
|---|---|
| **Geometry** | Fit within a 300 × 200 mm access opening |
| | Actuator never expands beyond the body, avoiding snags |
| **Electronics** | No electronics in the tank except camera and light |
| **Adhesion** | Support a 0.75 kg robot mass with a safety factor of 2 on oily vertical surfaces |
| | Adhesion on thin oil film over aluminium sheet |
| **Locomotion** | Control each leg individually |
| | Climb 90° corners |
| | Pass through a 30 cm × 30 cm access hole to the next fuel-tank chamber |
| **Material compatibility** | No damage to fuel-tank internal surfaces |
| | No swelling or damage due to prolonged oil exposure |

*Table 3. Preliminary system requirements.*

The proposed architecture consists of a pneumatically actuated robot body, a suction-cup attachment subsystem, external pneumatic and control hardware, and an inspection interface.

<figure>
<img src="{{ '/images/context/image10.png' | relative_url }}" alt="Proposed SoftCrawl system architecture">
<figcaption>Figure 9. Proposed SoftCrawl system architecture.</figcaption>
</figure>

Sensitive control hardware and vacuum generation are intended to remain outside the fuel tank, with pneumatic lines supplying the robot. This architecture provides the basis for subsequent subsystem development, including the Kresling body and the Robot Legs adhesion mechanism.

<div class="callout result"> <p>The first-semester project focuses on validating the principal mechanical and pneumatic functions before attempting fully integrated locomotion and inspection.</p> </div>

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
