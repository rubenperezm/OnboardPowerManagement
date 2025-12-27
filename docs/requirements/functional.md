# Functional Requirements

This document lists the functional requirements (FR) of the Power Management Subsystem.

| Requirement ID | Description |
|----------------|-------------|
| REQ-PWR-001    | The software shall operate in one of the defined operational modes: `NORMAL`, `SAFE`, or `OFF`. |
| REQ-PWR-002    | The software shall enter `SAFE` mode when battery voltage falls below the low-voltage threshold `V_LOW`. |
| REQ-PWR-003    | The software shall return to `NORMAL` mode when battery voltage rises above the recovery threshold `V_RECOVERY` and no blocking faults are present. |
| REQ-PWR-004    | The software shall enter `OFF` mode upon reception of a valid `OFF` mode command. |
| REQ-PWR-005    | The software shall perform all mode transitions in accordance with the operational mode definitions. |
| REQ-PWR-006    | The software shall monitor battery voltage provided as input to the subsystem. |
| REQ-PWR-007    | The software shall detect undervoltage conditions based on configured voltage thresholds. |
| REQ-PWR-008    | The software shall detect overvoltage conditions based on configured voltage thresholds. |
| REQ-PWR-009    | The software shall monitor battery current provided as input to the subsystem. |
| REQ-PWR-010    | The software shall detect overcurrent conditions when measured current exceeds the maximum allowable current `I_MAX`. |
| REQ-PWR-011    | The software shall react to sustained overcurrent conditions by transitioning to `SAFE` mode. |
| REQ-PWR-012    | The software shall monitor battery temperature provided as input to the subsystem. |
| REQ-PWR-013    | The software shall detect overtemperature conditions when measured temperature exceeds the maximum allowable temperature `T_MAX`. |
| REQ-PWR-014    | The software shall react to overtemperature conditions by limiting power usage or transitioning to `SAFE` mode. |
| REQ-PWR-015    | The software shall consume consolidated sensor health information. |
| REQ-PWR-016    | The software shall ignore sensor data marked as invalid by sensor health information. |
| REQ-PWR-017    | The software shall continue operation in a degraded mode when non-critical sensor faults are detected. |
| REQ-PWR-018    | The software shall control electrical loads based on the current operational mode. |
| REQ-PWR-019    | The software shall disable non-essential loads when operating in `SAFE` mode. |
| REQ-PWR-020    | The software shall ensure that critical loads remain powered whenever possible. |
| REQ-PWR-021    | The software shall provide telemetry outputs reflecting the current operational mode. |
| REQ-PWR-022    | The software shall provide telemetry outputs reflecting detected fault and health conditions. |
| REQ-PWR-023    | The software shall provide telemetry outputs reflecting load control decisions. |
| REQ-PWR-024    | The software shall detect and respond to fault conditions affecting power availability. |
| REQ-PWR-025    | The software shall prioritise system safety over performance when handling faults. |
| REQ-PWR-026    | The software shall recover from transient fault conditions when input values return to acceptable ranges. |

## Notes

- Thresholds such as `V_LOW`, `V_RECOVERY`, `I_MAX`, and `T_MAX` are parameters to be defined during system analysis and design.