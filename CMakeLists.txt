project(BehTavan)

cmake_minimum_required(VERSION 3.10)

# C++ Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(BehTavan
    ./src/main.cpp
)

target_include_directories(BehTavan PUBLIC ./include/)
