# Unit Test Specification: UT-PWR-003-A

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
returns from `SAFE` mode to `NORMAL` mode when battery voltage recovers from an
undervoltage condition and exceeds the lower safe voltage threshold by 5 %, provided
no blocking faults are present.

---

## 2. Requirements Verified

- REQ-PWR-003
- REQ-PWR-023

---

## 3. Test Level

Unit Test (UT)

---

## 4. Test Item

- Software module: PowerManager
- Functionality: Operational mode recovery logic

---

## 5. Preconditions

- PowerManager component is instantiated
- PowerManager state is `SAFE`
- SAFE mode was entered due to an undervoltage condition
- No external DDS communication is active
- No fault conditions are injected
- Sensor health status is reported as valid

---

## 6. Test Steps

The following steps are executed sequentially:

1. Initialize the PowerManager component
2. Force the operational mode to `SAFE` due to an undervoltage condition
3. Query the current operational mode
4. Inject a battery voltage value 24.0V, exceeding the lower safe voltage threshold by 5 %
5. Query the current operational mode

---

## 7. Expected Results

- The operational mode prior to voltage recovery is `SAFE`
- Upon injection of the recovery voltage condition, the PowerManager transitions to `NORMAL` mode

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Is initially in `SAFE` mode
  - Transitions to `NORMAL` mode after the recovery voltage condition is applied
- FAIL otherwise
