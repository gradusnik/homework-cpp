cmake_minimum_required(VERSION 3.19)
project("task1")

set(CMAKE_CXX_STANDARD 14)

add_executable(task1 main.cpp incl/tools.h incl/points.h)
target_include_directories(task1 PUBLIC incl)