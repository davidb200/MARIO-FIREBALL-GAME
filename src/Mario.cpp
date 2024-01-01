////////////////////////////////////////////////////////////////////
// Title      : Mario.cpp
// Author     : David Betanzos
// Description: Implements all methods and constructor declared in
//              Mario.h.
////////////////////////////////////////////////////////////////////
#include "../headers/Mario.h"


/*
 *  Initializes the xPos position, yPos position, velocity, score, and health
 *  of the mario when the gameState begins
 *  @parm  : none
 *  @return: void
 */
Mario :: Mario()
{
    setXPos(rand() % WINDOW_WIDTH);
    setYPos(405.f);
    setScore(0);
    setHealth(100);
    velocityX = 0.f;

}


/*
 *  Gets the mario's current score in the gameState
 *  @parm  : none
 *  @return: The score of the mario
 */
int   Mario:: getScore()
{
    return score;

} // End of getScore


/*
 *  Gets the mario's current health in the gameState
 *  @parm  : none
 *  @return: The health of the mario
 */
int Mario::getHealth()
{
    return health;

} // End of getHealth


/*
 *  Gets the mario's current xPos position in the gameState
 *  @parm  : none
 *  @return: The xPos position of mario
 */
float Mario::getXPos()
{
    return xPos;

} // End of getXPos


/*
 *  Gets the mario's current yPos position in the gameState
 *  @parm: none
 *  @return: The yPos position of mario
 */
float Mario::getYPos()
{
    return yPos;

} // End of getYPos


/*
 * Sets the health of mario
 * @parm  : an integer holding the current health of mario
 * @return: none
 */
void Mario::setHealth(int _health)
{
    health = _health;

} // End of setHealth

/*
 * Sets the score for mario
 * @parm  : an integer holding the current score of amrio
 * @return: none
 */
void Mario::setScore(int _score)
{
    score = _score;
} // End of setScore


/*
 * Sets mario's x position
 * @parm  : float holding the current x position of mario
 * @return: void
 */
void Mario::setXPos(float x)
{
    xPos = x;
} // End of setXPos


/*
 * Sets mario's y position
 * @parm: float holding the current x position of mario
 * @return: void
 */
void Mario::setYPos(float y)
{
    yPos = y;

} // End of setYPos


/*
 *  Resets the health of the mario back to 100, if the mario chooses
 *  to play again
 *  @parm  : none
 *  @return: none
 */
void  Mario::resetHealth()
{
    setHealth(100);

} // End of resetHealth


/*
 *  Resets the score of the mario back to 0, if the mario chooses
 *  to play again
 *  @parm  : none
 *  @return: none
 */
void Mario::resetScore()
{
    setScore(0);

} // End of resetScore


/*
 *  Respawn's Mario (xPos and yPos), for when the player wants
 *  to play again
 *  @parm  : none
 *  @return: none
 */
void Mario::respawn()
{
    setXPos(float(rand() % WINDOW_WIDTH));
    setYPos(405.f);

} // End of resetXPosition


/*
 *  Updates the current score of the mario
 *  @parm  : none
 *  @return: void
 */
void  Mario::addToScore()
{
    setScore(score + 50);

} // End of addToScore


/*
 *  Lowers the current health of the mario
 *  @parm  : none
 *  @return: void
 */
void  Mario::lowerHealth()
{
    setHealth(health - 25);

} // End of lowerHealth


/*
 *  Checks if the mario's position is out of left side of the window
 *  @parm  : none
 *  @return: boolean
 */
bool  Mario::isOutOfBoundsLeft()
{
    if (xPos <= LEFT_BOUND) // If the mario tries to go out of bounds on the left side
        return true;

    return false;

} // End of isOutOfBoundsLeft


/*
 *  Checks if the mario's position is out of right side of the window
 *  @parm  : none
 *  @return: boolean
 */
bool Mario::isOutOfBoundsRight()
{
    if(xPos >= RIGHT_BOUND) // If the mario is trying to go out fo bounds on the right side
        return true;

    return false;

} // End of isOutOfBoundsRight


/*
 *  Updates the mario to stay in within the width of the window
 *  @parm  : none
 *  @return: void
 */
void Mario::keepPlayerInBounds()
{
    if(isOutOfBoundsLeft())
    {
        xPos = LEFT_BOUND;
        return;
    }

    if(isOutOfBoundsRight())
        xPos = RIGHT_BOUND;

} // End of keepPlayerInBounds


/*
 *  Velocity that will helps move the mario left
 *  @parm  : none
 *  @return: void
 */
void Mario::moveLeft()
{
    velocityX = -10.f;

} // End of moveLeft


/*
 *  Velocity that will help move the mario right
 *  @parm  : none
 *  @return: void
 */
void Mario::moveRight()
{
    velocityX = 10.f;

} // End of moveRight


/*
 *  Keeps the mario in their current position
 *  @parm  : none
 *  @return: void
 */
void Mario::stayStill()
{
    velocityX = 0.f;

} // End of stayStill


/*
 *  Updates the current mario's position based of the current velocity
 *  @parm  : none
 *  @return: void
 */
void Mario::updateMovement()
{
    xPos += velocityX;

} // End of updateMovement


/*
 *  Checks the current key pressing of the mario, and based of whatever key they hit,
 *  will move and animate the mario going towards the desired direction (Some math must be done
 *  here to update the sprite frames correctly)
 *
 *  @parm  : mario sprite
 *  @return: void
 */
void Mario::processInput(sf::Sprite &mario)
{
    // Key pressings
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) // Left direction
    {
        int spriteSheetXPos;

        spriteSheetXPos = ((int) mario.getPosition().x / FPS ) % 16;
        spriteSheetXPos = spriteSheetXPos * 25;
        mario.setTextureRect(sf::IntRect(spriteSheetXPos, -3, 25, 35));

        moveLeft();
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) // Right direction
    {

        int spriteSheetXPos;

        spriteSheetXPos = ((int) mario.getPosition().x / FPS) % 16;
        spriteSheetXPos = (spriteSheetXPos + 8) * 25;

        if(spriteSheetXPos > 380)
            spriteSheetXPos = 380 + 5;

        mario.setTextureRect(sf::IntRect(spriteSheetXPos + 3, -3, 25, 35));

        moveRight();
    }

    else // No button is pressed
        stayStill();

} // End of processInput