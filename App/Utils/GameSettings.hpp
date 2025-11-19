#pragma once
#include <chrono>
#include "../Core/Utils/Vec.hpp"

using Width = size_t;
using Height = size_t;
using HP = size_t;
using FinishPoint = int;
using Position = Vec2i;
using SpawnRange = Vec2i;

struct GameSettings
{
    Vec2i playerStartPosition;

    size_t fullPlayerHp;

    size_t hpWhenCollision;
    size_t hpWhenAsteridFinish;

    size_t numAsteroids;

    std::chrono::milliseconds asteroidsUpdateTimeout;

    int asteroidFinishPoint;
    int bulletFinishPoint;

    int bulletWidth;
    int bulletHeight;

    Vec2i spawnXRange;
    Vec2i spawnYRange;
};  