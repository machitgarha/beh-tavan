project(BehTavan)

cmake_minimum_required(VERSION 3.10)

# C++ Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Source files
add_executable(BehTavan
    ./src/main.cpp
    ./src/output.cpp
    ./src/console-table/standard-console-table.cpp

    ./src/functions/power.cpp

    ./src/functions/sorting/bubble-sort.cpp
    ./src/functions/sorting/counting-sort.cpp
    ./src/functions/sorting/heap-sort.cpp
    ./src/functions/sorting/insertion-sort.cpp
    ./src/functions/sorting/merge-sort.cpp
    ./src/functions/sorting/quick-sort.cpp
    ./src/functions/sorting/radix-sort.cpp
    ./src/functions/sorting/selection-sort.cpp

    # Workflows
    ./src/workflows/power-funcs-time-comparison-workflow.cpp
    #./src/workflows/sorting-time-comparison-workflow.cpp
)

target_include_directories(BehTavan PUBLIC
    ./include/
    ./lib/console-table/
    ./lib/nameof/include/
    ./lib/chop/include
)
