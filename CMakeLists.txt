project(BehTavan)

cmake_minimum_required(VERSION 3.10)

# C++ Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Source files
add_executable(BehTavan
    ./src/main.cpp
    ./src/power.cpp
    ./src/input.cpp
    ./src/output.cpp
    ./src/console-table/standard-console-table.cpp
)

target_include_directories(BehTavan PUBLIC
    ./include/
    ./lib/console-table/
    ./lib/nameof/include/
)
