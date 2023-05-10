
#ifndef MAIN_CPP_GAMELOGIC_H
#define MAIN_CPP_GAMELOGIC_H
#include "Player.h"

class GameLogic : public Player{
private:
    bool GameOver = false;
    int score = 0;
public:
    bool isGameOver();
};


#endif //MAIN_CPP_GAMELOGIC_H
