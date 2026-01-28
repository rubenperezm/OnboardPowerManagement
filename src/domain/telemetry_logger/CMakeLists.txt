# =========================
# Domain library
# =========================
add_library(telemetry_logger
    TelemetryLogger.cpp
)

target_include_directories(telemetry_logger
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(telemetry_logger
    PRIVATE
        dds_types
)

target_compile_features(telemetry_logger
    PUBLIC cxx_std_17
)