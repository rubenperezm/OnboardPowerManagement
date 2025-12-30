# Unit Test Specification: UT-PWR-002-B

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
enters `SAFE` mode when battery voltage undergoes overvoltage conditions,
specifically when the voltage exceeds the normal range of 20.0V to 28.0V.

---

## 2. Requirements Verified

- REQ-PWR-002

---

## 3. Test Level

Unit Test (UT)

---

## 4. Test Item

- Software module: PowerManager
- Functionality: Operational mode management

---

## 5. Preconditions

- PowerManager component is instantiated
- PowerManager state is `NORMAL`
- No external DDS communication is active
- No fault conditions are injected

---

## 6. Test Steps

The following steps are applied sequentially:

1. Initialize the PowerManager component
2. Query the current operational mode
3. Inject battery voltage reading of 29.5V (above normal range)
4. Query the current operational mode

---

## 7. Expected Results
- The initial operational mode after initialization is `NORMAL`
- Upon injection of the overvoltage condition (29.5V), the PowerManager transitions to `SAFE` mode

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Initially is in `NORMAL` mode
  - Transitions to `SAFE` mode upon receiving the overvoltage condition
- FAIL otherwise
