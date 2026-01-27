#include "PowerManagerTestAdapter.hpp"

void PowerManagerTestAdapter::forceMode(PowerManager& pm, const PowerMode mode){
    pm.m_currentMode = mode;
}

bool PowerManagerTestAdapter::getVoltageOverloadFlag(const PowerManager& pm) {
    return pm.m_voltageOverload;
}

bool PowerManagerTestAdapter::getVoltageUnderloadFlag(const PowerManager& pm) {
    return pm.m_voltageUnderload;
}

bool PowerManagerTestAdapter::getCurrentOverloadFlag(const PowerManager& pm) {
    return pm.m_currentOverload;
}

bool PowerManagerTestAdapter::getSustainedOvercurrentFlag(const PowerManager& pm) {
    return pm.m_sustainedOvercurrent;
}

bool PowerManagerTestAdapter::getOvertemperatureFlag(const PowerManager& pm) {
    return pm.m_overtemperature;
}

bool PowerManagerTestAdapter::getUndertemperatureFlag (const PowerManager& pm) {
    return pm.m_undertemperature;
}