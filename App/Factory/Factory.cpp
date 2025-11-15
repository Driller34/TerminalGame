#include "Factory.hpp"

namespace Factory
{
    std::unique_ptr<MenuLayer> makeMenu(LayerManager& layerManager,
        ResourceManager& resourceManager,
        const GameSettings& gameSettings)
    {
        auto menuLayer = std::make_unique<MenuLayer>(layerManager, 
            resourceManager.getImage("Images/MenuBackground.bmp"),
            Vec2i{35, 35});

        menuLayer->addOption(MenuOption{
            resourceManager.getImage("Images/start.bmp"),
            Color{0, 255, 0, 255},
            [&](){
                return layerManager.push(std::make_unique<GameLayer>(layerManager, 
                    resourceManager, 
                    gameSettings));
        }});

        menuLayer->addOption(MenuOption{
            resourceManager.getImage("Images/exit.bmp"),
            Color{0, 255, 0, 255},
            [&](){
                return layerManager.pop();
        }});

        return menuLayer;
    }
}
