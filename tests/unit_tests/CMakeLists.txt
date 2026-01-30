# GoogleTest
find_package(GTest REQUIRED)

enable_testing()

add_executable(unit_tests
    PowerManagerTests.cpp
)

target_include_directories(unit_tests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/include
)

target_link_libraries(unit_tests
    PRIVATE
        config
        test_adapters
        test_helpers
        power_manager
        GTest::gtest
        GTest::gtest_main
)

set(TEST_CONFIG_FILE "${CMAKE_SOURCE_DIR}/tests/cfg/test_const.cfg")

target_compile_definitions(unit_tests
    PRIVATE TEST_CONFIG_FILE="${TEST_CONFIG_FILE}"
)

add_test(
    NAME unit_tests
    COMMAND unit_tests
)