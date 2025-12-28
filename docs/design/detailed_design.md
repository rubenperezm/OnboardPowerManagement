# Detailed Design Document
**Environment:** C++17, DDS-based middleware (Fast DDS), Linux  
**Modules:** BatteryMonitor, FaultInjector, SensorHealthManager, PowerManager, SubsystemController, TelemetryLogger  

---

## 1. Overview

This document describes the detailed design of the Onboard Power Management Subsystem simulator.  
It specifies:

- Module responsibilities and interfaces  
- Data flow between modules  
- DDS topics and QoS configurations  
- Scheduler and timing considerations  
- Threading model and deterministic execution  
- Fault injection configuration  

The design is **ready for implementation** while remaining platform and middleware independent at a conceptual level.

This document contains the final design of the system and supersedes any preliminary design documents. Any inconsistencies should be resolved in favour of this document.

---

## 2. Module Design

### 2.1 BatteryMonitor

**Responsibilities:**

- Acquire battery measurements: voltage, current, temperature  
- Evaluate basic sensor health (range checks, timeout detection)  
- Publish `BatteryMeasurements` to DDS  
- Publish `LocalSensorHealthStatus` to SensorHealthManager  

```
Every 10 ms:
    V, I, T = read_sensors()
    battery_measurements = {V, I, T, timestamp}
    health_status = check_values(battery_measurements) 
    publish battery_measurements on BatteryMeasurements
    publish health_status on LocalSensorHealthStatus
```

**DDS Topics Published:**

- `BatteryMeasurements` → PowerManager, SensorHealthManager, TelemetryLogger  
- `LocalSensorHealthStatus` → SensorHealthManager, TelemetryLogger  

---

### 2.2 FaultInjector

**Responsibilities:**

- Simulate sensor faults according to configurable profiles  
- Publish altered `LocalSensorHealthStatus` to SensorHealthManager  
- Optional module, only active in simulation/testing  

```
Every 10 ms:
    If fault injection enabled:
        Select fault from profile  
        health_status = generate_faulty_status()
        publish health_status on LocalSensorHealthStatus
```
**DDS Topics Published:**

- `LocalSensorHealthStatus` → SensorHealthManager, TelemetryLogger  

---

### 2.3 SensorHealthManager

**Responsibilities:**

- Aggregate health status from BatteryMonitor and FaultInjector  
- Produce consolidated `SensorHealthStatus` for PowerManager  
- Provide telemetry to TelemetryLogger  

```
Every 10 ms:
    battery_health = receive from BatteryMonitor
    fault_health = receive from FaultInjector
    consolidated_health = aggregate(battery_health, fault_health)
    publish consolidated_health on SensorHealthStatus
```
**DDS Topics:**

- Subscribes: `LocalSensorHealthStatus` from BatteryMonitor and FaultInjector  
- Publishes: `SensorHealthStatus` → PowerManager, TelemetryLogger  

---

### 2.4 PowerManager

**Responsibilities:**

- Receive `BatteryMeasurements` and consolidated `SensorHealthStatus`  
- Evaluate system state (`NORMAL`, `SAFE`, `OFF`)  
- Publish `PowerCommands` (mode decisions)  
- Provide telemetry  

```
Every 10 ms:
    measurements = receive from BatteryMeasurements
    health_status = receive from SensorHealthStatus
    mode = evaluate_mode(measurements, health_status)
    publish mode on PowerCommands
```

**DDS Topics:**

- Subscribes: `BatteryMeasurements`, consolidated `SensorHealthStatus`  
- Publishes: `PowerCommands` → SubsystemController, TelemetryLogger  

---

### 2.5 SubsystemController

**Responsibilities:**

- Receive `PowerCommands` from PowerManager  
- Simulate subsystem loads and operational context  
- Publish `LoadStatus` feedback to PowerManager and TelemetryLogger  

```
Every 10 ms:
    mode = receive from PowerCommands
    update_load(mode)
    load_status = get_load_status()
    publish load_status on LoadStatus
```

**DDS Topics:**

- Subscribes: `PowerCommands`  
- Publishes: `LoadStatus` → PowerManager, TelemetryLogger  

---

### 2.6 TelemetryLogger

**Responsibilities:**

- Passive subscriber to all topics  
- Aggregate telemetry with metadata: timestamp, module name, topic  
- Store logs for offline analysis  
- No impact on control loops  

**Pseudocode Example:**

- Upon receiving any topic:
  - Capture data with timestamp  
  - Store in local buffer  
  - Write asynchronously to disk or generate plot-ready files  

**DDS Topics Subscribed:**

- `BatteryMeasurements`, `SensorHealthStatus`, `PowerCommands`, `LoadStatus`  

---

## 3. DDS Configuration

- Middleware: eProsima Fast DDS (conceptual)  
- Topics and QoS:

| Topic                  | Reliability | History     | Deadline |
|------------------------|------------|------------|---------|
| BatteryMeasurements     | RELIABLE   | KEEP_LAST  | 10 ms   |
| SensorHealthStatus      | RELIABLE   | KEEP_LAST  | 10 ms   |
| PowerCommands           | RELIABLE   | KEEP_LAST  | 10 ms   |
| LoadStatus              | RELIABLE   | KEEP_LAST  | 10 ms   |
| TelemetryPackets        | BEST_EFFORT| KEEP_LAST  | -       |

- Each module has a **single DomainParticipant**, multiple publishers/subscribers as needed  

---

## 4. Scheduler and Timing

- Each module executes in its **own thread**  
- Fixed loop period: 10 ms  
- Deterministic execution required  
- Non-blocking callbacks for DDS  
- Logging done asynchronously to avoid affecting control loops  

---

## 5. Fault Injection

- Configurable via JSON or YAML profile  
- Generates altered sensor health status only  
- Does not change actual measurements  
- Supports multiple fault types: DEGRADED, FAILED, intermittent  

---

## 6. Threading Model

- Modules run independently in threads  
- DDS topics used for communication, no shared memory  
- PowerManager and SensorHealthManager subscribe asynchronously to input topics  
- BatteryMonitor and FaultInjector publish asynchronously  
- TelemetryLogger passive and asynchronous  

---

## 7. Data Flow

| From                   | To                        | Topic                  | Purpose                     |
|------------------------|--------------------------|-----------------------|-----------------------------|
| BatteryMonitor         | PowerManager             | BatteryMeasurements    | Raw sensor data             |
| BatteryMonitor         | SensorHealthManager      | SensorHealthStatus     | Local health                |
| FaultInjector          | SensorHealthManager      | SensorHealthStatus     | Simulated faults            |
| SensorHealthManager    | PowerManager             | SensorHealthStatus     | Consolidated health         |
| PowerManager           | SubsystemController      | PowerCommands          | Mode commands               |
| SubsystemController    | PowerManager             | LoadStatus             | Load feedback               |
| All modules            | TelemetryLogger          | All topics             | Logging and analysis        |

---

## 8. Deliverables

- The detailed design document (this file)
- DDS IDL files for all topics  
- Module interface definitions (header files with method signatures)  
- Scheduler / loop description  
- QoS and threading specifications  
- Fault injection profiles  

---

## 9. Notes

- Architecture supports simulation **with or without fault injection**  
- Deterministic scheduler ensures reproducibility  
- TelemetryLogger is passive, does not affect control logic