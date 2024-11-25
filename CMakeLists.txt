cmake_minimum_required(VERSION 3.10)

project(snake-2d)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/main.cpp
    src/Game.cpp
    src/ErrorHandler.cpp
    src/Grid.cpp
    src/Vector.cpp
    src/Texture.cpp
    src/Player.cpp
    src/InputManager.cpp
    src/InputDetector.cpp
    src/GamePlay.cpp
    src/StatesManager.cpp
    src/GameObject.cpp
)

add_executable(snake-2d ${SOURCES})

# target_link_libraries(snake-2d PRIVATE
#     SDL2::SDL2
#     SDL2::SDL2main
#     SDL2_image::SDL2_image
# )
target_link_libraries(snake-2d PRIVATE 
    SDL2::SDL2main
    SDL2::SDL2
    SDL2_image::SDL2_image
)

target_include_directories(snake-2d PRIVATE ${CMAKE_SOURCE_DIR}/include)