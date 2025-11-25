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

void initBullet(World& world,
    const GameSettings& settings)
{
    for(Bullet& bullet : world.bullets)
    {
        if(bullet.isActive){ continue; }

        const Vec2i playerSize = world.player.sprite.getSize();
            
        bullet.position = world.player.position;
        bullet.position.x += (playerSize.x / 2 - 1);
        bullet.isActive = true;

        return;
    }

    world.bullets.push_back(factory::createBullet(world, settings));
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