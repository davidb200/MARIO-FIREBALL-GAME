//////////////////////////////////////////////////////////////////////////////
//  Title       : StateManager.h
//  Author      : David Betanzos
//  Description : Outlines all the attributes and methods needed
//                for an object of State manager (manages states for Mario
//                Fireball Game).
//  Attributes  : Objects (MainMenu State, Game State, GameOverState)
//                Enum for States numbering, a current game state based off
//                the numbering
//  Methods     : initMainMenu, initGame, initGameOver, runMainMenu, runGame,
//                runGameOver, runCurrentGameState
//////////////////////////////////////////////////////////////////////////////
#ifndef MAIN_CPP_STATEMANAGER_H
#define MAIN_CPP_STATEMANAGER_H

// Builtin library
#include <SFML/graphics.hpp>

// Custom header files
// Used to help set up and run the states of the gameState)
#include "MainMenuState.h"
#include "GameState.h"
#include "GameOverState.h"


class StateManager{

private:

    // Objects (Aggregation)
    MainMenuState mainMenuState;
    GameState gameState;
    GameOverState gameOverState;

    // States to keep track of (enumerated for readability)
    enum States{
        MAIN_MENU =  0,
        GAME  =  1,
        GAME_OVER = 2,
        CLOSE_GAME = 3
    };

    // Current manager in the gameState
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