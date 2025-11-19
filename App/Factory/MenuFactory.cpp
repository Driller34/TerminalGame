#include "MenuFactory.hpp"

namespace factory
{
    std::unique_ptr<MenuLayer> createMenu(LayerManager& layerManager,
        ResourceManager& resourceManager)
    {
        auto menuLayer = std::make_unique<MenuLayer>(layerManager, 
            resourceManager.getImage("Images/MenuBackground.bmp"),
            Vec2i{35, 35});

        menuLayer->addOption(MenuOption{
            resourceManager.getImage("Images/start.bmp"),
            Color{0, 255, 0, 255},
            [&](){
                layerManager.push(createDifficultMenu(layerManager, resourceManager));
        }});

        menuLayer->addOption(MenuOption{
            resourceManager.getImage("Images/exit.bmp"),
            Color{0, 255, 0, 255},
            [&](){
                layerManager.pop();
        }});

        return menuLayer;
    }

    std::unique_ptr<MenuLayer> createDifficultMenu(LayerManager& layerManager,
        ResourceManager& resourceManager)
    {
        auto menuLayer = std::make_unique<MenuLayer>(layerManager, 
            resourceManager.getImage("Images/menuDifficultBackground.bmp"),
            Vec2i{35, 25});

        menuLayer->addOption(MenuOption{
            resourceManager.getImage("Images/easyOption.bmp"),
            Color{0, 255, 0, 255},
            [&](){
                layerManager.push(std::make_unique<GameLayer>(layerManager, 
                    resourceManager,
                    factory::createEasySettings()
                ));
        }});

        menuLayer->addOption(MenuOption{
            resourceManager.getImage("Images/mediumOption.bmp"),
            Color{0, 255, 0, 255},
            [&](){
                layerManager.push(std::make_unique<GameLayer>(layerManager, 
                    resourceManager,
                    factory::createMediumSettings()
                ));
        }});

        menuLayer->addOption(MenuOption{
            resourceManager.getImage("Images/hardOption.bmp"),
            Color{0, 255, 0, 255},
            [&](){
                layerManager.push(std::make_unique<GameLayer>(layerManager, 
                    resourceManager,
                    factory::createHardSettings()
                ));
        }});

        menuLayer->addOption(MenuOption{
            resourceManager.getImage("Images/exit.bmp"),
            Color{0, 255, 0, 255},
            [&](){
                layerManager.pop();
        }});

        return menuLayer;
    }

    std::unique_ptr<MenuLayer> createPauseMenu(LayerManager& layerManager,
        ResourceManager& resourceManager)
    {
        auto menuLayer = std::make_unique<MenuLayer>(layerManager, 
            resourceManager.getImage("Images/pauseBackground.bmp"),
            Vec2i{35, 25});

        menuLayer->addOption(MenuOption{
            resourceManager.getImage("Images/resumeOption.bmp"),
            Color{0, 255, 0, 255},
            [&](){
                layerManager.pop();
        }});

        menuLayer->addOption(MenuOption{
            resourceManager.getImage("Images/exit.bmp"),
            Color{0, 255, 0, 255},
            [&](){
                layerManager.pop(3ULL);
        }});

        return menuLayer;
    }
}
