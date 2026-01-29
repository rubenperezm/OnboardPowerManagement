#pragma once

#include <cstdint>
#include <optional>

#include "Config.hpp"
#include "BatteryMeasurements.hpp"

class BatteryMeasurementsBuilder {
    public:
        explicit BatteryMeasurementsBuilder(const Config& cfg);

        BatteryMeasurementsBuilder& withVoltage(float v);

        BatteryMeasurementsBuilder& withCurrent(float c);

        BatteryMeasurementsBuilder& withTemperature(float t);

        BatteryMeasurementsBuilder& withTimestamp(uint64_t ts);

        core::BatteryMeasurements build() const;

    private:
        const Config& cfg_;
        core::BatteryMeasurements measurements_;
};

