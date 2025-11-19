#pragma once
#include <filesystem>
#include "GameSettingsFactory.hpp"
#include "../Utils/GameSettings.hpp"
#include "../Layers/GameLayer.hpp"
#include "../../Core/Layers/LayerManager.hpp"
#include "../../Core/Layers/MenuLayer.hpp"
#include "../../Core/ResourceManager.hpp"
#include "../../Core/Graphic/Image.hpp"
#include "../../Core/Utils/Color.hpp"
#include "../../Core/Utils/Vec.hpp"

namespace factory
{
std::unique_ptr<MenuLayer> createMenu(LayerManager& layerManager,
    ResourceManager& resourceManager);

std::unique_ptr<MenuLayer> createDifficultMenu(LayerManager& layerManager,
    ResourceManager& resourceManager);

std::unique_ptr<MenuLayer> createPauseMenu(LayerManager& layerManager,
    ResourceManager& resourceManager);
}