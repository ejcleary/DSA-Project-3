cmake_minimum_required(VERSION 3.26)
project(DSA_Project_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DSA_Project_3
        driverdatacsv.cpp
        F1Data.h
        main.cpp)
