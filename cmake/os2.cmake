include(CMakePrintHelpers)
include(FetchContent)

if(DEFINED CACHE${GITHUB_BRANCH_OS2})
message(FATAL_ERROR "No valid branch specified to fetch for os2")
endif()

cmake_print_variables(GITHUB_BRANCH_OS2)
FetchContent_Declare(
    os2                             # Recommendation: Stick close to the original name.
    GIT_REPOSITORY  git@github.com:Hillrom-Enterprise/platfORm_os2.git 
    GIT_TAG         ${GITHUB_BRANCH_OS2}
)

FetchContent_GetProperties(os2)

if(NOT os2_POPULATED)
    FetchContent_Populate(os2)
    # Library libhos2.a is in the /build/_deps/os2-build directory
    if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "ARM")
        add_subdirectory(${os2_SOURCE_DIR} ${os2_BINARY_DIR})
    endif()
endif()