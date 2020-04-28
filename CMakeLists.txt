cmake_minimum_required(VERSION 3.8)

project(tic-tac)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(tic-tac src/main.cpp src/field.cpp include/field.h src/UI.cpp include/UI.h)
target_link_libraries(tic-tac ${CURSES_LIBRARIES})