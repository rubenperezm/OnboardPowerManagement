include_directories(
    ${PROJECT_SOURCE_DIR}/types
)

add_subdirectory(app)

add_subdirectory(infrastructure/config)
add_subdirectory(infrastructure/logging)

add_subdirectory(domain/battery_monitor)
add_subdirectory(domain/sensor_health_manager)
add_subdirectory(domain/power_manager)
add_subdirectory(domain/fault_injector)
add_subdirectory(domain/telemetry_logger)
add_subdirectory(domain/subsystem_controller)