cmake_minimum_required(VERSION 3.18)

# NOTE: Project name MUST match the test file name
project(
    ut_blinky_unity
)

# Add test sources here ...
set(TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../../cubemx/Core/Src/stm32h7xx_it.c
)

# DO NOT ADD ANY-THING IN THE VARIABLE BELOW
set(TEST_INCLUDE_DIR
    ${CMAKE_CURRENT_LIST_DIR}/..
)

# Add optional include files here based on architecture ...

# The ao uses following mocks
set(TEST_MOCK_HEADERS

)
# All above header files but mocked sources instead
set(TEST_MOCK_SOURCES

)
# The mock includes
set(TEST_MOCK_INCLUDES

)

generate_mocks(TEST_MOCK_HEADERS
    ${MOCKS_TEMPORARY_PATH} # Directory for temporary mocks
    ${PERL_SH_PATH} # Directory for perl.sh
    ${CREATE_MOCKS_RUBY_PATH} # Directory for create_mocks.rb
)

# Reconfigure the unity to use this as runner for this project
set(UNITY_TEST_RUNNER_PATH ${CMAKE_CURRENT_BINARY_DIR}/runner)
file(MAKE_DIRECTORY ${UNITY_TEST_RUNNER_PATH})

if(CMAKE_SYSTEM_PROCESSOR)
    if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "ARM")
        execute_process(
            COMMAND ruby ${unity_SOURCE_DIR}/auto/generate_test_runner.rb --main_name=app_main ${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.c ${UNITY_TEST_RUNNER_PATH}/${PROJECT_NAME}_runner.c
        )
       include(${arm_cc_PATH}/arm_cc.cmake)
    else()
        execute_process(
            COMMAND ruby ${unity_SOURCE_DIR}/auto/generate_test_runner.rb --main_name=main ${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.c ${UNITY_TEST_RUNNER_PATH}/${PROJECT_NAME}_runner.c
        )
        include(${x86_64_cc_PATH}/x86_64_cc.cmake)
    endif()
else()
    message(STATUS "[${PROJECT_NAME}] compiling with unknown architecture")
endif()

# Add optional definitions here ...
target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        TESTING
)
