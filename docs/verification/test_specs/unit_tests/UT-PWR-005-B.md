# Unit Test Specification: UT-PWR-005-B

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
does not allow invalid operational mode transitions strictly in accordance with the defined
operational mode rules and definitions.

---

## 2. Requirements Verified

- REQ-PWR-005

---

## 3. Test Level

Unit Test (UT)

---

## 4. Test Item

- Software module: PowerManager
- Functionality: Operational mode transition logic

---

## 5. Preconditions

- PowerManager component is instantiated
- PowerManager initial operational mode is `NORMAL`
- No DDS communication is active
- No fault conditions are injected
- All input values are within nominal ranges

---

## 6. Test Steps

The following steps are applied sequentially:

1. Initialize the PowerManager component
4. Send shutdown command transition to `OFF` mode
5. Query the current operational mode
6. Send restart command transition back to `SAFE`
7. Query the current operational mode
---

## 7. Expected Results

- The PowerManager initially operates in `NORMAL` mode
- Request transition to `OFF` is executed successfully
- Upon request to transition back to `SAFE` mode, the PowerManager remains in `OFF` mode

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Executes the valid transition to `OFF` mode successfully
  - Remains in `OFF` mode when an invalid transition to `SAFE` mode is requested
- FAIL if any undefined transition or state is observed