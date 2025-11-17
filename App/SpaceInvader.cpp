#include "SpaceInvader.hpp"

SpaceInvader::SpaceInvader(ResourceManager& resourceManager,
    const GameSettings& settings)
    : mResourceManager(resourceManager),
    mGameSettings(settings),
    mIsGameOver(false),
    mPlayerID(Factory::createPlayer(mWorld, mGameSettings, resourceManager)),
    mHpBar(100, 2, mGameSettings.fullPlayerHp)
{
    srand(time(NULL));
    Factory::createAsteroids(mWorld, mGameSettings, resourceManager);

}

void SpaceInvader::update()
{
    if(mIsGameOver){ return; }

    ecs_system::move(mWorld);

    if(mWorld.getEntity(mPlayerID).hp <= 0)
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
}

void SpaceInvader::moveUp()
{
    mWorld.getEntity(mPlayerID).moveOffset += {0, -1};
}

void SpaceInvader::moveDown()
{
    mWorld.getEntity(mPlayerID).moveOffset += {0, 1};
}

void SpaceInvader::moveLeft()
{
    mWorld.getEntity(mPlayerID).moveOffset += {-1, 0};
}

void SpaceInvader::moveRight()
{
    mWorld.getEntity(mPlayerID).moveOffset += {1, 0};
}

void SpaceInvader::gameOver()
{
    mIsGameOver = true;
}