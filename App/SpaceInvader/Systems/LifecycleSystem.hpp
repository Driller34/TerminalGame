#pragma once
#include "../World.hpp"
#include "../../Utils/GameSettings.hpp"
#include "../../../Core/Utils/Vec.hpp"
#include "../../../Core/Utils/RNG.hpp"

namespace ecs_system
{
void asteroidFinish(World& world, 
    const GameSettings& settings);

void initAsteroids(World& world,
    const GameSettings& settings);

void bulletFinish(World& world,
    const GameSettings& settings);
}