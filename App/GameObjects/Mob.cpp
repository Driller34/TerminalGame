#include "Mob.hpp"

Mob::Mob(const Image& image)
    : Sprite(image, Vec2i{0,0}),
    mMoveOffset({0, 0})
{}

void Mob::update()
{
    move(getMoveOffset());
    setMoveOffset({0, 0});
}

void Mob::setMoveOffset(const Vec2i& offset)
{
    mMoveOffset = offset;
}

Vec2i Mob::getMoveOffset() const
{
    return mMoveOffset;
}
