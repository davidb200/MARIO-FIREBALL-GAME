////////////////////////////////////////////////////////////////////////////////////
// Title      : GameOverState.h
// Author     : David Betanzos
// Description: Outlines all the attributes and methods needed
//              for an object of GameOverState of our game.
// Attributes : Fonts    -> bobaMilky font,
//              Texts    -> "GameOver", "Final Score,finalScore of Mario
//              Textures -> yes button, no button, game over button
//              Sprites  -> yes button sprite, no button sprite, game over sprite
// Methods    : loadTextures, loadFonts, initTexts, initSprites,drawSprites,
//              drawTexts, theNoButtonIsPressed, theYesButtonIsPressed
////////////////////////////////////////////////////////////////////////////////////

#ifndef MAIN_CPP_GAMEOVERSTATE_H
#define MAIN_CPP_GAMEOVERSTATE_H

// Builtin libraries
#include <SFML/Graphics.hpp>
#include <iostream>

// Custom header files
#include "Definitions.h" // Needed for size of text
#include "GameState.h" // Needed for the final score of the player


class GameOverState{

private:

    // Font
    sf::Font bobaMilky;

    // Texts
    sf::Text gameOverText;
    sf::Text finalScoreText;
    sf::Text finalScore;
    sf::Text playAgainText;

    // Textures
    sf::Texture yesButton;
    sf::Texture noButton;
    sf::Texture gameOver;

    // Sprites;
    sf::Sprite yesButtonSprite;
    sf::Sprite noButtonSprite;
    sf::Sprite gameOverSprite;

public:

    //---------------------------------------------------------------
    // methods
    //---------------------------------------------------------------

    // Loading
    void loadTextures();
    void loadFont();

    // Inits
    void initTexts();
    void initSprites();

    // Drawing
    void drawSprites(sf::RenderWindow &window);
    void drawTexts(sf::RenderWindow &window);

    // Next State Transitions
    bool theNoButtonIsPressed(sf::RenderWindow &window);
    bool theYesButtonIsPressed(sf::RenderWindow &window);

};


#endif //MAIN_CPP_GAMEOVERSTATE_H