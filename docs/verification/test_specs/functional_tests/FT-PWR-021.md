# Functional Test Specification: FT-PWR-021

## 1. Purpose

The purpose of this functional test is to verify that the Power Management
subsystem detects fault conditions that affect power availability and responds
appropriately to those conditions.

This test validates the end-to-end behaviour of fault detection, decision-making,
and response mechanisms when power availability is compromised.

---

## 2. Requirements Verified

- REQ-PWR-021

---

## 3. Test Level

Functional Test (FT)

---

## 4. Test Items

- PowerManager  
- BatteryMonitor  
- SensorHealthManager  
- SubsystemController  
- TelemetryLogger  
- DDS middleware

---

## 5. Preconditions

- All subsystem components are deployed and running
- DDS communication is active and operational
- Telemetry logging is enabled
- Nominal configuration parameters are loaded
- Initial operational mode is `NORMAL`
- All sensor health statuses are initially reported as valid
- Electrical loads are enabled and operating nominally

---

## 6. Test Steps

1. Start the complete Power Management subsystem
2. Verify via telemetry that:
   - Operational mode is `NORMAL`
   - Power availability is nominal
3. Inject a fault condition affecting power availability
   - Example: sustained overcurrent or undervoltage condition
4. Observe subsystem behaviour via telemetry and load control outputs
5. Inject an additional fault further reducing power availability
6. Observe subsystem behaviour via telemetry and load control outputs
7. Clear all injected fault conditions
8. Observe subsystem recovery behaviour
9. Stop the subsystem

---

## 7. Expected Results

- Upon detection of a fault affecting power availability:
  - The fault condition is detected and reported via telemetry
  - The PowerManager responds by adjusting operational mode and/or load control
- Possible responses include:
  - Transition to `SAFE` mode
  - Disabling non-essential loads
  - Limiting power consumption
- When fault conditions are cleared:
  - The subsystem recovers in accordance with defined recovery logic
- Telemetry accurately reflects:
  - Detected faults
  - Operational mode
  - Power availability status
  - Load control decisions

---

## 8. Pass / Fail Criteria

- PASS if:
  - Fault conditions affecting power availability are detected
  - Appropriate operational responses are applied
  - Telemetry accurately reflects detection and response
- FAIL otherwise
