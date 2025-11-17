#include "EntityFactory.hpp"

namespace Factory
{
    Entity& createPlayer(World& world,
        const GameSettings& settings,
        ResourceManager& resourceManager)
    {
        Entity& entity = world.create(EntityType::PLAYER,
            Sprite(resourceManager.getImage("Images/spaceship.bmp"), {0, 0}));
        
        entity.position = settings.playerStartPosition;
        entity.hp = settings.fullPlayerHp;

        return entity;
    }

    void createAsteroids(World& world,
        const GameSettings& settings,
        ResourceManager& resourceManager)
    {
        for(size_t i = 0; i < settings.numAsteroids; i++)
        {
            Entity& asteroid = world.create(EntityType::ASTEROID,
                Sprite(resourceManager.getImage("Images/asteroid.bmp"), {0, 0}));

            
        }
    }
}