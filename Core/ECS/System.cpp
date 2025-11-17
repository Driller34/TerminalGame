#include "System.hpp"

namespace ecs_system
{
void render(World& world, 
    Window& renderTarget)
{
    for(Entity& entity : world.getEntities())
    {
        renderTarget.draw(entity.sprite, entity.position);
    }
}

void move(World& world)
{
    for(Entity& entity : world.getEntities())
    {
        entity.position += entity.moveOffset;
        entity.moveOffset = {0, 0};
    }
}
}