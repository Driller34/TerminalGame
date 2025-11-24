#include "MovementSystem.hpp"

namespace ecs_system
{

void movePlayer(World& world)
{
    world.player.position += world.player.moveOffset;
    world.player.moveOffset = {0, 0};
}

void moveAsteroids(World& world,
    const GameSettings& settings)
{
    static Clock asteroidClock;
    
    if(asteroidClock.elapsedTime() < settings.asteroidsUpdateTimeout)
    {
        return;
    }

    asteroidClock.restart();

    for(Asteroid& asteroid : world.asteroids)
    {
        if(!asteroid.isActive){ continue; }
        asteroid.position += {0, 1};
    }
}

void moveBullets(World& world,
    const GameSettings& settings)
{
    for(Bullet& bullet : world.bullets)
    {
        if(!bullet.isActive){ continue; }
        bullet.position += {0, -1};
    }
}

}