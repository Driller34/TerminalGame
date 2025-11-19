#pragma once
#include "../SpaceInvader/World.hpp"
#include "../../Core/ECS/Entity.hpp"
#include "../SpaceInvader/Entities/Player.hpp"
#include "../../Core/ResourceManager.hpp"
#include "../../Core/Utils/Color.hpp"
#include "../../Core/Utils/Vec.hpp"
#include "../Utils/GameSettings.hpp"

namespace factory
{
Player createPlayer(World& world,
    const GameSettings& settings,
    ResourceManager& resourceManager);

void createAsteroids(World& world,
    const GameSettings& settings,
    ResourceManager& resourceManager);

Bullet createBullet(World& world,
    const GameSettings& settings);
}