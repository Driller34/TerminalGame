#include "SpaceInvader.hpp"

SpaceInvader::SpaceInvader(ResourceManager& resourceManager,
    const GameSettings& settings)
    : mResourceManager(resourceManager),
    mGameSettings(settings),
    mIsGameOver(false),
    mWorld(Factory::createPlayer(mWorld, mGameSettings, mResourceManager)),
    mHpBar(100, 2, mGameSettings.fullPlayerHp)
{
    srand(time(NULL));
    Factory::createAsteroids(mWorld, mGameSettings, mResourceManager);
}

void SpaceInvader::update()
{
    if(mIsGameOver){ return; }

    ecs_system::initAsteroids(mWorld, mGameSettings);
    ecs_system::moveAsteroids(mWorld, mGameSettings);
    ecs_system::moveBullets(mWorld, mGameSettings);
    ecs_system::bulletFinish(mWorld, mGameSettings);
    ecs_system::collisionBulletAsteroid(mWorld);
    ecs_system::collisionPlayerAsteroid(mWorld, mGameSettings);
    

    ecs_system::move(mWorld);
    ecs_system::asteroidFinish(mWorld, mGameSettings);

    mHpBar.setValue(mWorld.player.hp);

    if(mWorld.player.hp <= 0)
    {
        gameOver();
    }
}

void SpaceInvader::draw(Window& renderTarger, 
        const Vec2i& position)
{
    if(mIsGameOver)
    {
        renderTarger.draw(mResourceManager.getImage("Images/gameover.bmp"));
    }

    ecs_system::render(mWorld, renderTarger);

    renderTarger.draw(mHpBar);
}

bool SpaceInvader::isGameOver() const
{
    return mIsGameOver;
}

void SpaceInvader::fire()
{
    mWorld.bullets.push_back(Factory::createBullet(mWorld, mGameSettings));
}

void SpaceInvader::moveUp()
{
    mWorld.player.moveOffset += {0, -1};
}

void SpaceInvader::moveDown()
{
    mWorld.player.moveOffset += {0, 1};
}

void SpaceInvader::moveLeft()
{
    mWorld.player.moveOffset += {-1, 0};
}

void SpaceInvader::moveRight()
{
    mWorld.player.moveOffset += {1, 0};
}

void SpaceInvader::gameOver()
{
    mIsGameOver = true;
}