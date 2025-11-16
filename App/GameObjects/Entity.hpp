#pragma once
#include "../../Core/Utils/Vec.hpp"
#include "../../Core/Graphic/Sprite.hpp"

enum class EntityType{
    PLAYER,
    ASTEROID,
    BULLET
};

struct Entity
{
    EntityType type;
    Sprite sprite;
    Vec2i position;
    Vec2i moveOffset;
    size_t hp;
}