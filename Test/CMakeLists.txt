cmake_minimum_required(VERSION 3.27)
project(Test)

set(CMAKE_CXX_STANDARD 17)

add_executable(Test main.cpp
        dog.h
        dog.cpp)
