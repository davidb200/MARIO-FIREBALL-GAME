#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include <SFML/Graphics.hpp>
#include "../headers/Enemy.h"


class Player{

private:
    int health = 100;
    int score = 0;


    float x;
    float y;
    float velocityX;
    float velocityY;
    float gravity;

public:

    Player();

    bool isDamaged(sf::Sprite &player, sf::Sprite &enemy);
    bool checkOutOfBounds();
    void updateMovement();
    int getHealth();

    int getScore();
    bool addToScore();

    float getXPosition();
    float getYPosition();

    void moveRight();
    void moveLeft();
    void moveUp();

};


#endif //MAIN_CPP_PLAYER_H
