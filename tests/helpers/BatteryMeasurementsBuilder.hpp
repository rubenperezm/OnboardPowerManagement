#pragma once

#include <cstdint>
#include <optional>

#include "Config.hpp"
#include "BatteryMeasurements.h"

class BatteryMeasurementsBuilder {
    public:
        explicit BatteryMeasurementsBuilder(const Config& cfg);

        BatteryMeasurementsBuilder& withVoltage(float v);

        BatteryMeasurementsBuilder& withCurrent(float c);

        BatteryMeasurementsBuilder& withTemperature(float t);

        BatteryMeasurementsBuilder& withTimestamp(uint64_t ts);

        BatteryMeasurements build() const;

    private:
        const Config& cfg_;
        BatteryMeasurements measurements_;
};

