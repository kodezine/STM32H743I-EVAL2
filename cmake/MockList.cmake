# Generate all mocks here for common files
include(CMakePrintHelpers)
set(ENV{MOCK_OUT} ${CMAKE_CURRENT_BINARY_DIR}/mocks) # Mocks are to be found here
set(ENV{CMOCK_DIR} ${cmock_SOURCE_DIR})
set(CMOCK_SCRIPT_PATH $ENV{CMOCK_DIR}/scripts)
set(CMOCK_LIB_PATH $ENV{CMOCK_DIR}/lib)

set(HAL_DRIVERS_HEADER_PATH "${hal_SOURCE_DIR}/prototype_a/cubemx/Drivers/STM32H7xx_HAL_Driver/Inc")
set(HAL_CORE_HEADER_PATH "${hal_SOURCE_DIR}/prototype_a/cubemx/Core/Inc")
set(BANSHI_HAL_HEADER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/port")
#cmake_print_variables(HAL_HEADER_PATH)

set(SP_HEADERS_MOCKS
    ${os2_SOURCE_DIR}/keil_cortexM7/cert-mpu/ucsp/source/sp_osapi.h      #include "mock_sp_osapi.h"
    ${os2_SOURCE_DIR}/keil_cortexM7/cert-mpu/ucsp/source/sp_core.h       #include "mock_sp_core.h"
)

set(HAL_HEADERS_MOCKS
    ${hal_SOURCE_DIR}/prototype_a/cubemx/Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal.h
    ${BANSHI_HAL_HEADER_PATH}/banshi_to_hal.h

    ${HAL_CORE_HEADER_PATH}/adc.h
    ${HAL_CORE_HEADER_PATH}/crc.h
    ${HAL_CORE_HEADER_PATH}/dac.h
    ${HAL_CORE_HEADER_PATH}/fdcan.h
    ${HAL_CORE_HEADER_PATH}/fmc.h
    ${HAL_CORE_HEADER_PATH}/gpio.h
    ${HAL_CORE_HEADER_PATH}/i2c.h
    ${HAL_CORE_HEADER_PATH}/main.h
    ${HAL_CORE_HEADER_PATH}/spi.h
    ${HAL_CORE_HEADER_PATH}/tim.h
    ${HAL_CORE_HEADER_PATH}/usart.h
)
set(DUMMY
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_adc_ex.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_adc.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_cortex.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_crc_ex.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_crc.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_dac_ex.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_dac.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_def.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_dma_ex.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_dma.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_exti.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_fdcan.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_flash_ex.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_flash.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_gpio_ex.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_gpio.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_hsem.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_i2c_ex.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_i2c.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_mdma.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_pwr_ex.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_pwr.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_rcc_ex.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_rcc.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_sdram.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_spi_ex.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_spi.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_tim_ex.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_tim.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_uart_ex.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_hal_uart.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_ll_adc.h
    ${HAL_DRIVERS_HEADER_PATH}/stm32h7xx_ll_fmc.h
)

set(COMMON_HEADER_MOCKS
    ${SP_HEADERS_MOCKS}
    ${HAL_HEADERS_MOCKS}
)

include(${CMAKE_CURRENT_LIST_DIR}/utils.cmake)
set(COMMON_HEADER_MOCKS_TMP_PATH ${CMAKE_CURRENT_BINARY_DIR}/tmp)

generate_mocks(COMMON_HEADER_MOCKS 
    ${COMMON_HEADER_MOCKS_TMP_PATH} # Directory for temporary mocks
    ${CMAKE_CURRENT_LIST_DIR} # Directory for perl.sh
    ${CMAKE_CURRENT_LIST_DIR} # Directory for create_mocks.rb
)

# establish CMOCK environment
set(ENV{CMOCK_DIR} ${cmock_SOURCE_DIR})
set(CMOCK_SCRIPT_PATH $ENV{CMOCK_DIR}/scripts)
set(CMOCK_LIB_PATH $ENV{CMOCK_DIR}/lib)

# establish the unity framework
set(ENV{UNITY_DIR} ${unity_SOURCE_DIR})
