#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#pragma once
#include <SFML/Graphics.hpp>

namespace Ekter
{

    class InputManager
    {
    public:
        InputManager();
        ~InputManager();
        bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        sf::Vector2i GetMousePosition(sf::RenderWindow &window);

    private:
    };
}
#endif