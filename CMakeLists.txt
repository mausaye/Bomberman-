cmake_minimum_required(VERSION 3.7)

project(Bomberman2_0)
set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(Bomberman2_0
        src/main.cpp src/Network/server/network.h src/Network/server/client.cpp src/Network/server/server.cpp src/Network/networkinterface.h)
target_link_libraries(Bomberman2_0 ${SDL2_LIBRARIES}  ${Boost_LIBRARIES} )
