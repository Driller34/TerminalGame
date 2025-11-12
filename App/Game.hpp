#pragma once
#include <filesystem>
#include "Factory/Factory.hpp"
#include "GameSettings.hpp"
#include "../Core/Graphic/Window.hpp"
#include "../Core/ResourceManager.hpp"
#include "../Core/Utils/Vec.hpp"
#include "../Core/Utils/Input.hpp"
#include "../Core/Layers/LayerManager.hpp"
#include "../Core/Layers/Layer.hpp"

class Game
{
public:
    Game(const GameSettings& settings);

    void run();

private:
    void update();
    void render();
    void inputHandler();

private:
    GameSettings mGameSettings;
    Window mWindow;
    LayerManager mLayerManager;
    ResourceManager mResourceManager;
};