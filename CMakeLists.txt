cmake_minimum_required(VERSION 3.10)
project(AdventureQuest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_executable(AdventureQuest src/main.cpp)

target_link_libraries(AdventureQuest glfw3)



