#include "../headers/GameLogic.h"

bool GameLogic::isGameOver() {
    if(testHealth == 0) // If the player has no more health
        return true; // Game over
    return false; // Not game over
} // End of isGameOver
