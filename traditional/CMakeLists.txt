cmake_minimum_required(VERSION 3.24)
project(algorithms)

set(CMAKE_CXX_STANDARD 11)

add_executable(algorithms main.cpp
        "sort_algo/BubbleSort.cpp"
        apis/algo_def.h
        apis/algo_api.cpp
        sort_algo/MergeSort.cpp
        sort_algo/InsertSort.cpp)
