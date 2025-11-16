#pragma once
#include <filesystem>
#include "../Utils/GameSettings.hpp"
#include "../Layers/GameLayer.hpp"
#include "../../Core/Layers/LayerManager.hpp"
#include "../../Core/Layers/MenuLayer.hpp"
#include "../../Core/ResourceManager.hpp"
#include "../../Core/Graphic/Image.hpp"
#include "../../Core/Utils/Color.hpp"
#include "../../Core/Utils/Vec.hpp"

namespace Factory
{
    std::unique_ptr<MenuLayer> makeMenu(LayerManager& layerManager,
        ResourceManager& resourceManager,
        const GameSettings& gameSettings);
}