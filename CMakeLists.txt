# cmake_minimum_required(VERSION <specify CMake version here>)
project(quickstart C)

set(CMAKE_C_STANDARD 99)

add_executable(quickstart list/node.c)