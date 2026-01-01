# Integration Test Specification: IT-PWR-012

## 1. Purpose

The purpose of this integration test is to verify that the PowerManager
correctly monitors battery temperature provided as input to the subsystem.

This test validates the correct interaction between the battery temperature sensor
and the PowerManager.

---

## 2. Requirements Verified

- REQ-PWR-012

---

## 3. Test Level

Integration Test (IT)

---

## 4. Test Items

- PowerManager  
- BatteryMonitor
- DDS middleware (Fast DDS)

---

## 5. Preconditions

- PowerManager is instantiated and running
- PowerManager initial operational mode is `NORMAL`
- DDS communication is active and operational
- No fault conditions are present
- Command interface topics are correctly configured

---

## 6. Test Steps

1. Start the PowerManager component
2. Start the BatteryMonitor component
3. Verify that the current operational mode is `NORMAL`
4. Publish a simulated battery temperature reading via DDS
5. Allow the PowerManager to process the received command
6. Query the current operational mode

---

## 7. Expected Results

- Prior to command reception, the operational mode is `NORMAL`
- Upon reception of the simulated battery temperature reading:
  - The PowerManager correctly monitors and processes the temperature input

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
    - Correctly monitors the battery temperature input
- FAIL otherwise
