#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <sebgine/entity/VisualEntity.hpp>
#include <sebgine/entity/CircleCollidable.hpp>

class Enemy: public seb::VisualEntity, public seb::CircleCollidable
{
    public:
        Enemy(sf::RenderWindow* window);
        virtual sf::CircleShape* getCircleShape();
        virtual void handleCollision(seb::CircleCollidable* otherCollidable);

    protected:
        virtual void update();
        virtual void render(sf::RenderWindow* window);

    private:
        sf::CircleShape* shape;
        bool visible = true;
};