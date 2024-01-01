////////////////////////////////////////////////////////////////////////////////
// Title      : Definitions.h
// Author     : David Betanzos
// Description: Constants needed for mario fireball game. These are
//              properties for the window,the character and enemy
//              (Mario and fireball),and size of the text we want on the screen.
////////////////////////////////////////////////////////////////////////////////

#ifndef MAIN_CPP_DEFINITIONS_H
#define MAIN_CPP_DEFINITIONS_H

// Window Properties
const int WINDOW_WIDTH       = 600;
const int WINDOW_HEIGHT      = 600;
const int FPS                = 60;

// Mario Properties
const float RIGHT_BOUND      = 525.f;
const float LEFT_BOUND       = -10.f;

// Fireball Properties
const float GRAVITY_CONSTANT = 8.5f;

// Text size
const int TEXT_SIZE          = 38;

#endif //MAIN_CPP_DEFINITIONS_H
