#pragma once
#include <filesystem>
#include "../Layers/GameLayer.hpp"
#include "../../Core/Layers/LayerManager.hpp"
#include "../../Core/Layers/MenuLayer.hpp"
#include "../../Core/ResourceManager.hpp"
#include "../../Core/Graphic/Image.hpp"
#include "../../Core/Utils/Color.hpp"

namespace Factory
{
    std::unique_ptr<MenuLayer> makeMenu(LayerManager& layerManager,
        ResourceManager& resourceManager);
}