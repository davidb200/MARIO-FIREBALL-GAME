////////////////////////////////////////////////////////////////////
// Title      : StateManager.cpp
// Author     : David Betanzos
// Description: Implements all methods and constructors declared in
//              StateManager.h.
////////////////////////////////////////////////////////////////////
#include "../headers/StateManager.h"


/*
 * Starts the current manager of the window to be at the main menu
 * @parm: none
 */
StateManager::StateManager()
{
    currentGameState = MAIN_MENU;

}


/*
 * Initializes the MAIN MENU manager
 * @parm  : none
 * @return: void
 */
void StateManager::initMainMenu()
{
    // MAIN MENU
    mainMenuState.loadFont();
    mainMenuState.loadTextures();
    mainMenuState.initTexts();
    mainMenuState.initSprites();

} // End of initMainMenu


/*
 * Initializes the GAME manager
 * @parm  : none
 * @return: void
 */
void StateManager::initGame()
{
    gameState.loadFont();
    gameState.initTexts();
    gameState.loadTextures();
    gameState.initSprites();

} // End of initGame


/*
 * Initializes the GAME OVER manager
 * @parm  : none
 * @return: void
 */
void StateManager::initGameOver()
{
    gameOverState.loadFont();
    gameOverState.initTexts();
    gameOverState.loadTextures();
    gameOverState.initSprites();

} // End of initGameOver


/*
 * Runs the MAIN MENU manager on the window
 * @parm: The address of the render window
 * @return: void
 */
void StateManager::runMainMenu(sf::RenderWindow &window)
{
    mainMenuState.drawSprites(window);
    mainMenuState.drawTexts(window);

    window.display();
    window.clear();

} // End of runMainMenu


/*
 * Runs the GAME manager on the window
 * @parm  : The address of the render window
 * @return: void
 */
void StateManager::runGame(sf::RenderWindow &window)
{
    gameState.runLogic();

    // Update the score and players health as the gameState goes on
    gameState.updatePlayerScore();
    gameState.updatePlayerHealth();

    // Draw the Sprites and text to the window in each frame, then display it
    gameState.drawSprites(window);
    gameState.drawTexts(window);

    window.display();
    window.clear();

} // End of runGame


/*
 * Runs the GAME OVER manager on the window
 * @parm  : The address of the render window
 * @return: void
 */
void StateManager::runGameOver(sf::RenderWindow &window)
{
    window.clear(sf::Color::Cyan);
    gameOverState.drawSprites(window);
    gameOverState.drawTexts(window);

    window.display();
    window.clear();

} // End of runGameOver


/*
 * Runs the current manager the window is in (a manager machine)
 * @parm  : The address of the render window
 * @return: void
 */
void StateManager::runCurrentState(sf::RenderWindow &window)
{
    switch(currentGameState)
    {
        case MAIN_MENU:

            runMainMenu(window);

            if(mainMenuState.startButtonIsPressed(window))
                currentGameState = GAME; // The window will transition to the GAME manager

            if(mainMenuState.exitButtonIsPressed(window)) // If we want to exit our application
                currentGameState = CLOSE_GAME; // The window will transition to the CLOSE_GAME manager

            break;

        case GAME:

            runGame(window);

            if(gameState.isOver())
            {
                gameState.initFinalScore(); // Set the final score of the mario
                currentGameState = GAME_OVER; // The window will transition to the GAME OVER manager
            }

            break;

        case GAME_OVER:

            runGameOver(window);

            if(gameOverState.theYesButtonIsPressed(window)) // The player wants to continue playing the gameState
            {
                currentGameState = GAME; // Transition to the GAME manager
                gameState.reset(); // reset the Mario's attributes (health and score)
            }

            if(gameOverState.theNoButtonIsPressed(window)) // The player does not want to continue playing the gameState
            {
                currentGameState = MAIN_MENU; // Transition to the MAIN MENU manager
                gameState.reset(); // reset Mario's attributes (Since they can decide to play again by hitting the start button
            }

            break;

        case CLOSE_GAME:
            window.close();
    }

} // End of runCurrentState