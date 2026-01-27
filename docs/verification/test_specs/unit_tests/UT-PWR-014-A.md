# Unit Test Specification: UT-PWR-011-A

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
reacts to overtemperature conditions by transitioning to `SAFE` operational mode.

---

## 2. Requirements Verified

- REQ-PWR-014

---

## 3. Test Level

Unit Test (UT)

---

## 4. Test Item

- Software module: PowerManager
- Functionality: Overtemperature handling and mode transition logic

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
3. Inject a battery temperature value exceeding the maximum allowable temperature threshold
4. Query the current operational mode

## 7. Expected Results

- The initial operational mode after initialization is `NORMAL`
- The injected temperature value is detected as an overtemperature condition
- After the overtemperature condition, the PowerManager transitions to `SAFE` mode

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Transitions from `NORMAL` to `SAFE` mode as a result of the overtemperature condition
- FAIL otherwise
