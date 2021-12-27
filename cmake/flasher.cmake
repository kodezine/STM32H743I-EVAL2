
# Configure flasher script for the project
set(BINARY ${PROJECT_NAME}.bin)
set(FLASH_START 0x08000000)
configure_file(${CMAKE_CURRENT_LIST_DIR}/jflash.in ${CMAKE_CURRENT_BINARY_DIR}/jflash.jlink)

if(DEBUGGER_IP)
#message(STATUS "Segger_JLink:JTAG TCP/IP Connection @ ${DEBUGGER_IP}")
set(IF "ip" "${DEBUGGER_IP}")
else()
#message(STATUS "Segger_JLink:JTAG USB Connection")
set(IF)
endif()

if(DEVICE)
set(DEV "${DEVICE}")
else()
set(DEV "STM32H743XI")
endif()

# JLink flash command
add_custom_target(flash_${PROJECT_NAME} 
	COMMAND JLinkExe ${IF} -device ${DEV} -CommanderScript ${CMAKE_CURRENT_BINARY_DIR}/jflash.jlink 
	DEPENDS ${PROJECT_NAME}
)

# JLink erase command
add_custom_target(erase_${PROJECT_NAME} 
	COMMAND JLinkExe ${IF} -device ${DEV} -CommanderScript ${CMAKE_CURRENT_LIST_DIR}/jerase.jlink 
	DEPENDS ${PROJECT_NAME}
)
