cmake_minimum_required(VERSION 3.20)

project(hal
    VERSION     0.0.1
    LANGUAGES   C ASM CXX
    DESCRIPTION "Hardware Abstraction Layer for STM32CubeMx based project"
)

if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "ARM")

add_library(${PROJECT_NAME} STATIC)
add_library(${PROJECT_NAME}::framework ALIAS ${PROJECT_NAME})

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(CMakePrintHelpers)

target_sources(${PROJECT_NAME}
    PRIVATE
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc_ex.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dfsdm.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_eth_ex.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_eth.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_ltdc_ex.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_ltdc.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_nor.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd_ex.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_qspi.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sai_ex.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sai.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd_ex.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sdram.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sram.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_delayblock.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_fmc.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_sdmmc.c
    cubemx/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_usb.c

    cubemx/startup_stm32h743xx.s

    cubemx/Core/Src/adc.c
    cubemx/Core/Src/dfsdm.c
    cubemx/Core/Src/eth.c
    cubemx/Core/Src/fmc.c
    cubemx/Core/Src/gpio.c
    cubemx/Core/Src/i2c.c
    cubemx/Core/Src/ltdc.c
    cubemx/Core/Src/main.c
    cubemx/Core/Src/quadspi.c
    cubemx/Core/Src/sai.c
    cubemx/Core/Src/sdmmc.c
    cubemx/Core/Src/stm32h7xx_hal_msp.c
    #cubemx/Core/Src/stm32h7xx_it.c
    cubemx/Core/Src/system_stm32h7xx.c
    cubemx/Core/Src/usart.c
    cubemx/Core/Src/usb_otg.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cubemx/Drivers/STM32H7xx_HAL_Driver/Inc>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cubemx/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cubemx/Core/Inc>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cubemx/Drivers/CMSIS/Include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cubemx/Drivers/CMSIS/Device/ST/STM32H7xx/Include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}>
)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        USE_HAL_DRIVER
        STM32H743xx
        HW_BOARD_TYPE=2
)

cmake_print_variables(BOARD_TYPE)

set(${PROJECT_NAME}_PUBLIC_HEADERS
    cubemx/Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal.h
    cubemx/Core/Inc/adc.h
    cubemx/Core/Inc/dfsdm.h
    cubemx/Core/Inc/eth.h
    cubemx/Core/Inc/fmc.h
    cubemx/Core/Inc/gpio.h
    cubemx/Core/Inc/i2c.h
    cubemx/Core/Inc/ltdc.h
    cubemx/Core/Inc/main.h
    cubemx/Core/Inc/quadspi.h
    cubemx/Core/Inc/sai.h
    cubemx/Core/Inc/sdmmc.h
    cubemx/Core/Inc/stm327xx_hal_conf.h
    cubemx/Core/Inc/stm32h7xx_it.h
    cubemx/Core/Inc/usart.h
    cubemx/Core/Inc/usb_otg.h
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        C_STANDARD          11
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS        OFF
        PUBLIC_HEADER       "${${PROJECT_NAME}_PUBLIC_HEADERS}"
        EXPORT_NAME         framework
)

target_compile_options(${PROJECT_NAME}
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

write_basic_package_version_file(${PROJECT_NAME}ConfigVersion.cmake
    VERSION       ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
set(${PROJECT_NAME}_LINKER_SCRIPT "STM32H743XIHx_FLASH.ld" CACHE STRING "")
set(${PROJECT_NAME}_LINKER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cubemx" CACHE STRING "")

write_basic_package_version_file(${PROJECT_NAME}ConfigVersion.cmake
    VERSION       ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

## Target installation
install(TARGETS   ${PROJECT_NAME}
    EXPORT        ${PROJECT_NAME}Targets
    ARCHIVE       DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY       DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    COMPONENT     library
)

## Target's cmake files: targets export
install(EXPORT  ${PROJECT_NAME}Targets
    NAMESPACE   ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

## Target's cmake files: config and version config for find_package()
install(FILES   ${PROJECT_NAME}Config.cmake
                ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

include(CMakePrintHelpers)
cmake_print_variables(${PROJECT_NAME}_LINKER_SCRIPT)
cmake_print_variables(${PROJECT_NAME}_LINKER_PATH)

if(HW_UNIT_TESTS)
    include(cmake/hw_unit_tests.cmake)
    add_subdirectory(unity/test)
endif()

else()
    if(SW_UNIT_TESTS)
    include(cmake/sw_unit_tests.cmake)
    add_subdirectory(unity/test)
    else()
        message(FATAL_ERROR "${PROJECT_NAME} can only compile with ARM cross compiler, please use appropriate toolchain.")
    endif()
endif()