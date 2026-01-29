#include <chrono>

#include "BatteryMeasurementsBuilder.hpp"


BatteryMeasurementsBuilder::BatteryMeasurementsBuilder(const Config& cfg) : cfg_(cfg) {
    measurements_.voltage       = cfg_.getInitialVoltage();
    measurements_.current       = cfg_.getInitialCurrent();
    measurements_.temperature   = cfg_.getInitialTemperature();
    measurements_.timestamp_us  = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now().time_since_epoch()
    ).count();
}

BatteryMeasurementsBuilder& BatteryMeasurementsBuilder::withVoltage(float v) {
    measurements_.voltage = v;
    return *this;
}

BatteryMeasurementsBuilder& BatteryMeasurementsBuilder::withCurrent(float c) {
    measurements_.current = c;
    return *this;
}

BatteryMeasurementsBuilder& BatteryMeasurementsBuilder::withTemperature(float t) {
    measurements_.temperature = t;
    return *this;
}

BatteryMeasurementsBuilder& BatteryMeasurementsBuilder::withTimestamp(uint64_t ts) {
    measurements_.timestamp_us = ts;
    return *this;
}

core::BatteryMeasurements BatteryMeasurementsBuilder::build() const {
    return measurements_;
}