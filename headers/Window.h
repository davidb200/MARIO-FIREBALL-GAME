#ifndef MAIN_CPP_WINDOW_H
#define MAIN_CPP_WINDOW_H

// Builtin library
#include <SFML/graphics.hpp>

// Custom header files
#include "StateManager.h" // Needed for running the current state of the gam
#include "Definitions.h" // Needed to set up the window width, height, and FPS

/* The Window class needs to inherit from the State Manager class
 * because the window needs to know the current state of the game in order render
 * the current state of the game
 */


class Window: public StateManager{

public:

    //---------------------------------------------------------------
    // methods
    //---------------------------------------------------------------

    void runMarioFireballGame();

};


#endif //MAIN_CPP_WINDOW_H
