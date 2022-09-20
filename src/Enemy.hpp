#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <sebgine/entity/NonPlayerEntity.hpp>
#include <sebgine/collision/interfaces/CircleCollidable.hpp>

#include <random>

class Enemy: public seb::NonPlayerEntity, public seb::CircleCollidable
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
        std::default_random_engine e;
        std::uniform_real_distribution<>* disX;
        std::uniform_real_distribution<>* disY;
        bool isDead = true;
};