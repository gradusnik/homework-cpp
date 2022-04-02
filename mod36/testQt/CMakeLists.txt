cmake_minimum_required(VERSION 3.21)
project(testQt)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "D:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")

find_package(Qt5Widgets REQUIRED)

add_executable(testQt main.cpp)
target_link_libraries(testQt Qt5::Widgets)
