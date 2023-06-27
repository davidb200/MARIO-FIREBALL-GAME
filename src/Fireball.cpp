#include "../headers/Fireball.h"


/*
 * Default constructor for initializing the spawn and acceleration of the enemy when it falls
 * @parm : none
 */
Fireball::Fireball(): x(float(rand() % WINDOW_WIDTH)) , y(0.f), gravity(GRAVITY_CONSTANT)
{

}


/*
 * Gets the current X position of the enemy
 * @parm   : none
 * @return : float
 */
float Fireball:: getXPosition()
{
    return x;

} // End of getXPosition


/*
 * Gets the current Y position of the enemy
 * @parm   : none
 * @return : float
 */
float Fireball :: getYPosition()
{
    return y;

} // End of getYPosition


/*
 * Checks if the fireball leaves the current bounds of the window
 * @parm   : none
 * @return : boolean
 */
bool Fireball:: isOutOfWindow()
{
    if(y > WINDOW_HEIGHT)
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
        spawnInRandomPosition(); // Place it in a new position (With height being the same_)
        return; // exit
    }

    // If the enemy is not out of the window, then only update the Y position (The X
    // position will only update when the enemy has to spawn in again
    velocityY = gravity;
    y += velocityY;

} // End of moveCorrectly


/*
 * Spawns an enemy in a new random position, but just along the x-axis,
 * y-axis stays the same
 * @parm  : none
 * @return: void
 */
void Fireball:: spawnInRandomPosition()
{
    x = float(rand() % WINDOW_WIDTH);
    y = 0.f; // Keep the same height the enemy initially dropped
    // from because the height will not change

} // End of SpawnInRandomPosition;


/*
 * Checks if the enemy collides with the mario
 * @parm  : The sprite of the mario and the sprite of the enemy
 * @return: boolean
 */
bool Fireball:: collidesWithPlayer(sf::Sprite &player, sf::Sprite &enemy)
{
    // Check if the sprites intersect
    bool collides = player.getGlobalBounds().intersects(enemy.getGlobalBounds());

    return collides;

} // End of collidesWithPlayer