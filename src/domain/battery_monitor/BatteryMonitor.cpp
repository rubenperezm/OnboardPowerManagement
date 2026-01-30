#include <random>
#include <algorithm>
#include <chrono>

#include "Config.hpp"
#include "BatteryMonitor.hpp"

void BatteryMonitor::acquireMeasurements(){
    BatteryMeasurements measurements = m_lastMeasurements.value_or(
        BatteryMeasurements{config.getInitialVoltage(), config.getInitialCurrent(), config.getInitialTemperature(), 0}
    );

    generateRandomMeasurement(config.getGenerationMinVoltage(), config.getGenerationMaxVoltage(), measurements.voltage);

    generateRandomMeasurement(config.getGenerationMinCurrent(), config.getGenerationMaxCurrent(), measurements.current);

    generateRandomMeasurement(config.getGenerationMinTemperature(), config.getGenerationMaxTemperature(), measurements.temperature);
    measurements.timestamp_us = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now().time_since_epoch()
    ).count();

    m_lastMeasurements = measurements;
}

void BatteryMonitor::generateRandomMeasurement(const float lo, const float hi, float& measurement) {
    std::normal_distribution<float> dist(measurement, config.getDeltaRandomGeneration());

    measurement = std::clamp(dist(gen), lo, hi);
}

std::optional<BatteryMeasurements> BatteryMonitor::getMeasurements() const {
    return m_lastMeasurements;
}

LocalSensorHealthStatus BatteryMonitor::getSensorHealthStatus() {
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    double randVal = dist(gen);

    SensorState state = SensorState::NOMINAL;
    if (randVal < config.getSensorFailedProbability()) {
        state = SensorState::FAILED;
    } else if (randVal < config.getSensorDegradedProbability()) {
        state = SensorState::DEGRADED;
    }

    LocalSensorHealthStatus healthStatus;
    healthStatus.sourceId = SENSOR_ID;
    healthStatus.status = state;
    healthStatus.timestamp_us = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now().time_since_epoch()
    ).count();

    return healthStatus;
}
