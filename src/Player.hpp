#include <SFML/Graphics/Shape.hpp>

#include <sebgine/entity/VisualEntity.hpp>

class Player: public seb::VisualEntity
{
    public:
        virtual void update();

        virtual void render();

    private:
        sf::Shape shape;

        bool inMotion;
        sf::Vector2f movementPoint;
        const float speed = 20.f;
};