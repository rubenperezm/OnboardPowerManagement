# Functional Test Specification: FT-PWR-001

## 1. Purpose

The purpose of this functional test is to verify that the Power Management
subsystem operates exclusively in one of the defined operational modes:
`NORMAL`, `SAFE`, or `OFF`, and that it correctly transitions between these
modes under realistic input and command sequences.

This test validates the externally observable behaviour of the subsystem,
covering all operational modes.

---

## 2. Requirements Verified

- REQ-PWR-001

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
3. Apply input conditions that trigger a transition to `SAFE` mode
4. Verify via telemetry that the operational mode transitions to `SAFE`
5. Restore nominal input conditions
6. Verify via telemetry that the operational mode returns to `NORMAL`
7. Issue a valid `OFF` mode command via the external command interface
8. Observe and record the operational mode transitions
9. Stop the subsystem

---

## 7. Expected Results

- The subsystem only reports operational modes:
  - `NORMAL`
  - `SAFE`
  - `OFF`
- Mode transitions occur in the correct order:
  - `NORMAL` → `SAFE` → `NORMAL` → `OFF`
- Telemetry accurately reflects the current operational mode at all times
- No undefined or unsupported operational modes are observed

---

## 8. Pass / Fail Criteria

- PASS if:
  - The subsystem correctly transitions through `NORMAL`, `SAFE`, and `OFF`
  - Telemetry consistently reports the active operational mode
  - No undefined modes appear
- FAIL otherwise
