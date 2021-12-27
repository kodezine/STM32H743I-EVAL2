cmake_minimum_required(VERSION 3.12)

set(PROJJECT_NAME BANSHI)

if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "ARM")

add_library(${PROJJECT_NAME} STATIC)
add_library(${PROJJECT_NAME}::framework ALIAS ${PROJJECT_NAME})

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

target_sources(${PROJJECT_NAME}
    PRIVATE

#   Banshi layer files
    #port/banshi_to_hal.c
    #port/debug_swo.c
    banshi/src/BANSHI_gpio.c
    banshi/src/BANSHI_can.c
    banshi/src/BANSHI_adc.c
    banshi/src/BANSHI_spi.c
    banshi/src/BANSHI_i2c.c
    banshi/src/BANSHI_uart.c
    banshi/src/BANSHI_dac.c
    banshi/src/BANSHI_HWTimer.c
    banshi/src/BANSHI_HWPWM.c
    banshi/src/BANSHI_adc.c
    banshi/src/BANSHI_NVIC.c
)

target_include_directories(${PROJJECT_NAME}
    PUBLIC
        #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cubemx/Drivers/STM32H7xx_HAL_Driver/Inc>
        #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cubemx/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy>
        #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cubemx/Core/Inc>
        #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cubemx/Drivers/CMSIS/Include>
        #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cubemx/Drivers/CMSIS/Device/ST/STM32H7xx/Include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/banshi/inc>
        #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/port>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJJECT_NAME}>
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/application/cfg>
)

target_link_libraries(${PROJJECT_NAME}
    os2
    hal
)

set(${PROJJECT_NAME}_PUBLIC_HEADERS
    banshi/inc/BANSHI_gpio.h
    banshi/inc/BANSHI_can.h
    banshi/inc/BANSHI_adc.h
    banshi/inc/BANSHI_spi.h
    banshi/inc/BANSHI_i2c.h
    banshi/inc/BANSHI_dac.h
    banshi/inc/BANSHI_HWTimer.h
    banshi/inc/BANSHI_HWPWM.h
    banshi/inc/BANSHI_NVIC.h
)

set_target_properties(${PROJJECT_NAME}
    PROPERTIES 
        C_STANDARD          11
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS        OFF
        PUBLIC_HEADER       "${${PROJJECT_NAME}_PUBLIC_HEADERS}"
        EXPORT_NAME         framework
)

target_compile_options(${PROJJECT_NAME}
    PRIVATE
        $<$<C_COMPILER_ID:Clang>:-Wcast-align
                                 -Wcast-qual
                                 -Wconversion
                                 -Wexit-time-destructors
                                 -Wglobal-constructors
                                 -Wmissing-noreturn
                                 -Wmissing-prototypes
                                 -Wno-missing-braces
                                 -Wold-style-cast
                                 -Wshadow
                                 -Wweak-vtables
                                 -Werror
                                 -Wall>
        $<$<C_COMPILER_ID:GNU>:-Waddress
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
                               -Wunreachable-code
                               -Wwrite-strings
                               -Wpointer-arith
                               -Werror
                               -Wall>
       $<$<C_COMPILER_ID:MSVC>:/Wall>
)

include(CMakePrintHelpers)
cmake_print_variables(${PROJJECT_NAME}_LINKER_SCRIPT)
cmake_print_variables(${PROJJECT_NAME}_LINKER_PATH)

else()
    message(FATAL_ERROR "${PROJJECT_NAME} can only compile with ARM cross compiler, please use appropriate toolchain.")
endif()