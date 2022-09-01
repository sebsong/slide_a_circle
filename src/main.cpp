// author: seb
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <sebgine/Collision.hpp>
#include <sebgine/Entity.hpp>
#include <sebgine/Utils.hpp>

#include "Player.hpp"
#include "Enemy.hpp"

#include <iostream>

const std::string GAME_NAME{"slide_a_circle"};

int main()
{
    // std::vector<sf::VideoMode> fullScreenVideoModes{sf::VideoMode::getFullscreenModes()};
    sf::VideoMode videoMode{sf::VideoMode::getDesktopMode()};
    sf::RenderWindow window(videoMode, GAME_NAME, sf::Style::Resize);

    Player* player = new Player();
    Enemy* enemy = new Enemy(&window);

    seb::EntityManager* entityManager = new seb::EntityManager();
    entityManager->registerEntity(player);
    entityManager->registerEntity(enemy);

    seb::CircleCollisionDetector* collisionDetector = new seb::CircleCollisionDetector();
    collisionDetector->registerCollidable(player);
    collisionDetector->registerCollidable(enemy);

    // main game loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed: // keyboard controls
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;

            }
            player->consumeEvent(event);
        }

        // draw to window
        window.clear();
        entityManager->tick(&window);
        collisionDetector->detect();
        window.display();
    }

    return 0;
}