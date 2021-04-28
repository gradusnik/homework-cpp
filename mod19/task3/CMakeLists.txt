cmake_minimum_required(VERSION 3.17)
project(task3)

set(CMAKE_CXX_STANDARD 20)

add_executable(task3 main.cpp)

set(CMAKE_EXE_LINKER_FLAGS "-static")