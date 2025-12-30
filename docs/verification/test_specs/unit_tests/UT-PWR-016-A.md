# Unit Test Specification: UT-PWR-016

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
ignores sensor data that is marked as invalid by the consolidated sensor health
information.

---

## 2. Requirements Verified

- REQ-PWR-016

---

## 3. Test Level

Unit Test (UT)

---

## 4. Test Item

- Software module: PowerManager
- Functionality: Handling of invalid sensor data based on sensor health information

---

## 5. Preconditions

- PowerManager component is instantiated
- PowerManager operational mode is `NORMAL`
- Configured voltage, current, and temperature thresholds are available
- No fault conditions are injected
- No DDS communication is active

---

## 6. Test Steps

The following steps are executed sequentially:

1. Initialize the PowerManager component
2. Confirm that the operational mode is `NORMAL`
3. Provide valid battery sensor measurements that would normally trigger a mode transition
4. Provide consolidated sensor health information indicating the sensor data as `INVALID`
5. Query the current operational mode and internal fault status

---

## 7. Expected Results

- The initial operational mode after initialization is `NORMAL`
- Sensor health information indicating `INVALID` is correctly consumed by the PowerManager
- Battery sensor measurements marked as invalid are ignored by the decision logic
- No operational mode transition is triggered based on invalid sensor data
- The operational mode remains `NORMAL`

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Correctly ignores sensor measurements flagged as invalid
  - Maintains the operational mode despite receiving sensor values that would otherwise trigger a transition
- FAIL otherwise
