#include "DDSCoreAdapter.hpp"

core::PowerCommand DDSCoreAdapter::to_core(const dds::PowerCommand& dds_cmd){
    core::PowerCommand cmd;
    
    cmd.mode = to_core(dds_cmd.mode());
    cmd.emergencyShutdown = dds_cmd.emergencyShutdown();
    cmd.timestamp_us = dds_cmd.timestamp_us();

    return cmd;
}

dds::PowerCommand DDSCoreAdapter::to_dds(const core::PowerCommand& app_cmd){
    dds::PowerCommand dds_cmd;

    dds_cmd.mode(to_dds(app_cmd.mode));
    dds_cmd.emergencyShutdown(app_cmd.emergencyShutdown);
    dds_cmd.timestamp_us(app_cmd.timestamp_us);

    return dds_cmd;
}

core::LoadStatus DDSCoreAdapter::to_core(const dds::LoadStatus& dds_status){
    core::LoadStatus status;
    
    status.payloadActive = dds_status.payloadActive();
    status.commsActive = dds_status.commsActive();
    status.thermalActive = dds_status.thermalActive();
    status.timestamp_us = dds_status.timestamp_us();

    return status;
}

dds::LoadStatus DDSCoreAdapter::to_dds(const core::LoadStatus& app_status){
    dds::LoadStatus dds_status;

    dds_status.payloadActive(app_status.payloadActive);
    dds_status.commsActive(app_status.commsActive);
    dds_status.thermalActive(app_status.thermalActive);
    dds_status.timestamp_us(app_status.timestamp_us);

    return dds_status;
}

core::LocalSensorHealthStatus DDSCoreAdapter::to_core(const dds::LocalSensorHealthStatus& dds_status){
    core::LocalSensorHealthStatus status;
    
    status.sourceId = dds_status.sourceId();
    status.status = to_core(dds_status.status());
    status.timestamp_us = dds_status.timestamp_us();

    return status;
}

dds::LocalSensorHealthStatus DDSCoreAdapter::to_dds(const core::LocalSensorHealthStatus& app_status){
    dds::LocalSensorHealthStatus dds_status;

    dds_status.sourceId(app_status.sourceId);
    dds_status.status(to_dds(app_status.status));
    dds_status.timestamp_us(app_status.timestamp_us);

    return dds_status;
}

core::BatteryMeasurements DDSCoreAdapter::to_core(const dds::BatteryMeasurements& dds_bm){
    core::BatteryMeasurements bm;
    
    bm.voltage = dds_bm.voltage();
    bm.current = dds_bm.current();
    bm.temperature = dds_bm.temperature();
    bm.timestamp_us = dds_bm.timestamp_us();

    return bm;
}

dds::BatteryMeasurements DDSCoreAdapter::to_dds(const core::BatteryMeasurements& app_bm){
    dds::BatteryMeasurements dds_bm;
        
    dds_bm.voltage(app_bm.voltage);
    dds_bm.current(app_bm.current);
    dds_bm.temperature(app_bm.temperature);
    dds_bm.timestamp_us(app_bm.timestamp_us);

    return dds_bm;
}

core::SensorHealthStatus DDSCoreAdapter::to_core(const dds::SensorHealthStatus& dds_status){
    core::SensorHealthStatus status;
    
    status.anyDegraded = dds_status.anyDegraded();
    status.anyFailed = dds_status.anyFailed();
    status.timestamp_us = dds_status.timestamp_us();

    return status;
}

dds::SensorHealthStatus DDSCoreAdapter::to_dds(const core::SensorHealthStatus& app_status){
    dds::SensorHealthStatus dds_status;

    dds_status.anyDegraded(app_status.anyDegraded);
    dds_status.anyFailed(app_status.anyFailed);
    dds_status.timestamp_us(app_status.timestamp_us);

    return dds_status;
}

core::PowerMode DDSCoreAdapter::to_core(const dds::PowerMode& dds_mode){
    switch(dds_mode){
        case dds::PowerMode::OFF:    return core::PowerMode::OFF;
        case dds::PowerMode::SAFE:   return core::PowerMode::SAFE;
        case dds::PowerMode::NORMAL: return core::PowerMode::NORMAL;
        default:                  return core::PowerMode::OFF;
    }
}
dds::PowerMode DDSCoreAdapter::to_dds(const core::PowerMode& app_mode){
    switch(app_mode){
        case core::PowerMode::OFF:    return dds::PowerMode::OFF;
        case core::PowerMode::SAFE:   return dds::PowerMode::SAFE;
        case core::PowerMode::NORMAL: return dds::PowerMode::NORMAL;
        default:                      return dds::PowerMode::OFF;
    }
}

core::SensorState DDSCoreAdapter::to_core(const dds::SensorState& dds_state){
    switch(dds_state){
        case dds::SensorState::NOMINAL:    return core::SensorState::NOMINAL;
        case dds::SensorState::DEGRADED:   return core::SensorState::DEGRADED;
        case dds::SensorState::FAILED: return core::SensorState::FAILED;
        default:                  return core::SensorState::FAILED;
    }
}
dds::SensorState DDSCoreAdapter::to_dds(const core::SensorState& app_state){
    switch(app_state){
        case core::SensorState::NOMINAL:    return dds::SensorState::NOMINAL;
        case core::SensorState::DEGRADED:   return dds::SensorState::DEGRADED;
        case core::SensorState::FAILED: return dds::SensorState::FAILED;
        default:                      return dds::SensorState::FAILED;
    }
}
