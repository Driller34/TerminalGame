#include "Collision.hpp"

namespace collision
{
bool isPointInRect(const Vec2i& point,
    const Vec2i& topLeft,
    const Vec2i& bottomRight)
{
    return  point.x >= topLeft.x  &&
            point.y >= topLeft.y  &&
            point.x <= bottomRight.x &&
            point.y <= bottomRight.y;
}

bool isEntityInRect(const Entity* a,
    const Vec2i& topLeft,
    const Vec2i& bottomRight)
{
    Vec2i sizeA = a->sprite.getSize();

    return isPointInRect(a->position, topLeft, bottomRight) 
        && isPointInRect((a->position + sizeA), topLeft, bottomRight);
}

bool isColliding(const Entity* a, 
    const Entity* b)
{
    const Vec2i sizeA = a->sprite.getSize();
    const Vec2i sizeB = b->sprite.getSize(); 
    
    return (a->position.x < b->position.x + sizeB.x &&
            a->position.x + sizeA.x > b->position.x &&
            a->position.y < b->position.y + sizeB.y &&
            a->position.y + sizeA.y > b->position.y);
}
}