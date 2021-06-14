cmake_minimum_required(VERSION 3.19)

add_executable(task1mod26 main.cpp  ${INCL}/tracks.h ${INCL}/player.h)

target_include_directories(task1mod26 PUBLIC ${INCL})