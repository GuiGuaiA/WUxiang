cmake_minimum_required(VERSION 3.17)
project(AdjacencyList)

set(CMAKE_CXX_STANDARD 14)

add_executable(AdjacencyList main.cpp lib/VNode.cpp include/VNode.h lib/Arc.cpp include/Arc.h)