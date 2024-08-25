cmake_minimum_required(VERSION 3.25)

project(elite)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(APPLE)
  set(CMAKE_CXX_COMPILER "g++-14")
endif()
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall")
set(SRC_PATH ${PROJECT_SOURCE_DIR}/src)

include_directories(src)

add_subdirectory(src/array)
add_subdirectory(src/hashmap)
add_subdirectory(src/matrix)
add_subdirectory(src/sliding_window)
add_subdirectory(src/two_pointers)
