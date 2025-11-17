#pragma once
#include "../Core/ECS/World.hpp"
#include "../Core/Utils/Clock.hpp"
#include "../Core/Utils/RNG.hpp"
#include "Utils/GameSettings.hpp"

namespace ecs_system
{
//void collision();

void moveAsteroids(World& world,
    const GameSettings& settings);

void asteroidFinish(World& world, 
    const GameSettings& settings);

void initAsteroids(World& world,
    const GameSettings& settings);
    
}