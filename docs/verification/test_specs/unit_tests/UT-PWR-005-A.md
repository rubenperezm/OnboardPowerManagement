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
2. Inject battery measurements to transition to `NORMAL` mode
3. Query the current operational mode
4. Send shutdown command to the PowerManager to transition to `OFF` mode
5. Query the current operational mode
6. Send restart command to the PowerManager to transition to `NORMAL` mode
7. Query the current operational mode
8. Inject battery measurements to transition to `SAFE` mode
9. Query the current operational mode
10. Inject battery measurements to transition to `NORMAL` mode
11. Query the current operational mode
12. Inject battery measurements to transition to `SAFE` mode
13. Query the current operational mode
14. Inject battery measurements to transition to `SAFE` mode
15. Query the current operational mode
16. Inject sensor health status with failed sensors to transition to `OFF` mode
17. Query the current operational mode
18. Send shutdown command to transition to `OFF` mode
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
