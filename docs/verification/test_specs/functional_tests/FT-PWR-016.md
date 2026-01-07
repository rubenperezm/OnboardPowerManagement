# Functional Test Specification: FT-PWR-016

## 1. Purpose

The purpose of this functional test is to verify that the Power Management
subsystem ignores sensor data that is marked as invalid by the consolidated
sensor health information.

This test validates the end-to-end behaviour of the subsystem when invalid
sensor data is present, ensuring that operational decisions are not influenced
by data declared unreliable.

---

## 2. Requirements Verified

- REQ-PWR-016

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
- Sensor health status is initially reported as valid

---

## 6. Test Steps

1. Start the complete Power Management subsystem
2. Verify via telemetry that:
   - Operational mode is `NORMAL`
   - Sensor health status is reported as valid
3. Apply nominal battery sensor measurements
4. Confirm that the subsystem remains in `NORMAL` mode
5. Inject a sensor health status indicating invalid battery voltage data
6. Simultaneously inject an out-of-range battery voltage value
7. Observe subsystem behaviour via telemetry
8. Restore sensor health status to valid
9. Re-apply the same out-of-range battery voltage value
10. Observe subsystem behaviour via telemetry
11. Stop the subsystem

---

## 7. Expected Results

- While sensor data is marked as invalid:
  - The PowerManager ignores the associated sensor measurements
  - No operational mode transition is triggered by the invalid data
- When sensor health status is restored to valid:
  - The same out-of-range sensor data is correctly processed
  - The appropriate operational response (e.g. transition to `SAFE`) occurs
- Telemetry accurately reflects:
  - Sensor health status
  - Operational mode
  - Decisions taken by the PowerManager

---

## 8. Pass / Fail Criteria

- PASS if:
  - Invalid sensor data does not influence operational decisions
  - Valid sensor data is processed normally once health status is restored
  - Behaviour is consistent with telemetry observations
- FAIL otherwise
