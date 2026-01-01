# Integration Test Specification: IT-PWR-019

## 1. Purpose

The purpose of this integration test is to verify that the PowerManager
publishes telemetry data that correctly reflects fault and health conditions.

This test validates the correct interaction between the PowerManager,
the DDS middleware, and the TelemetryLogger.

---

## 2. Requirements Verified

- REQ-PWR-019

---

## 3. Test Level

Integration Test (IT)

---

## 4. Test Items

- PowerManager  
- TelemetryLogger  
- DDS middleware (Fast DDS)

---

## 5. Preconditions

- PowerManager is instantiated and running
- DDS communication is active and operational
- TelemetryLogger is subscribed to the operational mode telemetry topic
- No fault conditions are present
- PowerManager initial operational mode is `NORMAL`
- Telemetry logging is enabled

---

## 6. Test Steps

1. Start the PowerManager component
2. Start the TelemetryLogger component
3. Verify that an initial telemetry message is published indicating no faults and healthy status
4. Simulate a fault condition in the PowerManager (e.g., overcurrent, undervoltage)
5. Allow the PowerManager to process the fault condition
6. Observe and record telemetry messages published after the fault condition is detected
7. Clear the fault condition
8. Allow the PowerManager to recover from the fault condition
9. Observe and record telemetry messages published after fault recovery

---

## 7. Expected Results

- Telemetry messages are published indicating no faults and healthy status prior to fault injection
- Upon detection of the simulated fault condition:
  - The PowerManager publishes telemetry reflecting the detected fault condition
- Upon recovery from the fault condition:
  - The PowerManager publishes telemetry reflecting the healthy status

---

## 8. Pass / Fail Criteria

- PASS if telemetry outputs correctly reflect each fault condition and recovery, without missing or incorrect data
- FAIL otherwise
