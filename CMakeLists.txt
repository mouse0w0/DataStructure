cmake_minimum_required(VERSION 3.15)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

include_directories(includes)

add_executable(DataStructure Queue.c Stack.c BiTree.cpp Test4/Test1.cpp)