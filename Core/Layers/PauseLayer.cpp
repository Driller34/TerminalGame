#include "PauseLayer.hpp"

PauseLayer::PauseLayer(LayerManager& layerManager,
        ResourceManager& resourceManager)
    : mLayerManager(layerManager),
    mResourceManager(resourceManager)
{}

void PauseLayer::init(){}
void PauseLayer::update(){}
void PauseLayer::activateState(){}

void PauseLayer::draw(Window& window)
{
    window.draw(mResourceManager.getImage("Images/pause.bmp"));
}

void PauseLayer::inputHandler(const char pressedKey)
{
    mLayerManager.pop();
}