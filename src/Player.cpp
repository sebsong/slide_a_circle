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
    circle->setOrigin(sf::Vector2f(circleRadius, circleRadius));
    shape = circle;
}

void Player::consumeEvent(sf::Event event)
{
    switch(event.type)
    {
        case sf::Event::MouseButtonPressed: // mouse controls
        {
            sf::Event::MouseButtonEvent mouseButtonEvent = event.mouseButton;
            switch(mouseButtonEvent.button)
            {
                case sf::Mouse::Left:
                {
                    if (!inMotion)
                    {
                        movementPoint.x = mouseButtonEvent.x;
                        movementPoint.y = mouseButtonEvent.y;
                        inMotion = true;
                    }
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;

    }
}

void Player::input(sf::RenderWindow* window)
{
}

void Player::update()
{
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
    window->draw(*shape);
}

sf::CircleShape* Player::getCircleShape()
{
    return shape;
}

void Player::handleCollision(CircleCollidable* otherCollidable)
{
}