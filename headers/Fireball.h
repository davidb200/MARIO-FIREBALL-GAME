#ifndef MAIN_CPP_FIREBALL_H
#define MAIN_CPP_FIREBALL_H

// Builtin library
#include <SFML/graphics.hpp>

// Custom header file
#include "Definitions.h" // Used for Positioning and gravity


class Fireball {

private:

    // Position
    float x;
    float y;

    // Velocity and acceleration
    float velocityY;
    float gravity;

public:

    //---------------------------------------------------------------
    // Default Constructor
    //---------------------------------------------------------------

    Fireball();

    //---------------------------------------------------------------
    // methods
    //---------------------------------------------------------------

    // Getters
    float getXPosition();
    float getYPosition();

    // Position checking
    bool isOutOfWindow();

    // Updates
    void moveCorrectly();
    void spawnInRandomPosition();

    // Collision checking
    bool collidesWithPlayer(sf::Sprite &player, sf::Sprite &enemy);

};


#endif //MAIN_CPP_FIREBALL_H