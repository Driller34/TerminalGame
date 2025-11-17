#pragma once
#include "..//Utils/Vec.hpp"
#include "../Graphic/Sprite.hpp"
#include "../Graphic/Window.hpp"
#include "World.hpp"

namespace ecs_system
{
void render(World& world, 
    Window& renderTarget);

void move(World& world);
}
