cmake_minimum_required(VERSION 3.10.0)
project(test VERSION 0.1.0)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wno-unknown-pragmas -fdiagnostics-color=always -std=c++17")

enable_testing()

add_executable(myapp main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
