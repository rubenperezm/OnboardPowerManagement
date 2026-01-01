# Integration Test Specification: IT-PWR-512

## 1. Purpose

The purpose of this integration test is to verify that the Power Management
software supports the inclusion or removal of simulation-only components
without requiring modification of the core operational functionality.

This test ensures that the subsystem architecture cleanly separates
simulation-specific elements from flight-relevant logic.

---

## 2. Requirements Verified

- NFR-PWR-012

---

## 3. Test Level

Integration Test (IT)

---

## 4. Test Items

- PowerManager  
- BatteryMonitor  
- SensorHealthManager  
- TelemetryLogger  
- DDS middleware (Fast DDS)
- Simulation-only components (e.g. simulated battery or fault injectors)

---

## 5. Preconditions

- All software components are built from the same revision
- DDS communication is active and operational
- System configuration parameters are fixed
- Scheduler cycle period is fixed
- Telemetry logging is enabled
- Two system configurations are available:
  - Configuration A: with simulation-only components enabled
  - Configuration B: with simulation-only components disabled

---

## 6. Test Steps

1. Build and deploy the Power Management subsystem using Configuration A
   (simulation-only components enabled)
2. Start the complete subsystem
3. Apply a nominal sequence of input data
4. Record:
   - Operational mode transitions
   - Telemetry outputs
5. Stop the subsystem
6. Build and deploy the Power Management subsystem using Configuration B
   (simulation-only components disabled)
7. Start the complete subsystem
8. Apply the same nominal sequence of input data as in step 3
9. Record:
   - Operational mode transitions
   - Telemetry outputs
10. Compare the results from both configurations

---

## 7. Expected Results

- The subsystem operates correctly in both configurations
- Core operational behaviour (modes, transitions, decisions) is identical
  between Configuration A and Configuration B
- Telemetry content related to core functionality is identical
- The presence or absence of simulation-only components does not:
  - Alter operational logic
  - Introduce errors or undefined behaviour
- Any differences are limited strictly to simulation-only telemetry or logs

---

## 8. Pass / Fail Criteria

- PASS if:
  - Core functionality behaves identically with and without simulation-only components
  - No code or configuration changes to core modules are required
- FAIL otherwise
