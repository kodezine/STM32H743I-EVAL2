cmake_minimum_required(VERSION 3.18)

# NOTE: Project name MUST match the test file name
project(
    blinky_unity
)

add_library(${PROJECT_NAME} STATIC)
add_library(${PROJECT_NAME}::framework ALIAS ${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/blinky_unity.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${PROJECT_NAME}
    $<IF:${HW_UNIT_TESTS},hal, >
)