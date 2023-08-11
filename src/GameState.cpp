#include "../headers/GameState.h"


/*
 * Loads the font from the "boba_milky" folder
 *  @parm  : none
 * @return : void
 */
void GameState:: loadFont()
{
    if(!bobaMilky.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My GAME\\boba_milky\\Boba Milky.ttf"))
        std::cout << "Failed to load font!" << std::endl;

} // End of loadFont


/*
 *  Loads all the game Textures used which are located under the "GameState_Images" folder
 *  @parm  : none
 *  @return: void
 */
void GameState:: loadTextures() {

    // Mario Image
    if(!marioFramesImage.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My GAME\\Images\\GameState_Images\\MarioFrames.png"))
        std::cout << "Failed to load mario!" << std:: endl;

    // Fireball Image
    if(!fireballImage.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My GAME\\Images\\GameState_Images\\Fireball.png"))
        std::cout << "Failed to load fireballImage!" << std:: endl;

    // Ground Image
    if(!groundImage.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My GAME\\Images\\GameState_Images\\ground.png"))
        std::cout << "Failed to load groundImage!" << std::endl;

    // Background Image
    if(!backgroundImage.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My GAME\\Images\\GameState_Images\\Background.jpg"))
        std::cout << "Failed to load background!" << std::endl;

} // End of loadTextures


/*
 * Sets the texts used in the game
 * @parm  : none
 * @return: void
 */
void GameState:: setTexts()
{
    // Health text ("Just the word HEALTH on the screen")
    healthText.setFont(bobaMilky);
    healthText.setString("HEALTH:");
    healthText.setPosition(350.f, 5.f);
    healthText.setCharacterSize(TEXT_SIZE);
    healthText.setFillColor(sf::Color::White);

    // Mario's health
    health.setFont(bobaMilky);
    health.setPosition(500.f, 5.f);
    health.setCharacterSize(TEXT_SIZE);
    health.setFillColor(sf::Color::White);

    // Score text ("Just the word SCORE on the screen")
    scoreText.setFont(bobaMilky);
    scoreText.setString("SCORE:");
    scoreText.setPosition(75.f, 5.f);
    scoreText.setCharacterSize(TEXT_SIZE);
    scoreText.setFillColor(sf::Color::White);

    // Mario's score
    score.setFont(bobaMilky);
    score.setPosition(275.f, 5.f);
    score.setCharacterSize(TEXT_SIZE);
    score.setFillColor(sf::Color::White);

} // End of setTexts


/*
 * Draws the texts used for the game on the screen
 * @parm  : the address of the render window
 * @return: void
 */
void GameState:: drawTexts(sf::RenderWindow &window)
{
    window.draw(healthText);
    window.draw(health);
    window.draw(scoreText);
    window.draw(score);

} // End of drawTexts


/*
 *  Sets all the sprites to be formatted nicely on the
 *  window for when the game starts
 *  @parm  : none
 *  @return: void
 */
void GameState:: setSprites()
{
    // Mario
    marioSprite.setTexture(marioFramesImage);
    marioSprite.setTextureRect(sf::IntRect (25,-3,25,35));
    marioSprite.scale(5.f, 5.f);

    // Fireball
    fireballSprite.setTexture(fireballImage);
    fireballSprite.scale(0.1f, 0.1f);

    // Ground
    groundSprite.setTexture(groundImage);
    groundSprite.setPosition(0.f, 575.f);
    groundSprite.setScale(3.0f, 1.5f);

    // Background
    backgroundSprite.setTexture(backgroundImage);

    // Math calculations are here so the background fits on the entire screen
    sf::Vector2u backgroundTextureSize;
    backgroundTextureSize = backgroundImage.getSize();

    float scaleX = (float) WINDOW_WIDTH  / (float) backgroundTextureSize.x;
    float scaleY = (float) WINDOW_HEIGHT / (float) backgroundTextureSize.y;

    backgroundSprite.setScale(scaleX, scaleY);

} // End of setSprites


/*
 *  Sets the current mario (the mario) and the fireball (the enemy) sprite position
 *  on the window
 *  @parm  : none
 *  @return: void
 */
void GameState::setMarioAndFireballPositions()
{
    marioSprite.setPosition(mario.getXPosition(), mario.getYPosition());
    fireballSprite.setPosition(enemy.getXPosition(), enemy.getYPosition());

} // End of setMarioAndFireballPositions


/*
 * Final Score initialized
 */
int GameState::finalScore = 0;


/*
 * Sets the final Score of mario
 *  @parm   : none
 *  @return : none
 */
void GameState::setFinalScore()
{
    finalScore = mario.getScore();
} // End of setFinalScore


/*
 * Returns the final score of the mario
 * @parm  : none
 * @return: integer
 */
int GameState::getFinalScore()
{
    return finalScore;
} // End of getFinalScore


/*
 *  Draws all the sprites used in the game to be drawn to the window
 *  @parm  : the address of the render window
 *  @return: void
 */
void GameState:: drawSprites(sf::RenderWindow &window)
{
    window.draw(backgroundSprite);
    window.draw(marioSprite);
    window.draw(fireballSprite);
    window.draw(groundSprite);

} // End of drawSprites


/*
 *  Updates the mario's health on the window
 *  @parm  : none
 *  @return: void
 */
void GameState:: updatePlayerHealth()
{
    health.setString(std::to_string(mario.getHealth()));

} // End of updatePlayerHealth


/*
 *  Updates the mario's score on the window
 *  @parm  : none
 *  @return: void
 */
void GameState:: updatePlayerScore()
{
    score.setString(std::to_string(mario.getScore()));

} // End of updatePlayerScore


/*
 *  Updates Mario (the mario) and the fireball (the enemy) position, then checks a few conditions based
 *  off the movements of both to update the health and score of the mario
 *  @parm  : none
 *  @return: void
 */
void GameState:: runLogic()
{
    setMarioAndFireballPositions();

    // Player movement logic to keep track of
    mario.processInput(marioSprite);
    mario.updateMovement();
    mario.keepPlayerInBounds();

    // Enemy movement logic to keep track of
    enemy.moveCorrectly();

    // Updates to the game

    if(enemy.collidesWithPlayer(marioSprite, fireballSprite)) // If the fireball hits the mario
    {
        enemy.spawnInRandomPosition(); // Respawn the enemy
        mario.lowerHealth();
    }

    if(enemy.isOutOfWindow()) // If the mario successfully doges a fireball
    {
        mario.addToScore();
    }


} // End of runLogic


/*
 * Checks if we need to transition to the GAME OVER state by checking
 * if the game is over or not
 * @parm  : none
 * @return: boolean
 */
bool GameState:: isOver()
{
    if(mario.getHealth() == 0)
        return true;

    return false;

} // End of isGameOver


/*
 * Resets all the game's attributes for when the mario wants to play the game again
 * @parm  : none
 * @return: void
 */
void GameState::reset()
{
    // Reset the final score of mario
    finalScore = 0;

    // Reset the position
    mario.respawn();

    // Reset the score and health
    mario.resetHealth();
    mario.resetScore();

} // End of reset