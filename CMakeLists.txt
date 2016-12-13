cmake_minimum_required(VERSION 3.6)
project(math)
add_definitions("-Wall" "-std=c99")

set(SOURCE_FILES main.c geometry.c geometry.h graphing.c graphing.h)
add_executable(math ${SOURCE_FILES})