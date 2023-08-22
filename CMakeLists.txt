cmake_minimum_required(VERSION 3.24)
project(2023_II)

set(CMAKE_CXX_STANDARD 23)

add_executable(2023_II
        AED/S2/SimpleLinkedList.h
        AED/S2/main.cpp AED/S2/DoubleLinkedList.h AED/S2/CircularDoubleLinkedList.h)

add_executable(cpc CPC/Codeforces/ContestTrainee/B.cpp)
