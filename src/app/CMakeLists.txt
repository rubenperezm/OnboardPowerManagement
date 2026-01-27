add_executable(power_subsystem_simulator
    main.cpp
)

target_include_directories(power_subsystem_simulator
    PRIVATE
        ${PROJECT_SOURCE_DIR}/types
        ${PROJECT_SOURCE_DIR}/infrastructure/config
)

target_link_libraries(power_subsystem_simulator
    PRIVATE
        config
        battery_monitor
        # sensor_health_manager
        # power_manager
        # telemetry_logger
        fault_injector
        # subsystem_controller
)