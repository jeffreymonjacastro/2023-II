cmake_minimum_required(VERSION 3.23)
project(circular_array_grupo22)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(circular_array_grupo22
        circulararray.h
        main.cpp
        queue.h
        stack.h
        tester.h)
