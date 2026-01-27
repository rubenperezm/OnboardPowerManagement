#pragma once

#include <cstdint>

#include "SensorHealthStatus.hpp"

class SensorHealthStatusBuilder {
    public:
        SensorHealthStatusBuilder();

        SensorHealthStatusBuilder& withAnyDegraded(bool degraded);

        SensorHealthStatusBuilder& withAnyFailed(bool failed);

        SensorHealthStatusBuilder& withTimestamp(uint64_t ts);

        SensorHealthStatus build() const;

    private:
        SensorHealthStatus status_;
};

