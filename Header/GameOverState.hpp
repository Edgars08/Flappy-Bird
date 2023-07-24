#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#pragma once

#include "State.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "GameState.hpp"

namespace Ekter
{
    class GameOverState : public State
    {
    public:
        GameOverState(GameDataRef data,int score);
        ~GameOverState(){};
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _gameOverTitle;
        sf::Sprite _gameOverContainer;
        sf::Sprite _retryButton;
        sf::Text _scoreText;
        sf::Text _HighScoreText;
        int _score;
        int _highScore;
    };
}

#endif