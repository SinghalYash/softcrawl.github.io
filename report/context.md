---
layout: report
title: Context
group: Interim
code: SEC-01
nav_order: 1
permalink: /report/context/
---

This section sets out the aircraft fuel-tank environment, why current inspection is difficult, who SoftCrawl is for, and the requirements that drive the Robot Body and Robot Legs subsystems.

1.1 Aircraft Fuel-Tank Environment

Aircraft fuel tanks are essential components of the aircraft fuel storage and distribution system. In commercial aircraft, fuel is commonly stored within the wings and centre wing box, where internal structural components also contribute to the aircraft's load-bearing capability.

Unlike conventional storage tanks, aircraft wing tanks contain complex internal structures, including ribs, spars, stringers, pipes and sealant joints. These components divide the interior into restricted compartments, creating challenges for inspection and maintenance.

Access is typically provided through maintenance panels located along the aircraft structure. For large commercial aircraft such as the Airbus A350, these access points may be several metres above ground level, introducing additional requirements for maintenance equipment and personnel.

The confined geometry, restricted access and presence of residual fuel make aircraft fuel tanks a challenging environment for inspection.

<figure> <div class="img-placeholder">Aircraft fuel-tank layout and access locations</div> <figcaption>Figure 1. Aircraft fuel-tank layout and access locations.</figcaption> </figure>
1.2 Current Inspection Methods

Conventional aircraft fuel-tank inspection frequently requires maintenance personnel to enter the tank through access openings. Before entry, the tank must undergo appropriate safety preparation, including fuel removal where required, ventilation, atmospheric testing and confined-space entry procedures.

Once inside, technicians manually inspect internal structures using visual inspection equipment and other nondestructive testing methods. The confined working environment limits movement and requires personnel to navigate around structural obstacles while avoiding damage to sensitive components.

These conditions make inspection physically demanding and introduce occupational safety concerns associated with fuel vapours, restricted access and confined-space work.

<figure> <div class="img-placeholder">Technician performing maintenance inside a fuel tank</div> <figcaption>Figure 2. Technician performing maintenance inside an aircraft fuel tank.</figcaption> </figure>
1.3 What Are We Looking For?

Aircraft fuel-tank inspection aims to identify defects that may affect structural integrity, fuel containment and operational safety. Three important categories of defects are considered in this project.

<div class="card-grid"> <div class="feature-card"> <h3>Sealant failure</h3> <p>Fuel tanks rely on sealants to prevent leakage through structural joints, fasteners and interfaces. Over time, sealant deterioration, cracking or separation may compromise these joints, resulting in fuel leakage and maintenance requirements.</p> </div> <div class="feature-card"> <h3>Structural and composite damage</h3> <p>Impact, fatigue or environmental exposure can damage aircraft structures in ways that are hard to see, particularly in restricted locations or beneath the surface. In composite structures, barely visible impact damage and delamination may require specialised nondestructive inspection.</p> </div> <div class="feature-card"> <h3>Crack propagation</h3> <p>Repeated mechanical loading can initiate and propagate cracks in structural components. Detecting visible cracks and other signs of deterioration identifies locations requiring further inspection or maintenance.</p> </div> </div> <figure> <div class="figure-row"> <div class="img-placeholder">Sealant failure</div> <div class="img-placeholder">Structural damage</div> <div class="img-placeholder">Crack propagation</div> </div> <figcaption>Figure 3. Representative aircraft defects: sealant failure, structural damage and crack propagation.</figcaption> </figure> <div class="callout"> <p><strong>Design implication.</strong> SoftCrawl must ultimately support inspection of internal structural surfaces and sealant joints. The initial platform focuses on mobility and access; its final defect-detection capabilities will depend on the inspection sensors integrated in subsequent development.</p> </div>
1.4 Problems with Conventional Inspection

The challenges associated with conventional aircraft fuel-tank inspection can be divided into three categories.

Safety challenges. Technicians may be exposed to hazardous confined-space conditions, including residual fuel vapours, restricted ventilation and limited emergency access. These risks necessitate strict safety procedures and personnel monitoring.

Operational challenges. The complex internal geometry restricts technician movement and makes certain inspection locations difficult to access. Inspection can also require substantial preparation, including tank access, atmospheric testing and equipment setup. These activities contribute to labour-intensive maintenance procedures.

Business impact. Aircraft maintenance can result in periods during which the aircraft is unavailable for commercial operations. Extended downtime may affect airline schedules, maintenance expenditure and aircraft utilisation. Consequently, reducing the need for personnel to enter confined fuel-tank regions could provide both operational and economic benefits.

Problem Statement

Aircraft fuel-tank inspection exposes maintenance personnel to hazardous confined environments while requiring time-consuming and labour-intensive procedures. The restricted geometry also limits inspection accessibility, contributing to operational inefficiencies and aircraft downtime.

SoftCrawl seeks to investigate whether a compact, remotely operated soft robotic platform can improve inspection accessibility while reducing the need for human entry.

1.5 Value Proposition

The proposed value of SoftCrawl is evaluated across three dimensions: safety, time and cost.

<div class="card-grid"> <div class="value-card"> <h3>Safety</h3> <p>Conventional fuel-tank maintenance may require multiple personnel for inspection, equipment operation and safety monitoring. For example, published maintenance accounts describe leak-testing procedures involving a technician inside the tank, an external equipment operator and a safety attendant. A remotely operated inspection robot could reduce the need for personnel to enter the tank for selected inspection tasks.</p> </div> <div class="value-card time"> <h3>Time</h3> <p>Fuel-tank inspection involves preparation, access, inspection and restoration activities. SoftCrawl aims to improve accessibility by allowing a robot to navigate towards inspection locations while being controlled externally. This could reduce selected inspection-related activities, although actual time savings must be established through future operational studies.</p> </div> <div class="value-card money"> <h3>Cost</h3> <p>Reducing inspection-related aircraft downtime could provide financial benefits to airlines and MRO providers. However, potential savings depend on the aircraft type, maintenance procedure, labour requirements and actual reduction in downtime. The financial value of SoftCrawl is therefore currently a projected benefit rather than a demonstrated outcome.</p> </div> </div> <figure> <div class="img-placeholder">Value proposition: safety, time, cost</div> <figcaption>Figure 4. Proposed value of SoftCrawl across safety, time and cost.</figcaption> </figure>
1.6 Stakeholder Analysis

The development and implementation of SoftCrawl involve several stakeholders with different levels of influence and interest. A power–interest matrix was used to identify the stakeholders most relevant to the project.

Stakeholder	Interest	Influence	Engagement strategy
MRO teams and airlines	High	High	Manage closely
Aircraft maintenance technicians and inspection crews	High	Lower organisational influence	Keep informed and involved
Aviation regulators and industry bodies	Lower direct project interest	High	Keep satisfied
Passengers	Lower direct interest	Low	Monitor

Table 1. Stakeholder interest, influence and engagement strategy. {: .caption}

MRO teams and airlines are key decision-makers because they are responsible for maintenance operations, resource allocation and potential technology adoption.
Technicians and inspection crews are the primary intended users of the system. Their requirements influence the robot's usability, deployment process and inspection capabilities.
Regulatory authorities and industry bodies influence the safety and compliance requirements associated with aircraft maintenance technologies.
Passengers are indirect beneficiaries through potential improvements in aircraft maintenance and operational safety.
<figure> <div class="img-placeholder">Stakeholder power–interest matrix</div> <figcaption>Figure 5. Stakeholder power–interest matrix.</figcaption> </figure>
1.7 Primary User: Aircraft Maintenance Technicians

The primary intended users of SoftCrawl are aircraft maintenance technicians and inspection personnel. The robot is designed to support these users rather than replace their technical judgement.

Through remote operation, technicians could inspect difficult-to-access locations without physically entering every region of the fuel tank. This would allow maintenance personnel to focus on interpreting inspection information, identifying defects and determining appropriate maintenance actions.

Consequently, the robot's design must prioritise accessibility, controllability, inspection visibility and reliable attachment to internal tank surfaces.

1.8 Proposed User Journey

A proposed user journey was developed to illustrate how SoftCrawl could be incorporated into aircraft fuel-tank inspection.

The existing workflow may include fuel draining, ventilation, atmospheric testing, personnel entry, manual inspection and subsequent restoration activities. Under the proposed robotic workflow, a technician would deploy SoftCrawl through an existing access opening and remotely control its movement towards inspection locations. Inspection information would be transmitted to the operator for analysis, allowing potential defects to be identified without requiring direct human access to every inspection location. This approach could reduce selected manual entry and repositioning activities.

<div class="callout warning"> <p>Fuel removal, ventilation, atmospheric testing and other safety procedures cannot automatically be eliminated merely because inspection is performed remotely. Any changes would require assessment of the robot's electrical safety, fuel-vapour compatibility and applicable maintenance procedures.</p> </div> <figure> <div class="img-placeholder">Conventional vs proposed SoftCrawl inspection workflow</div> <figcaption>Figure 6. Conventional and proposed SoftCrawl inspection workflows.</figcaption> </figure>
1.9 Existing Inspection Technologies

Several inspection technologies have been investigated to address the accessibility challenges associated with aircraft fuel tanks.

<div class="card-grid"> <div class="feature-card"> <h3>Borescope</h3> <p>Rigid or flexible camera probes inspect internal regions through access openings. Established and relatively straightforward to operate, but reach and manoeuvrability are constrained by probe length and operator control.</p> </div> <div class="feature-card"> <h3>RANDE</h3> <p>The Remote Access Nondestructive Evaluation system uses an articulated robotic arm carrying inspection equipment. Its articulation lets it navigate around obstacles, but the external base and finite arm length constrain its accessible workspace.</p> </div> <div class="feature-card"> <h3>Eeloscope 1</h3> <p>An endoscopic inspection system propelled through fuel using fluid jets. Development encountered limitations from tether friction, insufficient propulsion and inspection through fuel.</p> </div> <div class="feature-card"> <h3>Eeloscope 2</h3> <p>Uses an externally controlled robotic arm and inspection extension to access internal fuel-tank regions. Its inspection reach remains dependent on the robotic arm and access geometry.</p> </div> <div class="feature-card"> <h3>Caterpillar robot</h3> <p>Proposes tracked locomotion along internal fuel-tank surfaces. Although it targets independent movement within the tank, full operational validation has not been established in the reviewed literature.</p> </div> </div> <figure> <div class="img-placeholder">Competitive landscape of existing fuel-tank inspection technologies</div> <figcaption>Figure 7. Competitive landscape of existing fuel-tank inspection technologies.</figcaption> </figure> <div class="callout"> <p><strong>Identified design gap.</strong> Existing approaches show different trade-offs between inspection reach, mobility, structural compliance and system complexity. Externally supported inspection tools remain constrained by their workspace, while independently mobile robotic concepts face challenges associated with navigation and validation. This motivates the investigation of a compact robotic platform combining compliant body deformation with controlled attachment to internal surfaces.</p> </div>
1.10 Why Soft Robotics?

Soft robotics uses compliant materials and deformable structures to achieve movement and interaction with the environment. Unlike conventional rigid robots, soft robotic structures can deform in response to geometric constraints and contact forces. These characteristics make soft robotics a promising approach for navigating confined environments containing irregular surfaces and obstacles.

Soft robots can achieve movement through several locomotion strategies, including crawling, climbing, growing and swimming.

<figure> <div class="img-placeholder">Soft robot locomotion strategies: crawling, climbing, growing, swimming</div> <figcaption>Figure 8. Soft robotic locomotion strategies.</figcaption> </figure>

For aircraft fuel-tank inspection, crawling and climbing were identified as the most relevant locomotion modes. Crawling enables movement along horizontal surfaces, while climbing provides access to vertical walls and other elevated inspection regions.

SoftCrawl adopts a pneumatically actuated Kresling-origami body to generate controlled deformation, combined with suction-cup adhesion to support locomotion.

1.11 System Requirements and Proposed Architecture

The proposed system must satisfy the following preliminary design requirements.

Category	Requirement
Geometry	Fit within a 300 × 200 mm access opening
Locomotion	Crawl and climb vertical surfaces
Corner traversal	Target 90° surface transitions
Adhesion	Individually controllable attachment and release
Surface interaction	Minimise damage to internal tank surfaces
Material compatibility	Withstand relevant fuel and oil exposure
Electrical safety	Minimise onboard electrical equipment; assess all components for hazardous-environment compatibility

Table 2. Preliminary system requirements. {: .caption}

The proposed architecture consists of a pneumatically actuated robot body, a suction-cup attachment subsystem, external pneumatic and control hardware, and an inspection interface.

<figure> <div class="img-placeholder">System architecture: robot body, suction cups, external pneumatics and control, inspection interface</div> <figcaption>Figure 9. Proposed SoftCrawl system architecture.</figcaption> </figure>

Sensitive control hardware and vacuum generation are intended to remain outside the fuel tank, with pneumatic lines supplying the robot. This architecture provides the basis for subsequent subsystem development, including the Kresling body and the Robot Legs adhesion mechanism.

<div class="callout result"> <p>The first-semester project focuses on validating the principal mechanical and pneumatic functions before attempting fully integrated locomotion and inspection.</p> </div>
References

<span class="todo">[Add references: Airbus A350 access panels, published maintenance / leak-testing account, RANDE, Eeloscope 1 and 2, Caterpillar robot, power–interest matrix source.]</span>