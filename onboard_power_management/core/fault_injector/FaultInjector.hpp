#pragma once

#include <optional>
#include <unordered_map>

#include "types/LocalSensorHealthStatus.hpp"

using namespace core;

/**
 * @brief FaultInjector
 *
 * @details
 * Provides controlled fault injection capabilities for verification
 * and validation purposes. This module simulates sensor and subsystem
 * anomalies without altering the domain logic of consuming components.
 */

class FaultInjector {
    public:
        /**
        * @brief Constructor
        */
        FaultInjector();

        /**
        * @brief Destructor
        */
        ~FaultInjector() = default;

        /**
        * @brief Activate a fault scenario.
        *
        * @param sensor source ID
        * @param state state to be injected
        */
        void activateFault(const uint8_t sensor, const SensorState state);

        /**
        * @brief Remove any active fault.
        */
        void clearFault(const uint8_t sensor);

        /**
        * @brief Retrieve the health status produced by the fault injector.
        *
        * This output is consumed by the SensorHealthManager.
        *
        * @return LocalSensorHealthStatus reported by the injector
        */
        LocalSensorHealthStatus getHealthStatus(const uint8_t sensor) const;

    private:
        /// Active fault definitions per sensor source
        std::unordered_map<std::uint8_t, SensorState> m_activeFaults;
};

