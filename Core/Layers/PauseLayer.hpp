#pragma once
#include "Layer.hpp"
#include "LayerManager.hpp"
#include "../ResourceManager.hpp"

class PauseLayer : public Layer
{
public:
    PauseLayer(LayerManager& layerManager,
        ResourceManager& resourceManager);

    virtual void init() override;

    virtual void update() override;

    virtual void draw(Window& window) override;

    virtual void activateState() override;

    virtual void inputHandler(const char pressedKey) override;

private:
    LayerManager& mLayerManager;
    ResourceManager& mResourceManager;
};