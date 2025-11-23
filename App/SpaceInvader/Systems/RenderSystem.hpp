#pragma once
#include "../World.hpp"
#include "../../Utils/GameSettings.hpp"
#include "../../../Core/Graphic/Window.hpp"
#include "../../../Core/Utils/Vec.hpp"
#include "../../../Core/Graphic/Sprite.hpp"

namespace ecs_system
{

void render(World& world, 
    Window& renderTarget);

}