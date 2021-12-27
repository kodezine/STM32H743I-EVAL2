include(FetchContent)

# The options to build the Fixtures and Memory for Unity are enabled here.
set(UNITY_EXTENSION_FIXTURE ON CACHE BOOL "Build unity with fixture")
set(UNITY_EXTENSION_MEMORY  ON CACHE BOOL "Build unity with memory")


FetchContent_Declare(
    unity                             # Recommendation: Stick close to the original name.
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG        v2.5.2
)

FetchContent_GetProperties(unity)

if(NOT unity_POPULATED)
    FetchContent_Populate(unity)
    # Library libcomock.a is in the /build/_deps/cmock-build directory
    add_subdirectory(${unity_SOURCE_DIR} ${unity_BINARY_DIR})
endif()
