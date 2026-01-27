add_library(test_helpers
    BatteryMeasurementsBuilder.cpp
    SensorHealthStatusBuilder.cpp
)

target_include_directories(test_helpers
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src/types
)

target_link_libraries(test_helpers
    PRIVATE
        config
)

target_compile_features(test_helpers
    PUBLIC cxx_std_17
)