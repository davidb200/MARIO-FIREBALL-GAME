////////////////////////////////////////////////////////////////////////////////////////////////
//  Title      : MainMenuState.h
//  Author     : David Betanzos
//  Description: Outlines all the attributes and methods needed for
//               an object of main menu state of our game.
//  Attributes : Fonts      -> boba milky
//               Texts      -> video game text
//               Textures   -> Mario image, start button, background, exit button
//               Sprites    -> Mario image sprite, start button sprite, exit button sprite,
//                             background sprite
//  Methods    : loadFont, loadTextures, initTexts, initSprites, drawSprites, drawTexts,
//               startButtonIsPressed, exitButtonIsPressed
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MAIN_CPP_MAINMENUSTATE_H
#define MAIN_CPP_MAINMENUSTATE_H

// Builtin library
#include <SFML/graphics.hpp>
#include <iostream>

// Custom header files
#include "Definitions.h" /* Used for the text size and helping shape the background (the window constants are needed)
                            (the window constants are needed) */


class MainMenuState{

private:

    // Font
    sf::Font bobaMilky;

    // Texts
    sf::Text videoGameText;

    // Textures
    sf::Texture marioImage;
    sf::Texture startButton;
    sf::Texture background;
    sf::Texture exitButton;

    // Sprites
    sf::Sprite marioImageSprite;
    sf::Sprite startButtonSprite;
    sf::Sprite exitButtonSprite;
    sf::Sprite backgroundSprite;

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

    // Drawing
    void drawSprites(sf::RenderWindow &window);
    void drawTexts(sf::RenderWindow &window);

    // Next manager transitions
    bool startButtonIsPressed(sf::RenderWindow &window);
    bool exitButtonIsPressed(sf::RenderWindow &window);

};


#endif //MAIN_CPP_MAINMENUSTATE_H