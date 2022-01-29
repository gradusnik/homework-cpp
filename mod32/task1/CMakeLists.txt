cmake_minimum_required(VERSION 3.20)
project(test_json)

set(JSON_BuildTests OFF CACHE INTERNAL "")

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(nlohmann_json)

add_executable(test_json main.cpp)

target_link_libraries(test_json PRIVATE nlohmann_json::nlohmann_json)