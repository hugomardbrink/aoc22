cmake_minimum_required(VERSION 3.10)

project(aoc22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if( NOT CMAKE_BUILD_TYPE )
   SET( CMAKE_BUILD_TYPE Release )
endif()

add_executable(d1 "d1/main.cxx") 
add_executable(d2 "d2/main.cxx") 
