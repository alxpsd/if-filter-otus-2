cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VERSION})

option(WITH_BOOST_TEST "Enable Boost.Test" ON)
option(WITH_GTEST "Enable GoogleTest" ON)

configure_file(version.h.in version.h)

add_executable(ip_filter src/main.cpp src/ip_filter.cpp)
add_library(ip_filter_lib src/ip_filter.cpp src/ip_filter.h)

set_target_properties(ip_filter ip_filter_lib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(ip_filter_lib PRIVATE "${CMAKE_BINARY_DIR}")
target_link_libraries(ip_filter PRIVATE ip_filter_lib)

if(WITH_BOOST_TEST)
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
    add_executable(test_ip_filter_boost tests/test_ip_filter.cpp)
    target_link_libraries(test_ip_filter_boost ${Boost_LIBRARIES} ip_filter_lib)
endif()

if(WITH_GTEST)
    find_package(GTest REQUIRED)
    add_executable(test_ip_filter_gtest tests/test_ip_filter.cpp)
    target_link_libraries(test_ip_filter_gtest GTest::GTest GTest::Main ip_filter_lib)
endif()

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT "your-email@example.com")
include(CPack)

enable_testing()
if(WITH_BOOST_TEST)
    add_test(NAME test_ip_filter_boost COMMAND test_ip_filter_boost)
endif()
if(WITH_GTEST)
    add_test(NAME test_ip_filter_gtest COMMAND test_ip_filter_gtest)
endif()
