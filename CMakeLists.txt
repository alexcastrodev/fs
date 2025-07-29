cmake_minimum_required(VERSION 3.31)
project(fs C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(fs
        src/vsfs.c
        src/vsfs.h)
