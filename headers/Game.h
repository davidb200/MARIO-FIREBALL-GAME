#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

// Builtin library
#include <SFML/Graphics.hpp>
#include <iostream>

// Custom header files
// Aspects needed for the game (Mario and the fireball)
#include "Mario.h"
#include "Fireball.h"


class Game{

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
     game is created) */
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

    // Setters
    void setTexts();
    void setSprites();
    void setMarioAndFireballPositions();
    void setFinalScore();

    // Getters
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


#endif //MAIN_CPP_GAME_H