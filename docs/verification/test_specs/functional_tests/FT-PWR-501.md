# Functional Test Specification: FT-PWR-501

## 1. Purpose

The purpose of this functional test is to verify that the Power Management
subsystem exhibits deterministic behaviour with respect to input processing and
output generation from an end-to-end perspective.

This test validates determinism at the system level, including interactions
between all modules and telemetry output, as opposed to focusing on a single
module in isolation (which is the scope of an integration test).

---

## 2. Requirements Verified

- NFR-PWR-001

---

## 3. Test Level

Functional Test (FT)

---

## 4. Test Items

- PowerManager  
- BatteryMonitor  
- SensorHealthManager  
- SubsystemController  
- TelemetryLogger  
- DDS middleware

---

## 5. Preconditions

- All subsystem components are deployed and running
- DDS communication is active and operational
- Telemetry logging is enabled
- System configuration parameters are fixed and identical across executions
- Scheduler cycle period is fixed
- No fault injection is active
- Initial operational mode is `NORMAL`
- Sensor measurements are within nominal ranges

---

## 6. Test Steps

1. Start the complete Power Management subsystem
2. Apply a predefined, time-stamped sequence of input data:
   - Battery voltage
   - Battery current
   - Battery temperature
   - Load status
3. Allow the system to operate for a fixed duration
4. Record all outputs:
   - Operational mode transitions
   - Telemetry messages (operational mode, sensor health, load control)
   - Timestamps of telemetry messages
5. Stop the subsystem
6. Repeat steps 1–5 at least three times with:
   - Identical input sequences
   - Identical system configuration
7. Compare recorded outputs from all executions for consistency

---

## 7. Expected Results

- All executions produce identical outputs:
  - Operational mode transitions are consistent
  - Telemetry messages content and ordering are identical
  - Timing differences are within defined scheduler tolerance
- No nondeterministic behaviour (missing, reordered, or inconsistent outputs) is observed

---

## 8. Pass / Fail Criteria

- PASS if:
  - Outputs from repeated executions match exactly within defined tolerances
- FAIL otherwise
