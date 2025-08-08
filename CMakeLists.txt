cmake_minimum_required(VERSION 3.29)
project(management)

set(CMAKE_CXX_STANDARD 20)

add_executable(management main.cpp
        System.cpp
        System.h
        User.cpp
        User.h
        Stock.cpp
        Stock.h
        Customers.cpp
        Customers.h)
