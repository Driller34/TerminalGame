#pragma once
#include <chrono>
#include "../Core/Utils/Vec.hpp"

struct GameSettings
{
    size_t width;
    size_t height;

    Vec2i playerStartPosition;

    size_t fullPlayerHp;

    size_t hpWhenCollision;
    size_t hpWhenAsteridFinish;

    size_t numAsteroids;

    std::chrono::milliseconds asteroidsUpdateTimeout;

    int asteroidFinishPoint;

    Vec2i spawnXRange;
    Vec2i spawnYRange;
};  