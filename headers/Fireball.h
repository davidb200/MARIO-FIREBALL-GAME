////////////////////////////////////////////////////////////////////////
// Title      : Fireball.h
// Author     : David Betanzos
// Description: Outlines the necessary attributes and methods needed for
//              an object of Fireball.
// Attributes : x position, y position, y velocity
// Methods    : getXPos, getYPos, setXPosition, setYPosition,
//              isOutofWindow, moveCorrectly, spawnInRandomPosition,
//              collidesWithPlayer
/////////////////////////////////////////////////////////////////////////

#ifndef MAIN_CPP_FIREBALL_H
#define MAIN_CPP_FIREBALL_H

// Builtin library
#include <SFML/graphics.hpp>

// Custom header file
#include "Definitions.h" // Used for Positioning and gravity


class Fireball {

private:

    // Position
    float xPos;
    float yPos;

    // acceleration
    float yVelocity;

public:

    //---------------------------------------------------------------
    // Default Constructor
    //---------------------------------------------------------------

    Fireball();

    //---------------------------------------------------------------
    // methods
    //---------------------------------------------------------------

    // Getters
    float getXPos();
    float getYPos();

    // Setters
    void setXPos(float x);
    void setYPos(float y);

    // Position checking
    bool isOutOfWindow();

    // Updates
    void moveCorrectly();
    void spawnInRandomPosition();

    // Collision checking
    bool collidesWithPlayer(sf::Sprite &player, sf::Sprite &enemy);

};


#endif //MAIN_CPP_FIREBALL_H