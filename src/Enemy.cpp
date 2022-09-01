#include "Enemy.hpp"

#include <random>

Enemy::Enemy(sf::RenderWindow* window)
{
    // setup circle
    sf::CircleShape* circle = new sf::CircleShape(50.f);
    circle->setFillColor(sf::Color::Red);
    const float circleRadius{circle->getRadius()};
    circle->setOrigin(sf::Vector2f(circleRadius, circleRadius));
    shape = circle;
    const sf::Vector2u windowSize = window->getSize();

    static std::default_random_engine e;
    static std::uniform_real_distribution<> disX(0, windowSize.x);
    static std::uniform_real_distribution<> disY(0, windowSize.y);

    shape->setPosition(sf::Vector2f(disX(e), disY(e)));
}

void Enemy::update()
{

}

void Enemy::render(sf::RenderWindow* window)
{
    if (visible)
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
    visible = false;
}