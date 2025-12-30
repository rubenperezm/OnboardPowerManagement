# Unit Test Specification: UT-PWR-001-A

## 1. Purpose

The purpose of this unit test is to verify that the PowerManager software component
supports and correctly manages the defined operational modes: `NORMAL`, `SAFE`, and `OFF`.

This test focuses on the internal representation and handling of operational modes,
independently of external inputs or middleware communication.

---

## 2. Requirements Verified

- REQ-PWR-001

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
3. Request transition to `SAFE` mode via internal interface
4. Request transition to `OFF` mode via internal interface
5. Request transition back to `NORMAL` mode via internal interface

---

## 7. Expected Results

- The PowerManager supports exactly the following operational modes:
  - `NORMAL`
  - `SAFE`
  - `OFF`
- The initial operational mode after initialization is one of the defined modes
- Each requested operational mode transition results in the corresponding internal state
- No undefined or unsupported operational modes are accepted or entered

---

## 8. Pass / Fail Criteria

- PASS if the PowerManager:
  - Recognizes all defined operational modes
  - Successfully transitions between the defined modes
  - Does not enter any undefined mode
- FAIL otherwise
