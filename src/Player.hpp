#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <sebgine/entity/ControllableEntity.hpp>

class Player: public seb::ControllableEntity
{
    public:
        Player();
        virtual void consumeEvent(sf::Event event);

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