#ifndef PIPECLASS_H
#define PIPECLASS_H

#pragma once

#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "Defination.hpp"
#include <vector>

namespace Ekter
{
    class PipeClass
    {
    public:
        PipeClass(GameDataRef data);
        ~PipeClass(){};
        void SpawnBottomPipe();
        void SpawnTopPipe();
        void SpawnInvisiblePipe();
        void SpawnScoringPipe();//checks if bird went through pipes
        void MovePipe(float dt);
        void DrawPipe();
        void RandomisePipeOffset();
        const std::vector<sf::Sprite> &GetSprite() const;
       std::vector<sf::Sprite> &GetScoringSprite();

    private:
        std::vector<sf::Sprite> pipeSprites;
        std::vector<sf::Sprite> scoringPipes;
        GameDataRef _data;
        int _landHeight;
        int _pipeSpawnOffset;
    };
}
#endif