cmake_minimum_required(VERSION 3.25)

project(elite)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER "g++-14")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall")
set(SRC_PATH ${PROJECT_SOURCE_DIR}/src)

include_directories(src)



add_subdirectory(src/array)
