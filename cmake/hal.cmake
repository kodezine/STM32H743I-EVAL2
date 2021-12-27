include(CMakePrintHelpers)
include(FetchContent)

if(DEFINED CACHE${GITHUB_BRANCH_HAL})
message(FATAL_ERROR "No valid branch specified to fetch for hal")
endif()

cmake_print_variables(GITHUB_BRANCH_HAL)

FetchContent_Declare(
    hal                             # Recommendation: Stick close to the original name.
    GIT_REPOSITORY  git@github.com:Hillrom-Enterprise/platfORm_hal.git 
    GIT_TAG         ${GITHUB_BRANCH_HAL}
)

FetchContent_GetProperties(hal)

if(NOT hal_POPULATED)
    FetchContent_Populate(hal)
    # Library libhal.a is in the /build/_deps/hal-build directory
    if("${CMAKE_BUILD_TYPE}" STREQUAL "Test")
        if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "ARM")
            add_subdirectory(${hal_SOURCE_DIR}/${BOARD_TYPE} ${hal_BINARY_DIR})
        endif()
    else()
        add_subdirectory(${hal_SOURCE_DIR}/${BOARD_TYPE} ${hal_BINARY_DIR})
    endif()
endif()