cmake_minimum_required(VERSION 3.14)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

include_directories(includes)

add_executable(DataStructure Queue.c Stack.c MyString.c)