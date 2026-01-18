#pragma once

#include <cstdint>

/**
 * @brief LocalSensorHealthStatus
 *
 * @details
 * Health status reported by a single sensor instance.
 * Contains source identifier and status.
 */
enum class SensorState : uint8_t {
    NOMINAL,
    DEGRADED,
    FAILED
};

struct LocalSensorHealthStatus {
    uint8_t sourceId;         // Unique sensor ID
    SensorState status;       // Current health state
    uint64_t timestamp_us;    // Timestamp in microseconds
};

