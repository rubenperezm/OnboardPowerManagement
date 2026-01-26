# =========================
# Domain library
# =========================
add_library(config
    Config.cpp
)

target_include_directories(config
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(config
    PRIVATE
        logging
)

target_compile_features(config
    PUBLIC cxx_std_17
)