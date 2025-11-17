#include "World.hpp"

World::World()
{}

EntityID World::create(const EntityType type,
        const Sprite& sprite)
{
    mEntities.push_back(Entity(type, sprite));
    return mEntities.size() - 1;
}

std::vector<Entity>& World::getEntities()
{
    return mEntities;
}

Entity& World::getEntity(const EntityID id)
{
    return mEntities[id];
}

const Entity& World::getEntity(const EntityID id) const
{
    return mEntities[id];
}