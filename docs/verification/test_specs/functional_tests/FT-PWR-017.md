# Functional Test Specification: FT-PWR-017

## 1. Purpose

The purpose of this functional test is to verify that the Power Management
subsystem continues operation in a degraded mode when non-critical sensor faults
are detected.

This test validates that the subsystem maintains partial functionality and does
not transition to a fully safe or off state when faults classified as
non-critical are present.

---

## 2. Requirements Verified

- REQ-PWR-017

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
- Nominal configuration parameters are loaded
- Telemetry logging is enabled
- Initial operational mode is `NORMAL`
- Battery voltage, current, and temperature are within nominal ranges
- All sensor health statuses are initially reported as valid

---

## 6. Test Steps

1. Start the complete Power Management subsystem
2. Verify via telemetry that:
   - Operational mode is `NORMAL`
   - Sensor health status is reported as valid
3. Inject a non-critical sensor fault via the SensorHealthManager
   - Example: sensor health status reported as `DEGRADED`
4. Maintain nominal battery voltage, current, and temperature inputs
5. Observe subsystem behaviour via telemetry
6. Inject additional non-critical sensor faults affecting multiple measurements
7. Observe subsystem behaviour via telemetry
8. Restore all sensor health statuses to valid
9. Observe subsystem behaviour via telemetry
10. Stop the subsystem

---

## 7. Expected Results

- Upon detection of non-critical sensor faults:
  - The PowerManager does not transition to `OFF` mode
  - The PowerManager does not enter a fully safe shutdown state
  - The subsystem continues operating in a degraded mode
- Degraded operation may include:
  - Reduced load availability
  - Conservative power management decisions
- Telemetry accurately reflects:
  - Degraded sensor health status
  - Continued subsystem operation
  - Any limitations applied due to degraded operation
- When sensor health is restored:
  - The subsystem resumes nominal operation

---

## 8. Pass / Fail Criteria

- PASS if:
  - Non-critical sensor faults do not cause a shutdown or unsafe state
  - The subsystem continues operating in a degraded but controlled manner
  - Telemetry reflects the correct operational and health status
- FAIL otherwise
