# =========================
# Domain library
# =========================
add_library(subsystem_controller
    SubsystemController.cpp
)

target_include_directories(subsystem_controller
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(subsystem_controller
    PRIVATE
        dds_types
)

target_compile_features(subsystem_controller
    PUBLIC cxx_std_17
)