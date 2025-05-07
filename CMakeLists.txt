cmake_minimum_required(VERSION 3.30)
project(spacegame C)

set(CMAKE_C_STANDARD 11)

add_executable(spacegame main.c
        game.h)
