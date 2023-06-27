cmake_minimum_required(VERSION 3.23)
project(My_Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(My_Game src/main.cpp src/StateManager.cpp headers/StateManager.h src/Mario.cpp headers/Mario.h src/Window.cpp headers/Window.h src/Fireball.cpp headers/Fireball.h headers/Definitions.h src/MainMenu.cpp headers/MainMenu.h src/Game.cpp headers/Game.h src/GameOver.cpp headers/GameOver.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(My_Game sfml-system sfml-window sfml-graphics sfml-audio)