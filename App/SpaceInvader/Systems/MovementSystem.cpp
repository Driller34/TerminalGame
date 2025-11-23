#include "MovementSystem.hpp"

namespace ecs_system
{

void move(World& world)
{
    world.forEach([&](Entity* entity){
        if(entity->isActive)
        {
            entity->position += entity->moveOffset;
            entity->moveOffset = {0, 0};
        }
    });
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
        asteroid.moveOffset = {0, 1};
    }
}

void moveBullets(World& world,
    const GameSettings& settings)
{
    for(Bullet& bullet : world.bullets)
    {
        if(!bullet.isActive){ continue; }
        bullet.moveOffset = {0, -1};
    }
}

}