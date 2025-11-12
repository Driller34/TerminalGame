#pragma once
#include <filesystem>
#include <cstdlib>
#include <chrono>
#include "../GameSettings.hpp"
#include "../GameObjects/Player.hpp"
#include "../Core/Graphic/Window.hpp"
#include "../Core/ResourceManager.hpp"
#include "../Core/Utils/Vec.hpp"
#include "../Core/Utils/Input.hpp"
#include "../Core/Utils/Color.hpp"
#include "../Core/Utils/Clock.hpp"
#include "../Core/Layers/LayerManager.hpp"
#include "../Core/Layers/Layer.hpp"

class GameLayer : public Layer
{
public:
    GameLayer(LayerManager& layerManager,
        ResourceManager& resourceManager,
        const GameSettings& settings);

    virtual void init() override;
    virtual void update() override;
    virtual void draw(Window& window) override;
    virtual void activateState() override;
    virtual void inputHandler(const char pressedKey) override;

private:
    
    void updateAsteroids();
    void updateBullets();

    int randomInt(const Vec2i& range);

    Vec2i randAsteroidPosition();
    void initAsteroids();
    void startAsteroid(Mob& asteroid);
    bool checkColision(const Mob& asteroid);
    bool checkColision(const Mob& a, 
    const Mob& b) const;
    bool checkAsteroidFinish(const Mob& asteroid);

    void makeBullet();

    void playerColision();
    void bulletColision();

    void gameOver();


private:
    LayerManager& mLayerManager;
    ResourceManager& mResourceManager;
    GameSettings mGameSettings;

    Player mPlayer;
    std::vector<Mob> mAsteroids;
    std::vector<Mob> mBullets;
    Clock mAsteroidsClock;
};