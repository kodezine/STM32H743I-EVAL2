include(CMakePrintHelpers)
include(FetchContent)

if(DEFINED CACHE${GITHUB_BRANCH_CMSIS})
message(FATAL_ERROR "No valid branch specified to fetch for CMSIS")
endif()

cmake_print_variables(GITHUB_BRANCH_CMSIS)

FetchContent_Declare(
    cmsis                             # Recommendation: Stick close to the original name.
    GIT_REPOSITORY  git@github.com:ARM-software/CMSIS_5.git
    GIT_TAG         ${GITHUB_BRANCH_CMSIS}
)

FetchContent_GetProperties(cmsis)

if(NOT cmsis_POPULATED)
    FetchContent_Populate(cmsis)
    set(ROOT "${cmsis_SOURCE_DIR}")
    cmake_print_variables(ROOT)

    set(DSP "${ROOT}/CMSIS/DSP")
    cmake_print_variables(DSP)
    # Library libhal.a is in the /build/_deps/hal-build directory
    if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "ARM")
        list(APPEND CMAKE_MODULE_PATH ${DSP})
        # BANSHI specific CMSIS customization, helps to limit the tables to be imported to the flash memory
        set(BASICMATH "ON")
        set(COMPLEXMATH "OFF")
        set(CONTROLLER "OFF")
        set(FASTMATH "ON")
        set(FILTERING "OFF")
        set(MATRIX "ON")
        set(STATISTICS "OFF")
        set(SUPPORT "ON")
        set(TRANSFORM "OFF")
        set(SVM "OFF")
        set(BAYES "OFF")
        set(DISTANCE "OFF")
        set(INTERPOLATION "OFF")
        set(QUATERNIONMATH "OFF")
        set(CONFIGTABLE "ON")
        set(ARM_SIN_F32 "ON")
        set(ARM_COS_F32 "ON")
        add_subdirectory(${DSP}/Source bin_dsp)
    endif()
endif()