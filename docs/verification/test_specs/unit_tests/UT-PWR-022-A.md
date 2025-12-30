# Unit Test Specification: UT-PWR-022-A

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
prioritizes system safety over performance when handling fault conditions.
This includes ensuring that operational mode transitions and load control
decisions always favor safe states when faults are detected.

---

## 2. Requirements Verified

- REQ-PWR-022

---

## 3. Test Level

Unit Test (UT)

---

## 4. Test Item

- Software module: PowerManager
- Functionality: Fault handling and safety prioritization

---

## 5. Preconditions

- PowerManager component is instantiated
- Operational mode is `NORMAL`
- Configured voltage, current, and temperature thresholds are available
- Sensor health information is valid
- Fault conditions can be injected
- No DDS communication is active

---

## 6. Test Steps

The following steps are executed sequentially:

1. Initialize the PowerManager component
2. Confirm that the operational mode is `NORMAL`
3. Inject a simulated minor sensor anomaly
4. Query the operational mode
5. Inject a simulated critical sensor failure
6. Query the operational mode

---

## 7. Expected Results

- Upon injection of a non-critical fault:
  - The operational mode transitions to `SAFE`
- Upon injection of a critical fault:
  - The operational mode transitions to `OFF`
  - All safety rules are enforced regardless of performance impact

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Correctly prioritizes safe operational states over performance when faults occur
  - Transitions to `SAFE` mode for non-critical fault conditions
  - Transitions to `OFF` mode for critical fault conditions
- FAIL otherwise
