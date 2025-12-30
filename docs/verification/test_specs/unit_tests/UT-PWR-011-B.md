# Unit Test Specification: UT-PWR-011-B

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
does not transition to `SAFE` operational mode if overcurrent conditions are not sustained.

---

## 2. Requirements Verified

- REQ-PWR-011
- REQ-PWR-023

---

## 3. Test Level

Unit Test (UT)

---

## 4. Test Item

- Software module: PowerManager
- Functionality: Overcurrent handling and mode transition logic

---

## 5. Preconditions

- PowerManager component is instantiated
- PowerManager operational mode is `NORMAL`
- Configured current thresholds are available
- No fault conditions are injected
- No DDS communication is active

---

## 6. Test Steps

The following steps are applied sequentially:

1. Initialize the PowerManager component
2. Query the current operational mode
3. Inject a battery current value exceeding the maximum allowable current threshold
4. Maintain the overcurrent condition for a duration less than the configured sustain time
5. Query the current operational mode

---

## 7. Expected Results

- The initial operational mode after initialization is `NORMAL`
- The injected current value is detected as an overcurrent condition
- After the brief overcurrent condition, the PowerManager remains in `NORMAL` mode

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Detects the sustained overcurrent condition
  - Remains in `NORMAL` mode after the brief overcurrent condition
- FAIL otherwise
