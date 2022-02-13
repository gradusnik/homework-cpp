cmake_minimum_required(VERSION 3.20)
project(json_02)

set(JSON_BuildTests OFF CACHE INTERNAL "")

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(nlohmann_json)

add_executable(json_02 main.cpp menuOptions.h)

target_link_libraries(json_02 PRIVATE nlohmann_json::nlohmann_json)