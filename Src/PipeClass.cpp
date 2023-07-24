#include "PipeClass.hpp"

namespace Ekter
{
    PipeClass::PipeClass(GameDataRef data) : _data(data)
    {
        //_landHeight = _data->assets.GetTexture("Land").getSize().y;
        _landHeight = 100;
        _pipeSpawnOffset = 0;
    }

    void PipeClass::SpawnBottomPipe()
    {
        sf::Sprite sprite(_data->assets.GetTexture("PIPE UP"));
        sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - 0.5 * sprite.getGlobalBounds().height - _pipeSpawnOffset);
        pipeSprites.push_back(sprite);
    }

    void PipeClass::SpawnTopPipe()
    {
        sf::Sprite sprite(_data->assets.GetTexture("PIPE DOWN"));
        sprite.setPosition(_data->window.getSize().x, 0);
        sprite.setScale(1, 0.6793478261f);
        pipeSprites.push_back(sprite);
    }

    void PipeClass::SpawnInvisiblePipe()
    {
        sf::Sprite sprite(_data->assets.GetTexture("SCORING PIPE"));
        sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnOffset);
        sprite.setColor(sf::Color(0, 0, 0, 0));
        pipeSprites.push_back(sprite);
    }

    void PipeClass::SpawnScoringPipe()
    {
        sf::Sprite sprite(_data->assets.GetTexture("SCORING PIPE"));
        sprite.setPosition(_data->window.getSize().x, 0);
        scoringPipes.push_back(sprite);
    }

    void PipeClass::MovePipe(float dt)
    {
        for (unsigned int i = 0; i < pipeSprites.size(); i++)
        {
            if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width)
            {
                pipeSprites.erase(pipeSprites.begin() + i); // begin is at index zero
            }
            else
            {
                float movement = PIPE_MOVEMENT_SPEED * dt;
                pipeSprites.at(i).move(-movement, 0);
            }
        }
        ///
        for (unsigned int i = 0; i < scoringPipes.size(); i++)
        {
            if (scoringPipes.at(i).getPosition().x < 0 - scoringPipes.at(i).getGlobalBounds().width)
            {
                scoringPipes.erase(scoringPipes.begin() + i); // begin is at index zero
            }
            else
            {
                float movement = PIPE_MOVEMENT_SPEED * dt;
                scoringPipes.at(i).move(-movement, 0);
            }
        }
    }

    void PipeClass::DrawPipe()
    {
        for (unsigned int i = 0; i < pipeSprites.size(); i++)
        {
            _data->window.draw(pipeSprites.at(i));
        }
    }
    void PipeClass::RandomisePipeOffset()
    {
        _pipeSpawnOffset = rand() % (_landHeight + 1);
    }
    const std::vector<sf::Sprite> &PipeClass::GetSprite() const
    {
        return pipeSprites;
    }
    std::vector<sf::Sprite> &PipeClass::GetScoringSprite()
    {

        return scoringPipes;
    }
}