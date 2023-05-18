#ifndef MAIN_CPP_DEFINITIONS_H
#define MAIN_CPP_DEFINITIONS_H

// Window Properties
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;


// Player Properties
const float INITIAL_X_POS = 200.f;
const float INITIAL_Y_POS = 450.f;

const float PLAYER_SCALE_FACTOR_X = 0.1f;
const float PLAYER_SCALE_FACTOR_Y = 0.20f;

const float RIGHT_BOUND = 525.f;
const float LEFT_BOUND = -10.f;


// Enemy Properties
const float ENEMY_SCALE_FACTOR_X = 0.1f;
const float ENEMY_SCALE_FACTOR_Y = 0.1f;


// Ground Properties
const float X_GROUND_POS = 0.f;
const float Y_GROUND_POS = 575.f;
const float GROUND_SCALE_FACTOR_X = 3.0f;
const float GROUND_SCALE_FACTOR_Y = 1.5f;


// Health Text and health Properties
const float HEALTH_X_POS = 325.f;
const float HEALTH_Y_POS = 5.f;

const float PLAYER_HEALTH_SCORE_X_POS = 450.f;
const float PLAYER_HEALTH_SCORE_Y_POS = 5.f;

const int TEXT_SIZE = 34;

#endif //MAIN_CPP_DEFINITIONS_H
