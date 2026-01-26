#include <stdexcept>
#include <iostream>
#include <chrono>

#include "FaultInjector.hpp"
#include "LocalSensorHealthStatus.hpp"
#include "Log.hpp"

FaultInjector::FaultInjector() : m_activeFaults() {}

void FaultInjector::activateFault(const uint8_t source, const SensorState state) {
    if (state == SensorState::NOMINAL){
        LOG_WARN("Injecting 'NOMINAL' state on sensor " + std::to_string(source) + " - consider using clearFault() instead.");
    }

    m_activeFaults[source] = state;

    LOG_DEBUG("Injected '" + std::to_string(static_cast<int>(state)) + "' state on sensor " + std::to_string(source));
}

void FaultInjector::clearFault(const uint8_t source){
    size_t removed = m_activeFaults.erase(source);

    if (removed == 1){
        LOG_DEBUG("Removed state on sensor " + std::to_string(source));
    } else {
        LOG_WARN("Could not find fault for sensor " + std::to_string(source) + " while clearing it.");
    }
}

LocalSensorHealthStatus FaultInjector::getHealthStatus(const uint8_t source) const {
    if (source >= 128){
        throw std::out_of_range("Source ID must be within the range [0, 127]");
    }
    
    auto it = m_activeFaults.find(source);

    if (it != m_activeFaults.end()){
        LocalSensorHealthStatus healthStatus;

        healthStatus.sourceId = it->first + 128;
        healthStatus.status = it->second;
        healthStatus.timestamp_us = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now().time_since_epoch()
        ).count();

        return healthStatus;

    } else {
        LOG_ERROR("Could not find fault for sensor " +  std::to_string(source));

        throw std::runtime_error("Sensor not found in FaultInjector.");
    }
}