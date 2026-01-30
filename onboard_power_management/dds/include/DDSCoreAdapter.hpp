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
        static core::PowerCommand to_core(const ::PowerCommand& dds_cmd);
        static ::PowerCommand to_dds(const core::PowerCommand& app_cmd);

        static core::LoadStatus to_core(const ::LoadStatus& dds_status);
        static ::LoadStatus to_dds(const core::LoadStatus& app_status);

        static core::LocalSensorHealthStatus to_core(const ::LocalSensorHealthStatus& dds_status);
        static ::LocalSensorHealthStatus to_dds(const core::LocalSensorHealthStatus& app_status);

        static core::BatteryMeasurements to_core(const ::BatteryMeasurements& dds_bm);
        static ::BatteryMeasurements to_dds(const core::BatteryMeasurements& app_bm);

        static core::SensorHealthStatus to_core(const ::SensorHealthStatus& dds_status);
        static ::SensorHealthStatus to_dds(const core::SensorHealthStatus& app_status);
        

    private:
        static core::PowerMode to_core(const ::PowerMode& dds_mode);
        static ::PowerMode to_dds(const core::PowerMode& app_mode);

        static core::SensorState to_core(const ::SensorState& dds_state);
        static ::SensorState to_dds(const core::SensorState& app_state);
};
