#pragma once
#include <chrono>
#include "../Core/Utils/Vec.hpp"

using Width = size_t;
using Height = size_t;
using HP = int;
using FinishPoint = int;
using Position = Vec2i;
using SpawnRange = Vec2i;

struct GameSettings
{
    Vec2i playerStartPosition;

    HP fullPlayerHp;

    HP hpWhenCollision;
    HP hpWhenAsteridFinish;

    size_t numAsteroids;

    std::chrono::milliseconds asteroidsUpdateTimeout;

    FinishPoint asteroidFinishPoint;
    FinishPoint bulletFinishPoint;

    Width bulletWidth;
    Height bulletHeight;

    Vec2i spawnXRange;
    Vec2i spawnYRange;
};  