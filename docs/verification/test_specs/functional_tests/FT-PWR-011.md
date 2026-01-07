# Functional Test Specification: FT-PWR-011

## 1. Purpose

The purpose of this functional test is to verify that the Power Management
subsystem reacts to sustained overcurrent conditions by transitioning to
`SAFE` mode.

This test validates the end-to-end behaviour of the subsystem when battery
current exceeds the maximum allowable current for a sustained duration, as
observed through external interfaces and telemetry.

---

## 2. Requirements Verified

- REQ-PWR-011
- REQ-PWR-023

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
- Battery voltage and temperature are within nominal ranges

---

## 6. Test Steps

1. Start the complete Power Management subsystem
2. Verify via telemetry that the initial operational mode is `NORMAL`
3. Apply a battery current value within the nominal range
4. Confirm via telemetry that the operational mode remains `NORMAL`
5. Apply a battery current value exceeding the maximum allowable current
6. Maintain the overcurrent condition for a duration exceeding the
   configured sustained overcurrent time
7. Verify via telemetry that the operational mode transitions to `SAFE`
8. Restore battery current to within nominal limits
9. Verify via telemetry that the operational mode remains `SAFE`
   (until recovery conditions are met as defined elsewhere)
10. Stop the subsystem

---

## 7. Expected Results

- The subsystem remains in `NORMAL` mode while battery current is within
  nominal limits
- Upon detection of a sustained overcurrent condition:
  - The subsystem transitions to `SAFE` mode
- Telemetry accurately reflects the detected overcurrent condition and the
  operational mode transition
- No undefined or unsupported operational modes are observed

---

## 8. Pass / Fail Criteria

- PASS if:
  - The subsystem transitions to `SAFE` mode only after the overcurrent
    condition is sustained for the configured duration
  - The subsystem remains in `NORMAL` mode for nominal current conditions
  - Telemetry consistently reports the correct operational mode and fault status
- FAIL otherwise
