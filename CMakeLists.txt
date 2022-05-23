cmake_minimum_required(VERSION 3.21)
project(Grafy)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Grafy
        dijkstra.cpp
        graf.cpp
        graf.h
        main.cpp)
