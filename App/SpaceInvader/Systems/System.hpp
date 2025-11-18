#pragma once
#include "../World.hpp"
#include "../Entities/Player.hpp"
#include "../../Utils/GameSettings.hpp"
#include "../../../Core/Graphic/Window.hpp"
#include "../../../Core/Utils/Vec.hpp"
#include "../../../Core/Graphic/Sprite.hpp"
#include "../../../Core/Utils/RNG.hpp"
#include "../../../Core/Utils/Clock.hpp"

namespace ecs_system
{
void render(World& world, 
    Window& renderTarget);

void move(World& world);

void moveAsteroids(World& world,
    const GameSettings& settings);

void asteroidFinish(World& world, 
    const GameSettings& settings);

void initAsteroids(World& world,
    const GameSettings& settings);

void moveBullets(World& world,
    const GameSettings& settings);

void bulletFinish(World& world,
    const GameSettings& settings);

void collisionBulletAsteroid(World& world);

void collisionPlayerAsteroid(World& world,
    const GameSettings& settings);

bool isColliding(const Entity* a, 
    const Entity* b);
}