# Unit Test Specification: UT-PWR-024-A

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
sets the operational mode to `OFF` when a critical sensor failure is detected.
This ensures that the system enters a safe state in response to critical sensor faults.

---

## 2. Requirements Verified

- REQ-PWR-024

---

## 3. Test Level

Unit Test (UT)

---

## 4. Test Item

- Software module: PowerManager
- Functionality: Fault handling and operational mode management

---

## 5. Preconditions

- PowerManager component is instantiated
- Current operational mode is `NORMAL` or `SAFE`
- Critical sensor failure flag is initially `FALSE`
- No DDS communication is active

---

## 6. Test Steps

The following steps are executed sequentially:

1. Initialize the PowerManager component
2. Confirm that the operational mode is `NORMAL`
3. Inject a simulated critical sensor failure
4. Query the operational mode
5. Reset the critical sensor failure flag
6. Query the operational mode again

---

## 7. Expected Results

- Upon injection of the critical sensor failure:
  - Operational mode transitions immediately to `OFF`
  - Load control outputs are set to reflect an inactive/powered-off state
- After clearing the critical sensor failure:
  - Operational mode remains `OFF` until a valid command or reset is issued

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Transitions to `OFF` mode upon receiving a critical sensor failure flag
  - Maintains safe load control outputs while in `OFF` mode
- FAIL otherwise
