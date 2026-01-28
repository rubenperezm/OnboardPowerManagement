#include <iostream>

#include "TelemetryLogger.hpp"

TelemetryLogger::TelemetryLogger(std::ostream& outputStream = std::cout) : m_out(outputStream) {}

void TelemetryLogger::logBatteryMeasurements(const BatteryMeasurements& measurements){
    m_out << "[TELEMETRY] timestamp=" << measurements.timestamp_us() << "module=BatteryMonitor" <<
        "voltage=" << measurements.voltage() << "current=" << measurements.current() <<
        "temperature=" << measurements.temperature() << std::endl;
}

void TelemetryLogger::logLocalSensorHealthStatus(const LocalSensorHealthStatus& status){
    const bool isInjected = status.sourceId() >= 128;

    m_out << "[TELEMETRY] timestamp=" << status.timestamp_us() << "module=" << 
        (isInjected ? "FaultInjector" : "BatteryMonitor") << "source=" << status.sourceId() % 128 <<
        "status=" << sensorStateEnumNames[static_cast<int>(status.status())] << std::endl;
}

void TelemetryLogger::logSensorHealthStatus(const SensorHealthStatus& status){
    m_out << "[TELEMETRY] timestamp=" << status.timestamp_us() << "module=SensorHealthManager" <<
        "any_degraded=" << status.anyDegraded() << "any_failed=" << status.anyFailed() << std::endl;
}

void TelemetryLogger::logLoadStatus(const LoadStatus& load) {
    m_out << "[TELEMETRY] timestamp=" << load.timestamp_us() << "module=SubsystemController" <<
        "payload=" << getOnOffStateFromBoolean(load.payloadActive()) <<
        "comms=" << getOnOffStateFromBoolean(load.commsActive()) <<
        "thermal=" << getOnOffStateFromBoolean(load.thermalActive()) << std::endl;
}

void TelemetryLogger::logPowerCommand(const PowerCommand& command){
    m_out << "[TELEMETRY] timestamp=" << command.timestamp_us() << "module=PowerManager" <<
        "mode=" << powerModeEnumNames[static_cast<int>(command.mode())] << "emergency_shutdown" << command.emergencyShutdown() << std::endl;
}

const std::string getOnOffStateFromBoolean(const bool state){
    return state ? "ON" : "OFF";
}