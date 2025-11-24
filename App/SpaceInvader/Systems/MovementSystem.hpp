#pragma once
#include "../World.hpp"
#include "../../Utils/GameSettings.hpp"
#include "../../../Core/Utils/Vec.hpp"
#include "../../../Core/Utils/Clock.hpp"

namespace ecs_system
{
void movePlayer(World& world);

void moveAsteroids(World& world,
    const GameSettings& settings);

void moveBullets(World& world,
    const GameSettings& settings);
}