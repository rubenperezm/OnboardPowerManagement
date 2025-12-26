# DDS Topics Definition

This document defines the **conceptual DDS topics** for inter-module communication within the Onboard Power Management Subsystem Simulator.

No IDL, types, or QoS settings are included at this stage; these will be defined later during interface implementation.

---

## 1. Operational Data Topics

### 1.1 BatteryMeasurements
- **Publisher:** BatteryMonitor
- **Subscribers:** PowerManager, TelemetryLogger
- **Description:** Provides current simulated battery measurements including voltage, current, and temperature. Operational input for the PowerManager to make mode decisions. Delivered to TelemetryLogger for logging.

### 1.2 LoadStatus
- **Publisher:** SubsystemController
- **Subscribers:** PowerManager, TelemetryLogger
- **Description:** Reports the status of downstream loads (enabled/disabled, power consumption). Used by PowerManager for load-dependent decisions and by TelemetryLogger for logging.

### 1.3 OperationalMode
- **Publisher:** GroundSimulator or SubsystemController
- **Subscribers:** PowerManager
- **Description:** Indicates the current high-level operational mode (e.g., NORMAL, SAFE, OFF).

---

## 2. Fault and Health Data Topics

### 2.1 FaultEvents
- **Publisher:** FaultInjector
- **Subscribers:** PowerManager, TelemetryLogger
- **Description:** Communicates injected fault events (sensor anomalies, overcurrent) for PowerManager response and logging.

### 2.2 SensorHealth
- **Publisher:** BatteryMonitor / FaultInjector
- **Subscribers:** PowerManager
- **Description:** Indicates sensor validity. PowerManager uses this to distinguish real anomalies from sensor failures.

- **Note:** As there are two possible publishers, a merging mechanism may be needed (a possible solution: a middleware ``SensorHealthManager`` that receives from both and publishes a consolidated status). This would mean:

#### 2.2.1 BatteryMonitorHealth
- **Publisher:** BatteryMonitor
- **Subscribers:** SensorHealthManager
- **Description:** Health status of battery sensors.

#### 2.2.2 FaultInjectorHealth
- **Publisher:** FaultInjector
- **Subscribers:** SensorHealthManager
- **Description:** Health status of sensors as affected by injected faults.

#### 2.2.3 SensorHealth
- **Publisher:** SensorHealthManager
- **Subscribers:** PowerManager
- **Description:** Consolidated health status of all sensors.

The SensorHealthManager would need to be defined and implemented as an additional module if this approach is taken.

---

## 3. Control and Configuration Topics

### 3.1 ModeCommands
- **Publisher:** GroundSimulator
- **Subscribers:** PowerManager, SubsystemController
- **Description:** Commands to force mode changes, reset faults, or alter load configuration.  
- **Note:** Simulates ground mission inputs in the lab environment.

### 3.2 ConfigurationParameters
- **Publisher:** GroundSimulator
- **Subscribers:** PowerManager
- **Description:** Provides adjustable parameters such as thresholds or operational limits.  
- **Note:** Used for simulation tuning and testing.

---

## 4. Power Management Output Topics

### 4.1 PowerCommands
- **Publisher:** PowerManager
- **Subscribers:** SubsystemController, TelemetryLogger
- **Description:** Sends mode commands and load control flags to SubsystemController.  
- **Purpose:** Operational control and telemetry logging.

---

## 5. Telemetry Topics

### 5.1 SensorTelemetry
- **Publisher:** BatteryMonitor
- **Subscribers:** TelemetryLogger
- **Description:** Provides sensor measurements with **additional metadata** for logging, analysis, and V&V.

### 5.3 FaultTelemetry
- **Publisher:** FaultInjector
- **Subscribers:** TelemetryLogger
- **Description:** Publishes fault events metadata for logging and verification.

### 5.4 LoadTelemetry
- **Publisher:** SubsystemController
- **Subscribers:** TelemetryLogger
- **Description:** Publishes downstream load status metadata for logging and monitoring.

### 5.2 TelemetryData
- **Publisher:** PowerManager
- **Subscribers:** TelemetryLogger
- **Description:** Publishes internal state, mode decisions, flags and metadata for logging and analysis.
---

## 6. Notes

- TelemetryLogger subscribes to **both operational topics (e.g., BatteryMeasurements) and metadata topics (e.g., SensorTelemetry)** to reconstruct full system behavior. Each module publishes an independent telemetry topic, in order to decouple operational logic from logging.
- OperationalMode and SensorHealth are not directly logged; their effects are reflected in outputs and other telemetry topics.
- Telemetry topics are **passive observers** and do not affect PowerManager behaviour.  
- GroundSimulator is a conceptual publisher used to simulate mission inputs in the lab environment.  
- Topic definitions are **conceptual at this stage**; IDL, QoS, and serialization will be defined later.
