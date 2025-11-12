#include "Mob.hpp"

Mob::Mob(const Image& image)
    : Sprite(image, Vec2i{0,0}),
    mMoveOffset({0, 0}),
    mHp(0ULL)
{}

void Mob::update()
{
    move(getMoveOffset());
}

void Mob::setMoveOffset(const Vec2i& offset)
{
    mMoveOffset = offset;
}

Vec2i Mob::getMoveOffset() const
{
    return mMoveOffset;
}

void Mob::setHp(const size_t hp)
{
    mHp = hp;
}

size_t Mob::getHp() const
{
    return mHp;
}