# Functional Test Specification: FT-PWR-018

## 1. Purpose

The purpose of this functional test is to verify that the Power Management
subsystem provides telemetry outputs that accurately reflect the current
operational mode.

This test validates that operational mode changes are correctly propagated to
telemetry consumers and that telemetry remains consistent with the internal
state of the PowerManager.

---

## 2. Requirements Verified

- REQ-PWR-018

---

## 3. Test Level

Functional Test (FT)

---

## 4. Test Items

- PowerManager  
- TelemetryLogger  
- DDS middleware

---

## 5. Preconditions

- All subsystem components are deployed and running
- DDS communication is active and operational
- Telemetry logging is enabled
- Nominal configuration parameters are loaded
- Initial operational mode is `NORMAL`
- No fault conditions are active

---

## 6. Test Steps

1. Start the Power Management subsystem
2. Subscribe to the operational mode telemetry topic
3. Verify via telemetry that the reported operational mode is `NORMAL`
4. Trigger a transition to `SAFE` mode using a valid stimulus
   - Example: inject an out-of-range battery voltage condition
5. Observe telemetry outputs
6. Trigger a transition to `OFF` mode using a valid mode command
7. Observe telemetry outputs
8. Restore conditions allowing transition back to `NORMAL` mode
9. Observe telemetry outputs
10. Stop the subsystem

---

## 7. Expected Results

- Telemetry reports the correct operational mode at all times:
  - `NORMAL` during nominal operation
  - `SAFE` when safe conditions are triggered
  - `OFF` when an off command is issued
- Telemetry updates occur promptly after each operational mode transition
- No discrepancies exist between:
  - Internal operational mode state
  - Published telemetry operational mode

---

## 8. Pass / Fail Criteria

- PASS if:
  - Telemetry always reflects the current operational mode
  - All mode transitions are correctly reported via telemetry
- FAIL if:
  - Telemetry reports an incorrect or outdated operational mode
  - Telemetry updates are missing or inconsistent
