cmake_minimum_required(VERSION 1.8.12.2)
project(project5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(project5 ${SOURCE_FILES})