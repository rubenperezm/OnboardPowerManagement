# =========================
# Domain library
# =========================
add_library(telemetry_logger
    TelemetryLogger.cpp
)

target_include_directories(telemetry_logger
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src/types
)

target_compile_features(telemetry_logger
    PUBLIC cxx_std_17
)