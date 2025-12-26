# Project Scope

## 1. Purpose

The purpose of this project is to develop a **flight-like simulator of an on-board Power Management subsystem**, focusing on **software architecture, decision logic, and system behaviour** rather than hardware implementation.

The project is intended as an **engineering demonstrator**, showing how an on-board software subsystem can be designed, implemented, verified, and analysed following **ECSS-like practices**.

---

## 2. Project Objectives

The main objectives of the project are:

- To simulate a **Power Management decision-making function** under nominal and off-nominal conditions
- To design a **modular and distributed architecture** using DDS publish/subscribe communication
- To implement **deterministic execution logic** suitable for embedded and on-board contexts
- To demonstrate **fault handling, mode management, and telemetry generation**
- To provide **reproducible verification and validation evidence**

---

## 3. What's Included

The project includes the following elements:

### 3.1 Software Scope

- A **Power Manager module** responsible for:
  - Monitoring power-related inputs
  - Estimating internal power state
  - Managing operational modes (e.g. NORMAL, SAFE, OFF)
- Simulated sensor modules (e.g. voltage, current)
- A **Fault Injection module** to trigger off-nominal scenarios
- A **Telemetry Logger module** for data recording and analysis
- Inter-module communication implemented via **DDS (publish/subscribe)**
- A basic deterministic scheduler suitable for simulation purposes

### 3.2 Engineering Scope
- Definition of clear module responsibilities
- Data modelling using IDL
- Separation of flight-like logic and non-critical tooling
- Basic verification and validation activities
- Documentation of design decisions and trade-offs

---

## 4. What's NOT included

The following elements are **out of scope** for this project:

- Real flight hardware or hardware-in-the-loop testing
- Real-time operating systems (RTOS)
- Detailed electrochemical battery models
- Electrical or thermal physical modelling
- Full satellite system simulation

The project is **not intended to represent a complete spacecraft**, but a focused on-board software subsystem.

The project applies a partial V-model approach, limited to the software subsystem responsibilities, and does not aim to cover the full system-level V-model lifecycle.

---

## 5. Assumptions

- The system runs in a Linux-based environment
- Timing requirements are simulated and not hard real-time
- Sensor data is simulated and idealised unless faults are injected
- DDS configuration is kept simple and suitable for demonstration
