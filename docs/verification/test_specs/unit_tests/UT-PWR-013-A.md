# Unit Test Specification: UT-PWR-013-A

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
detects undesirable temperature conditions based on configured temperature thresholds.

---

## 2. Requirements Verified

- REQ-PWR-013

---

## 3. Test Level

Unit Test (UT)

---

## 4. Test Item

- Software module: PowerManager
- Functionality: Temperature detection logic

---

## 5. Preconditions

- PowerManager component is instantiated
- PowerManager operational mode is `NORMAL`
- Configured temperature thresholds are available
- No fault conditions are injected
- No DDS communication is active

---

## 6. Test Steps

The following steps are applied sequentially:

1. Initialize the PowerManager component
2. Query the current operational mode
3. Inject a battery temperature value above the configured upper temperature threshold
4. Query the internal undertemperature and overtemperature detection status
5. Inject a battery temperature value below the configured lower temperature threshold
6. Query the internal undertemperature and overtemperature detection status

---

## 7. Expected Results

  - The initial operational mode after initialization is `NORMAL`
  - The overtemperature condition is correctly flagged by the PowerManager logic
  - The undertemperature condition is correctly flagged by the PowerManager logic

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Correctly identifies the injected temperature as being above the configured upper threshold
  - Flags the overtemperature condition as detected
  - Correctly identifies the injected temperature as being below the configured lower threshold
  - Flags the undertemperature condition as detected
- FAIL otherwise
