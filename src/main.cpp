/////////////////////////////////////////////////////////////////////////////////////
//  Title      : main.cpp
//  Author     : David Betanzos
//  Description: Runs the main application. In this case, the Mario
//               Fireball Game. An object of window is created and calls the method
//               runMarioFireballGame. All the implementation is in the other source
//               and header files located under a folder named headers and src
//               for this project.
/////////////////////////////////////////////////////////////////////////////////////
// Custom header file
#include "../headers/Window.h" // Used to run the gameState


int main()
{
    Window window = Window(); // Creating instance of class Window

    window.runMarioFireballGame(); // Running the gameState

    return 0; // EXIT SUCCESS

}