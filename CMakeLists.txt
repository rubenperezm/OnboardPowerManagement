cmake_minimum_required(VERSION 3.16)

project(OnboardPowerSimulator
    VERSION 0.1
    LANGUAGES CXX
)

# =========================
# Global C++ settings
# =========================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Warnings
add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

set(LOG_LEVEL "LOG_LEVEL_INFO"
    CACHE STRING "Logging level (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_WARN, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG)"
)

set(VALID_LOG_LEVELS
    LOG_LEVEL_NONE
    LOG_LEVEL_ERROR
    LOG_LEVEL_WARN
    LOG_LEVEL_INFO
    LOG_LEVEL_DEBUG
)

list(FIND VALID_LOG_LEVELS ${LOG_LEVEL} LOG_LEVEL_INDEX)

if (LOG_LEVEL_INDEX EQUAL -1)
    message(FATAL_ERROR
        "Invalid LOG_LEVEL='${LOG_LEVEL}'. "
        "Valid values are: ${VALID_LOG_LEVELS}"
    )
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Release" AND LOG_LEVEL STREQUAL "LOG_LEVEL_DEBUG")
    message(WARNING
        "LOG_LEVEL_DEBUG used with Release build. "
        "This is allowed but not recommended for flight builds."
    )
endif()

option(BUILD_TESTS "Build unit tests" OFF)

add_subdirectory(onboard_power_management)

if (BUILD_TESTS)
    add_subdirectory(tests/adapters)
    add_subdirectory(tests/helpers)
    add_subdirectory(tests/unit_tests)
endif()