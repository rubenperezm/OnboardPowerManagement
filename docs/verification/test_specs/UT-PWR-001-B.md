# Unit Test Specification: UT-PWR-001-B

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
does not accept any undefined or unsupported operational modes beyond the defined set: `NORMAL`, `SAFE`, and `OFF`.

This test focuses on the internal representation and handling of operational modes,
independently of external inputs or middleware communication.

---

## 2. Requirements Verified

- REQ-PWR-001
- NFR-PWR-004 

---

## 3. Test Level

Unit Test (UT)

---

## 4. Test Item

- Software module: PowerManager
- Functionality: Operational mode management

---

## 5. Preconditions

- PowerManager component is instantiated
- PowerManager is in an initialized state
- No external DDS communication is active
- No fault conditions are injected

---

## 6. Test Steps

The following steps are applied sequentially:

1. Initialize the PowerManager component
2. Query the current operational mode
3. Request transition to `INVALID` mode via internal interface

---

## 7. Expected Results

- The PowerManager supports exactly the following operational modes:
  - `NORMAL`
  - `SAFE`
  - `OFF`
- The initial operational mode after initialization is one of the defined modes
- When an invalid or unsupported operational mode is requested:
  - The PowerManager does not change its current mode
  - An appropriate error handling mechanism is triggered (e.g., logging, exception)

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Does not accept any undefined or unsupported operational modes
- FAIL otherwise
