#include "MenuFactory.hpp"

namespace Factory
{
    std::unique_ptr<MenuLayer> makeMenu(LayerManager& layerManager,
        ResourceManager& resourceManager)
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

                    GameSettings{
                        Position{42, 70}, 
                        HP{100}, HP{50}, HP{10}, 10ULL, 
                        std::chrono::milliseconds(500),
                        FinishPoint{90}, 
                        SpawnRange{10, 90}, 
                        SpawnRange{10, 100}
                    }
            ));
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
