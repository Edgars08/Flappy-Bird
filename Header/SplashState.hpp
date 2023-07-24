#ifndef SPLASHSTATE_H
#define SPLASHSTATE_H

#pragma once
#include "State.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>

namespace Ekter
{
    class SplashState : public State
    {
    public:
        SplashState(GameDataRef data);
        ~SplashState(){};
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;
        sf::Clock _clock;
        sf::Sprite _background;
    };
}
#endif