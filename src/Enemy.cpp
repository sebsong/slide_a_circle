#include "Enemy.hpp"

Enemy::Enemy(sf::RenderWindow* window)
{
    // setup circle
    sf::CircleShape* circle = new sf::CircleShape(50.f);
    circle->setFillColor(sf::Color::Red);
    const float circleRadius{circle->getRadius()};
    circle->setOrigin(circleRadius, circleRadius);
    shape = circle;
    const sf::Vector2u windowSize = window->getSize();
    shape->setPosition(windowSize.x / 2, windowSize.y / 2);
}

void Enemy::update()
{

}

void Enemy::render(sf::RenderWindow* window)
{
    window->draw(*shape);
}