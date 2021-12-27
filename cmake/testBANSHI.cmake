# creates a library target for test build (saves build time)

add_library(testBANSHI
    STATIC
)

target_sources(testBANSHI
    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/../banshi/src/BANSHI_arm_math.c
    ${CMAKE_CURRENT_LIST_DIR}/../banshi/src/BANSHI_gpio.c
    ${CMAKE_CURRENT_LIST_DIR}/../banshi/src/BANSHI_can.c
    ${CMAKE_CURRENT_LIST_DIR}/../banshi/src/BANSHI_adc.c
    ${CMAKE_CURRENT_LIST_DIR}/../banshi/src/BANSHI_spi.c
    ${CMAKE_CURRENT_LIST_DIR}/../banshi/src/BANSHI_uart.c
    ${CMAKE_CURRENT_LIST_DIR}/../banshi/src/BANSHI_dac.c
    ${CMAKE_CURRENT_LIST_DIR}/../banshi/src/BANSHI_HWTimer.c
    ${CMAKE_CURRENT_LIST_DIR}/../banshi/src/BANSHI_HWPWM.c
    ${CMAKE_CURRENT_LIST_DIR}/../banshi/src/BANSHI_adc.c
    ${CMAKE_CURRENT_LIST_DIR}/../banshi/src/BANSHI_SDRAM.c
    ${CMAKE_CURRENT_LIST_DIR}/../banshi/src/BANSHI_NVIC.c
    ${CMAKE_CURRENT_LIST_DIR}/../banshi/src/BANSHI_i2c.c
    ${CMAKE_CURRENT_LIST_DIR}/../banshi/src/BANSHI_flash.c
    ${CMAKE_CURRENT_LIST_DIR}/../port/banshi_to_hal.c
    ${CMAKE_CURRENT_LIST_DIR}/../port/banshi_ll_init.c
    ${CMAKE_CURRENT_LIST_DIR}/../port/debug_swo.c
    ${CMAKE_CURRENT_LIST_DIR}/../port/debug_usart.c
    ${CMAKE_CURRENT_LIST_DIR}/../tests/helper/sp_helper.c
)

target_include_directories(testBANSHI
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/../tests/helper
    ${CMAKE_CURRENT_LIST_DIR}/../banshi/inc
    ${CMAKE_CURRENT_LIST_DIR}/../port
)

target_link_libraries(testBANSHI
    PRIVATE
    CMSISDSP
    hal
)

# Linker path and flags
if(LINKERPATH)
else()
    set (LINKERPATH "${hal_LINKER_PATH}") 
endif()

if(LINKERSCRIPT)
else()
    set(LINKERSCRIPT "${hal_LINKER_SCRIPT}")
endif()

message (STATUS "[${PROJECT_NAME}] Linker script used ${LINKERPATH}/${LINKERSCRIPT}")