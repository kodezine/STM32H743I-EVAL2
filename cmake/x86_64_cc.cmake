add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
        ${TEST_INCLUDE_DIR}/test/${PROJECT_NAME}.c
        ${UNITY_TEST_RUNNER_PATH}/${PROJECT_NAME}_runner.c

        ${TEST_MOCK_SOURCES}
        ${TEST_SOURCES}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $ENV{MOCK_OUT}
    PRIVATE
        ${TEST_MOCK_INCLUDES}
        ${TEST_INCLUDE_DIR}
        ${OTHER_INCLUDE_DIR}
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
        -g -O0 -Wall -Wshadow
        -fprofile-arcs -ftest-coverage
)

target_link_options(${PROJECT_NAME}
    PRIVATE
        -fprofile-arcs
)

target_link_libraries(${PROJECT_NAME}
    unity
    cmock
    blinky_unity
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        SUFFIX ".out"
)

# Register the test bin as a ctest executable test
add_test(NAME ctest_${PROJECT_NAME} COMMAND ${PROJECT_NAME}.out)
