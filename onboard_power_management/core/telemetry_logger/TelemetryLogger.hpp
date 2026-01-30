#pragma once

#include <vector>
#include <string>
#include <ostream>

#include "types/BatteryMeasurements.hpp"
#include "types/SensorHealthStatus.hpp"
#include "types/LocalSensorHealthStatus.hpp"
#include "types/LoadStatus.hpp"
#include "types/PowerCommand.hpp"

using namespace core;

/**
 * @brief TelemetryLogger
 *
 * @details
 * Collects telemetry data and allows printing to a user-specified output stream.
 * By default, telemetry is printed to standard output.
 */
class TelemetryLogger {
    public:
        /**
        * @brief Constructor
        *
        * @param outputStream Stream to write telemetry to (default: std::cout)
        */
        explicit TelemetryLogger(std::ostream& outputStream);

        ~TelemetryLogger() = default;

        /**
        * @brief Log battery measurements
        *
        * @param measurements Current measurements from a BatteryMonitor
        */
        void logBatteryMeasurements(const BatteryMeasurements& measurements);

        /**
        * @brief Log local sensor health statuses
        *
        * @param status Current local health status
        */
        void logLocalSensorHealthStatus(const LocalSensorHealthStatus& status);

        /**
        * @brief Log sensor health statuses
        *
        * @param status Current consolidated health status
        */
        void logSensorHealthStatus(const SensorHealthStatus& status);

        /**
        * @brief Log load status
        *
        * @param load Current load status
        */
        void logLoadStatus(const LoadStatus& load);

        /**
        * @brief log power command
        *
        * @param command Current power command
        */
        void logPowerCommand(const PowerCommand& command);

        /**
        * @brief Clear all stored telemetry
        */
        void reset();

    private:
        // Output stream for telemetry
        std::ostream& m_out;

        // Enum Names
        const char* sensorStateEnumNames[3] = {"NOMINAL", "DEGRADED", "FAILED"};
        const char* powerModeEnumNames[3] = {"OFF", "SAFE", "NORMAL"};

        const std::string getOnOffStateFromBoolean(const bool state);
};

