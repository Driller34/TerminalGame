#pragma once
#include <filesystem>
#include <cstdlib>
#include <chrono>
#include <memory>
#include "GameObjects/Player.hpp"
#include "../Core/Graphic/Window.hpp"
#include "../Core/ResourceManager.hpp"
#include "../Core/Utils/Vec.hpp"
#include "../Core/Utils/Input.hpp"
#include "../Core/Utils/Color.hpp"
#include "../Core/Utils/Clock.hpp"
#include "../Core/Base/Drawable.hpp"
#include "Utils/GameSettings.hpp"

class SpaceInvader : public Drawable
{
public:
    SpaceInvader(ResourceManager& resourceManager,
        const GameSettings& settings);

    void update();
    virtual void draw(Window& renderTarger, 
        const Vec2i& position) override;
    bool isGameOver() const;
    
    void fire();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

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
    ResourceManager& mResourceManager;
    GameSettings mGameSettings;
    bool mIsGameOver;

    Player mPlayer;
    std::vector<Mob> mAsteroids;
    std::vector<Mob> mBullets;
    Clock mAsteroidsClock;
};