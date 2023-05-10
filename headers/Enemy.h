#ifndef MAIN_CPP_ENEMY_H
#define MAIN_CPP_ENEMY_H
#include <iostream>
#include <SFML/graphics.hpp>

class Enemy {
private:
    float x;
    float y;
    float velocityX;
    float velocityY;
    float gravity;

public:
    Enemy();

    void moveEnemy();

    float getXPosition();
    float getYPosition();

    bool isOutOfMap();
    bool collidesWithPlayer(sf::Sprite &player, sf::Sprite &enemy);

};


#endif //MAIN_CPP_ENEMY_H
