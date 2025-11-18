#pragma once
#include "../../Core/ECS/World.hpp"
#include "../../Core/Utils/Clock.hpp"
#include "../../Core/Utils/RNG.hpp"
#include "../Utils/GameSettings.hpp"

namespace ecs_system
{
void collision(World& world);

void moveAsteroids(World& world,
    const GameSettings& settings);

void asteroidFinish(World& world, 
    const GameSettings& settings,
    const EntityID playerID);

void initAsteroids(World& world,
    const GameSettings& settings);
}