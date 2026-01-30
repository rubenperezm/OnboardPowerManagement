#pragma once

#include <optional>

#include "types/BatteryMeasurements.hpp"
#include "types/SensorHealthStatus.hpp"
#include "types/PowerCommand.hpp"
#include "types/LoadStatus.hpp"
#include "Config.hpp"

using namespace core;

/**
 * @brief PowerManager
 *
 * @details
 * The PowerManager is responsible for evaluating battery measurements
 * and consolidated sensor health information in order to determine
 * the operational mode of the subsystem and generate appropriate
 * power management commands.
 *
 */
 
class PowerManager {
    public:
        /**
        * @brief Constructor
        */
        explicit PowerManager(const Config& config);

        /**
        * @brief Destructor
        */
        ~PowerManager() = default;

        /**
        * @brief Process new battery measurements.
        *
        * @param measurements Latest battery voltage, current and temperature.
        */
        void processBatteryMeasurements(const core::BatteryMeasurements& measurements);

        /**
        * @brief Process consolidated sensor health status.
        *
        * @param healthStatus Consolidated health information from SensorHealthManager.
        */
        void processSensorHealthStatus(const core::SensorHealthStatus& healthStatus);

        /**
        * @brief Evaluate current state and update internal operational mode.
        *
        * This method is expected to be called periodically by the scheduler.
        */
        void evaluate();

        /**
        * @brief Get current operational mode.
        *
        * @return Current operational mode of the subsystem.
        */
        core::PowerMode getCurrentMode() const;

        /**
        * @brief Get latest power command, if available.
        *
        * @return Optional power command.
        */
        std::optional<core::PowerCommand> getPowerCommand() const;

        void setShutdown(const bool sd);
        bool getShutdown() const;

    private:
        /**
         * @brief Configuration parameters
         * 
         */
        const Config& config;

        /**
         * @brief Latest processed measurements
         */
        std::optional<core::BatteryMeasurements> m_lastMeasurements;

        /**
         * @brief Latest processed sensor health status
         */
        std::optional<core::SensorHealthStatus>  m_lastHealthStatus;

        /**
         * @brief Timestamp when overcurrent condition started
         */
        std::optional<u_int64_t> m_overcurrentStartTimestamp;

        /**
         * @brief Shutdown flag
         */
        bool m_isShutdown;

        /**
         * @brief Current operational mode
         */
        core::PowerMode m_currentMode;

        /**
         * @brief Voltage overload flag
         */
        bool m_voltageOverload;

        /**
         * @brief Voltage underload flag
         */
        bool m_voltageUnderload;

        /**
         * @brief Current overload flag
         */
        bool m_currentOverload;

        /**
         * @brief Sustained current overload flag
         */
        bool m_sustainedOvercurrent;

        /**
         * @brief Temperature overlimit flag
         */
        bool m_overtemperature;

        /**
         * @brief Temperature underlimit flag
         */
        bool m_undertemperature;

        /**
         * @brief Latest power command
         */
        std::optional<core::PowerCommand> m_lastCommand;

        /**
         * @brief Flag indicating if a new command is available
         */
        bool m_newCommandAvailable;

        /**
         * @brief Set voltage-related flags based on latest measurements
         * 
         */
        void setVoltageFlags();

        /**
         * @brief Set current-related flags based on latest measurements
         */
        void setCurrentFlags();

        /**
         * @brief Set temperature-related flags based on latest measurements
         */
        void setTemperatureFlags();

        /**
         * @brief Check if conditions to transition to OFF mode are met
         */
        bool checkOffConditions() const;

        /**
         * @brief Check if conditions to transition to SAFE mode are met
         */
        bool checkSafeConditions() const;

        /**
         * @brief Test adapter to access private members for testing purposes
         */
        friend struct PowerManagerTestAdapter;
};
