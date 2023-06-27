#ifndef MAIN_CPP_STATEMANAGER_H
#define MAIN_CPP_STATEMANAGER_H

// Builtin library
#include <SFML/graphics.hpp>

// Custom header files
// Used to help set up and run the states of the game)
#include "MainMenu.h"
#include "Game.h"
#include "GameOver.h"


class StateManager{

private:

    // Objects
    MainMenu mainMenu;
    Game game;
    GameOver gameOver;

    // States to keep track of (enumerated for readability)
    enum States{
        MAIN_MENU =  0,
        GAME  =  1,
        GAME_OVER = 2,
        CLOSE_GAME = 3
    };

    // Current state in the game
    States currentGameState;

public:

    //---------------------------------------------------------------
    // Default Constructor
    //---------------------------------------------------------------
    StateManager();

    //---------------------------------------------------------------
    // Methods
    //---------------------------------------------------------------

    // Initializing
    void initMainMenu();
    void initGame();
    void initGameOver();

    // Running
    void runMainMenu(sf::RenderWindow &window);
    void runGame(sf::RenderWindow &window);
    void runGameOver(sf::RenderWindow &window);

    void runCurrentState(sf::RenderWindow &window);

};


#endif //MAIN_CPP_STATEMANAGER_H