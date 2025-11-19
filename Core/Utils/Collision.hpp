#pragma once
#include "../Graphic/Sprite.hpp"
#include "../ECS/Entity.hpp"

namespace collision
{
bool isPointInRect(const Vec2i& point,
    const Vec2i& topLeft,
    const Vec2i& bottomRight);

bool isColliding(const Entity* a, 
    const Entity* b);
}