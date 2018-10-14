#
# codoc (c) blacktriangles 2018 ###############################################
#

#
# Build gtest and gmock #######################################################
#
set(gmock_build_tests           OFF CACHE BOOL "")
set(gtest_build_samples         OFF CACHE BOOL "")
set(gtest_build_tests           OFF CACHE BOOL "")
set(gtest_disable_pthreads      OFF CACHE BOOL "")
set(gtest_force_shared_crt      ON  CACHE BOOL "")
set(gtest_hide_internal_symbols OFF CACHE BOOL "")

add_subdirectory(googletest)

# Create interface library to link against gtest and gmock
add_library(gtest-dev INTERFACE)

target_include_directories(gtest-dev
    SYSTEM INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include
    ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googlemock/include
)

target_link_libraries(gtest-dev
    INTERFACE
    gmock
    gtest
)

#
# Build abseil-cpp ############################################################
#

add_subdirectory(abseil-cpp)

#
# Buld yaml-cpp ###############################################################
#

set(YAML_CPP_BUILD_TESTS   OFF CACHE BOOL "")
set(YAML_CPP_BUILD_TOOLS   OFF CACHE BOOL "")
set(YAML_CPP_BUILD_CONTRIB OFF CACHE BOOL "")
add_subdirectory(yaml-cpp)
