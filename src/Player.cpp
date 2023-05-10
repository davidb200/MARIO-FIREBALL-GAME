#include "../headers/Player.h"

Player :: Player(){
    x = 200.f;
    y = 450.f;
    velocityX = 0.f;
    velocityY = 0.f;
    gravity = 0.005f;

}


bool Player::isDamaged(sf::Sprite &player, sf::Sprite &enemy) {

    bool damaged = player.getGlobalBounds().intersects(enemy.getGlobalBounds());

    if (damaged){
        health = health - 50;
        player.setPosition(200.f, 450.f);
        return damaged;
    }

    return damaged;
} // End of isDamaged

bool Player::addToScore(){



}

bool Player::checkOutOfBounds() {

    bool outOfBounds = false;

    if (x >= 460.f) {
        x = 460.f;
        //spritePlayer.setPosition(player.x - 1, player.y);
        outOfBounds = true;
    }

    if (x <= -1.f) {

        //spritePlayer.setPosition(player.x + 1, player.y);
        x = -1.f;
        outOfBounds = true;
    }
    return outOfBounds;

} // End of checkOutOfBounds

int Player:: getHealth(){return health;} // End of getHealth

int Player:: getScore(){return score;} // End of getScore

void Player::updateMovement() {

    if(y < 450.f) {
        velocityY += gravity;
    }
    else if(y >= 450.f)
        y = 450.f;

    x += velocityX;
    y += velocityY;
} // End of updateMovement

float Player::getXPosition() {return x;}

float Player::getYPosition() {return y;}

void Player:: moveRight(){velocityX = 0.085f;}

void Player:: moveLeft(){velocityX = -0.085f;}

void Player:: moveUp(){velocityY = -0.5f;}
