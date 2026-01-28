find_package(fastrtps REQUIRED)
find_package(fastcdr REQUIRED)

file(GLOB DDS_TYPES_SOURCES
    "*.cxx"
)

add_library(dds_types
    ${DDS_TYPES_SOURCES}
)

target_include_directories(dds_types PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(dds_types
    fastcdr
    fastrtps
)