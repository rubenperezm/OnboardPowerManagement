# =========================
# Domain library
# =========================
add_library(battery_monitor
    BatteryMonitor.cpp
)

target_include_directories(battery_monitor
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(battery_monitor
    PUBLIC
        config
    PRIVATE
        dds_types
)

target_compile_features(battery_monitor
    PUBLIC cxx_std_17
)
