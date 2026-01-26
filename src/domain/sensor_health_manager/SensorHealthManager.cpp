#include <stdexcept>
#include <iostream>
#include <chrono>

#include "SensorHealthManager.hpp"

SensorHealthManager::SensorHealthManager() : m_originalHealthBySource(), m_effectiveHealthBySource() {}


void SensorHealthManager::updateHealth(const LocalSensorHealthStatus& health){
    uint8_t source = health.sourceId;
    auto orig_it = m_originalHealthBySource.find(source);
    auto effe_it = m_effectiveHealthBySource.find(source);

    if (orig_it == m_originalHealthBySource.end()){
        if (isSourceSimulated(source)){
            throw std::runtime_error("Injecting state on an undefined source.");
        } else {
            m_originalHealthBySource[source] = health;
            m_effectiveHealthBySource[source] = health;
        }
    } else if (isSourceSimulated(source)) {
        m_effectiveHealthBySource[injectedToActualSource(source)] = health;
    } else {
        if (effe_it == m_effectiveHealthBySource.end() || effe_it->second == orig_it->second){
            m_effectiveHealthBySource[source] = health;
        }
        m_originalHealthBySource[source] = health;
    }
}

SensorHealthStatus SensorHealthManager::getHealthStatus() const{
    SensorHealthStatus health;
    health.anyDegraded = false;
    health.anyFailed = false;

    for (const auto& it : m_effectiveHealthBySource){
        if (it.second.status == SensorState::DEGRADED){
            health.anyDegraded = true;
        } else if (it.second.status == SensorState::FAILED){
            health.anyFailed = true;
        }

        if (health.anyDegraded && health.anyFailed){
            break;
        }
    }

    health.timestamp_us = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now().time_since_epoch()
    ).count();

    return health;
}

void SensorHealthManager::reset(){
    m_effectiveHealthBySource = m_originalHealthBySource;
}

bool isSourceSimulated(const uint8_t source){
    return (source >= 128);
}

uint8_t injectedToActualSource(const uint8_t injectedSource){
    return injectedSource & 127;
}