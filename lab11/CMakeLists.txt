project(lab11)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 23)
add_executable(lab11 main_11.cpp
        Settlement.cpp
        Settlement.h
        SettlementStatistics.h
        SettlementStatisticsImpl.cpp
        SettlementStatisticsImpl.h
        Index.cpp
        Index.h)
