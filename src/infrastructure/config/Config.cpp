#include <fstream>
#include <sstream>

#include "Config.hpp"
#include "Log.hpp"

// To be called in main
Config::Config(const std::string& filename) {
    load(filename);
}


void Config::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open config file: " + filename);
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        if (std::getline(iss, key, '=')) {
            std::string value;
            if (std::getline(iss, value)) {
                float val = std::stof(value);

                if (key == "MIN_VOLTAGE") {
                    minVoltage_ = val;
                } else if (key == "MAX_VOLTAGE") {
                    maxVoltage_ = val;
                } else if (key == "UNDERVOLTAGE_RECOVERY_MARGIN") {
                    undervoltageRecoveryMargin_ = val;
                } else if (key == "OVERVOLTAGE_RECOVERY_MARGIN") {
                    overvoltageRecoveryMargin_ = val;
                } else if (key == "MIN_CURRENT") {
                    minCurrent_ = val;
                } else if (key == "MAX_CURRENT") {
                    maxCurrent_ = val;
                } else if (key == "OVERCURRENT_DURATION_THRESHOLD") {
                    overcurrentDurationThreshold_ = val;
                } else if (key == "MAX_TEMPERATURE") {
                    maxTemperature_ = val;
                } else if (key == "MIN_TEMPERATURE") {
                    minTemperature_ = val;
                } else if (key == "DELTA_RANDOM_GENERATION") {
                    deltaRandomGeneration_ = val;
                } else if (key == "INITIAL_VOLTAGE") {
                    initialVoltage_ = val;
                } else if (key == "INITIAL_CURRENT") {
                    initialCurrent_ = val;
                } else if (key == "INITIAL_TEMPERATURE") {
                    initialTemperature_ = val;
                } else if (key == "GENERATION_MIN_VOLTAGE") {
                    generationMinVoltage_ = val;
                } else if (key == "GENERATION_MAX_VOLTAGE") {
                    generationMaxVoltage_ = val;
                } else if (key == "GENERATION_MIN_CURRENT") {
                    generationMinCurrent_ = val;
                } else if (key == "GENERATION_MAX_CURRENT") {
                    generationMaxCurrent_ = val;
                } else if (key == "GENERATION_MIN_TEMPERATURE") {
                    generationMinTemperature_ = val;
                } else if (key == "GENERATION_MAX_TEMPERATURE") {
                    generationMaxTemperature_ = val;
                } else if (key == "SENSOR_FAILED_PROBABILITY") {
                    sensorFailedProbability_ = val;
                } else if (key == "SENSOR_DEGRADED_PROBABILITY") {
                    sensorDegradedProbability_ = val;
                } else if (key == "TELEMETRY_UPDATE_INTERVAL") {
                    telemetryUpdateInterval_ = val;
                } else {
                    LOG_WARN("Unknown config key: " + key);
                }
            }
        }
    }
    file.close();
}   

float Config::getMinVoltage() const { return minVoltage_; }
float Config::getMaxVoltage() const { return maxVoltage_; }
float Config::getUndervoltageRecoveryMargin() const { return undervoltageRecoveryMargin_; }
float Config::getOvervoltageRecoveryMargin() const { return overvoltageRecoveryMargin_; }
float Config::getMinCurrent() const { return minCurrent_; }
float Config::getMaxCurrent() const { return maxCurrent_; }
float Config::getOvercurrentDurationThreshold() const { return overcurrentDurationThreshold_; }
float Config::getMaxTemperature() const { return maxTemperature_; }
float Config::getMinTemperature() const { return minTemperature_; }
float Config::getDeltaRandomGeneration() const { return deltaRandomGeneration_; }
float Config::getInitialVoltage() const { return initialVoltage_; }
float Config::getInitialCurrent() const { return initialCurrent_; }
float Config::getInitialTemperature() const { return initialTemperature_; }
float Config::getGenerationMinVoltage() const { return generationMinVoltage_; }
float Config::getGenerationMaxVoltage() const { return generationMaxVoltage_; }
float Config::getGenerationMinCurrent() const { return generationMinCurrent_; }
float Config::getGenerationMaxCurrent() const { return generationMaxCurrent_; }
float Config::getGenerationMinTemperature() const { return generationMinTemperature_; }
float Config::getGenerationMaxTemperature() const { return generationMaxTemperature_; }
float Config::getSensorFailedProbability() const { return sensorFailedProbability_; }
float Config::getSensorDegradedProbability() const { return sensorDegradedProbability_; }
float Config::getTelemetryUpdateInterval() const { return telemetryUpdateInterval_; }