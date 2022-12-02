cmake_minimum_required(VERSION 3.12)

project(
    Advent_of_code_23
    VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_COMPILER "/usr/bin/g++-11" )
SET(CMAKE_CXX_FLAGS "-fconstexpr-depth=10000 --save-temps")

# add_subdirectory(include)
add_subdirectory(01)
