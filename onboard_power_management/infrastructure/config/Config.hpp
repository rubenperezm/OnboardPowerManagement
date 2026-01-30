#pragma once
#include <string>

class Config {
public:
    Config(const std::string& filename);

    ~Config() = default;
    
    float getMinVoltage() const;
    float getMaxVoltage() const;
    float getUndervoltageRecoveryMargin() const;
    float getOvervoltageRecoveryMargin() const;

    float getMinCurrent() const;
    float getMaxCurrent() const;
    float getOvercurrentDurationThreshold() const;

    float getMaxTemperature() const;
    float getMinTemperature() const;

    float getDeltaRandomGeneration() const;
    float getInitialVoltage() const;
    float getInitialCurrent() const;
    float getInitialTemperature() const;
    float getGenerationMinVoltage() const;
    float getGenerationMaxVoltage() const;
    float getGenerationMinCurrent() const;
    float getGenerationMaxCurrent() const;
    float getGenerationMinTemperature() const;
    float getGenerationMaxTemperature() const;

    float getSensorFailedProbability() const;
    float getSensorDegradedProbability() const;

    float getTelemetryUpdateInterval() const;

private:
    float minVoltage_{0};
    float maxVoltage_{0};
    float undervoltageRecoveryMargin_{0};
    float overvoltageRecoveryMargin_{0};

    float minCurrent_{0};
    float maxCurrent_{0};
    float overcurrentDurationThreshold_{0};

    float maxTemperature_{0};
    float minTemperature_{0};

    float deltaRandomGeneration_{0};
    float initialVoltage_{0};
    float initialCurrent_{0};
    float initialTemperature_{0};
    float generationMinVoltage_{0};
    float generationMaxVoltage_{0};
    float generationMinCurrent_{0};
    float generationMaxCurrent_{0};
    float generationMinTemperature_{0};
    float generationMaxTemperature_{0};

    float sensorFailedProbability_{0};
    float sensorDegradedProbability_{0};
    
    float telemetryUpdateInterval_{0};

    void load(const std::string& filename);
};
