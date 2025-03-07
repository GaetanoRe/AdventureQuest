cmake_minimum_required(VERSION 3.10)
project(AdventureQuest)

find_package(SDL3)
find_package(SDL3_image)
find_package(SDL3_ttf)

add_executable(AdventureQuest
    src/main.cpp
    src/main/window.cpp
    src/main/engine.cpp
)

target_link_libraries(AdventureQuest SDL3::SDL3 
SDL3_image::SDL3_image 
SDL3_ttf::SDL3_ttf
)