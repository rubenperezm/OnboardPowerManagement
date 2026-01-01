# Integration Test Specification: IT-PWR-020

## 1. Purpose

The purpose of this integration test is to verify that the BatteryMonitor
publishes telemetry data that correctly reflects the sensor readings of the battery subsystem.

This test validates the correct interaction between the BatteryMonitor,
the DDS middleware, and the TelemetryLogger.

---

## 2. Requirements Verified

- REQ-PWR-020

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

- BatteryMonitor is instantiated and running
- DDS communication is active and operational
- TelemetryLogger is subscribed to the battery telemetry topic
- No fault conditions are present
- Telemetry logging is enabled

---

## 6. Test Steps

1. Start the BatteryMonitor component
2. Start the TelemetryLogger component
3. Verify that an initial telemetry message is published indicating normal battery readings
4. Simulate various battery sensor readings (e.g., voltage, current, temperature)
5. Allow the BatteryMonitor to process the simulated readings
6. Observe and record telemetry messages published after each simulated reading

---

## 7. Expected Results

- Telemetry messages are published for each simulated battery sensor reading
- Each telemetry message contains the correct sensor reading values:
  - Voltage reading
  - Current reading
  - Temperature reading
- Telemetry messages reflect the current battery sensor readings at the time of publication
- No inconsistent or missing battery telemetry is observed

---

## 8. Pass / Fail Criteria

- PASS if telemetry outputs correctly reflect each simulated battery sensor reading, without missing or incorrect data
- FAIL otherwise
