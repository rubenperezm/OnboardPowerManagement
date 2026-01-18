#pragma once

/**
 * @brief BatteryMeasurements
 *
 * @details
 * Contains instantaneous measurements from a battery sensor.
 * Used as input to PowerManager and for telemetry.
 */
struct BatteryMeasurements {
    float voltage;     // Battery voltage in volts
    float current;     // Battery current in amperes
    float temperature; // Battery temperature in degrees Celsius
    uint64_t timestamp_us; // Timestamp in microseconds
};
