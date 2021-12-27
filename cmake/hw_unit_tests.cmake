
enable_testing()

include(CTest)

include(cmake/unity.cmake)
include(cmake/cmock.cmake)
include(cmake/MockList.cmake)

add_subdirectory(unity)
