#include "System.hpp"

namespace ecs_system
{
    
void collision(World& world)
{

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

    for(Entity& entity : world.getEntities())
    {
        if(entity.isActive 
           && entity.type == EntityType::ASTEROID)
        { 
            entity.moveOffset = {0, 1}; 
        }
    }
}

void asteroidFinish(World& world, 
    const GameSettings& settings,
    const EntityID playerID)
{
    for(Entity& entity : world.getEntities())
    {
        if(entity.isActive 
           && entity.type == EntityType::ASTEROID
           && entity.position.y >= settings.asteroidFinishPoint)
        {
            entity.isActive = false;
            world.getEntity(playerID).hp -= settings.hpWhenAsteridFinish;
        }
    }
}    

void initAsteroids(World& world,
    const GameSettings& settings)
{
    for(Entity& entity : world.getEntities())
    {
        if(!entity.isActive 
           && entity.type == EntityType::ASTEROID)
        {
            entity.position.x = rng::randomInt(settings.spawnXRange);
            entity.position.y = rng::randomInt(settings.spawnYRange);
            entity.isActive = true;
        }
    }   
}

}