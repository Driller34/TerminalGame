#pragma once
#include "..//Utils/Vec.hpp"
#include "../Graphic/Sprite.hpp"

enum class EntityType
{
    PLAYER,
    ASTEROID,
    BULLET
};

struct Entity
{
    Entity(const EntityType type,
        const Sprite& sprite)
        : type(type),
        sprite(sprite),
        position({0, 0}),
        moveOffset({0, 0}),
        hp(100ULL),
        isActive(true)
    {}

    EntityType type;
    Sprite sprite;
    Vec2i position;
    Vec2i moveOffset;
    size_t hp;
    bool isActive;
};