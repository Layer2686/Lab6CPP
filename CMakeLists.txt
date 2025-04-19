cmake_minimum_required(VERSION 3.30)
project(lab6)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab6 main.cpp
        Device.cpp
        Device.h
        Phone.cpp
        Phone.h)
