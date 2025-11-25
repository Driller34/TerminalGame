#include "EntityFactory.hpp"

namespace factory
{
    Player createPlayer(World& world,
        const GameSettings& settings,
        ResourceManager& resourceManager)
    {
        Player player(EntityType::PLAYER,
            resourceManager.getImage("Images/spaceship.bmp"));
        
        player.position = settings.playerStartPosition;
        player.moveOffset = {0, 0};
        player.hp = settings.fullPlayerHp;
        player.isActive = true;

        return player;
    }

    void createAsteroids(World& world,
        const GameSettings& settings,
        ResourceManager& resourceManager)
    {
        for(size_t i = 0; i < settings.numAsteroids; i++)
        {
            world.asteroids.emplace_back(EntityType::AI,
                resourceManager.getImage("Images/asteroid.bmp"));
        }
    }

    Bullet createBullet(World& world,
        const GameSettings& settings)
    {
        Bullet bullet(EntityType::AI, Image(settings.bulletWidth, 
            settings.bulletHeight, Color{255, 0, 0, 255}));

        return bullet;
    }
}