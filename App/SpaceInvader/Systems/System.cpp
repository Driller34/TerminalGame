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

void moveBullets(World& world,
    const GameSettings& settings)
{
    for(Bullet& bullet : world.bullets)
    {
        if(!bullet.isActive){ continue; }
        bullet.moveOffset = {0, -1};
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

void collisionBulletAsteroid(World& world)
{
    for(Bullet& bullet : world.bullets)
    {
        if(!bullet.isActive){ continue; }

        for(Asteroid& asteroid : world.asteroids)
        {
            if(!asteroid.isActive){ continue; }
            if(!isColliding(&bullet, &asteroid)){ continue; }

            bullet.isActive = false;
            asteroid.isActive = false;
        }
    }
}

void collisionPlayerAsteroid(World& world,
    const GameSettings& settings)
{
    for(Asteroid& asteroid : world.asteroids)
    {
        if(!world.player.isActive || !asteroid.isActive){ continue; }
        if(!isColliding(&world.player, &asteroid)){ continue; }

        asteroid.isActive = false;
        world.player.hp -= settings.hpWhenCollision;
    }
}

bool isColliding(const Entity* a, 
    const Entity* b)
{
    const Vec2i sizeA = a->sprite.getSize();
    const Vec2i sizeB = b->sprite.getSize(); 
    
    return (a->position.x < b->position.x + sizeB.x &&
            a->position.x + sizeA.x > b->position.x &&
            a->position.y < b->position.y + sizeB.y &&
            a->position.y + sizeA.y > b->position.y);
}

}