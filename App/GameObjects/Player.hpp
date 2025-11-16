#pragma once
#include "../Utils/GameSettings.hpp"
#include "../../Core/Utils/Vec.hpp"
#include "Mob.hpp"

class Player : public Mob
{
public:
    virtual ~Player() = default;

    Player(const Image& image,
        const GameSettings& settings);
    
    void update();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRigth();

private:
    GameSettings mGameSettings;
};