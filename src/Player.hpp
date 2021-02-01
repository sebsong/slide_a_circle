#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <sebgine/entity/VisualEntity.hpp>

class Player: public seb::VisualEntity
{
    public:
        Player();
        virtual void update(sf::Event* event, sf::RenderWindow* window);
        virtual void render(sf::RenderWindow* window);

    private:
        sf::CircleShape* shape;
        sf::Vector2f movementPoint;
        bool inMotion = false;
        const float speed = 20.f;
};