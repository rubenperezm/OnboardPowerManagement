add_library(test_adapters
    PowerManagerTestAdapter.cpp
)

target_include_directories(test_adapters
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src/include
)

target_link_libraries(test_adapters
    PRIVATE
        power_manager
)

target_compile_features(test_adapters
    PUBLIC cxx_std_17
)