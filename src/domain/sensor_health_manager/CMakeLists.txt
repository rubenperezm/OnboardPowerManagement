# =========================
# Domain library
# =========================
add_library(sensor_health_manager
    SensorHealthManager.cpp
)

target_include_directories(sensor_health_manager
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(sensor_health_manager
    PRIVATE
        dds_types
)

target_compile_features(sensor_health_manager
    PUBLIC cxx_std_17
)