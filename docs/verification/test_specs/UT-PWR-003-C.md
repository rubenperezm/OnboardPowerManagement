# Unit Test Specification: UT-PWR-003-C

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component does not
return from `SAFE` mode to `NORMAL` the lower safe voltage threshold is not exceeded by 5 %, provided
no blocking faults are present. The state should remain in `SAFE` mode when the voltage is still
outside the safe range.

---

## 2. Requirements Verified

- REQ-PWR-003
- NFR-PWR-004

---

## 3. Test Level

Unit Test (UT)

---

## 4. Test Item

- Software module: PowerManager
- Functionality: Operational mode recovery logic

---

## 5. Preconditions

- PowerManager component is instantiated
- PowerManager state is `SAFE`
- SAFE mode was entered due to an undervoltage condition
- No external DDS communication is active
- No fault conditions are injected
- Sensor health status is reported as valid

---

## 6. Test Steps

The following steps are executed sequentially:

1. Initialize the PowerManager component
2. Force the operational mode to `SAFE` due to an undervoltage condition
3. Query the current operational mode
4. Inject a battery voltage value 19.2V, outside the safe range
5. Query the current operational mode
6. Inject a battery voltage value 20.2V, not exceeding the lower safe voltage threshold by 5 %
7. Query the current operational mode

---

## 7. Expected Results

- The operational mode prior to voltage recovery is `SAFE`
- Upon injection of the first voltage conditions (19.2V), the PowerManager remains in `SAFE` mode
- Upon injection of the second voltage condition (20.2V), the PowerManager remains in `SAFE` mode


---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Is initially in `SAFE` mode
  - Remains in `SAFE` mode after both voltage conditions are applied
- FAIL otherwise
