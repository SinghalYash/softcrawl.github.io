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

Aircraft fuel tanks are essential components of the aircraft fuel storage and distribution system. In commercial aircraft, fuel is commonly stored within the wings and centre wing box, where internal structural components also contribute to the aircraft's load-bearing capability.

Unlike conventional storage tanks, aircraft wing tanks contain complex internal structures, including ribs, spars, stringers, pipes and sealant joints. These components divide the interior into restricted compartments, creating challenges for inspection and maintenance.

Access is typically provided through maintenance panels located along the aircraft structure. For large commercial aircraft such as the Airbus A350, these access points may be several metres above ground level, introducing additional requirements for maintenance equipment and personnel.

The confined geometry, restricted access and presence of residual fuel make aircraft fuel tanks a challenging environment for inspection.

<figure>
<img src="{{ '/images/context/image1.png' | relative_url }}" alt="Aircraft fuel-tank layout">
<figcaption>Figure 1. Aircraft fuel-tank layout and access locations.</figcaption>
</figure>

### 1.2 Current Inspection Methods

Conventional aircraft fuel-tank inspection frequently requires maintenance personnel to enter the tank through access openings.

Before entry, the tank must undergo appropriate safety preparation, including fuel removal where required, ventilation, atmospheric testing and confined-space entry procedures.

Once inside, technicians manually inspect internal structures using visual inspection equipment and other nondestructive testing methods.

The confined working environment limits movement and requires personnel to navigate around structural obstacles while avoiding damage to sensitive components.

These conditions make inspection physically demanding and introduce occupational safety concerns associated with fuel vapours, restricted access and confined-space work.

<figure>
<img src="{{ '/images/context/image2.png' | relative_url }}" alt="Technician inside a fuel tank">
<figcaption>Figure 2. Technician performing maintenance inside an aircraft fuel tank.</figcaption>
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
<figcaption>Figure 3. Representative aircraft defects: sealant failure, structural damage and crack propagation.</figcaption>
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

The proposed value of SoftCrawl is evaluated across three dimensions: safety, time and cost.

<div class="card-grid"> <div class="value-card"> <h3>Safety</h3> <p>Conventional fuel-tank maintenance may require multiple personnel for inspection, equipment operation and safety monitoring. For example, published maintenance accounts describe leak-testing procedures involving a technician inside the tank, an external equipment operator and a safety attendant. A remotely operated inspection robot could reduce the need for personnel to enter the tank for selected inspection tasks.</p> </div> <div class="value-card time"> <h3>Time</h3> <p>Fuel-tank inspection involves preparation, access, inspection and restoration activities. SoftCrawl aims to improve accessibility by allowing a robot to navigate towards inspection locations while being controlled externally. This could reduce selected inspection-related activities, although actual time savings must be established through future operational studies.</p> </div> <div class="value-card money"> <h3>Cost</h3> <p>Reducing inspection-related aircraft downtime could provide financial benefits to airlines and MRO providers. However, potential savings depend on the aircraft type, maintenance procedure, labour requirements and actual reduction in downtime. The financial value of SoftCrawl is therefore currently a projected benefit rather than a demonstrated outcome.</p> </div> </div> <figure> <div class="img-placeholder">Value proposition: safety, time, cost</div> <figcaption>Figure 4. Proposed value of SoftCrawl across safety, time and cost.</figcaption> </figure>

#### 1.5.1 Safety

Conventional fuel-tank maintenance may require multiple personnel for inspection, equipment operation and safety monitoring. For example, published maintenance accounts describe leak-testing procedures involving a technician inside the tank, an external equipment operator and a safety attendant. A remotely operated inspection robot could potentially reduce the need for personnel to enter the tank for selected inspection tasks.

#### 1.5.2 Time

Fuel-tank inspection involves preparation, access, inspection and restoration activities. SoftCrawl aims to improve accessibility by allowing a robot to navigate towards inspection locations while being controlled externally. This could reduce selected inspection-related activities, although actual time savings must be established through future operational studies.

#### 1.5.3 Cost

Reducing inspection-related aircraft downtime could provide financial benefits to airlines and MRO providers. However, potential savings depend on the aircraft type, maintenance procedure, labour requirements and actual reduction in downtime. Accordingly, the financial value of SoftCrawl is currently a projected benefit rather than a demonstrated outcome.

<figure>
<img src="{{ '/images/context/image6.png' | relative_url }}" alt="SoftCrawl value proposition">
<figcaption>Figure 4. Proposed value of SoftCrawl across safety, time and cost.</figcaption>
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
<img src="{{ '/images/context/image7.png' | relative_url }}" alt="Stakeholder power-interest matrix">
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
<img src="{{ '/images/context/image8.png' | relative_url }}" alt="Conventional and proposed inspection workflows">
<figcaption>Figure 6. Conventional and proposed SoftCrawl inspection workflows.</figcaption>
</figure>

### 1.9 Existing Inspection Technologies

Several inspection technologies have been investigated to address the accessibility challenges associated with aircraft fuel tanks.

| Technology | Approach | Strength | Limitation |
|---|---|---|---|
| Borescope | Rigid or flexible camera probe inserted through access openings | Established and simple to operate | Reach and manoeuvrability limited by probe length and operator control |
| RANDE | Robotic arm carrying inspection equipment | Navigates around obstacles | External base and finite arm length limit the workspace |
| Eeloscope 1 | Endoscope propelled through fuel by fluid jets | Self-propelled inside the tank | Tether friction, insufficient propulsion and poor visibility through fuel |
| Eeloscope 2 | Externally controlled robotic arm with an inspection extension | Reaches internal fuel-tank regions | Reach depends on the arm and access geometry |
| Caterpillar robot | Tracked locomotion along internal tank surfaces | Targets independent movement within the tank | Full operational validation not yet established |

*Table 2. Existing fuel-tank inspection technologies.*

#### 1.9.1 Identified Design Gap

Existing approaches demonstrate different trade-offs between inspection reach, mobility, structural compliance and system complexity. Externally supported inspection tools remain constrained by their workspace, while independently mobile robotic concepts face challenges associated with navigation and validation.

This motivates the investigation of a compact robotic platform combining compliant body deformation with controlled attachment to internal surfaces.

<figure>
<img src="{{ '/images/context/image9.png' | relative_url }}" alt="Competitive landscape">
<figcaption>Figure 7. Competitive landscape of existing fuel-tank inspection technologies.</figcaption>
</figure>

### 1.10 Why Soft Robotics?

Soft robotics uses compliant materials and deformable structures to achieve movement and interaction with the environment. Unlike conventional rigid robots, soft robotic structures can deform in response to geometric constraints and contact forces. These characteristics make soft robotics a promising approach for navigating confined environments containing irregular surfaces and obstacles.

Soft robots can achieve movement through several locomotion strategies, including crawling, climbing, growing and swimming.

For aircraft fuel-tank inspection, crawling and climbing were identified as the most relevant locomotion modes. Crawling enables movement along horizontal surfaces, while climbing provides access to vertical walls and other elevated inspection regions.

SoftCrawl adopts a pneumatically actuated Kresling-origami body to generate controlled deformation, combined with suction-cup adhesion to support locomotion.

### 1.11 System Requirements and Proposed Architecture

The proposed system must satisfy the following preliminary design requirements:

| Category | Requirement |
|---|---|
| **Geometry** | Fit within a 300 × 200 mm access opening |
| | Actuator never expands beyond the body, avoiding snags |
| **Electronics** | No electronics in the tank except camera and light |
| **Adhesion** | Actuate with a 0.75 kg robot mass with safety factor 2 on oily vertical surfaces |
| | Adhesion on thin oil film over aluminium sheet |
| **Locomotion** | Control each leg individually |
| | Climb 90 degree corners |
| | Pass through 30 cm × 30 cm access hole to next fuel tank chamber |
| **Material compatibility** | No damage to fuel tank internal surfaces |
| | No swelling/damage due to prolonged oil exposure |

*Table 3. SoftCrawl system requirements.*

The proposed architecture consists of a pneumatically actuated robot body, a suction-cup attachment subsystem, external pneumatic and control hardware, and an inspection interface.

<figure>
<img src="{{ '/images/context/image10.png' | relative_url }}" alt="SoftCrawl system architecture">
<figcaption>Figure 8. Proposed SoftCrawl system architecture.</figcaption>
</figure>

Sensitive control hardware and vacuum generation are intended to remain outside the fuel tank, with pneumatic lines supplying the robot. This architecture provides the basis for subsequent subsystem development, including the Kresling body and Robot Legs adhesion mechanism.

The first-semester project focuses on validating the principal mechanical and pneumatic functions before attempting fully integrated locomotion and inspection.