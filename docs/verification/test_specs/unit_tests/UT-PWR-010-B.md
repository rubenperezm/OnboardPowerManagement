# Unit Test Specification: UT-PWR-008-B

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
does not flag overcurrent conditions when battery current values are within the configured current thresholds.

---

## 2. Requirements Verified

- REQ-PWR-010

---

## 3. Test Level

Unit Test (UT)

---

## 4. Test Item

- Software module: PowerManager
- Functionality: Overcurrent detection logic

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
3. Query the internal overcurrent detection status
4. Inject a battery current value above the configured upper current threshold
5. Query the internal overcurrent detection status
6. Inject a battery current value of within the configured recovery current thresholds
7. Query the internal overcurrent detection status

## 7. Expected Results

- The initial operational mode after initialization is `NORMAL`
- The overcurrent condition is not flagged by the PowerManager logic when current is within thresholds
- The injected current values are correctly identified as being within the configured thresholds

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Does not flag overcurrent condition when current is within thresholds
- FAIL otherwise
