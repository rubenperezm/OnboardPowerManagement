#pragma once

#include <cstdint>
#include <unordered_map>

#include "LocalSensorHealthStatus.hpp"
#include "SensorHealthStatus.hpp"

using namespace core;

/**
 * @brief SensorHealthManager
 *
 * @details
 * Aggregates local sensor health status information originating from
 * multiple sources and provides a single, consolidated health view
 * to the PowerManager.
 *
 * This class belongs to the domain layer and contains no middleware
 * or communication logic.
 */
class SensorHealthManager {
    public:
        /**
        * @brief Constructor
        */
        SensorHealthManager();

        /**
        * @brief Destructor
        */
        ~SensorHealthManager() = default;

        /**
        * @brief Update internal health state using local sensor health input.
        *
        * @param health Local sensor health status data
        */
        void updateHealth(const LocalSensorHealthStatus& health);

        /**
        * @brief Return the consolidated sensor health status.
        *
        * The consolidation policy is defined in the detailed design.
        *
        * @param source the source ID
        *
        * @return SensorHealthStatus structure
        */
        SensorHealthStatus getHealthStatus() const;

        /**
        * @brief Reset internal health state.
        */
        void reset();

    private:
        /// Original health status as received from each sensor source
        std::unordered_map<std::uint8_t, LocalSensorHealthStatus> m_originalHealthBySource;

        /// Effective health status after fault injection, per sensor source
        std::unordered_map<std::uint8_t, LocalSensorHealthStatus> m_effectiveHealthBySource;

        bool isSourceSimulated(const uint8_t source);

        uint8_t injectedToActualSource(const uint8_t injectedSource);


};

