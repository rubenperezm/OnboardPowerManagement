# Functional Test Specification: FT-PWR-002

## 1. Purpose

The purpose of this functional test is to verify that the Power Management
subsystem transitions to `SAFE` mode when the battery voltage falls outside
the defined normal operating range (20.0V to 28.0V).

This test validates the end-to-end behaviour of the subsystem under
undervoltage and overvoltage conditions, as observed through external
interfaces and telemetry.

---

## 2. Requirements Verified

- REQ-PWR-002
- REQ-PWR-003
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

---

## 6. Test Steps

1. Start the complete Power Management subsystem
2. Verify via telemetry that the initial operational mode is `NORMAL`
3. Apply a battery voltage input within the normal range
4. Confirm via telemetry that the operational mode remains `NORMAL`
5. Apply an undervoltage condition (battery voltage below 20.0V)
6. Verify via telemetry that the operational mode transitions to `SAFE`
7. Restore battery voltage to within the normal range
8. Verify via telemetry that the operational mode returns to `NORMAL`
9. Apply an overvoltage condition (battery voltage above 28.0V)
10. Verify via telemetry that the operational mode transitions to `SAFE`
11. Stop the subsystem

---

## 7. Expected Results

- The subsystem remains in `NORMAL` mode when battery voltage is within the
  defined normal range
- The subsystem transitions to `SAFE` mode when:
  - Battery voltage is below the lower threshold, or
  - Battery voltage is above the upper threshold
- Telemetry accurately reflects all operational mode transitions
- No undefined or unsupported operational modes are observed

---

## 8. Pass / Fail Criteria

- PASS if:
  - The subsystem enters `SAFE` mode for both undervoltage and overvoltage conditions
  - The subsystem remains in `NORMAL` mode for nominal voltage conditions
  - Telemetry consistently reports the correct operational mode
- FAIL otherwise
