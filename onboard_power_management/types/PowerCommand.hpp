#pragma once

#include <cstdint>

namespace core {
    /**
     * @brief PowerCommand
     *
     * @details
     * Commands issued by the PowerManager to subsystems.
     */
    enum class PowerMode : uint32_t {
        OFF,
        SAFE,
        NORMAL
    };

    struct PowerCommand {
        PowerMode mode;         // Requested power mode
        bool emergencyShutdown; // Flag for immediate shutdown
        uint64_t timestamp_us;  // Timestamp in microseconds
    };
};

