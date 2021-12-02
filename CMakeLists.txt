cmake_minimum_required(VERSION 3.20)
project(1_1VERSIJA)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O3")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O3")

add_executable(1_1VERSIJA main.cpp studentasKlase.h studentasKlase.cpp funkcijosKlase.cpp funkcijosKlase.h funkcijosStruct.cpp studentasStruct.h funkcijosStruct.h)
