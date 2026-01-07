# Integration Test Specification: IT-PWR-004

## 1. Purpose

The purpose of this integration test is to verify that the PowerManager
correctly transitions to the `OFF` operational mode upon reception of a valid
`OFF` mode command through the system communication interface.

This test validates the correct interaction between the command source
and the PowerManager.

---

## 2. Requirements Verified

- REQ-PWR-004

---

## 3. Test Level

Integration Test (IT)

---

## 4. Test Items

- PowerManager  
- SubsystemController (or command source module)  
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
2. Start the SubsystemController (or equivalent command publisher)
3. Verify that the current operational mode is `NORMAL`
4. Publish a valid `OFF` mode command via DDS
5. Allow the PowerManager to process the received command
6. Query the current operational mode

---

## 7. Expected Results

- Prior to command reception, the operational mode is `NORMAL`
- Upon reception of the valid `OFF` mode command:
  - The PowerManager transitions to `OFF`
  - No intermediate or undefined operational modes are entered

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Transitions to `OFF` mode after receiving the valid command
- FAIL otherwise
