cmake_minimum_required(VERSION 3.14)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStructure Test1/4.c)
add_library(pta/6-1.c pta/6-2.c pta/6-3.c pta/6-4.c pta/6-5.c pta/6-6.c pta/6-7.c Test1/1.c Test1/2.c Test1/3.c)