# Unit Test Specification: UT-PWR-007-A

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
detects undervoltage conditions based on configured voltage thresholds.

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
3. Inject a battery voltage value below the configured lower voltage threshold
4. Query the internal undervoltage detection status

---

## 7. Expected Results

- The initial operational mode after initialization is `NORMAL`
- The injected voltage value is identified as an undervoltage condition
- The undervoltage condition is correctly flagged by the PowerManager logic

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Correctly identifies the injected voltage as being below the configured lower threshold
  - Flags the undervoltage condition as detected
- FAIL otherwise
