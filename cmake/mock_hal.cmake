# Minimum version for cmake compatiblity
cmake_minimum_required(VERSION 3.18)
include(CMakePrintHelpers)

project(
    mock_hal
    VERSION 1.0
    DESCRIPTION "The project is a hal mock layer implementation"
    LANGUAGES ASM C CXX
)

set(MOCK_HAL_SOURCES
    $ENV{MOCK_OUT}/mock_stm32h7xx_hal.c
    ${CMAKE_SOURCE_DIR}/banshi/src/BANSHI_flash.c
)

add_library(mock_hal
    STATIC
    ${MOCK_HAL_SOURCES}
)

target_compile_definitions(mock_hal
    PUBLIC
    STM32H743xx
    USE_HAL_DRIVER
)

target_include_directories(mock_hal
    PUBLIC
    ${CMAKE_SOURCE_DIR}/banshi/inc
    $ENV{MOCK_OUT}
    ${hal_SOURCE_DIR}/prototype_a/cubemx/Drivers/STM32H7xx_HAL_Driver/Inc
    ${hal_SOURCE_DIR}/prototype_a/cubemx/Core/Inc
    ${hal_SOURCE_DIR}/prototype_a/cubemx/Drivers/CMSIS/Device/ST/STM32H7xx/Include
    ${hal_SOURCE_DIR}/prototype_a/cubemx/Drivers/CMSIS/Include
)

target_link_libraries(mock_hal
    unity
    cmock
)
target_compile_options(mock_hal
PRIVATE
    $<$<C_COMPILER_ID:Clang>:-m32
                            -Wcast-align
                            -Wcast-qual
                            -Wconversion
                            -Wexit-time-destructors
                            -Wglobal-constructors
                            -Wmissing-noreturn
                            -Wmissing-prototypes
                            -Wno-missing-braces
                            -Wno-int-to-void-pointer-cast
                            -Wold-style-cast
                            -Wshadow
                            -Wweak-vtables
                            -Wall>
    $<$<C_COMPILER_ID:GNU>:-m32
                        -Waddress
                        -Waggregate-return
                        -Wformat-nonliteral
                        -Wformat-security
                        -Wformat
                        -Winit-self
                        -Wmissing-declarations
                        -Wmissing-include-dirs
                        -Wno-multichar
                        -Wno-parentheses
                        -Wno-type-limits
                        -Wno-unused-parameter
                        -Wno-int-to-void-pointer-cast
                        -Wunreachable-code
                        -Wwrite-strings
                        -Wpointer-arith
                        -Werror
                        >
$<$<C_COMPILER_ID:MSVC>:/Wall>
)