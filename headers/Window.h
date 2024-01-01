/////////////////////////////////////////////////////////////////
// Title      : Window.h
// Author     : David Betanzos
// Description: Outlines all the attributes and methods needed for
//              an object of Window.
// Attributes : Objects (state manager)
// Methods    : runMarioFireballGame
//////////////////////////////////////////////////////////////////
#ifndef MAIN_CPP_WINDOW_H
#define MAIN_CPP_WINDOW_H

// Builtin library
#include <SFML/graphics.hpp>

// Custom header files
#include "StateManager.h" // Needed for running the current manager of the gam
#include "Definitions.h" // Needed to set up the window width, height, and FPS


class Window{
private:
    // Object of type StateManager to display the correct state on the window
    // (aggregation)
    StateManager manager;

public:

    //---------------------------------------------------------------
    // methods
    //---------------------------------------------------------------

    void runMarioFireballGame();

};


#endif //MAIN_CPP_WINDOW_H
