#pragma once

#include <optional>
#include <random>

#include "BatteryMeasurements.hpp"
#include "SensorHealthStatus.hpp"

/**
 * @brief BatteryMonitor
 *
 * @details
 * The BatteryMonitor is responsible for acquiring (simulated) battery
 * sensor data such as voltage, current and temperature, and for assessing
 * the basic health status of the battery sensors.
 *
 */

class BatteryMonitor {
    public:
        /**
        * @brief Constructor
        */
        BatteryMonitor(const Config& config) : config(config), gen(rd()) {};

        /**
        * @brief Destructor
        */
        ~BatteryMonitor() = default;

        /**
        * @brief Acquire new battery measurements.
        *
        * This method simulates the acquisition of raw sensor data.
        */
        void acquireMeasurements();

        /**
        * @brief Get the latest battery measurements.
        *
        * @return Latest battery measurements if available.
        */
        std::optional<BatteryMeasurements> getMeasurements() const;

        /**
        * @brief Evaluate sensor health based on latest measurements.
        *
        * @return Local sensor health status related to battery measurements.
        */
        LocalSensorHealthStatus getSensorHealthStatus();

    private:
        // Configuration parameters
        const Config& config;

        // Sensor ID
        constexpr static uint8_t SENSOR_ID = 1;

        // Cached measurements
        std::optional<BatteryMeasurements> m_lastMeasurements;

        // Random number generation
        std::random_device rd;
        std::mt19937 gen;

        /**
         * @brief Generate a random measurement within a specified range.
         *
         * @param lo Lower bound of the range.
         * @param hi Upper bound of the range.
         * @param measurement Reference to store the generated measurement.
         */
        void generateRandomMeasurement(const float lo, const float hi, float& measurement);
};
