#include "Bird.hpp"

namespace Ekter
{
    Bird::Bird(GameDataRef data) : _data(data)
    {
        _animationIterator = 0;

        _animationFrames.push_back(_data->assets.GetTexture("BirdFrame01"));
        _animationFrames.push_back(_data->assets.GetTexture("BirdFrame02"));
        _animationFrames.push_back(_data->assets.GetTexture("BirdFrame03"));
        _animationFrames.push_back(_data->assets.GetTexture("BirdFrame04"));

        _birdSprite.setTexture(_animationFrames.at(_animationIterator));
        _birdSprite.setPosition(_data->window.getSize().x / 4 - _birdSprite.getGlobalBounds().width / 2, _data->window.getSize().y / 2 - _birdSprite.getGlobalBounds().height / 2);

        _birdState = BIRD_STATE_STILL;
        // has to rotate around its origin
        sf::Vector2f origin = sf::Vector2f(_birdSprite.getGlobalBounds().width / 2, _birdSprite.getGlobalBounds().height / 2);
        _birdSprite.setOrigin(origin);
    }
    void Bird::DrawBird()
    {
        _data->window.draw(_birdSprite);
    }
    void Bird::Animate(float dt)
    {
        if (_clock.getElapsedTime().asSeconds() > (BIRD_ANIMATION_DURATION / _animationFrames.size()))
        {
            if (_animationIterator < (_animationFrames.size() - 1))
            {
                _animationIterator++;
            }
            else
            {
                _animationIterator = 0;
            }
            _birdSprite.setTexture(_animationFrames.at(_animationIterator));
            _clock.restart();
        }
    }
    void Bird::Update(float dt)
    {
        if (_birdState == BIRD_STATE_FALLING)
        {
            _birdSprite.move(0, GRAVITY * dt);
            _rotation += dt * ROTATING_SPEED;
            if (_rotation > 25.0f)
            {
                _rotation = 25.0f;
            }
            _birdSprite.setRotation(_rotation);
        }
        if (_birdState == BIRD_STATE_FLYING)
        {
            _birdSprite.move(0, -FLYING_SPEED * dt);
            _rotation -= dt * ROTATING_SPEED;
            if (_rotation < -25.0f)
            {
                _rotation = -25.0f;
            }
            _birdSprite.setRotation(_rotation);
        }
        if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION)
        {
            _movementClock.restart();
            _birdState = BIRD_STATE_FALLING;
        }
    }
    void Bird::Tap()
    {
        _movementClock.restart();
        _birdState = BIRD_STATE_FLYING;
    }
    const sf::Sprite &Bird::GetSprite() const
    {
        // TODO: insert return statement here
        return _birdSprite;
    }
}