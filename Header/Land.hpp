#ifndef LAND_H
#define LAND_H

#pragma once

#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "Defination.hpp"
#include <vector>

namespace Ekter
{
    class Land
    {
    public:
        Land(GameDataRef data);
        ~Land(){};

        void MoveLand(float dt);
        void DrawLand();
        const std::vector<sf::Sprite> &GetSprite() const;

    private:
        std::vector<sf::Sprite> _landSprites;
        GameDataRef _data;
    };
}
#endif