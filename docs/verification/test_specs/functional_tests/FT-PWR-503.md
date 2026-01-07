# Functional Test Specification: FT-PWR-503

## 1. Purpose

The purpose of this functional test is to verify that the Power Management
subsystem processes operational mode transitions within a bounded time `X_MODE`
after detection of triggering conditions.

This test evaluates the end-to-end timing of the subsystem from sensor input
detection to the observable mode change and telemetry reporting.

---

## 2. Requirements Verified

- NFR-PWR-003

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
- Nominal system configuration is loaded
- Initial operational mode is `NORMAL`
- Scheduler cycle period is fixed
- No fault injection is active
- Sensor measurements are within nominal ranges

---

## 6. Test Steps

1. Start the complete Power Management subsystem
2. Verify initial operational mode is `NORMAL`
3. Inject a triggering condition that should cause a mode transition:
   - Example: battery voltage below the safe threshold
4. Record the timestamp of the input detection
5. Observe operational mode change via telemetry
6. Record the timestamp of the mode change
7. Repeat steps 3–6 for different triggering conditions:
   - Overvoltage, overcurrent, overtemperature, etc.
8. Stop the subsystem

---

## 7. Expected Results

- The subsystem transitions to the expected operational mode for each triggering condition
- The time elapsed between input detection and mode transition does not exceed `X_MODE`
- Telemetry accurately reflects the detected triggering condition and resulting mode

---

## 8. Pass / Fail Criteria

- PASS if:
  - All mode transitions occur within the bounded time `X_MODE`
  - Telemetry accurately reports the mode transitions and triggering conditions
- FAIL otherwise
