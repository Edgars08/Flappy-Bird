#include "InputManager.hpp"

namespace Ekter
{
    InputManager::InputManager(){};
    InputManager::~InputManager(){};

    bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
    {
        if (sf::Mouse::isButtonPressed(button))
        {
            sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
            if (tempRect.contains(sf::Mouse::getPosition(window))) // checks for collision between mouse and sprite/if sprite is clicked
            // contain=Check if a point is inside the rectangle's area
            {
                return true;
            }
        }
        return false;
    }
    sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window)
    {
        return sf::Mouse::getPosition(window);
    }
}