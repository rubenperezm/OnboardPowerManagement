# Integration Test Specification: IT-PWR-018

## 1. Purpose

The purpose of this integration test is to verify that the PowerManager
publishes telemetry data that correctly reflects the current operational mode
of the subsystem.

This test validates the correct interaction between the PowerManager,
the DDS middleware, and the TelemetryLogger.

---

## 2. Requirements Verified

- REQ-PWR-018

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
3. Verify that an initial telemetry message is published indicating operational mode `NORMAL`
4. Request a transition to `SAFE` mode via the PowerManager internal interface or command input
5. Allow the PowerManager to process the mode transition
6. Observe and record telemetry messages published after the transition
7. Request a transition to `OFF` mode
8. Allow the PowerManager to process the mode transition
9. Observe and record telemetry messages published after the transition

---

## 7. Expected Results

- Telemetry messages are published for each operational mode
- Each telemetry message contains the correct operational mode value:
  - `NORMAL` after initialization
  - `SAFE` after the SAFE mode transition
  - `OFF` after the OFF mode transition
- Telemetry messages reflect the current operational mode at the time of publication
- No inconsistent or missing operational mode telemetry is observed

---

## 8. Pass / Fail Criteria

- PASS if telemetry outputs correctly reflect each operational mode transition, without missing or incorrect data
- FAIL otherwise
