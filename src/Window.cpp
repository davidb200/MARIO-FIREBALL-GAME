#include "../headers/Window.h"


/*
 * Creates the window, sets the FPS of the window, and initializes all the states to be used
 * .Then while the window is open will run, the current state of the game on the window.
 * @parm  : none
 * @return: void
 */
void Window::runMarioFireballGame()
{
    // Basic window information
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "MARIO FIREBALL GAME");
    window.setFramerateLimit(FPS);

    // Setting up all the states so that they are ready to go
    initMainMenu();
    initGame();
    initGameOver();

    while (window.isOpen())  // run the program as long as the window is open
    {
        // check all the window's events that were triggered since the last iteration of the loop

        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        runCurrentState(window);
    }

} // End of runMarioFireballGame