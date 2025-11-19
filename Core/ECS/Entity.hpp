#pragma once
#include "../Utils/Vec.hpp"
#include "../Graphic/Sprite.hpp"

enum class EntityType{ PLAYER, AI };

struct Entity
{
    EntityType type;
    Sprite sprite;
    Vec2i position;
    Vec2i moveOffset;
    size_t hp;
    bool isActive;

    Entity(const EntityType type,
        const Image& image)
        : type(type), 
        sprite(Sprite(image, {0, 0})),
        position({0, 0}),
        moveOffset({0, 0}),
        hp(100ULL),
        isActive(false)
    {}
};