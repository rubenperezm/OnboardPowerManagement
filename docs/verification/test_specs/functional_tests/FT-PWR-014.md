# Functional Test Specification: FT-PWR-014

## 1. Purpose

The purpose of this functional test is to verify that the Power Management
subsystem reacts to overtemperature conditions by limiting power usage or
transitioning to `SAFE` mode, in accordance with the defined operational logic.

This test validates the end-to-end behaviour of the subsystem when battery
temperature exceeds the normal operating range, as observed through external
interfaces and telemetry.

---

## 2. Requirements Verified

- REQ-PWR-014

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
- Nominal configuration parameters are loaded
- No fault injection is active
- Telemetry logging is enabled
- Initial operational mode is `NORMAL`
- Battery voltage and current are within nominal ranges

---

## 6. Test Steps

1. Start the complete Power Management subsystem
2. Verify via telemetry that the initial operational mode is `NORMAL`
3. Apply a battery temperature value within the normal operating range
4. Confirm via telemetry that the operational mode remains `NORMAL`
5. Apply a battery temperature value above the upper temperature limit
6. Observe subsystem behaviour via telemetry:
   - Power usage limitation signals, or
   - Operational mode transition
7. Verify that the subsystem either:
   - Limits power usage while remaining operational, or
   - Transitions to `SAFE` mode
8. Restore battery temperature to within the normal range
9. Verify subsystem behaviour according to recovery rules
10. Stop the subsystem

---

## 7. Expected Results

- The subsystem remains in `NORMAL` mode while battery temperature is within
  the normal operating range
- When an overtemperature condition is detected:
  - Power usage is limited, and/or
  - The subsystem transitions to `SAFE` mode
- Telemetry accurately reflects the detected temperature condition and
  corresponding system response
- No undefined or unsupported operational modes are observed

---

## 8. Pass / Fail Criteria

- PASS if:
  - The subsystem reacts to overtemperature conditions as specified
  - The reaction is observable through telemetry
  - Normal operation is maintained when temperature is within limits
- FAIL otherwise
