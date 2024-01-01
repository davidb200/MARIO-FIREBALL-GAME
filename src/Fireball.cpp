////////////////////////////////////////////////////////////////////
// Title      : Fireball.cpp
// Author     : David Betanzos
// Description: Implements all methods and constructor declared in
//              Fireball.h.
////////////////////////////////////////////////////////////////////
#include "../headers/Fireball.h"


/*
 * Default constructor for initializing the spawn and acceleration of the enemy when it falls
 * @parm : none
 */
Fireball::Fireball()
{
    setXPos(float(rand() % WINDOW_WIDTH));
    setYPos(0.f);
    yVelocity = GRAVITY_CONSTANT;

}


/*
 * Gets the current X position of the enemy
 * @parm   : none
 * @return : float
 */
float Fireball::getXPos()
{
    return xPos;

} // End of getXPos


/*
 * Gets the current Y position of the enemy
 * @parm   : none
 * @return : float
 */
float Fireball::getYPos()
{
    return yPos;

} // End of getYPos


/*
 * Sets the X position for the fireball
 * @parm: float with the x position we are setting it to
 * @return: none
 */
void Fireball::setXPos(float x)
{
    xPos = x;
} // End of setXPos

/*
 * Sets the Y position for the fireball
 * @parm  : float with the y position we are setting it to
 * @return: none
 */
void Fireball::setYPos(float y)
{
    yPos = y;

} // End of setYPos


/*
 * Checks if the fireball leaves the current bounds of the window
 * @parm   : none
 * @return : boolean
 */
bool Fireball::isOutOfWindow()
{
    if(yPos > WINDOW_HEIGHT)
        return true;

    return false;
} // End of isOutOfWindow


/*
 * Updates the enemy position
 * @parm   : none
 * @return : void
 */
void  Fireball::moveCorrectly()
{
    if(isOutOfWindow()) // If the enemy is out of bounds
    {
        spawnInRandomPosition(); // Place it in a new position (With height being the same)
        return; // exit
    }

    // If the enemy is not out of the window, then only update the Y position (The X
    // position will only update when the enemy has to spawn in again
    yPos += yVelocity;

} // End of moveCorrectly


/*
 * Spawns an enemy in a new random position, but just along the xPos-axis,
 * yPos-axis stays the same
 * @parm  : none
 * @return: void
 */
void Fireball::spawnInRandomPosition()
{
    setXPos(float(rand() % WINDOW_WIDTH)); // The xPos will change
    setYPos(0.f); // The height will not change

} // End of SpawnInRandomPosition;


/*
 * Checks if the enemy collides with the mario
 * @parm  : The sprite of the mario and the sprite of the enemy
 * @return: boolean
 */
bool Fireball::collidesWithPlayer(sf::Sprite &player, sf::Sprite &enemy)
{
    // Check if the sprites intersect
    return player.getGlobalBounds().intersects(enemy.getGlobalBounds());

} // End of collidesWithPlayer