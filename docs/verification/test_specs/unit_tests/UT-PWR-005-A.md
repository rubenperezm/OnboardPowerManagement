# Unit Test Specification: UT-PWR-005-A

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
performs all operational mode transitions strictly in accordance with the defined
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
2. Request transition to `NORMAL` mode
3. Query the current operational mode
4. Request transition to `OFF` mode via internal trigger
5. Query the current operational mode
6. Request transition back to `NORMAL` mode via internal trigger
7. Query the current operational mode
8. Request transition to `SAFE` mode via internal trigger
9. Query the current operational mode
10. Request transition back to `NORMAL` mode via internal trigger
11. Query the current operational mode
12. Request transition back to `SAFE` mode via valid internal command
13. Query the current operational mode
14. Request transition to `SAFE` mode via internal trigger
15. Query the current operational mode
16. Request transition to `OFF` mode via valid internal command
17. Query the current operational mode
18. Request transition to `OFF` mode via invalid internal command
19. Query the current operational mode
---

## 7. Expected Results

- The PowerManager initially operates in `NORMAL` mode
- All requested transitions are executed successfully

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Executes all requested mode transitions successfully
  - Transitions only between defined operational modes
  - Adheres strictly to the operational mode definitions
  - The results of all mode queries match the expected operational modes after each transition request
- FAIL if any undefined transition or state is observed
