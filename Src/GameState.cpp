
#include <sstream>
#include <iostream>
#include "Defination.hpp"
#include "GameState.hpp"

namespace Ekter
{
    GameState::GameState(GameDataRef data) : _data(data)
    {
    }

    void GameState::Init()
    {
        // store them in a map ...then get
        _data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture("PIPE UP", PIPE_UP_FILEPATH);
        _data->assets.LoadTexture("PIPE DOWN", PIPE_DOWN_FILEPATH);
        _data->assets.LoadTexture("Land", LAND_FILEPATH);
        _data->assets.LoadTexture("BirdFrame01", BIRD_FRAME_1_FILEPATH);
        _data->assets.LoadTexture("BirdFrame02", BIRD_FRAME_2_FILEPATH);
        _data->assets.LoadTexture("BirdFrame03", BIRD_FRAME_3_FILEPATH);
        _data->assets.LoadTexture("BirdFrame04", BIRD_FRAME_4_FILEPATH);
        _data->assets.LoadTexture("SCORING PIPE", SCORRING_PIPE_FILEPATH);
        _data->assets.LoadFont("FlappyFont", FLAPPY_FONT_FILEPATH);
      

        _background.setTexture(this->_data->assets.GetTexture("Game Background"));
        _background.setScale(1, 0.68359375f);

        // CREATE PIPE OBJECT
        pipe = new PipeClass(_data);
        land = new Land(_data);
        bird = new Bird(_data);
        flash = new Flash(_data);
        hud = new Hud(_data);

        _gameState = GAME_STATES::eReady;
        _score = 0;
        hud->UpdateScore(_score);
    }

    void GameState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                _data->window.close();
            }
            if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
            {
                if (_gameState != GAME_STATES::eGameOver)
                {
                    _gameState = GAME_STATES::ePlaying;
                    bird->Tap(); // on stack
                }
            }
        }
    }
    void GameState::Update(float dt)
    {
        if (_gameState != GAME_STATES::eGameOver)
        {
            land->MoveLand(dt);
            bird->Animate(dt);
        }
        if (_gameState == GAME_STATES::ePlaying)
        {
            pipe->MovePipe(dt);

            if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
            {
                pipe->RandomisePipeOffset();
                pipe->SpawnInvisiblePipe();
                pipe->SpawnBottomPipe();
                pipe->SpawnTopPipe();
                pipe->SpawnScoringPipe();
                clock.restart();
            }

            bird->Update(dt);
            std::vector<sf::Sprite> landSprite = land->GetSprite();
            for (unsigned int i = 0; i < landSprite.size(); i++)
            {
                if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, landSprite.at(i), 1.0f))
                {
                    _gameState = GAME_STATES::eGameOver;
                    clock.restart();
                }
            }

            std::vector<sf::Sprite> pipeSprite = pipe->GetSprite();
            for (unsigned int i = 0; i < pipeSprite.size(); i++)
            {
                if (collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, pipeSprite.at(i), 1.0f))
                {
                    _gameState = GAME_STATES::eGameOver;
                    clock.restart();
                }
            }
            if (_gameState == GAME_STATES::ePlaying)
            {
                std::vector<sf::Sprite> &scoringSprites = pipe->GetScoringSprite();
                for (unsigned int i = 0; i < scoringSprites.size(); i++)
                {
                    if (collision.CheckSpriteCollision(bird->GetSprite(), 0.7f, scoringSprites.at(i), 1.0f))
                    {
                        _score++;
                        // std::cout << _score << std::endl;
                        hud->UpdateScore(_score);
                        scoringSprites.erase(scoringSprites.begin() + i);
                    }
                }
            }
        }
        if (_gameState == GAME_STATES::eGameOver)
        {
            flash->Show(dt);
            if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAMEOVER_APPEARS)
            {
                _data->machine.AddState(StateRef(new GameOverState(_data)), true);
            }
        }
    }
    void GameState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        pipe->DrawPipe();
        land->DrawLand();
        bird->DrawBird();
        flash->DrawFlash();
        hud->Draw();
        _data->window.display();
    }
}