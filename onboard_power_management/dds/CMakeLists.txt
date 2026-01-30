# =========================
# DDS Interfaces library
# =========================

file(GLOB GENERATED_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/generated/*.cxx"
)

file(GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(dds_interfaces
    ${SOURCES}
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