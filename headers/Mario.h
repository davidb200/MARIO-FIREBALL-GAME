#ifndef MAIN_CPP_MARIO_H
#define MAIN_CPP_MARIO_H

// Builtin library
#include <SFML/Graphics.hpp>

// Custom header file
#include "Definitions.h" // Constants that check out of bounds for the window


class Mario{

private:

    // Score
    int score;

    // Positioning
    float x;
    float y;
    float velocityX;

    // Health
    int health;

public:

    //---------------------------------------------------------------
    // Default Constructor
    //---------------------------------------------------------------

    Mario();

    //---------------------------------------------------------------
    // Methods
    //---------------------------------------------------------------

    // Getters
    int getScore();
    int getHealth();
    float getXPosition();
    float getYPosition();

    // Setters
    void resetHealth();
    void resetScore();
    void respawn();

    // Updates
    void addToScore();
    void lowerHealth();

    // Conditions for checking if the mario is out of bounds
    bool isOutOfBoundsLeft();
    bool isOutOfBoundsRight();
    void keepPlayerInBounds();

    // Movement
    void moveLeft();
    void moveRight();
    void stayStill();
    void updateMovement();

    // Input
    void processInput(sf::Sprite &mario);

};


#endif //MAIN_CPP_MARIO_H
