// author: seb
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <sebgine/Utils.hpp>

#include "Player.hpp"

const std::string GAME_NAME{"slide_a_circle"};

int main()
{
    sf::VideoMode fullScreenVideoMode{sf::VideoMode::getFullscreenModes()[0]};
    sf::RenderWindow window(fullScreenVideoMode, GAME_NAME, sf::Style::Fullscreen);

    Player* player = new Player();

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
        player->tick(&window);
        window.display();
    }

    return 0;
}