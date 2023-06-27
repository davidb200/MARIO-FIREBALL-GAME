#include "../headers/MainMenu.h"


/*
 * Loads the font from the "boba_milky" folder
 * @parm   : none
 * @return : void
 */
void MainMenu::loadFont()
{
    if(!bobaMilky.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My GAME\\boba_milky\\Boba Milky.ttf"))
       std::cout << "Failed to load font!" << std::endl;

} // End of loadFont


/*
 * Loads the textures used that are used in the main menu from the "MainMenuImages" folder
 *  @parm  : none
 *  @return: void
 */
void MainMenu::loadTextures()
{
    if(!marioImage.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My GAME\\Images\\MainMenuImages\\Mario.png"))
        std::cout << "Failed to load main menu mario image" << std::endl;
    if(!startButton.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My GAME\\Images\\MainMenuImages\\StartButton.png"))
        std::cout << "Failed to load start button image" << std::endl;
    if(!background.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My GAME\\Images\\MainMenuImages\\MainMenuBackground.png"))
        std::cout << "Failed to load background image" << std::endl;
    if(!exitButton.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My GAME\\Images\\MainMenuImages\\ExitButton.png"))
        std::cout << "Failed to load exit button" << std::endl;

} // End of loadTextures


/*
 * Sets the texts to be used in the main menu screen
 * @parm  : none
 * @return: void
 */
void MainMenu:: setTexts()
{
    videoGameText.setFont(bobaMilky);
    videoGameText.setPosition(155.f, 150.f);
    videoGameText.setCharacterSize(TEXT_SIZE);
    videoGameText.setFillColor(sf::Color::White);
    videoGameText.setString("MARIO FIREBALL");

} // End of setTexts


/*
 * Creates the needed sprites from the textures loaded and sets the sprites correctly
 * to the window
 * @parm  : none
 * @return: void
 */
void MainMenu::setSprites()
{
    // Mario main menu sprite
    marioImageSprite.setTexture(marioImage);
    marioImageSprite.setPosition(310.f, 400.f);
    marioImageSprite.setScale(0.35f, 0.35f);

    // Start button sprite
    startButtonSprite.setTexture(startButton);
    startButtonSprite.setPosition(160.f, 250.f);

    // Exit button sprite
    exitButtonSprite.setTexture(exitButton);
    exitButtonSprite.setPosition(190.f, 350.f);
    exitButtonSprite.scale(0.35f, 0.25f);

    /* Background Image (Some math has to be done here to fit the background nicely
       with the window properties) */
    backgroundSprite.setTexture(background);

    sf::Vector2u backgroundTextureSize;

    backgroundTextureSize = background.getSize();

    float scaleX = (float) WINDOW_WIDTH  / (float) backgroundTextureSize.x;
    float scaleY = (float) WINDOW_HEIGHT / (float) backgroundTextureSize.y;

    backgroundSprite.setScale(scaleX, scaleY);

} // End of setSprites


/*
 * Draws all the sprites set for the main menu to the screen
 * @parm  : The address of the render window
 * @return: void
 */
void MainMenu::drawSprites(sf::RenderWindow &window)
{
    window.draw(backgroundSprite);
    window.draw(marioImageSprite);
    window.draw(startButtonSprite);
    window.draw(exitButtonSprite);

} // End of drawSprites


/*
 * Draws all the texts set for the main menu to the screen
 * @parm  : The address of the render window
 * @return: void
 */
void MainMenu::drawTexts(sf::RenderWindow &window)
{
    window.draw(videoGameText);

} // End of drawTexts


/*
 * Checks if we need to transition to the GAME state by checking if the user
 * wants to press start. If the user presses the "start" button, then the transition
 * to the GAME state will be true and false otherwise
 *
 * @parm  : The address of the render window
 * @return: Boolean
 */
bool MainMenu::startButtonIsPressed(sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) // If the mouse is pressed
    {
        bool buttonPressed = startButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
        if (buttonPressed)
            return true;
    }

    return false;

} // End of gameIsStarted


/*
 * Checks if we need to transition to the CLOSE GAME state by checking if the user
 * presses "exit" . If the user presses the "exit" button, then the transition
 * to the CLOSE GAME state will be true and false otherwise
 *
 * @parm  : The address of the render window
 * @return: Boolean
 */
bool MainMenu::exitButtonIsPressed(sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) // If the mouse is pressed
    {
        bool buttonPressed = exitButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
        if (buttonPressed)
            return true;
    }

    return false;

} // End of exitButtonIsPressed