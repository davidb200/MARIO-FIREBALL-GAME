#include "../headers/StateManager.h"


/*
 * Starts the current state of the window to be at the main menu
 * @parm: none
 */
StateManager::StateManager(): currentGameState(MAIN_MENU)
{

}


/*
 * Initializes the MAIN MENU state
 * @parm  : none
 * @return: void
 */
void StateManager::initMainMenu()
{
    // MAIN MENU
    mainMenu.loadFont();
    mainMenu.loadTextures();
    mainMenu.setTexts();
    mainMenu.setSprites();

} // End of initMainMenu


/*
 * Initializes the GAME state
 * @parm  : none
 * @return: void
 */
void StateManager::initGame()
{
    game.loadFont();
    game.setTexts();
    game.loadTextures();
    game.setSprites();

} // End of initGame


/*
 * Initializes the GAME OVER state
 * @parm  : none
 * @return: void
 */
void StateManager::initGameOver()
{
    gameOver.loadFont();
    gameOver.setTexts();
    gameOver.loadTextures();
    gameOver.setSprites();

} // End of initGameOver


/*
 * Runs the MAIN MENU state on the window
 * @parm: The address of the render window
 * @return: void
 */
void StateManager::runMainMenu(sf::RenderWindow &window)
{
    mainMenu.drawSprites(window);
    mainMenu.drawTexts(window);

    window.display();
    window.clear();

} // End of runMainMenu


/*
 * Runs the GAME state on the window
 * @parm  : The address of the render window
 * @return: void
 */
void StateManager::runGame(sf::RenderWindow &window)
{
    game.runLogic();

    // Update the score and players health as the game goes on
    game.updatePlayerScore();
    game.updatePlayerHealth();

    // Draw the Sprites and text to the window in each frame, then display it
    game.drawSprites(window);
    game.drawTexts(window);

    window.display();
    window.clear();

} // End of runGame


/*
 * Runs the GAME OVER state on the window
 * @parm  : The address of the render window
 * @return: void
 */
void StateManager::runGameOver(sf::RenderWindow &window)
{
    window.clear(sf::Color::Cyan);
    gameOver.drawSprites(window);
    gameOver.drawTexts(window);

    window.display();
    window.clear();

} // End of runGameOver


/*
 * Runs the current state the window is in (a state machine)
 * @parm  : The address of the render window
 * @return: void
 */
void StateManager::runCurrentState(sf::RenderWindow &window)
{
    switch(currentGameState)
    {
        case MAIN_MENU:

            runMainMenu(window);

            if(mainMenu.startButtonIsPressed(window))
                currentGameState = GAME; // The window will transition to the GAME state

            if(mainMenu.exitButtonIsPressed(window)) // If we want to exit our application
                currentGameState = CLOSE_GAME; // The window will transition to the CLOSE_GAME state

            break;

        case GAME:

            runGame(window);

            if(game.isOver())
            {
                game.setFinalScore(); // Set the final score of the mario
                currentGameState = GAME_OVER; // The window will transition to the GAME OVER state
            }

            break;

        case GAME_OVER:

            runGameOver(window);

            if(gameOver.theYesButtonIsPressed(window)) // The mario wants to continue playing the game
            {
                currentGameState = GAME; // Transition to the GAME state
                game.reset(); // reset the mario's attributes (health and score)
            }

            if(gameOver.theNoButtonIsPressed(window)) // The mario does not want to continue playing the game
            {
                currentGameState = MAIN_MENU; // Transition to the MAIN MENU state
                game.reset(); // reset the mario's attributes (Since they can decide to play again by hitting the start button
            }

            break;

        case CLOSE_GAME:
            window.close();
    }

} // End of runCurrentState