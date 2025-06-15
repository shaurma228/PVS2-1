cmake_minimum_required(VERSION 3.31)
project(PVS_2 C)

set(CMAKE_C_STANDARD 11)

add_executable(PVS_2 serial.c
        parallel.c)
