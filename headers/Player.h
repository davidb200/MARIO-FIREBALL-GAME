#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include <SFML/Graphics.hpp>
#include "../headers/Enemy.h"
#include <iostream>

class Player{

private:
    int score = 0;


    float x;
    float y;
    float velocityX;
    float velocityY;
    float gravity;

public:

    Player();

    bool checkOutOfBounds();
    void updateMovement();

    int getScore();
    bool addToScore();

    float getXPosition();
    float getYPosition();

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
};


#endif //MAIN_CPP_PLAYER_H
