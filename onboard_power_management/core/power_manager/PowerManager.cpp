#include <chrono>

#include "PowerManager.hpp"
#include "Log.hpp"

PowerManager::PowerManager(const Config& config) : config(config), m_lastMeasurements(), m_lastHealthStatus(),
    m_overcurrentStartTimestamp(), m_isShutdown(false), m_currentMode(core::PowerMode::NORMAL), m_voltageOverload(false),
    m_voltageUnderload(false), m_currentOverload(false), m_sustainedOvercurrent(false), m_overtemperature(false),
    m_undertemperature(false), m_lastCommand() {}

void PowerManager::processBatteryMeasurements(const core::BatteryMeasurements& measurements){
        m_lastMeasurements = measurements;

        setVoltageFlags();
        setCurrentFlags();
        setTemperatureFlags();
}

void PowerManager::setVoltageFlags(){
    if (m_voltageOverload || m_voltageUnderload){
        m_voltageOverload = m_lastMeasurements.value().voltage > (1-config.getOvervoltageRecoveryMargin())*config.getMaxVoltage();
        m_voltageUnderload = m_lastMeasurements.value().voltage < (1+config.getUndervoltageRecoveryMargin())*config.getMinVoltage();
    } else {
        m_voltageOverload = m_lastMeasurements.value().voltage > config.getMaxVoltage();
        m_voltageUnderload = m_lastMeasurements.value().voltage < config.getMinVoltage();
    }
}

void PowerManager::setCurrentFlags(){
    m_currentOverload = m_lastMeasurements.value().current > config.getMaxCurrent();
    
    if (m_currentOverload){
        if (m_overcurrentStartTimestamp.has_value()){
            m_sustainedOvercurrent = (m_lastMeasurements.value().timestamp_us - m_overcurrentStartTimestamp.value() > config.getOvercurrentDurationThreshold() * 1000000);
        } else {
            m_overcurrentStartTimestamp = m_lastMeasurements.value().timestamp_us;
        }
    } else {
        m_sustainedOvercurrent = false;
        m_overcurrentStartTimestamp = std::nullopt;
    }
}

void PowerManager::setTemperatureFlags(){
    m_overtemperature = m_lastMeasurements.value().temperature > config.getMaxTemperature();
    m_undertemperature = m_lastMeasurements.value().temperature < config.getMinTemperature();
}

void PowerManager::processSensorHealthStatus(const core::SensorHealthStatus& healthStatus){
    m_lastHealthStatus = healthStatus;
}

void PowerManager::evaluate(){
    core::PowerMode previousMode = m_currentMode;

    if (checkOffConditions()){
        m_currentMode = core::PowerMode::OFF;
    } else if (checkSafeConditions()){
        m_currentMode = core::PowerMode::SAFE;
    } else {
        m_currentMode = core::PowerMode::NORMAL;
    }

    m_newCommandAvailable = (m_currentMode != previousMode);

    PowerCommand command;
    command.mode = m_currentMode;
    command.emergencyShutdown = m_isShutdown;
    command.timestamp_us = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now().time_since_epoch()
    ).count();

    m_lastCommand = command;
 
}

bool PowerManager::checkOffConditions() const {
    return m_isShutdown || (m_lastHealthStatus.has_value() && m_lastHealthStatus.value().anyFailed);
}

bool PowerManager::checkSafeConditions() const {
    return (m_lastHealthStatus.has_value() && m_lastHealthStatus.value().anyDegraded) || m_voltageOverload ||
        m_voltageUnderload || m_sustainedOvercurrent || m_undertemperature || m_overtemperature;
}

core::PowerMode PowerManager::getCurrentMode() const {
    return m_currentMode;
}

std::optional<core::PowerCommand> PowerManager::getPowerCommand() const {
    return m_newCommandAvailable ? m_lastCommand : std::nullopt;
}

bool PowerManager::getShutdown() const {
    return m_isShutdown;
}

void PowerManager::setShutdown(const bool sd){
    m_isShutdown = sd;
    m_currentMode = m_isShutdown ? core::PowerMode::OFF : core::PowerMode::NORMAL;
}