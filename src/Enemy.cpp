#include "Enemy.hpp"

#include <iostream>

Enemy::Enemy(sf::RenderWindow* window)
{
    // setup circle
    sf::CircleShape* circle = new sf::CircleShape(50.f);
    circle->setFillColor(sf::Color::Red);
    const float circleRadius{circle->getRadius()};
    circle->setOrigin(sf::Vector2f(circleRadius, circleRadius));
    shape = circle;
    const sf::Vector2u windowSize = window->getSize();

    disX = new std::uniform_real_distribution<>(0, windowSize.x);
    disY = new std::uniform_real_distribution<>(0, windowSize.y);
}

void Enemy::update()
{
    if(isDead)
    {
        shape->setPosition(sf::Vector2f((*disX)(e), (*disY)(e)));
        isDead = false;
    }
}

void Enemy::render(sf::RenderWindow* window)
{
    if (!isDead)
    {
        window->draw(*shape);
    }
}

sf::CircleShape* Enemy::getCircleShape()
{
    return shape;
}

void Enemy::handleCollision(CircleCollidable* otherCollidable)
{
    isDead = true;
}
