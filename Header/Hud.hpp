#ifndef HUD_H
#define HUD_H

#pragma once
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "Defination.hpp"
#include <vector>

namespace Ekter
{
    class Hud
    {
    public:
        Hud(GameDataRef data);
        ~Hud(){};
        void Draw();
        void UpdateScore(int score);

    private:
    GameDataRef _data;
    sf::Text _scoreText;

    };
}
#endif