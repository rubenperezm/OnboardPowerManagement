# Functional Test Specification: FT-PWR-020

## 1. Purpose

The purpose of this functional test is to verify that the Power Management
subsystem provides telemetry outputs reflecting sensor measurements.

This test validates that sensor data acquired by the subsystem (e.g. battery
voltage, current, and temperature) is correctly published via telemetry and can
be observed by external consumers without alteration.

---

## 2. Requirements Verified

- REQ-PWR-020

---

## 3. Test Level

Functional Test (FT)

---

## 4. Test Items

- BatteryMonitor  
- TelemetryLogger  
- DDS middleware

---

## 5. Preconditions

- All subsystem components are deployed and running
- DDS communication is active and operational
- Telemetry logging is enabled
- Nominal configuration parameters are loaded
- Sensor health status is reported as valid

---

## 6. Test Steps

1. Start the Power Management subsystem
2. Subscribe to sensor measurement telemetry topics
3. Inject nominal battery sensor measurements:
   - Voltage
   - Current
   - Temperature
4. Observe telemetry outputs
5. Inject updated sensor measurements with different valid values
6. Observe telemetry outputs
7. Inject out-of-range sensor measurements while sensor health remains valid
8. Observe telemetry outputs
9. Stop the subsystem

---

## 7. Expected Results

- Telemetry publishes sensor measurements corresponding to injected values
- Published telemetry values match injected sensor measurements
- Telemetry updates occur for each new sensor measurement
- Telemetry reflects sensor measurements independently of operational mode changes
- Out-of-range measurements are still reported as measurements (not filtered),
  with any associated fault or health information handled separately

---

## 8. Pass / Fail Criteria

- PASS if:
  - Telemetry consistently reflects injected sensor measurements
  - No loss or corruption of measurement data is observed
- FAIL otherwise
