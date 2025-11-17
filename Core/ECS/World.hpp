#pragma once
#include <vector>
#include "Entity.hpp"
#include "../Graphic/Sprite.hpp"
#include "../Utils/Vec.hpp"

using EntityID = size_t;

class World
{
public:
    World();

    EntityID create(const EntityType type,
        const Sprite& sprite);

    std::vector<Entity>& getEntities();

    Entity& getEntity(const EntityID id);

    const Entity& getEntity(const EntityID id) const;

private:
    std::vector<Entity> mEntities;
};
