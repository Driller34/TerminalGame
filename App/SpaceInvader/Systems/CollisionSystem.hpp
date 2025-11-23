#pragma once
#include "../World.hpp"
#include "../../Utils/GameSettings.hpp"
#include "../../../Core/Utils/Vec.hpp"
#include "../../../Core/Utils/Collision.hpp"

namespace ecs_system
{
void collisionBulletAsteroid(World& world);

void collisionPlayerAsteroid(World& world,
    const GameSettings& settings);
}