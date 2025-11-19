#pragma once
#include <filesystem>
#include <cstdlib>
#include <chrono>
#include <memory>
#include "../../Core/Graphic/Window.hpp"
#include "../../Core/ResourceManager.hpp"
#include "../../Core/Utils/Vec.hpp"
#include "../../Core/Utils/Color.hpp"
#include "../../Core/Utils/Clock.hpp"
#include "../../Core/Base/Drawable.hpp"
#include "../../Core/GUI/ProgressBar.hpp"
#include "World.hpp"
#include "../../Core/ECS/Entity.hpp"
#include "Systems/System.hpp"
#include "../Utils/GameSettings.hpp"
#include "../Factory/EntityFactory.hpp"

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
    void gameOver();

private:
    ResourceManager& mResourceManager;
    GameSettings mGameSettings;
    bool mIsGameOver;

    World mWorld;
    gui::ProgressBar mHpBar;
};