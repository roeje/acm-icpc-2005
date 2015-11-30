cmake_minimum_required(VERSION 3.3)
project(icpc2005)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES icpc2005.cpp)
add_executable(icpc2005 ${SOURCE_FILES} icpc2005.cpp)