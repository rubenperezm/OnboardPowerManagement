# Unit Test Specification: UT-PWR-010-A

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
detects overcurrent conditions based on configured current thresholds.

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
3. Inject a battery current value above the configured upper current threshold
4. Query the internal overcurrent detection status

---

## 7. Expected Results

- The initial operational mode after initialization is `NORMAL`
- The injected current value is identified as an overcurrent condition
- The overcurrent condition is correctly flagged by the PowerManager logic

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Correctly identifies the injected current as being above the configured upper threshold
  - Flags the overcurrent condition as detected
- FAIL otherwise
