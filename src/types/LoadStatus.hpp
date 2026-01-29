#pragma once

namespace core {
    /**
     * @brief LoadStatus
     *
     * @details
     * Status of the loads connected to the power subsystem.
     */
    struct LoadStatus {
        bool payloadActive;
        bool commsActive;
        bool thermalActive;
        uint64_t timestamp_us; // Timestamp in microseconds
    };
};

