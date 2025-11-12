#pragma once
#include "../../Core/Utils/Vec.hpp"
#include "../../Core/Graphic/Sprite.hpp"
#include "../../Core/Graphic/Image.hpp"

class Mob : public Sprite
{
public:
    virtual ~Mob() = default;

    Mob(const Image& image);

    void update();

    void setMoveOffset(const Vec2i& offset);
    
    Vec2i getMoveOffset() const;

    void setHp(const size_t hp);

    size_t getHp() const;

private:
    Vec2i mMoveOffset;
    size_t mHp;
};