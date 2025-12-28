# Module Overview

This document describes the main software modules of the Power Management Subsystem Simulator and their respective responsibilities.

---

## 1. BatteryMonitor

**Role:** Simulated power sensor module

**Description:**  
The BatteryMonitor module simulates the behaviour of power-related sensors and provides electrical measurements to the rest of the system.

**Responsibilities:**
- Generate simulated voltage, current, and temperature measurements
- Publish sensor data
- Support nominal and degraded sensor behaviour
- Provide time-consistent data suitable for deterministic processing

---

## 2. PowerManager

**Role:** Core power management logic

**Description:**  
The PowerManager module implements the main decision-making logic of the subsystem. It evaluates incoming power data, estimates internal power state, and manages operational modes.

**Responsibilities:**
- Consume power-related data
- Maintain an internal representation of the power state
- Manage subsystem operational modes
- Detect off-nominal conditions and trigger protective actions
- Publish power management decisions and status

---

## 3. FaultInjector

**Role:** Off-nominal scenario generator

**Description:**  
The FaultInjector module is used to introduce controlled faults and disturbances into the system in order to evaluate PowerManager behaviour under non-nominal conditions.

**Responsibilities:**
- Inject simulated sensor faults and power anomalies
- Control fault activation timing and duration
- Publish fault information
- Support repeatable and reproducible fault scenarios

**Notes:**  
This module exists primarily to support verification and validation activities and is not part of the operational power management logic.

---

## 4. SubsystemController

**Role:** Simulated load and mode controller

**Description:**  
The SubsystemController module represents downstream subsystems or loads that are affected by power management decisions.

**Responsibilities:**
- Communicates to PowerManager mode and command outputs
- Simulate enabling and disabling of loads
- Reflect system-level effects of power management decisions
- Publish status information (if required)
---

## 5. TelemetryLogger

**Role:** Telemetry collection and logging module

**Description:**  
The TelemetryLogger module collects telemetry data and records it for analysis and verification purposes.

**Responsibilities:**
- Subscribe to sensor, power management, and fault topics
- Log telemetry data in a deterministic and reproducible format
- Support post-processing and analysis workflows
- Provide data suitable for plotting and reporting

**Notes:**  
This module is non-critical and intentionally decoupled from the operational logic. It supports verification, validation, and engineering analysis.

## 6. SensorHealthManager
**Role:** Sensor health status aggregator
**Description:**
The SensorHealthManager module consolidates health status information from multiple BatteryMonitor and FaultInjector modules to provide a unified view of sensor validity to the PowerManager.

**Responsibilities:**
- Receive health status from BatteryMonitor and FaultInjector
- Aggregate and evaluate sensor health data
- Send consolidated sensor health status to PowerManager
---

# Boundaries of Modules
The boundaries of the modules within the Onboard Power Management subsystem are defined in this document to ensure clear separation of responsibilities and facilitate integration.

All module boundaries are treated as formal software interfaces, allowing independent development, testing, and verification of each module.

- **BatteryMonitor, FaultInjector → SensorHealthManager, TelemetryLogger**: Provide individual sensor health status.
- **SensorHealthManager → PowerManager**: Provides consolidated sensor health status.
- **BatteryMonitor → PowerManager, TelemetryLogger**: Provides simulated power sensor measurements (voltage, current, temperature).
- **PowerManager → SubsystemController, TelemetryLogger**: Sends power management decisions and mode commands.
- **SubsystemController → PowerManager, TelemetryLogger**: Provides load status and operational context feedback.

The telemetry logging module is designed to be non-intrusive and does not affect the operational behaviour of the other modules.