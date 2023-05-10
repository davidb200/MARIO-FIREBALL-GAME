#include "../headers/Enemy.h"

Enemy::Enemy(){
    x = 225.f;
    y = 50.f;
    velocityX = 0.f;
    velocityY = 0.f;
    gravity = 0.05f;
}

float Enemy:: getXPosition(){return x;}

float Enemy :: getYPosition(){return y;}

bool Enemy:: isOutOfMap(){
    if(y > 600.f)
        return true;
    return false;
} // End of isOurOfMap

void Enemy::moveEnemy() {

    if(isOutOfMap()) {
        x = float(rand() % 600);
        y = 50.f;
        return;
    }
    velocityX = 0.f;
    velocityY = gravity;

    x += velocityX;
    y += velocityY;
} // End of moveEnemy

bool Enemy::collidesWithPlayer(sf::Sprite &player, sf::Sprite &enemy) {

    bool collides = player.getGlobalBounds().intersects(enemy.getGlobalBounds());

    if(collides) {
        x = float(rand() % 600);
        y = 50.f;
        return true;
    }
    return false;
}
