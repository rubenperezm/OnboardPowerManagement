# =========================
# DDS Interfaces library
# =========================

file(GLOB_RECURSE GENERATED_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/generated/*.cxx"
)

add_library(dds_interfaces
    DDSContext.cpp
    DDSCoreAdapter.cpp
    ${GENERATED_SOURCES}
)

target_include_directories(dds_interfaces
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/generated
        ${CMAKE_SOURCE_DIR}/src/include
)

target_link_libraries(dds_interfaces
    PRIVATE
        fastdds
)

target_compile_features(dds_interfaces
    PUBLIC cxx_std_17
)