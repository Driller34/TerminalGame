#pragma once
#include <filesystem>
#include "Factory/Factory.hpp"
#include "Utils/GameSettings.hpp"
#include "../Core/Graphic/Window.hpp"
#include "../Core/ResourceManager.hpp"
#include "../Core/Utils/Vec.hpp"
#include "../Core/Utils/Input.hpp"
#include "../Core/Layers/LayerManager.hpp"
#include "../Core/Layers/Layer.hpp"

class Game
{
public:
    Game(const size_t width,
        const size_t height);

    void run();

private:
    void update();
    void render();
    void inputHandler();

private:
    Window mWindow;
    LayerManager mLayerManager;
    ResourceManager mResourceManager;
};