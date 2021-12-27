include(FetchContent)

FetchContent_Declare(
    cmock                             # Recommendation: Stick close to the original name.
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/CMock.git
    GIT_TAG        v2.5.3
)

FetchContent_GetProperties(cmock)

if(NOT cmock_POPULATED)
    FetchContent_Populate(cmock)
    configure_file(cmake/cmockhelper.cmake ${cmock_SOURCE_DIR}/CMakeLists.txt)
    # Library libcomock.a is in the /build/_deps/cmock-build directory
    add_subdirectory(${cmock_SOURCE_DIR} ${cmock_BINARY_DIR})
endif()
