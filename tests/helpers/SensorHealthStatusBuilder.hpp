#pragma once

#include <cstdint>

#include "types/SensorHealthStatus.hpp"

class SensorHealthStatusBuilder {
    public:
        SensorHealthStatusBuilder();

        SensorHealthStatusBuilder& withAnyDegraded(bool degraded);

        SensorHealthStatusBuilder& withAnyFailed(bool failed);

        SensorHealthStatusBuilder& withTimestamp(uint64_t ts);

        core::SensorHealthStatus build() const;

    private:
        core::SensorHealthStatus status_;
};

