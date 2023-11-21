cmake_minimum_required(VERSION 3.24)
project(2023_II)

set(CMAKE_CXX_STANDARD 23)

add_executable(2023_II
        AED/S13/graph.h
        AED/S13/main.cpp
        AED/S13/heap.h
        AED/S13/heap.h)

add_executable(mentoria
        Mentorias/S13/main.cpp
        Mentorias/S13/pc3.h
        Mentorias/S13/pc3.cpp
)

add_executable(cpc CPC/Codeforces/895D3/A.cpp)
