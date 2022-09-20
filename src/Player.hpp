#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <sebgine/collision/interfaces/CircleCollidable.hpp>
#include <sebgine/entity/PlayerEntity.hpp>

class Player: public seb::PlayerEntity, public seb::CircleCollidable
{
    public:
        Player();
        virtual void consumeEvent(sf::Event event);
        virtual sf::CircleShape* getCircleShape();
        virtual void handleCollision(seb::CircleCollidable* otherCollidable);

    protected:
        virtual void update();
        virtual void render(sf::RenderWindow* window);
        virtual void input(sf::RenderWindow* window);

    private:
        virtual void move();

        sf::CircleShape* shape;
        sf::Vector2f direction;
        float initialVelocity = 2;
        float velocity;
        float velocityDecayRate = 0.997;
        const float minVelocity = 0.1;
};