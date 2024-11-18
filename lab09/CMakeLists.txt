project(lab9)
cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 23)
add_executable(lab9 main_09.cpp
        Person.cpp
        Person.h
        Employee.cpp
        Employee.h
        Manager.cpp
        Manager.h)
