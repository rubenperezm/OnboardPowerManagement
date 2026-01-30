# =========================
# Domain library
# =========================
add_library(battery_monitor
    BatteryMonitor.cpp
)

target_include_directories(battery_monitor
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/onboard_power_management/include
)

target_link_libraries(battery_monitor
    PUBLIC
        config
)

target_compile_features(battery_monitor
    PUBLIC cxx_std_17
)
