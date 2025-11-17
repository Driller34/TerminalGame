#pragma once
#include <vector>
#include "Entity.hpp"
#include "../Graphic/Sprite.hpp"
#include "../Utils/Vec.hpp"

using EntityId = size_t;

class World
{
public:
    World();

    Entity& create(const EntityType type,
        const Sprite& sprite);

    std::vector<Entity>& getEntities();

    Entity& getEntity(const EntityId id);

    const Entity& getEntity(const EntityId id) const;

private:
    std::vector<Entity> mEntities;
};
