cmake_minimum_required(VERSION 3.19)
set(INCLUDED_DIR ${CMAKE_SOURCE_DIR}/included)
add_executable(task2mod25 cpu.cpp disk.cpp gpu.cpp kbd.cpp main.cpp ram.cpp
        ${INCLUDED_DIR}/cpu.h ${INCLUDED_DIR}/disk.h ${INCLUDED_DIR}/gpu.h ${INCLUDED_DIR}/kbd.h
        ${INCLUDED_DIR}/ram.h)
target_include_directories(task2mod25 PUBLIC ${INCLUDED_DIR})