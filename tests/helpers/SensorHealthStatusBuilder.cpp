#include <chrono>

#include "SensorHealthStatusBuilder.hpp"


SensorHealthStatusBuilder::SensorHealthStatusBuilder() {
    status_.anyDegraded = false;
    status_.anyFailed = false;
    status_.timestamp_us  = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now().time_since_epoch()
    ).count();
}

SensorHealthStatusBuilder& SensorHealthStatusBuilder::withAnyDegraded(bool degraded) {
    status_.anyDegraded = degraded;
    return *this;
}

SensorHealthStatusBuilder& SensorHealthStatusBuilder::withAnyFailed(bool failed) {
    status_.anyFailed = failed;
    return *this;
}

SensorHealthStatusBuilder& SensorHealthStatusBuilder::withTimestamp(uint64_t ts) {
    status_.timestamp_us = ts;
    return *this;
}

SensorHealthStatus SensorHealthStatusBuilder::build() const {
    return status_;
}