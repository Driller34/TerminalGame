#include "System.hpp"

namespace ecs_system
{
void render(World& world, 
    Window& renderTarget)
{
    world.forEach([&](Entity* entity){
        if(entity->isActive)
        {
            renderTarget.draw(entity->sprite, entity->position);
        }
    });
}

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

void asteroidFinish(World& world, 
    const GameSettings& settings)
{
    for(Asteroid& asteroid : world.asteroids)
    {
        if(!asteroid.isActive){ continue; }
        if(asteroid.position.y >= settings.asteroidFinishPoint)
        {
            asteroid.isActive = false;
            world.player.hp -= settings.hpWhenAsteridFinish;
        }
    }
}

void initAsteroids(World& world,
    const GameSettings& settings)
{
    for(Asteroid& asteroid : world.asteroids)
    {
        if(!asteroid.isActive)
        {
            asteroid.position.x = rng::randomInt(settings.spawnXRange);
            asteroid.position.y = rng::randomInt(settings.spawnYRange);
            asteroid.isActive = true;
        }
    }
}

}