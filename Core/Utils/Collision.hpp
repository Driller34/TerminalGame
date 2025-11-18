#pragma once
#include "../Graphic/Shape.hpp"

namespace collision
{
bool inBounds(const Vec2i& position, 
    const Vec2i& first,
    const Vec2i& last);
}