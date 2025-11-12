#include "Factory.hpp"

namespace Factory
{
    std::unique_ptr<MenuLayer> makeMenu(LayerManager& layerManager,
        ResourceManager& resourceManager)
    {
        auto menuLayer = std::make_unique<MenuLayer>(layerManager, Vec2i{5, 10});
        
        auto startImage = resourceManager.getImage("Resources/Images/start.bmp");
        auto exitImage = resourceManager.getImage("Resources/Images/exit.bmp");

        menuLayer->addOption(MenuOption{
            startImage,
            Image(startImage.width, startImage.height, {255, 0, 0, 255}),
            [&](LayerManager& layerManager){
                return layerManager.push(std::make_unique<GameLayer>(layerManager, resourceManager));
        }});

        menuLayer->addOption(MenuOption{
            exitImage,
            Image(exitImage.width, exitImage.height, {255, 0, 0, 255}),
            [](LayerManager& layerManager){
                return layerManager.pop();
        }});

        return menuLayer;
    }
}
