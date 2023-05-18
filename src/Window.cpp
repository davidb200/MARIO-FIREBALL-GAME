#include "../headers/Window.h"
#include "../headers/Player.h"


void Window::RunWindow() {

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "My Game");
    ///////////////////////////////////// Texts//////////////////////////////////////////////////////////////

    sf::Font bobaMilky;
    sf::Text healthScore;
    sf::Text playerhealth;
    sf::Text gameOver;

    if(!bobaMilky.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My Game\\boba_milky\\Boba Milky.ttf"))
        std::cout << "Failed to load font!" << std::endl;

    healthScore.setFont(bobaMilky);
    healthScore.setPosition(PLAYER_HEALTH_SCORE_X_POS, PLAYER_HEALTH_SCORE_Y_POS);
    healthScore.setCharacterSize(TEXT_SIZE);
    healthScore.setFillColor(sf::Color::White);


    playerhealth.setFont(bobaMilky);
    playerhealth.setString("Health:");
    playerhealth.setPosition(HEALTH_X_POS, HEALTH_Y_POS);
    playerhealth.setCharacterSize(TEXT_SIZE);
    playerhealth.setFillColor(sf::Color::White);


    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////Images///////////////////////////////////////////////////////////
    //  Player Image
    sf::Texture mario;
    if(!mario.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My Game\\Images\\Mario.png"))
        std::cout << "Failed to load player" << std:: endl;

    sf::Sprite marioSprite(mario);

    marioSprite.setPosition(INITIAL_X_POS, INITIAL_Y_POS);
    marioSprite.scale(PLAYER_SCALE_FACTOR_X, PLAYER_SCALE_FACTOR_Y);

    // fireball Image
    sf::Texture fireball;
    if(!fireball.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My Game\\Images\\Enemy.png"))
        std::cout << "Failed to load fireball" << std:: endl;

    sf::Sprite fireballSprite(fireball);
    fireballSprite.scale(ENEMY_SCALE_FACTOR_X, ENEMY_SCALE_FACTOR_Y);

    // Ground
    sf::Texture ground;
    if(!ground.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My Game\\Images\\ground.png"))
        std::cout << "Failed to load barrel images" << std::endl;

    sf::Sprite groundSprite(ground);
    groundSprite.setPosition(X_GROUND_POS, Y_GROUND_POS);
    groundSprite.setScale(GROUND_SCALE_FACTOR_X, GROUND_SCALE_FACTOR_Y);


    // Background Image
    sf::Texture backgroundImage;
    if(!backgroundImage.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My Game\\Images\\Background.jpg"))
        std::cout << "Failed to load background image!" << std::endl;

    sf::Sprite background(backgroundImage);

    sf::Vector2u backgroundTextureSize;
    sf::Vector2u windowSize;
    backgroundTextureSize = backgroundImage.getSize();
    windowSize = window.getSize();

    float scaleX = (float) windowSize.x/ (float) backgroundTextureSize.x;
    float scaleY = (float) windowSize.y / (float) backgroundTextureSize.y;

    background.setTexture(backgroundImage);
    background.setScale(scaleX, scaleY);


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    Player player;
    Enemy enemy;
    GameLogic game;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed || game.isGameOver())
                window.close();

        }

        // Key pressings
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            player.moveUp();
            if(player.getYPosition() < 350.f) // Player can't over jump
                player.moveDown();
        }

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            player.moveLeft();

        }

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            player.moveRight();
        }


        player.updateMovement();
        marioSprite.setPosition(player.getXPosition(), player.getYPosition());
        enemy.moveEnemy();

       if(enemy.collidesWithPlayer(marioSprite, fireballSprite))
           game.testHealth = game.testHealth - 50;

        fireballSprite.setPosition(enemy.getXPosition(), enemy.getYPosition());

        window.clear();

        player.checkOutOfBounds();

        healthScore.setString(std::to_string(enemy.getPlayerHealth()));

        // Draws in the order it appears in
        window.draw(background);
        window.draw(playerhealth);
        window.draw(healthScore);

        window.draw(marioSprite);
        window.draw(fireballSprite);
        window.draw(groundSprite);


        window.display();
    }

}