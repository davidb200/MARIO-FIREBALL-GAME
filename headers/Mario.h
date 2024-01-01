////////////////////////////////////////////////////////////////////////////////////////////////
//  Title      : Mario.h
//  Author     : David Betanzos
//  Description: Outlines all the attributes and methods needed for
//               an object of Mario.
//  Attributes : x position, y position, x velocity, health
//  Methods    : getScore, getHealth, getXPos, getYPos, setHealth, setScore,
//               setXPos, setYPos, resetHealth, resetScore, respawn, addToScore, lowerHealth,
//               isOutOfBoundsLeft, isOutOfBoundsRight, keepPlayerInBounds, moveLeft, moveRight,
//               stayStill, updateMovement, processInput
////////////////////////////////////////////////////////////////////////////////////////////////

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
    float xPos;
    float yPos;
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
    float getXPos();
    float getYPos();

    // Setters
    void setHealth(int _health);
    void setScore(int _score);
    void setXPos(float x);
    void setYPos(float y);

    // Reset
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
