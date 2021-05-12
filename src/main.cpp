// author: seb
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <sebgine/Utils.hpp>
#include <sebgine/Collision.hpp>

#include "Player.hpp"
#include "Enemy.hpp"

const std::string GAME_NAME{"slide_a_circle"};

int main()
{
    sf::VideoMode fullScreenVideoMode{sf::VideoMode::getFullscreenModes()[0]};
    sf::RenderWindow window(fullScreenVideoMode, GAME_NAME, sf::Style::Fullscreen);

    Player* player = new Player();
    Enemy* enemy = new Enemy(&window);

    std::vector<seb::CircleCollidable*>* collidables = new std::vector<seb::CircleCollidable*>();
    collidables->push_back(player);
    collidables->push_back(enemy);
    seb::CircleCollisionDetector* collisionDetector = new seb::CircleCollisionDetector(collidables);

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
        enemy->tick(&window);
        player->tick(&window);
        collisionDetector->detect();
        window.display();
    }

    return 0;
}