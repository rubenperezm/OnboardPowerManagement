# Unit Test Specification: UT-PWR-014-B

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
does not transition to `SAFE` operational mode if there are no overtemperature conditions.

---

## 2. Requirements Verified

- REQ-PWR-014
- REQ-PWR-023

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
3. Inject a battery temperature value below the minimum allowable temperature threshold
4. Query the current operational mode
5. Inject a battery temperature value above the maximum allowable temperature threshold
6. Query the internal overtemperature detection status
7. Inject a battery temperature value back within the allowable temperature range
8. Query the current operational mode
---

## 7. Expected Results

- The initial operational mode after initialization is `NORMAL`
- The injected temperature value is detected as an undertemperature condition
- The PowerManager remains in `NORMAL` mode
- The injected temperature value is detected as an overtemperature condition
- The overtemperature condition is correctly flagged by the PowerManager logic
- After returning to normal temperature conditions, the PowerManager remains in `NORMAL` mode

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Detects the sustained overtemperature condition
  - Remains in `NORMAL` mode after returning to normal temperature conditions
- FAIL otherwise
