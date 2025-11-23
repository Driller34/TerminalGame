#include "CollisionSystem.hpp"

namespace ecs_system
{

void collisionBulletAsteroid(World& world)
{
    for(Bullet& bullet : world.bullets)
    {
        if(!bullet.isActive){ continue; }

        for(Asteroid& asteroid : world.asteroids)
        {
            if(!asteroid.isActive){ continue; }
            if(!collision::isColliding(&bullet, &asteroid)){ continue; }

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
        if(!collision::isColliding(&world.player, &asteroid)){ continue; }

        asteroid.isActive = false;
        world.player.hp -= settings.hpWhenCollision;
    }
}

}