#include "EntityFactory.hpp"

namespace factory
{
    Player createPlayer(World& world,
        const GameSettings& settings,
        ResourceManager& resourceManager)
    {
        return Player(resourceManager.getImage("Images/spaceship.bmp"),
            settings.playerStartPosition,
            {0, 0},
            settings.fullPlayerHp,
            true
        );
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
        Bullet bullet(EntityType::AI, Image(1, 1, Color{255, 0, 0, 255}));
        bullet.position = world.player.position;
        bullet.isActive = true;

        return bullet;
    }
}