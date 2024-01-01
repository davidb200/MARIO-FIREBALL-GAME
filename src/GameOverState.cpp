////////////////////////////////////////////////////////////////////
// Title      : GameOverState.cpp
// Author     : David Betanzos
// Description: Implements all methods declared in
//              GameOverState.h.
////////////////////////////////////////////////////////////////////
#include "../headers/GameOverState.h"


/*
 * Loads the font from the "boba_milky" folder
 * @parm   : none
 * @return : void
 */
void GameOverState::loadFont()
{
    if(!bobaMilky.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\Mario Fireball Game\\boba_milky\\Boba Milky.ttf"))
        std::cout << "Failed to load font!" << std::endl;

}


/*
 *  Initializes the texts for the gameState over screen so that they are ready to use
 *  @parm  : none
 *  @return: void
 */
void GameOverState::initTexts()
{
    // GameState Over Text
    gameOverText.setFont(bobaMilky);
    gameOverText.setFillColor(sf::Color::Black);
    gameOverText.setString("GAME OVER!");
    gameOverText.setCharacterSize(TEXT_SIZE);
    gameOverText.setPosition(200.f, 50.f);

    // Final Score text
    finalScoreText.setFont(bobaMilky);
    finalScoreText.setFillColor(sf::Color::Black);
    finalScoreText.setString("FINAL SCORE:");
    finalScoreText.setCharacterSize(TEXT_SIZE);
    finalScoreText.setPosition(125.f, 150.f);

    // Final Score
    finalScore.setFont(bobaMilky);
    finalScore.setFillColor(sf::Color::Black);
    finalScore.setCharacterSize(TEXT_SIZE);
    finalScore.setPosition(435.f, 150.f);

    // Play Again Text
    playAgainText.setFont(bobaMilky);
    playAgainText.setFillColor(sf::Color::Black);
    playAgainText.setString("PLAY AGAIN?");
    playAgainText.setCharacterSize(TEXT_SIZE);
    playAgainText.setPosition(205.f, 250.f);

} // End of initTexts


/*
 * Draws the texts used for the gameState over screen
 * to the window
 * @parm  : The address of the render window
 * @return: void
 */
void GameOverState::drawTexts(sf::RenderWindow &window)
{
    window.draw(gameOverText);
    finalScore.setString(std::to_string(GameState::getFinalScore()));

    window.draw(finalScoreText);
    window.draw(finalScore);
    window.draw(playAgainText);

} // End of drawTexts


/*
 * Load the textures used in the gameState over screen from the "GameOverState_Images"
 * folder
 * @parm  : none
 * @return: void
 */
void GameOverState::loadTextures()
{
    if(!yesButton.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\Mario Fireball Game\\Images\\GameOverState_Images\\YesButton.png"))
        std::cout << "Failed to load yes button" << std::endl;
    if(!noButton.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\Mario Fireball Game\\Images\\GameOverState_Images\\noButton.png"))
        std::cout << "Failed to load no button" << std::endl;
    if(!gameOver.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\Mario Fireball Game\\Images\\GameOverState_Images\\GameOverImage.png"))
        std::cout << "Failed to load gameState over image" << std::endl;

} // End of loadTextures


/*
 * Creates the needed sprites from the textures loaded and sets the sprites correctly
 * to the gameState over window screen
 * @parm  : none
 * @return: void
 */
void GameOverState::initSprites()
{
    yesButtonSprite.setTexture(yesButton);
    yesButtonSprite.setPosition(125.f, 400.f);
    yesButtonSprite.setScale(0.5f, 0.5f);

    noButtonSprite.setTexture(noButton);
    noButtonSprite.setPosition(335.f, 400.f);
    noButtonSprite.setScale(0.65f, 0.58f);

    gameOverSprite.setTexture(gameOver);
    gameOverSprite.setPosition(250.f, 300.f);
    gameOverSprite.setScale(0.08f, 0.08f);

} // End of initSprites


/*
 * Draw the sprites that we set to the  gameState over screen
 * @parm  : none
 * @return: void
 */
void GameOverState::drawSprites(sf::RenderWindow &window)
{
    window.draw(gameOverSprite);
    window.draw(yesButtonSprite);
    window.draw(noButtonSprite);

} // End of drawSprites


/*
 * Checks if we need to transition to the GAME manager by checking if the user
 * wants to play the gameState again. If the user presses the yes button, then the transition
 * to the GAME state will be true and false otherwise
 *
 * @parm  : The address of the render window
 * @return: boolean
 */
bool GameOverState::theYesButtonIsPressed(sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) // If the mouse is pressed
    {
        // Checking if the "yes" button is pressed
        bool buttonPressed = yesButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)));

        if (buttonPressed)
            return true;
    }

    return false;

} // End of theYesButtonIsPressed


/*
 * Checks if we need to transition to the MAIN MENU manager by checking if the user
 * wants to play the gameState again. If the user presses the no button, then the transition
 * to the MAIN MENU state will be true and false otherwise
 *
 * @parm  : The address of the render window
 * @return: boolean
 */
bool GameOverState::theNoButtonIsPressed(sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) // If the mouse is pressed
    {
        // Checking if the "no" button is pressed
        bool buttonPressed = noButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)));

        if (buttonPressed)
            return true;
    }

    return false;

} // End of theNoButtonIsPressed
