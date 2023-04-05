
if(NOT (CMAKE_SYSTEM_PROCESSOR STREQUAL "arm"))
    message(FATAL_ERROR "${PROJECT_NAME} can only compile with a suitable ARM cross compiler; no target build.")
endif()

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(CMakePrintHelpers)

add_library(${PROJECT_NAME} STATIC)
add_library(${PROJECT_NAME}::framework ALIAS ${PROJECT_NAME})

include(cmake/lib_cmsis.cmake)
set(cmsis_DEVICE_INCLUDE_DIR "${cmsis_SOURCE_DIR}/Device/ARM/ARMCM0/Include" CACHE STRING "Path to ARM0 from standard CMSIS")
set(cmsis_CORE_INCLUDE_DIR "${cmsis_SOURCE_DIR}/CMSIS/Core/Include" CACHE STRING "Path to CMSIS core includes")

set(hal_core_INCLUDES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Core/Inc")
set(hal_core_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Core/Src")
set(hal_core_SOURCES
    ${hal_core_SOURCE_DIR}/main.c
    ${hal_core_SOURCE_DIR}/stm32f0xx_hal_msp.c
    ${hal_core_SOURCE_DIR}/system_stm32f0xx.c
    ${hal_core_SOURCE_DIR}/stm32f0xx_hal_timebase_tim.c
)

set(hal_drivers_CMSIS_device_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Device/ST/STM32F0xx/Include")
set(hal_drivers_CMSIS_INCLUDE_DIR "${cmake_SOURCE_DIR}/CMSIS/Core/Include")
set(hal_drivers_legacy_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy")
set(hal_drivers_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F0xx_HAL_Driver/Inc")
set(hal_drivers_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F0xx_HAL_Driver/Src")
set(hal_drivers_SOURCES
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_cortex.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_dma.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_exti.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_flash.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_flash_ex.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_gpio.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_i2c_ex.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_i2c.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_pwr_ex.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_pwr.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_rcc_ex.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_rcc.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_tim_ex.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_tim.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_uart_ex.c
    ${hal_drivers_SOURCE_DIR}/stm32f0xx_hal_uart.c
)

target_sources(${PROJECT_NAME}
    PRIVATE
    ${hal_core_SOURCES}
    ${hal_drivers_SOURCES}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${cmsis_CORE_INCLUDE_DIR}>
        $<BUILD_INTERFACE:${cmsis_DEVICE_INCLUDE_DIR}>
        $<BUILD_INTERFACE:${hal_drivers_CMSIS_device_INCLUDE_DIR}>
        $<BUILD_INTERFACE:${hal_drivers_legacy_INCLUDE_DIR}>
        $<BUILD_INTERFACE:${hal_drivers_INCLUDE_DIR}>
        $<BUILD_INTERFACE:${hal_core_INCLUDES_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}>
)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        USE_HAL_DRIVER
        STM32H743xx
        __UVISION_VERSION="537"
        _RTE_
)

set(${PROJECT_NAME}_PUBLIC_HEADERS
    ${hal_drivers_CMSIS_device_INCLUDE_DIR}/stm32f0xx.h
    ${hal_drivers_CMSIS_device_INCLUDE_DIR}/stm32f030x8.h
    ${hal_drivers_CMSIS_device_INCLUDE_DIR}/system_stm32f0xx.h
    ${hal_core_INCLUDES_DIR}/main.h
    ${hal_core_INCLUDES_DIR}/stm32h7xx_hal_conf.h
    ${hal_core_INCLUDES_DIR}/stm32h7xx_it.h
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        C_STANDARD          11
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS        OFF
        PUBLIC_HEADER       "${${PROJECT_NAME}_PUBLIC_HEADERS}"
        EXPORT_NAME         framework
)

write_basic_package_version_file(${PROJECT_NAME}ConfigVersion.cmake
    VERSION       ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

setTargetCompileOptions(PROJECT_NAME)

#target_link_libraries(${PROJECT_NAME}
#    cmsis
#)

# CPACK begins here
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
set(CPACK_BINARY_7Z ON)
set(CPACK_BINARY_NSIS OFF)
include(CPack)
