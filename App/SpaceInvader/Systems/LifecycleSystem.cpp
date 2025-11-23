#include "LifecycleSystem.hpp"

namespace ecs_system
{
    
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

void bulletFinish(World& world,
    const GameSettings& settings)
{
    for(Bullet& bullet : world.bullets)
    {
        if(!bullet.isActive){ continue; }
        if(bullet.position.y <= settings.bulletFinishPoint)
        {
            bullet.isActive = false;
        }
    }
}

}