#ifndef GAME_H
#define GAME_H

#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Ekter
{
    struct GameData
    {
        StateMachine machine;
        InputManager input;
        AssetManager assets;
        sf::RenderWindow window;
    };
    // use a smart pointer to access the struct
    // creating alias for shared pointer
    typedef std::shared_ptr<GameData> GameDataRef;

    class Game
    {
    public:
        Game(int width, int height, std::string title);

    private:
        const float dt = 1.0f / 60.0f;
        sf::Clock _clock;
        GameDataRef _data = std::make_shared<GameData>(); // use _data to access GameData
        void Run();
    };
}
#endif