# Analysis Specification: AN-PWR-515

## 1. Purpose

Verify that all non-functional requirements (NFRs) of the Power Management
subsystem are traceable to defined verification activities.

Focus is on documentation, traceability matrices, and linkage between NFRs
and corresponding tests (unit, integration, functional) or analysis activities.

---

## 2. Requirement Verified

- NFR-PWR-015

---

## 3. Analysis Scope

- Non-functional requirements documentation (NFR-PWR-001 to NFR-PWR-016)
- Verification activities:
  - Unit Tests (UT)
  - Integration Tests (IT)
  - Functional Tests (FT)
  - Analysis specifications (AN)
- Traceability matrix (`traceability.html` or equivalent)
- Project documentation supporting NFR coverage

---

## 4. Preconditions

- NFRs are clearly documented with unique identifiers
- Verification activities are planned or implemented
- Traceability matrix is initialized or available
- Project documentation is accessible

---

## 5. Analysis Method

1. Review each NFR and identify associated verification activities
2. Verify that each NFR is linked to at least one UT, IT, FT, or AN
3. Check that traceability matrix entries are consistent and correctly reference requirements and test/analysis identifiers
4. Identify any NFRs without assigned verification activities
5. Document findings and recommendations for unverified NFRs

---

## 6. Expected Findings

- Each NFR has at least one corresponding verification activity
- Traceability matrix entries are complete and consistent
- Any gaps or missing verifications are identified and documented

---

## 7. Pass / Fail Criteria

- PASS if:
  - All NFRs are traceable to verification activities
  - Traceability matrix is complete and accurate
- FAIL if:
  - Any NFR lacks verification
  - Traceability links are missing or inconsistent
