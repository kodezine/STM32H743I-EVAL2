
enable_testing()

include(CTest)

# include unity config files here
add_definitions(
    -DUNITY_INCLUDE_CONFIG_H
)

#include_directories(unity/config)

include(cmake/unity.cmake)
include(cmake/cmock.cmake)
include(cmake/MockList.cmake)

add_library(rs232 STATIC)
add_library(rs232::framework ALIAS rs232)
# Includes ---------------------------------------------------------------------
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

target_sources(rs232
    PRIVATE
        unity/config/RS232_helper.c
)

target_include_directories(rs232
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/unity/config>
)

target_link_libraries(rs232
    hal
)

set(rs232_PUBLIC_HEADERS
        unity/config/unity_config.h
        unity/config/RS232_helper.h
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES 
        C_STANDARD          11
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS        OFF
        PUBLIC_HEADER       "${${PROJECT_NAME}_PUBLIC_HEADERS}"
        EXPORT_NAME         framework
)

set_target_properties(rs232
    PROPERTIES
        C_STANDARD          11
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS        OFF
        PUBLIC_HEADER       "${${PROJECT_NAME}_PUBLIC_HEADERS}"
        EXPORT_NAME         framework
)

target_compile_options(rs232
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

write_basic_package_version_file(rs232ConfigVersion.cmake
    VERSION       ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
## Target installation
install(TARGETS   rs232
    EXPORT        rs232Targets
    ARCHIVE       DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY       DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    COMPONENT     library
)

## Target's cmake files: targets export
install(EXPORT  rs232Targets
    NAMESPACE   rs232::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/rs232
)

## Target's cmake files: config and version config for find_package()
install(FILES   rs232Config.cmake
                ${CMAKE_CURRENT_BINARY_DIR}/rs232ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/rs232
)


add_subdirectory(unity)
