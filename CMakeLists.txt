cmake_minimum_required(VERSION 3.23)
project(SFML_Practice)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFML_Practice src/main.cpp src/Window.cpp headers/Window.h src/Player.cpp headers/Player.h src/GameLogic.cpp headers/GameLogic.h src/GameStates.cpp headers/GameStates.h src/Enemy.cpp headers/Enemy.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(SFML_Practice sfml-system sfml-window sfml-graphics sfml-audio)