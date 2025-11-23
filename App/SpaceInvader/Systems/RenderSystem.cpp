#include "RenderSystem.hpp"

namespace ecs_system
{

void render(World& world, 
    Window& renderTarget)
{
    world.forEach([&](Entity* entity){
        if(entity->isActive)
        {
            renderTarget.draw(entity->sprite, entity->position);
        }
    });
}

}