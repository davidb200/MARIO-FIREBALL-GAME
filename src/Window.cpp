#include "../headers/Window.h"
#include "../headers/Player.h"


void Window::RunWindow() {

    sf::RenderWindow window(sf::VideoMode(600,600), "My Game");
    std::cout << "Hello" << std::endl;
    ///////////////////////////////////// Texts//////////////////////////////////////////////////////////////

    sf::Font BobaMilky;
    sf::Text healthScore;
    sf::Text health;

    if(!BobaMilky.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My Game\\boba_milky\\Boba Milky.ttf"))
        std::cout << "Failed to load font!" << std::endl;

    healthScore.setFont(BobaMilky);
    healthScore.setPosition(450.f, 5.f);
    healthScore.setCharacterSize(34);
    healthScore.setFillColor(sf::Color::White);


    health.setFont(BobaMilky);
    health.setString("Health:");
    health.setPosition(325.f,5.f);
    health.setCharacterSize(34);
    health.setFillColor(sf::Color::White);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////Images///////////////////////////////////////////////////////////
    //  Player Image
    sf::Texture mainMenuImage;
    if(!mainMenuImage.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My Game\\Images\\square.png"))
        std::cout << "Failed to load player" << std:: endl;

    sf::Sprite sprite(mainMenuImage);

    sprite.setPosition(200.f, 450.f);
    sprite.scale(0.8, 0.8f);

    // EnemyTexture Image
    sf::Texture EnemyTexture;
    if(!EnemyTexture.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My Game\\Images\\Enemy.png"))
        std::cout << "Failed to load EnemyTexture" << std:: endl;

    sf::Sprite sprite2(EnemyTexture);
    sprite2.setPosition(225.f, 50.f);
    sprite2.scale(0.1f, 0.1f);

    // Ground
    sf::Texture ground;
    if(!ground.loadFromFile("C:\\Users\\david\\OneDrive - Florida Gulf Coast University\\COP 3003\\My Game\\Images\\ground.png"))
        std::cout << "Failed to load barrel images" << std::endl;

    sf::Sprite sprite3(ground);
    sprite3.setPosition(0.f, 575.f);
    sprite3.setScale(3.00f,1.5f);


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

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
           player.moveLeft();
        }

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            player.moveRight();
        }


        player.updateMovement();
        sprite.setPosition(player.getXPosition(), player.getYPosition());
        enemy.moveEnemy();

       if(enemy.collidesWithPlayer(sprite, sprite2))
           game.testHealth = game.testHealth - 50;

        sprite2.setPosition(enemy.getXPosition(), enemy.getYPosition());

        window.clear();

        player.checkOutOfBounds();

        healthScore.setString(std::to_string(enemy.getPlayerHealth()));

        // Draws in the order it appears in
        window.draw(background);
        window.draw(health);
        window.draw(healthScore);

        window.draw(sprite);
        window.draw(sprite2);
        window.draw(sprite3);

        window.display();
    }

}