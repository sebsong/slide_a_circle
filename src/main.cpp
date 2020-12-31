// author: seb
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <sebgine/Utils.hpp>

const std::string GAME_NAME{"slide_a_circle"};

template <class T>
static sf::Vector2<T> getNormalizedVector(const sf::Vector2<T> vector)
{
    float magnitude{seb::getVectorMagnitude(vector)};
    if (magnitude == 0)
    {
        return vector;
    }

    return vector / magnitude;
}

static void moveTowardPoint(sf::Transformable& toMove, const sf::Vector2f& point, const float& speed)
{
    sf::Vector2f currPos{toMove.getPosition()};
    sf::Vector2f dir{point - currPos};
    sf::Vector2f movementVector{getNormalizedVector(dir) * speed};

    if (seb::getVectorMagnitude(movementVector) > seb::getVectorMagnitude(dir))
    {
        toMove.setPosition(point);
    } else
    {
        toMove.move(movementVector);
    }
}

int main()
{
    sf::VideoMode fullScreenVideoMode{sf::VideoMode::getFullscreenModes()[0]};
    sf::RenderWindow window(fullScreenVideoMode, GAME_NAME, sf::Style::Fullscreen);

    // setup circle
    sf::CircleShape circle(50.f);
    {
        circle.setFillColor(sf::Color::Blue);
        const float circleRadius{circle.getRadius()};
        circle.setOrigin(circleRadius, circleRadius);
    }

    sf::Vector2f movementPoint;
    bool inMotion = false;
    const float speed = 20.f;

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
                case sf::Event::MouseButtonPressed: // mouse controls
                    switch(event.mouseButton.button)
                    {
                        case sf::Mouse::Left:
                        {
                            if (!inMotion)
                            {
                                movementPoint = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                                inMotion = true;
                            }
                            break;
                        }
                        default:
                            break;
                    }
                default:
                    break;

            }
        }

        if (inMotion)
        {
            moveTowardPoint(circle, movementPoint, speed);
            if (circle.getPosition() == movementPoint)
            {
                inMotion = false;
            }
        }

        // draw to window
        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}