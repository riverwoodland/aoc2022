cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(
  myproject
  DESCRIPTION "aoc2022"
  VERSION 1.0.0
  LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(src)