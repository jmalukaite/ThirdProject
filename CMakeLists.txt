cmake_minimum_required(VERSION 3.20)
project(2_0Versija)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

add_executable(2_0Versija main.cpp funkcijos.cpp funkcijos.h studentas.h studentas.cpp tests/basic_check.cpp tests/studentas_check.cpp studentai_check.cpp)
target_link_libraries(2_0Versija gtest gtest_main)