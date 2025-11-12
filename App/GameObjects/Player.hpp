#pragma once
#include "../../Core/Utils/Vec.hpp"
#include "Mob.hpp"

class Player : public Mob
{
public:
    virtual ~Player() = default;

    Player(const Image& image);
    
    void update();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRigth();
};