#include "../headers/GameLogic.h"

bool GameLogic::isGameOver() {
    if(getHealth() == 0)
        GameOver = true;
    return GameOver;
}
