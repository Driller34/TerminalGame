#pragma once
#include <filesystem>
#include "../GameObjects/Player.hpp"
#include "../Core/Graphic/Window.hpp"
#include "../Core/ResourceManager.hpp"
#include "../Core/Utils/Vec.hpp"
#include "../Core/Utils/Input.hpp"
#include "../Core/Utils/Color.hpp"
#include "../Core/Layers/LayerManager.hpp"
#include "../Core/Layers/Layer.hpp"

class GameLayer : public Layer
{
public:
    GameLayer(LayerManager& layerManager,
        ResourceManager& resourceManager);

    virtual void init() override;
    virtual void update() override;
    virtual void draw(Window& window) override;
    virtual void activateState() override;
    virtual void inputHandler(const char pressedKey) override;

private:
    LayerManager& mLayerManager;
    ResourceManager& mResourceManager;

    Player mPlayer;
};