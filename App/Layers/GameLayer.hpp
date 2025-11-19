#pragma once
#include <filesystem>
#include <cstdlib>
#include <chrono>
#include <memory>
#include "../Factory/MenuFactory.hpp"
#include "../Utils/GameSettings.hpp"
#include "../Core/Graphic/Window.hpp"
#include "../Core/ResourceManager.hpp"
#include "../Core/Utils/Vec.hpp"
#include "../Core/Utils/Color.hpp"
#include "../Core/Utils/Clock.hpp"
#include "../Core/Layers/LayerManager.hpp"
#include "../Core/Layers/Layer.hpp"
#include "../SpaceInvader/SpaceInvader.hpp"

class GameLayer : public Layer
{
public:
    GameLayer(LayerManager& layerManager,
        ResourceManager& resourceManager,
        const GameSettings& settings);

    virtual void init() override;
    virtual void update() override;
    virtual void draw(Window& window) override;
    virtual void activateState() override;
    virtual void inputHandler(const char pressedKey) override;

private:
    LayerManager& mLayerManager;
    ResourceManager& mResourceManager;
    GameSettings mGameSettings;
    SpaceInvader mSpaceInvader;
};