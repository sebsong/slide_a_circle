#include <sebgine/utils/VectorUtils.hpp>

#include "Player.hpp"

static void moveTowardPoint(sf::Transformable* toMove, const sf::Vector2f& point, const float& speed)
{
    sf::Vector2f currPos{toMove->getPosition()};
    sf::Vector2f dir{point - currPos};
    sf::Vector2f movementVector{seb::getNormalizedVector(dir) * speed};

    if (seb::getVectorMagnitude(movementVector) > seb::getVectorMagnitude(dir))
    {
        toMove->setPosition(point);
    } else
    {
        toMove->move(movementVector);
    }
}

Player::Player()
{
    // setup circle
    sf::CircleShape* circle = new sf::CircleShape(50.f);
    circle->setFillColor(sf::Color::Blue);
    const float circleRadius{circle->getRadius()};
    circle->setOrigin(circleRadius, circleRadius);
    shape = circle;
}


void Player::update(sf::Event* event, sf::RenderWindow* window)
{
    switch(event->type)
    {
        case sf::Event::MouseButtonPressed: // mouse controls
            switch(event->mouseButton.button)
            {
                case sf::Mouse::Left:
                {
                    if (!inMotion)
                    {
                        movementPoint = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
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

    if (inMotion)
    {
        moveTowardPoint(shape, movementPoint, speed);
        if (shape->getPosition() == movementPoint)
        {
            inMotion = false;
        }
    }
}

void Player::render(sf::RenderWindow* window)
{
    // maybe render needs to take in a window object
    window->draw(*shape);
}
