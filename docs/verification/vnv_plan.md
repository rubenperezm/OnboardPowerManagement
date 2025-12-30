# Verification and Validation Plan

## 1. Purpose

This document defines the **Verification and Validation (V&V) strategy** for the On-board Power Management Subsystem Simulator.  
The objective is to demonstrate that the software implementation **correctly satisfies the defined software requirements** and behaves as expected under nominal and off-nominal conditions.

This V&V plan is defined **prior to implementation** to ensure testability and traceability.

---

## 2. Scope

The V&V activities cover:

- Software functional requirements
- Software non-functional requirements (timing, robustness, logging)
- Interfaces and data exchange via DDS
- Power management logic and state transitions

The following are **out of scope**:

- Hardware-level validation
- Electrical accuracy validation of real batteries
- Mission-level validation

---

## 3. Verification Strategy

### 3.1 Verification Levels

| Level | Description |
|-----|------------|
| Unit Verification | Verification of individual modules (BatteryMonitor, SensorHealthManager, PowerManager, etc.) |
| Software Integration Verification | Verification of interactions between modules via DDS |
| Functional Verification | Verification of end-to-end power management behavior |

---

### 3.2 Verification Methods

| Method | Description |
|------|------------|
| Test | Execution of unit, integration, or functional tests |
| Analysis | Offline analysis of telemetry logs and timing |
| Inspection | Review of design and requirement consistency |

---

### 3.3 Requirement Coverage

Each requirement shall be:

- Assigned a unique identifier (REQ-PWR-XXX)
- Verified by at least one test case
- Traceable to:
  - Design elements
  - Test cases
  - Test results

---

## 4. Validation Strategy

Validation is performed at **subsystem functional level** using realistic operational scenarios:

- Nominal power operation
- Undervoltage events
- Overcurrent conditions
- Temperature limit violations
- Fault injection scenarios

Validation focuses on:

- Correct operational mode transitions
- Stability and determinism of behavior
- Consistency of telemetry outputs

---

## 5. Test Types

### 5.1 Unit Tests

- Implemented in C++
- Focus on isolated logic
- Mocked DDS interfaces where applicable

---

### 5.2 Software Integration Tests

- Validate DDS communication between modules
- Verify correct topic usage and data propagation
- Verify behavior under delayed or missing data

---

### 5.3 Functional Tests

- Implemented in Python
- Drive the simulator using predefined scenarios
- Validate outputs and telemetry against expected behavior

---

## 6. Acceptance Criteria

A requirement is considered **verified** when:

- All associated test cases pass
- No blocking anomalies are detected
- Timing and performance constraints are respected

A validation scenario is considered **successful** when:

- System behavior matches expected operational logic
- No undefined or unstable states are observed

---

## 7. Traceability

A traceability matrix shall be maintained linking:

- Requirements → Test Cases → Test Results

Traceability data shall be **automatically generated** from test metadata and results.

---

## 8. Test Environment

- OS: Linux (Ubuntu 22.04)
- Language: C++17, Python 3
- Middleware: DDS (Fast DDS)
- Tooling: CMake, pytest, GitHub Actions

---

## 9. Limitations

This V&V plan does not aim to replace mission-level qualification or hardware acceptance testing.  
It focuses on demonstrating **software engineering competence**.
