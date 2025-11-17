#include "SpaceInvader.hpp"

SpaceInvader::SpaceInvader(ResourceManager& resourceManager,
    const GameSettings& settings)
    : mResourceManager(resourceManager),
    mGameSettings(settings),
    mIsGameOver(false),
    mPlayer(Factory::createPlayer(mWorld, mGameSettings, resourceManager)),
    mHpBar(100, 2, mGameSettings.fullPlayerHp)
{
    srand(time(NULL));
    Factory::createAsteroids(mWorld, mGameSettings, resourceManager);

}

void SpaceInvader::update()
{
    if(mIsGameOver){ return; }

    ecs_system::move(mWorld);

    if(mPlayer.hp <= 0)
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
    mPlayer.moveOffset += {0, -1};
}

void SpaceInvader::moveDown()
{
    mPlayer.moveOffset += {0, 1};
}

void SpaceInvader::moveLeft()
{
    mPlayer.moveOffset += {-1, 0};
}

void SpaceInvader::moveRight()
{
    mPlayer.moveOffset += {1, 0};
}

void SpaceInvader::gameOver()
{
    mIsGameOver = true;
}