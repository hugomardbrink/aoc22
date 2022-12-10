cmake_minimum_required(VERSION 3.10)

project(aoc22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if( NOT CMAKE_BUILD_TYPE )
   SET( CMAKE_BUILD_TYPE Release )
endif()

add_executable(d1 "d1/main.cxx") 
add_executable(d2 "d2/main.cxx") 
add_executable(d3 "d3/main.cxx") 
add_executable(d4 "d4/main.cxx") 
add_executable(d5 "d5/main.cxx") 
add_executable(d6 "d6/main.cxx") 
add_executable(d7 "d7/main.cxx") 
add_executable(d8 "d8/main.cxx") 
add_executable(d9 "d9/main.cxx") 
