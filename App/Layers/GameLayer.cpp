#include "GameLayer.hpp"

GameLayer::GameLayer(LayerManager& layerManager,
    ResourceManager& resourceManager)
    : mLayerManager(layerManager),
    mResourceManager(resourceManager),
    mPlayer(mResourceManager.getImage("Images/spaceship.bmp"))
{

}

void GameLayer::init()
{

}

void GameLayer::update()
{
    mPlayer.update();
}

void GameLayer::draw(Window& window)
{
    window.draw(mPlayer);
}

void GameLayer::activateState() 
{
    mPlayer.setPosition({42, 70});
}

void GameLayer::inputHandler(const char pressedKey)
{
    switch(pressedKey)
    {
        case 'w': mPlayer.move({0, -1}); break;
        case 's': mPlayer.moveDown(); break;
        case 'a': mPlayer.moveLeft(); break;
        case 'd': mPlayer.moveRigth(); break;
    }
}