#pragma once
#include "../SpaceInvader/World.hpp"
#include "../SpaceInvader/Entities/Entity.hpp"
#include "../SpaceInvader/Entities/Player.hpp"
#include "../../Core/ResourceManager.hpp"
#include "../../Core/Utils/Color.hpp"
#include "../../Core/Utils/Vec.hpp"
#include "../Utils/GameSettings.hpp"

namespace Factory
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