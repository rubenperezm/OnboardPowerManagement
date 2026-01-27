# Analysis Specification: AN-PWR-005

## 1. Purpose

Verify that the PowerManager software component does not allow invalid operational 
mode transitions strictly in accordance with the defined operational mode rules and definitions.

---

## 2. Requirement Verified

- REQ-PWR-005

---

## 3. Analysis Scope
- PowerManager module

---

## 4. Preconditions

- PowerManager design documents and models are available

---

## 5. Analysis Method

1. Inspect module designs for:
   - Methods that allow transitions
   - Behaviour in situations where the current state is `OFF` and could transition to `SAFE`.
---

## 6. Expected Findings

- The PowerManager does not support transitions from `OFF` to `SAFE`.

---

## 7. Pass / Fail Criteria

- PASS if invalid transition is not possible.
- FAIL otherwise
