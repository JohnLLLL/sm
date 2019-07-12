cmake_minimum_required(VERSION 3.5)
project(sm)

set(CMAKE_C_STANDARD 99)

#aux_source_directory($(PROJECT_SOURCE_DIR) DIR_SRCS)

add_executable(sm main.c sm.c sm.h input.cpp input.h)