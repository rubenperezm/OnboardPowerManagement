#pragma once
#include "PowerManager.hpp"
#include "PowerCommand.hpp"

struct PowerManagerTestAdapter {
    static void forceMode(PowerManager& pm, const PowerMode mode);

    static bool getVoltageOverloadFlag(const PowerManager& pm);

    static bool getVoltageUnderloadFlag(const PowerManager& pm);

    static bool getCurrentOverloadFlag(const PowerManager& pm);

    static bool getSustainedOvercurrentFlag(const PowerManager& pm);

    static bool getOvertemperatureFlag(const PowerManager& pm);

    static bool getUndertemperatureFlag(const PowerManager& pm);
};