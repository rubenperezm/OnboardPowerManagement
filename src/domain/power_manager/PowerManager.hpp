#pragma once

#include <optional>

#include "BatteryMeasurements.hpp"
#include "SensorHealthStatus.hpp"
#include "PowerCommand.hpp"
#include "LoadStatus.hpp"
#include "Config.hpp"

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
        void processBatteryMeasurements(const BatteryMeasurements& measurements);

        /**
        * @brief Process consolidated sensor health status.
        *
        * @param healthStatus Consolidated health information from SensorHealthManager.
        */
        void processSensorHealthStatus(const SensorHealthStatus& healthStatus);

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
        PowerMode getCurrentMode() const;

        /**
        * @brief Get latest power command, if available.
        *
        * @return Optional power command.
        */
        std::optional<PowerCommand> getPowerCommand() const;

        void setShutdown(const bool sd);
        bool getShutdown() const;

    private:
        // Config 
        const Config& config;

        // Cached inputs
        std::optional<BatteryMeasurements> m_lastMeasurements;
        std::optional<SensorHealthStatus>  m_lastHealthStatus;
        std::optional<u_int64_t> m_overcurrentStartTimestamp;

        // Internal state
        bool m_isShutdown;
        PowerMode m_currentMode;

        // Internal Flags
        bool m_voltageOverload;
        bool m_voltageUnderload;
        bool m_currentOverload;
        bool m_sustainedOvercurrent;
        bool m_overtemperature;
        bool m_undertemperature;

        // Auxiliary methods
        void setVoltageFlags();
        void setCurrentFlags();
        void setTemperatureFlags();
        bool checkOffConditions() const;
        bool checkSafeConditions() const;

        // Latest output
        std::optional<PowerCommand> m_lastCommand;

        // Friend struct for testing purposes
        friend struct PowerManagerTestAdapter;
};
