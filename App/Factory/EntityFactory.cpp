#include "EntityFactory.hpp"

namespace Factory
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
            world.asteroids.emplace_back(resourceManager.getImage("Images/asteroid.bmp"));
        }
    }
}