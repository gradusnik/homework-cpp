cmake_minimum_required(VERSION 3.17)
project(task2)

set(CMAKE_CXX_STANDARD 20)

add_executable(task2 main.cpp)

set(CMAKE_EXE_LINKER_FLAGS "-static")