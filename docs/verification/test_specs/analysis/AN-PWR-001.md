# Analysis Specification: AN-PWR-001

## 1. Purpose

Verify that the PowerManager software component does not accept any undefined or 
unsupported operational modes beyond the defined set: `NORMAL`, `SAFE`, and `OFF`.

---

## 2. Requirement Verified

- REQ-PWR-001
- NFR-PWR-004

---

## 3. Analysis Scope
- PowerManager module

---

## 4. Preconditions

- PowerManager design documents and models are available

---

## 5. Analysis Method

1. Inspect module designs for:
   - Enumeration of operational modes
---

## 6. Expected Findings

- The PowerManager supports exactly the following operational modes:
  - `NORMAL`
  - `SAFE`
  - `OFF`
- No other operational modes are defined or handled in the design

---

## 7. Pass / Fail Criteria

- PASS if only the defined modes are present in the design
- FAIL if any missing or additional modes are found
