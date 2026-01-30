#pragma once

#include "LoadStatus.h"
#include "PowerCommand.h"
#include "LocalSensorHealthStatus.h"
#include "LoadStatus.h"
#include "SensorHealthStatus.h"
#include "BatteryMeasurements.h"
#include "types/PowerCommand.hpp"
#include "types/LoadStatus.hpp"
#include "types/LocalSensorHealthStatus.hpp"
#include "types/BatteryMeasurements.hpp"
#include "types/SensorHealthStatus.hpp"

class DDSCoreAdapter {
    public:
        static core::PowerCommand to_core(const dds::PowerCommand& dds_cmd);
        static dds::PowerCommand to_dds(const core::PowerCommand& app_cmd);

        static core::LoadStatus to_core(const dds::LoadStatus& dds_status);
        static dds::LoadStatus to_dds(const core::LoadStatus& app_status);

        static core::LocalSensorHealthStatus to_core(const dds::LocalSensorHealthStatus& dds_status);
        static dds::LocalSensorHealthStatus to_dds(const core::LocalSensorHealthStatus& app_status);

        static core::BatteryMeasurements to_core(const dds::BatteryMeasurements& dds_bm);
        static dds::BatteryMeasurements to_dds(const core::BatteryMeasurements& app_bm);

        static core::SensorHealthStatus to_core(const dds::SensorHealthStatus& dds_status);
        static dds::SensorHealthStatus to_dds(const core::SensorHealthStatus& app_status);
        

    private:
        static core::PowerMode to_core(const dds::PowerMode& dds_mode);
        static dds::PowerMode to_dds(const core::PowerMode& app_mode);

        static core::SensorState to_core(const dds::SensorState& dds_state);
        static dds::SensorState to_dds(const core::SensorState& app_state);
};
