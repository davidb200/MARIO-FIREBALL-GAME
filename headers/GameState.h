////////////////////////////////////////////////////////////////////////////////////////////////
//  Title      : GameState.h
//  Author     : David Betanzos
//  Description: Outlines all the attributes and methods needed for
//               an object of game state of our game.
//  Attributes : Fonts      -> boba milky
//               Texts      -> health, "health" text, "Game Over" text, "Score" text,
//               Textures   -> Mario frames image, fireball image, ground image, background image,
//               Sprites    -> Mario sprite, fireball sprite, ground sprite, background sprite
//               Additional -> final score of the player
//  Methods    : loadFont, loadTextures, initTexts, initSprites, initMarioandFireballPositions,
//               initFinalScore, getFinalScore, drawTexts, drawSprites, updatePlayerScore,
//               updatePlayerHealth, runLogic, isOver, reset
//  Aggregation: GameState has a Mario and a fireball
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MAIN_CPP_GAMESTATE_H
#define MAIN_CPP_GAMESTATE_H

// Builtin library
#include <SFML/Graphics.hpp>
#include <iostream>

// Custom header files
// Aspects needed for the gameState (Mario and the fireball)
#include "Mario.h"
#include "Fireball.h"


class GameState{

private:

    // Font
    sf::Font bobaMilky;

    // Texts
    sf::Text health;
    sf::Text healthText;
    sf::Text gameOver;
    sf::Text scoreText;
    sf::Text score;

    // Textures
    sf::Texture marioFramesImage;
    sf::Texture fireballImage;
    sf::Texture groundImage;
    sf::Texture backgroundImage;

    // Sprites
    sf::Sprite marioSprite;
    sf::Sprite fireballSprite;
    sf::Sprite groundSprite;
    sf::Sprite backgroundSprite;

    /* Objects (Their Constructors will be called as soon as an instance of
     gameState is created) */
    Mario mario;
    Fireball enemy;

    // Static members
    static int finalScore;

public:

    //---------------------------------------------------------------
    // methods
    //---------------------------------------------------------------

    // Loading
    void loadFont();
    void loadTextures();

    // Inits
    void initTexts();
    void initSprites();
    void initMarioAndFireballPositions();
    void initFinalScore();

    // Final Score
    static int getFinalScore();

    // Drawing
    void drawTexts(sf::RenderWindow &window);
    void drawSprites(sf::RenderWindow &window);

    // Updates
    void updatePlayerScore();
    void updatePlayerHealth();

    // Game logic
    void runLogic();

    // State transitions
    bool isOver();

    // Reset
    void reset();

};


#endif //MAIN_CPP_GAMESTATE_H