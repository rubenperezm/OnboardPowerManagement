# Configuration Values
This document outlines the configurable parameters for the Power Manager module. These configuration values allow tailoring the module's behaviour to specific mission requirements, hardware characteristics, and operational constraints.

## 1. Voltage Thresholds
- **Undervoltage Threshold**: 20.0V
    - Description: The voltage level below which the Power Manager detects an undervoltage condition.
- **Overvoltage Threshold**: 28.0V
    - Description: The voltage level above which the Power Manager detects an overvoltage condition.
- **Undervoltage Recovery Margin**: 5%
    - Description: The percentage above the undervoltage threshold that the voltage must rise to recover.
- **Overvoltage Recovery Margin**: 5%
    - Description: The percentage below the overvoltage threshold that the voltage must fall to recover.
## 2. Current Limits
- **Maximum Allowable Current**: 50.0A
    - Description: The maximum current level above which the Power Manager detects an overcurrent condition.
- **Overcurrent Duration Threshold**: 0.5 seconds
    - Description: The duration for which the current must exceed the maximum allowable current to trigger an overcurrent condition.
## 3. Temperature Limits
- **Normal Temperature Range**: 0°C to 45°C
    - Description: The acceptable temperature range for battery operation.
- **Overtemperature Threshold**: 45°C
    - Description: The temperature level above which the Power Manager detects an overtemperature condition.
- **Undertemperature Threshold**: 0°C
    - Description: The temperature level below which the Power Manager detects an undertemperature condition.
## 4. Telemetry Update Rate
- **Telemetry Update Interval**: 1 second
    - Description: The interval at which telemetry data is updated and transmitted.