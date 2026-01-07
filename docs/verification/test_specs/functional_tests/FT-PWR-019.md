# Functional Test Specification: FT-PWR-019

## 1. Purpose

The purpose of this functional test is to verify that the Power Management
subsystem provides telemetry outputs reflecting detected fault conditions and
sensor health status.

This test validates that fault detection and health evaluation results are
correctly exposed through telemetry and are observable by external consumers.

---

## 2. Requirements Verified

- REQ-PWR-019

---

## 3. Test Level

Functional Test (FT)

---

## 4. Test Items

- PowerManager  
- BatteryMonitor  
- SensorHealthManager  
- TelemetryLogger  
- DDS middleware

---

## 5. Preconditions

- All subsystem components are deployed and running
- DDS communication is active and operational
- Telemetry logging is enabled
- Nominal configuration parameters are loaded
- Initial operational mode is `NORMAL`
- All sensor health statuses are initially reported as valid
- No fault conditions are active

---

## 6. Test Steps

1. Start the complete Power Management subsystem
2. Subscribe to fault and health telemetry topics
3. Verify via telemetry that:
   - No faults are reported
   - Sensor health status is reported as nominal/valid
4. Inject a non-critical sensor fault (e.g. degraded voltage sensor)
5. Observe fault and health telemetry outputs
6. Inject a critical sensor fault via the SensorHealthManager
7. Observe fault and health telemetry outputs
8. Clear all injected faults
9. Observe fault and health telemetry outputs
10. Stop the subsystem

---

## 7. Expected Results

- When non-critical faults are injected:
  - Telemetry reports the presence of the fault
  - Sensor health status is reported as degraded
- When critical faults are injected:
  - Telemetry reports the critical fault condition
  - Sensor health status is reported as failed
- When faults are cleared:
  - Telemetry reflects the absence of fault conditions
  - Sensor health status returns to nominal/valid
- Telemetry updates accurately reflect the current fault and health state at all times

---

## 8. Pass / Fail Criteria

- PASS if:
  - Fault and health telemetry accurately reflects injected conditions
  - Telemetry updates occur consistently with fault state changes
- FAIL otherwise
