cmake_minimum_required(VERSION 3.26)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 17)

add_executable(DesignPatterns main.cpp
        src/CreationalPatterns/Singleton/Singleton.cpp
        src/CreationalPatterns/Singleton/Singleton.h
)
