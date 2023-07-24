#ifndef FLASH_H
#define FLASH_H

#pragma once

#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "Defination.hpp"

namespace Ekter
{
    class Flash
    {
    public:
        Flash(GameDataRef data);
        ~Flash(){};

        void DrawFlash();
        void Show(float dt);

    private:
        GameDataRef _data;
        sf::RectangleShape _shape;
        bool flashOn;
    };
}
#endif