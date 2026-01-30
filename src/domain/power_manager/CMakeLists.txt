# =========================
# Domain library
# =========================
add_library(power_manager
    PowerManager.cpp
)

target_include_directories(power_manager
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src/include
)

target_link_libraries(power_manager
    PUBLIC
        config
    PRIVATE
        logging
)

target_compile_features(power_manager
    PUBLIC cxx_std_17
)