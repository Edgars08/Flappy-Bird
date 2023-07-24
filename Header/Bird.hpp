#ifndef BIRD_H
#define BIRD_H

#pragma once
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "Defination.hpp"
#include <vector>

namespace Ekter
{
    class Bird
    {
    public:
        Bird(GameDataRef data);
        ~Bird(){};
        void DrawBird();
        void Animate(float dt);
        void Update(float dt);
        void Tap();
        const sf::Sprite &GetSprite() const;

    private:
        sf::Sprite _birdSprite;
        GameDataRef _data;
        sf::Clock _clock;
        unsigned int _animationIterator;
        std::vector<sf::Texture> _animationFrames;
        sf::Clock _movementClock;
        int _birdState;
        float _rotation;
    };
}
#endif