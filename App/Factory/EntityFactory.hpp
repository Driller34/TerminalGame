#pragma once
#include "../../Core/ECS/World.hpp"
#include "../../Core/ECS/Entity.hpp"
#include "../../Core/ECS/System.hpp"
#include "../../Core/ResourceManager.hpp"
#include "../Utils/GameSettings.hpp"

namespace Factory
{
    Entity& createPlayer(World& world,
        const GameSettings& settings,
        ResourceManager& resourceManager);

    void createAsteroids(World& world,
        const GameSettings& settings,
        ResourceManager& resourceManager);
}