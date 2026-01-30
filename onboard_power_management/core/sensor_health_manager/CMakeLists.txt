# =========================
# Domain library
# =========================
add_library(sensor_health_manager
    SensorHealthManager.cpp
)

target_include_directories(sensor_health_manager
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/onboard_power_management/include
)

target_compile_features(sensor_health_manager
    PUBLIC cxx_std_17
)