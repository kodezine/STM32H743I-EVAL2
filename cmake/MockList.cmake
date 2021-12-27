# Generate all mocks here for common files

set(ENV{MOCK_OUT} ${CMAKE_CURRENT_BINARY_DIR}/mocks) # Mocks are to be found here
set(ENV{CMOCK_DIR} ${cmock_SOURCE_DIR})
set(CMOCK_SCRIPT_PATH $ENV{CMOCK_DIR}/scripts)
set(CMOCK_LIB_PATH $ENV{CMOCK_DIR}/lib)

set(SP_HEADERS_MOCKS
    ${os2_SOURCE_DIR}/keil_cortexM7/cert-mpu/ucsp/source/sp_osapi.h      #include "mock_sp_osapi.h"
    ${os2_SOURCE_DIR}/keil_cortexM7/cert-mpu/ucsp/source/sp_core.h       #include "mock_sp_core.h"
)

set(QF_HEADERS_MOCKS
    ${ql_SOURCE_DIR}/ports/ucos-ii_cert_cm7/qf_port.h #include "mock_qf_port.h"
    ${ql_SOURCE_DIR}/include/qf.h                     #include "mock_qf.h"
    ${ql_SOURCE_DIR}/include/qequeue.h                #include "mock_qequeue.h"
)

set(AO_COMMON_MOCKS
    ${CMAKE_SOURCE_DIR}/common/inc/system_functions.h
)

set(COMMON_HEADER_MOCKS
#    ${SP_HEADERS_MOCKS}
#    ${QF_HEADERS_MOCKS}
#    ${AO_COMMON_MOCKS}
)

include(${CMAKE_CURRENT_LIST_DIR}/utils.cmake)
set(MOCKS_TEMPORARY_PATH ${CMAKE_CURRENT_BINARY_DIR}/tmp CACHE PATH "Path to temp mocks")
set(PERL_SH_PATH ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Path to perl script")
set(CREATE_MOCKS_RUBY_PATH ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Path to ruby script")
set(CREATE_RUNNER_RUBY_PATH ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Path to ruby script")
set(x86_64_cc_PATH ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Path to x86_64.cmake script")
set(arm_cc_PATH ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Path to x86_64.cmake script")

generate_mocks(COMMON_HEADER_MOCKS
    ${MOCKS_TEMPORARY_PATH} # Directory for temporary mocks
    ${PERL_SH_PATH} # Directory for perl.sh
    ${CREATE_MOCKS_RUBY_PATH} # Directory for create_mocks.rb
)

# establish CMOCK environment
set(ENV{CMOCK_DIR} ${cmock_SOURCE_DIR})
set(CMOCK_SCRIPT_PATH $ENV{CMOCK_DIR}/scripts)
set(CMOCK_LIB_PATH $ENV{CMOCK_DIR}/lib)

# establish the unity framework
set(ENV{UNITY_DIR} ${unity_SOURCE_DIR})
