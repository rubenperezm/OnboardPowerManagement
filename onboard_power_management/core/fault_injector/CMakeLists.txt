# =========================
# Domain library
# =========================
add_library(fault_injector
    FaultInjector.cpp
)

target_include_directories(fault_injector
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src/include
)

target_link_libraries(fault_injector
    PRIVATE
        logging
)

target_compile_features(fault_injector
    PUBLIC cxx_std_17
)