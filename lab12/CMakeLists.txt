project(lab12)

cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 23)
add_executable(lab12 main_12.cpp
        TextGenerator.h
        SimpleTextGenerator.cpp
        SimpleTextGenerator.h
        EmailService.cpp
        EmailService.h)
