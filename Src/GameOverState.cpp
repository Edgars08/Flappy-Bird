#include "GameOverState.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include "Defination.hpp"
#include "GameState.hpp"

namespace Ekter
{
    GameOverState::GameOverState(GameDataRef data,int score) : _data(data),_score(score)
    {
    }

    void GameOverState::Init()
    {
        // store them in a map ...then get
        _data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture("gameOverTitle", GAME_OVERTITLE_FILEPATH);
        _data->assets.LoadTexture("retryButton", GAME_OVERBODY_FILEPATH);
        _data->assets.LoadTexture("gameOverContainer", SCORRING_PIPE_FILEPATH);
        _background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
        _gameOverContainer.setTexture(this->_data->assets.GetTexture("gameOverContainer"));
        _gameOverTitle.setTexture(this->_data->assets.GetTexture("gameOverTitle"));
        _retryButton.setTexture(this->_data->assets.GetTexture("retryButton"));

        _gameOverContainer.setPosition((_data->window.getSize().x - _gameOverContainer.getGlobalBounds().width) / 2, (_data->window.getSize().y - _gameOverContainer.getGlobalBounds().height) / 2);
        _gameOverTitle.setPosition((_data->window.getSize().x - _gameOverContainer.getGlobalBounds().width) / 2, (_gameOverContainer.getPosition().y - _gameOverContainer.getGlobalBounds().height * 1.2));
        _retryButton.setPosition((_data->window.getSize().x - _gameOverContainer.getGlobalBounds().width) / 2, (_gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + _retryButton.getGlobalBounds().height) / 2);
        ///////////////////////////
        _scoreText.setFont(_data->assets.GetFont("FlappyFont"));
        _scoreText.setString(std::to_string(_score));
        _scoreText.setCharacterSize(56);
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
        _scoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 2.15);
        //////
        _HighScoreText.setFont(_data->assets.GetFont("FlappyFont"));
        _HighScoreText.setString(std::to_string(_score));
        _HighScoreText.setCharacterSize(56);
        _HighScoreText.setFillColor(sf::Color::White);
        _HighScoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
        _HighScoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 1.78);

        std::ifstream readfile;
        readfile.open(HIGHSCORE_FILEPATH);
        if (readfile.is_open())
        {
            while (!readfile.eof())
            {
                readfile >> _highScore;
            }
        }
        readfile.close();
        std::ofstream writefile(HIGHSCORE_FILEPATH);
        if (writefile.is_open())
        {
            while (_score > _highScore)
            {
                _highScore = _score;
            }
            writefile << _highScore;
        }
        readfile.close();
    }

    void GameOverState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                _data->window.close();
            }
            if (_data->input.IsSpriteClicked(_retryButton, sf::Mouse::Left, _data->window))
            {
                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
        }
    }
    void GameOverState::Update(float dt)
    {
    }
    void GameOverState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(_gameOverContainer);
        _data->window.draw(_gameOverTitle);
        _data->window.draw(_retryButton);
        _data->window.draw(_scoreText);
        _data->window.draw(_HighScoreText);
        _data->window.display();
    }
}