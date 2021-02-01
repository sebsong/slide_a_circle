#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <sebgine/entity/VisualEntity.hpp>

class Player: public seb::VisualEntity
{
    public:
        virtual void update(sf::Event* event, sf::RenderWindow* window);

        virtual void render(sf::RenderWindow* window);

    private:
        sf::Shape* shape;

        bool inMotion;
        sf::Vector2f* movementPoint;
        const float speed = 20.f;
};