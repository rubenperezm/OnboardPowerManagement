# =========================
# DDS Interfaces library
# =========================

find_package(fastrtps REQUIRED)
find_package(fastcdr REQUIRED)

file(GLOB GENERATED_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/generated/*.cxx"
)

file(GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

file(GLOB NODE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/nodes/*.cpp"
)

add_library(dds_interfaces
    ${SOURCES}
    ${GENERATED_SOURCES}
    ${NODE_SOURCES}
)

target_include_directories(dds_interfaces
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/generated
        ${CMAKE_SOURCE_DIR}/onboard_power_management/include
)

target_link_libraries(dds_interfaces
    PUBLIC
        fastrtps
        fastcdr
    PRIVATE
        power_manager
)

target_compile_features(dds_interfaces
    PUBLIC cxx_std_17
)