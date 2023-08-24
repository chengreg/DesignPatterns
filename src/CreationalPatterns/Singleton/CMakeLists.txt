# 设置最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名
project(Singleton)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True) #如果当前的编译器不支持该标准，CMake配置阶段将会失败并显示一个错误

# 添加执行文件
add_executable(Singleton
        main.cpp
        SingletonEager.cpp
        SingletonEager.h
        SingletonLazy.cpp
        SingletonLazy.h
        ConfigManager.cpp
        ConfigManager.h
        inicpp.hpp
)