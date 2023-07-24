#ifndef GAMESTATE_H
#define GAMESTATE_H

#pragma once

#include "State.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "PipeClass.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "Hud.hpp"
#include "GameOverState.hpp"
#include "StateMachine.hpp"
#include "InputManager.hpp"
namespace Ekter
{
    class GameState : public State
    {
    public:
        GameState(GameDataRef data);
        ~GameState(){};
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;
        sf::Sprite _background;
        PipeClass *pipe;
        Land *land;
        Bird *bird;
        Flash *flash;
        Hud *hud;

        Collision collision;
        sf::Clock clock;
        int _gameState;
        int _score;
    };
}

#endif