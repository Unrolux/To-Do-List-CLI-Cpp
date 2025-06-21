cmake_minimum_required(VERSION 3.10)

# Project Name:
project(TodoList)

# C++ 17 requirement:
set(CMAKE_CXX_STANDARD 17)

# Including include folder's header files:
include_directories(include)

# Defining executable and sources files:
add_executable(todo
    main.cpp
    src/Task.cpp
    src/utils.cpp
)
