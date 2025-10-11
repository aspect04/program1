cmake_minimum_required(VERSION 3.31)
project(program1)

set(CMAKE_CXX_STANDARD 20)

add_executable(program1 main.cpp
        vending_bank.h)
