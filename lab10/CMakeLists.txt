project(lab10)
cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 23)
add_executable(lab10 main_10.cpp
        Student.cpp
        Student.h
        GraduationDao.cpp
        GraduationDao.h
        StudentService.cpp
        StudentService.h)
