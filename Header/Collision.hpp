#ifndef COLLISION_H
#define COLLISION_H

#pragma once
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "Defination.hpp"

namespace Ekter{

    class Collision
    {
    public:
        Collision();
        ~Collision(){};
        bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
        bool CheckSpriteCollision(sf::Sprite sprite1,float scale1, sf::Sprite sprite2,float scale2);

    private:
    };
}
#endif