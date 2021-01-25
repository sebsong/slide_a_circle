#include <SFML/Graphics.hpp>
#include <sebgine/utils/VectorUtils.hpp>

#include <Player.hpp>

// setup circle
sf::CircleShape circle(50.f);
{
    circle.setFillColor(sf::Color::Blue);
    const float circleRadius{circle.getRadius()};
    circle.setOrigin(circleRadius, circleRadius);
}

void Player::update()
{
    // maybe update needs to take in some input
    // handle events
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch(event.type)
        {
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
}

void Player::render()
{
    // maybe render needs to take in a window object
    window.draw(circle);
}

static void moveTowardPoint(sf::Transformable& toMove, const sf::Vector2f& point, const float& speed)
{
    sf::Vector2f currPos{toMove.getPosition()};
    sf::Vector2f dir{point - currPos};
    sf::Vector2f movementVector{seb::getNormalizedVector(dir) * speed};

    if (seb::getVectorMagnitude(movementVector) > seb::getVectorMagnitude(dir))
    {
        toMove.setPosition(point);
    } else
    {
        toMove.move(movementVector);
    }
}
