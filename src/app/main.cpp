
#include <iostream>

#include "Config.hpp"
#include "BatteryMonitor.hpp"

int main() {
    Config config("../cfg/const.cfg");
    BatteryMonitor batteryMonitor(config);

    for (int i = 0; i < 25; ++i) {
    batteryMonitor.acquireMeasurements();
    auto measurements = batteryMonitor.getMeasurements();
    if (measurements) {
        std::cout << "Voltage: " << measurements->voltage() << " V\n";
        std::cout << "Current: " << measurements->current() << " A\n";
        std::cout << "Temperature: " << measurements->temperature() << " °C\n";
        std::cout << "Timestamp: " << measurements->timestamp_us() << " us\n";
    } else {
        std::cout << "No measurements available.\n";
    }

    auto healthStatus = batteryMonitor.getSensorHealthStatus();
    std::cout << "Sensor ID: " << static_cast<int>(healthStatus.sourceId()) << "\n";
    std::cout << "Sensor Status: " << static_cast<int>(healthStatus.status()) << "\n";
    std::cout << "Health Timestamp: " << healthStatus.timestamp_us() << " us\n";

    std::cout << "-------------------------\n";
    }
    return 0;
}