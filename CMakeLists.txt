cmake_minimum_required(VERSION 3.9)

project(BehTavan)

# C++ Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(BehTavan
    ./src/output.cpp
    ./src/console-table/standard-console-table.cpp
)

target_include_directories(BehTavan PUBLIC
    ./include/
    ./lib/console-table/
    ./lib/nameof/include/
    ./lib/chop/include
)
