# Functional Test Specification: FT-PWR-022

## 1. Purpose

The purpose of this functional test is to verify that the Power Management
subsystem prioritises system safety over performance when handling fault
conditions.

This test validates that, in the presence of faults, the subsystem consistently
selects conservative and safety-oriented responses rather than performance-
optimised behaviour.

---

## 2. Requirements Verified

- REQ-PWR-022

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
- All electrical loads are enabled and operating nominally

---

## 6. Test Steps

1. Start the complete Power Management subsystem
2. Verify nominal operation via telemetry
3. Inject a fault condition with potential safety implications
   - Example: battery undervoltage or overcurrent condition
4. Observe subsystem behaviour via telemetry and load control outputs
5. Inject a competing performance-oriented demand
   - Example: request to enable additional non-essential loads
6. Observe subsystem response
7. Clear all fault conditions
8. Observe subsystem recovery behaviour
9. Stop the subsystem

---

## 7. Expected Results

- When a fault condition is detected:
  - Safety-oriented actions are prioritised
  - Non-essential loads are disabled or limited
  - Operational mode transitions to a safer state if required
- Performance-oriented requests are:
  - Deferred
  - Rejected
  - Overridden by safety constraints
- Telemetry reflects:
  - Fault detection
  - Safety-driven decisions
  - Rejected or overridden performance requests
- Upon fault clearance:
  - Subsystem resumes nominal behaviour according to recovery logic

---

## 8. Pass / Fail Criteria

- PASS if:
  - Safety-related actions consistently override performance requests during faults
  - Subsystem behaviour aligns with safety-first principles
- FAIL otherwise
