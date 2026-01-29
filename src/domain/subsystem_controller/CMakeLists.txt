# =========================
# Domain library
# =========================
add_library(subsystem_controller
    SubsystemController.cpp
)

target_include_directories(subsystem_controller
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src/types
)

target_compile_features(subsystem_controller
    PUBLIC cxx_std_17
)