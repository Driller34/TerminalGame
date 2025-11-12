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
        
        auto startImage = resourceManager.getImage("Images/start.bmp");
        auto exitImage = resourceManager.getImage("Images/exit.bmp");

        menuLayer->addOption(MenuOption{
            startImage,
            Image(startImage.width, startImage.height, {0, 255, 0, 255}),
            [&](LayerManager& layerManager){
                return layerManager.push(std::make_unique<GameLayer>(layerManager, 
                    resourceManager, 
                    gameSettings));
        }});

        menuLayer->addOption(MenuOption{
            exitImage,
            Image(exitImage.width, exitImage.height, {0, 255, 0, 255}),
            [](LayerManager& layerManager){
                return layerManager.pop();
        }});

        return menuLayer;
    }
}
