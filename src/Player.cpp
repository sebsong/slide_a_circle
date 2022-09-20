#include <sebgine/utils/VectorUtils.hpp>

#include "Player.hpp"

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
                    if (velocity <= 0)
                    {
                        const sf::Vector2f mousePosition{static_cast<float>(mouseButtonEvent.x), static_cast<float>(mouseButtonEvent.y)};
                        direction = mousePosition - shape->getPosition();
                        velocity = initialVelocity;
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

void Player::move()
{
    if (velocity > 0)
    {
        sf::Vector2f movementVector{seb::getNormalizedVector(direction) * velocity};
        shape->move(movementVector);
        velocity *= velocityDecayRate;
        if (velocity < minVelocity)
        {
            velocity = 0.f;
        }
    }
}

void Player::update()
{
    move();
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