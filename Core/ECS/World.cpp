#include "World.hpp"

World::World()
{}

Entity& World::create(const EntityType type,
        const Sprite& sprite)
{
    mEntities.push_back(Entity(type, sprite));
    return mEntities.back();
}

std::vector<Entity>& World::getEntities()
{
    return mEntities;
}

Entity& World::getEntity(const EntityId id)
{
    return mEntities[id];
}

const Entity& World::getEntity(const EntityId id) const
{
    return mEntities[id];
}