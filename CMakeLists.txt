cmake_minimum_required(VERSION 3.1)
project(kasner CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(GMP REQUIRED)
include_directories(${GMP_INCLUDE_DIR})

add_library(${CMAKE_PROJECT_NAME} integer.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${GMP_LIBRARY})

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(googletest/googletest)

    add_executable(${CMAKE_PROJECT_NAME}_test integer_test.cpp)
    target_link_libraries(${CMAKE_PROJECT_NAME}_test ${CMAKE_PROJECT_NAME} gtest)

    add_test(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_test)
endif()
