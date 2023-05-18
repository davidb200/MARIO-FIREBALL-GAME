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

void Enemy:: addEnemy(){
}

bool Enemy::collidesWithPlayer(sf::Sprite &player, sf::Sprite &enemy) {
    // Merge Request comment
    bool collides = player.getGlobalBounds().intersects(enemy.getGlobalBounds());
    // Did Something here, hi there
    // Fixed Collision Detection
    // Player collision branch
    if(collides) {
        playerHealth = playerHealth - 50;
        x = float(rand() % 600);
        y = 50.f;
        return true;
    }
    return false;
}

int Enemy:: getPlayerHealth(){return playerHealth;}