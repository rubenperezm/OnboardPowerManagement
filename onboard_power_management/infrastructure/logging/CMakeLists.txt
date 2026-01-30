# =========================
# Domain library
# =========================
add_library(logging
    LogBackend.cpp
)

target_include_directories(logging
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(logging
    PUBLIC cxx_std_17
)

target_compile_definitions(logging
    PUBLIC LOG_LEVEL=${LOG_LEVEL}
)

message("-- LOG_LEVEL: ${LOG_LEVEL}")