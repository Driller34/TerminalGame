#pragma once
#include "Entity.hpp"
#include "../../../Core/Graphic/Image.hpp"
#include "../../../Core/Graphic/Sprite.hpp"
#include "../../../Core/Utils/Vec.hpp"

class Player : public Entity
{
public:
    Player(const Image& spriteImage,
        const Vec2i& position,
        const Vec2i& moveOffset,
        const size_t hp,
        const bool isActive);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};