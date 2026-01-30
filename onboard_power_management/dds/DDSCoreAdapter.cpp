#include "DDSCoreAdapter.hpp"

core::PowerCommand DDSCoreAdapter::to_core(const ::PowerCommand& dds_cmd){
        core::PowerCommand cmd;
        
        cmd.mode = to_core(dds_cmd.mode());
        cmd.emergencyShutdown = dds_cmd.emergencyShutdown();
        cmd.timestamp_us = dds_cmd.timestamp_us();

        return cmd;
}

::PowerCommand DDSCoreAdapter::to_dds(const core::PowerCommand& app_cmd){
    ::PowerCommand dds_cmd;

    dds_cmd.mode(to_dds(app_cmd.mode));
    dds_cmd.emergencyShutdown(app_cmd.emergencyShutdown);
    dds_cmd.timestamp_us(app_cmd.timestamp_us);

    return dds_cmd;
}

core::LoadStatus DDSCoreAdapter::to_core(const ::LoadStatus& dds_status){
        core::LoadStatus status;
        
        status.payloadActive = dds_status.payloadActive();
        status.commsActive = dds_status.commsActive();
        status.thermalActive = dds_status.thermalActive();
        status.timestamp_us = dds_status.timestamp_us();

        return status;
}

::LoadStatus DDSCoreAdapter::to_dds(const core::LoadStatus& app_status){
    ::LoadStatus dds_status;

    dds_status.payloadActive(app_status.payloadActive);
    dds_status.commsActive(app_status.commsActive);
    dds_status.thermalActive(app_status.thermalActive);
    dds_status.timestamp_us(app_status.timestamp_us);

    return dds_status;
}

core::LocalSensorHealthStatus DDSCoreAdapter::to_core(const ::LocalSensorHealthStatus& dds_status){
        core::LocalSensorHealthStatus status;
        
        status.sourceId = dds_status.sourceId();
        status.status = to_core(dds_status.status());
        status.timestamp_us = dds_status.timestamp_us();

        return status;
}

::LocalSensorHealthStatus DDSCoreAdapter::to_dds(const core::LocalSensorHealthStatus& app_status){
    ::LocalSensorHealthStatus dds_status;

    dds_status.sourceId(app_status.sourceId);
    dds_status.status(to_dds(app_status.status));
    dds_status.timestamp_us(app_status.timestamp_us);

    return dds_status;
}

core::BatteryMeasurements DDSCoreAdapter::to_core(const ::BatteryMeasurements& dds_bm){
        core::BatteryMeasurements bm;
        
        bm.voltage = dds_bm.voltage();
        bm.current = dds_bm.current();
        bm.temperature = dds_bm.temperature();
        bm.timestamp_us = dds_bm.timestamp_us();

        return bm;
}

::BatteryMeasurements DDSCoreAdapter::to_dds(const core::BatteryMeasurements& app_bm){
    BatteryMeasurements dds_bm;
        
    dds_bm.voltage(app_bm.voltage);
    dds_bm.current(app_bm.current);
    dds_bm.temperature(app_bm.temperature);
    dds_bm.timestamp_us(app_bm.timestamp_us);

    return dds_bm;
}

core::SensorHealthStatus DDSCoreAdapter::to_core(const ::SensorHealthStatus& dds_status){
        core::SensorHealthStatus status;
        
        status.anyDegraded = dds_status.anyDegraded();
        status.anyFailed = dds_status.anyFailed();
        status.timestamp_us = dds_status.timestamp_us();

        return status;
}

::SensorHealthStatus DDSCoreAdapter::to_dds(const core::SensorHealthStatus& app_status){
    ::SensorHealthStatus dds_status;

    dds_status.anyDegraded(app_status.anyDegraded);
    dds_status.anyFailed(app_status.anyFailed);
    dds_status.timestamp_us(app_status.timestamp_us);

    return dds_status;
}

core::PowerMode DDSCoreAdapter::to_core(const ::PowerMode& dds_mode){
    switch(dds_mode){
        case ::PowerMode::OFF:    return core::PowerMode::OFF;
        case ::PowerMode::SAFE:   return core::PowerMode::SAFE;
        case ::PowerMode::NORMAL: return core::PowerMode::NORMAL;
        default:                  return core::PowerMode::OFF;
    }
}
::PowerMode DDSCoreAdapter::to_dds(const core::PowerMode& app_mode){
        switch(app_mode){
        case core::PowerMode::OFF:    return ::PowerMode::OFF;
        case core::PowerMode::SAFE:   return ::PowerMode::SAFE;
        case core::PowerMode::NORMAL: return ::PowerMode::NORMAL;
        default:                      return ::PowerMode::OFF;
    }
}

core::SensorState DDSCoreAdapter::to_core(const ::SensorState& dds_state){
    switch(dds_state){
        case ::SensorState::NOMINAL:    return core::SensorState::NOMINAL;
        case ::SensorState::DEGRADED:   return core::SensorState::DEGRADED;
        case ::SensorState::FAILED: return core::SensorState::FAILED;
        default:                  return core::SensorState::FAILED;
    }
}
::SensorState DDSCoreAdapter::to_dds(const core::SensorState& app_state){
        switch(app_state){
        case core::SensorState::NOMINAL:    return ::SensorState::NOMINAL;
        case core::SensorState::DEGRADED:   return ::SensorState::DEGRADED;
        case core::SensorState::FAILED: return ::SensorState::FAILED;
        default:                      return ::SensorState::FAILED;
    }
}
