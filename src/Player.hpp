#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <sebgine/entity/PlayerEntity.hpp>
#include <sebgine/entity/CircleCollidable.hpp>

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
        sf::CircleShape* shape;
        sf::Vector2f movementPoint;
        bool inMotion = false;
        const float speed = 20.f;
};