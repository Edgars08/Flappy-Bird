#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#pragma once
#include "State.hpp"
#include "Game.hpp"
#include "InputManager.hpp"
#include <SFML/Graphics.hpp>

namespace Ekter
{
    class MainMenuState : public State
    {
    public:
        MainMenuState(GameDataRef data);
        ~MainMenuState(){};
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _playbutton;
        sf::Sprite _title;
    };
}

#endif