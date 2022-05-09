cmake_minimum_required(VERSION 3.7)

project(Bomberman2_0)
set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Bomberman2_0
        src/main.cpp)
target_link_libraries(Bomberman2_0 ${SDL2_LIBRARIES})
