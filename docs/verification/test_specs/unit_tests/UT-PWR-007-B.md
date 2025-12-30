# Unit Test Specification: UT-PWR-007-B

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
does not flag undervoltage conditions when battery voltage values are within the configured voltage thresholds.

---

## 2. Requirements Verified

- REQ-PWR-007

---

## 3. Test Level

Unit Test (UT)

---

## 4. Test Item

- Software module: PowerManager
- Functionality: Undervoltage detection logic

---

## 5. Preconditions

- PowerManager component is instantiated
- PowerManager operational mode is `NORMAL`
- Configured voltage thresholds are available
- No fault conditions are injected
- No DDS communication is active

---

## 6. Test Steps

The following steps are applied sequentially:

1. Initialize the PowerManager component
2. Query the current operational mode
3. Query the internal undervoltage detection status
4. Inject a battery voltage value below the configured lower voltage threshold
5. Query the internal undervoltage detection status
6. Inject a battery voltage value of within the configured recovery voltage thresholds
7. Query the internal undervoltage detection status

---

## 7. Expected Results

- The initial operational mode after initialization is `NORMAL`
- The undervoltage condition is not flagged by the PowerManager logic when voltage is within thresholds
- The injected voltage values are correctly identified as being within the configured thresholds

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Does not flag undervoltage condition when voltage is within thresholds
- FAIL otherwise
