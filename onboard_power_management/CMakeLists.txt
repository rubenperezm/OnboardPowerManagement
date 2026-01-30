add_subdirectory(apps)

add_subdirectory(infrastructure/config)
add_subdirectory(infrastructure/logging)

add_subdirectory(core/battery_monitor)
add_subdirectory(core/sensor_health_manager)
add_subdirectory(core/power_manager)
add_subdirectory(core/fault_injector)
add_subdirectory(core/telemetry_logger)
add_subdirectory(core/subsystem_controller)

add_subdirectory(dds)