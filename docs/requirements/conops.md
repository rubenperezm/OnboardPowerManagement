# Concept of Operations

# Operational Modes

This section defines the operational modes of the Onboard Power Management Subsystem.

## NORMAL
The subsystem operates under nominal conditions.
All critical and non-critical loads may be enabled according to mission needs.

## SAFE
The subsystem operates under degraded or fault conditions.
Only critical loads are guaranteed to be powered.
Non-essential loads are disabled to preserve energy.

## OFF
The subsystem is not providing power to loads.
Only minimal monitoring functions may remain active.

# Valid Transitions Between Modes
| From \ To | NORMAL | SAFE | OFF |
|-----------|--------|------|-----|
| NORMAL    |   Y    |  Y   |  Y  |
| SAFE      |   Y    |  Y   |  Y  |
| OFF       |   Y    |  N   |  Y  |