cmake_minimum_required(VERSION 3.26)
project(XsAndOs)

set(CMAKE_CXX_STANDARD 17)

add_executable(XsAndOs Game.cpp
        Square.cpp
        Square.h
        Grid.cpp
        Grid.h)
