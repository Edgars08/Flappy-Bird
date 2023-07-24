
#include "Flash.hpp"

Ekter::Flash::Flash(GameDataRef data) : _data(data)
{
    _shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize()));
    _shape.setFillColor(sf::Color(255, 255, 255, 0));
    flashOn = true;
}

void Ekter::Flash::DrawFlash()
{
    _data->window.draw(_shape);
}

void Ekter::Flash::Show(float dt)
{
    if (flashOn)
    {
        int alpha = (int)_shape.getFillColor().a + (FLASH_SPEED * dt);
        if (alpha >= 255.0f)
        {
            alpha = 255.0f;
            flashOn = false;
        }
        _shape.setFillColor(sf::Color(255, 255, 255, alpha));
    }
    else
    {

        int alpha = (int)_shape.getFillColor().a - (FLASH_SPEED * dt);
        if (alpha <= 0.0f)
        {
            alpha = 0.0f;
            flashOn = false;
        }
        _shape.setFillColor(sf::Color(255, 255, 255, alpha));
    }
}

