#include "EntityFactory.hpp"

namespace Factory
{
    EntityID createPlayer(World& world,
        const GameSettings& settings,
        ResourceManager& resourceManager)
    {
        EntityID id = world.create(EntityType::PLAYER,
            Sprite(resourceManager.getImage("Images/spaceship.bmp"), {0, 0}));
        
        world.getEntity(id).position = settings.playerStartPosition;
        world.getEntity(id).hp = settings.fullPlayerHp;
        world.getEntity(id).isActive = true;

        return id;
    }

    void createAsteroids(World& world,
        const GameSettings& settings,
        ResourceManager& resourceManager)
    {
        for(size_t i = 0; i < settings.numAsteroids; i++)
        {
            EntityID id = world.create(EntityType::ASTEROID,
                Sprite(resourceManager.getImage("Images/asteroid.bmp"), {0, 0}));

            
        }
    }
}