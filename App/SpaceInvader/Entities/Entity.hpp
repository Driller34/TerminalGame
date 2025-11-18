#pragma once
#include "../../../Core/Utils/Vec.hpp"
#include "../../../Core/Graphic/Sprite.hpp"

struct Entity
{
    Sprite sprite;
    Vec2i position;
    Vec2i moveOffset;
    size_t hp;
    bool isActive;

    Entity(const Image& image)
        : sprite(Sprite(image, {0, 0})),
        position({0, 0}),
        moveOffset({0, 0}),
        hp(100ULL),
        isActive(false)
    {}
};