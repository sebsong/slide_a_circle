#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <sebgine/entity/VisualEntity.hpp>

class Enemy: public seb::VisualEntity
{
    public:
        Enemy(sf::RenderWindow* window);

    protected:
        virtual void update();
        virtual void render(sf::RenderWindow* window);

    private:
        sf::CircleShape* shape;
};