#include "GameLayer.hpp"

GameLayer::GameLayer(LayerManager& layerManager,
    ResourceManager& resourceManager,
    const GameSettings& settings)
    : mLayerManager(layerManager),
    mResourceManager(resourceManager),
    mGameSettings(settings),
    mSpaceInvader(mResourceManager, mGameSettings)
{
    init();
}

void GameLayer::init()
{
    
}

void GameLayer::update()
{
    mSpaceInvader.update();
}

void GameLayer::draw(Window& window)
{
    window.draw(mSpaceInvader);
}

void GameLayer::activateState(){}

void GameLayer::inputHandler(const char pressedKey)
{
    switch(pressedKey)
    {
        case 'w': mSpaceInvader.moveUp(); break;
        case 's': mSpaceInvader.moveDown(); break;
        case 'a': mSpaceInvader.moveLeft(); break;
        case 'd': mSpaceInvader.moveRight(); break;
        case ' ': mSpaceInvader.fire(); break;
        case 27: {
            if(!mSpaceInvader.isGameOver())
            {
                mLayerManager.push(
                    factory::createPauseMenu(mLayerManager, mResourceManager));
            }
            else{ mLayerManager.pop(); }

            break;
        }
    }
}