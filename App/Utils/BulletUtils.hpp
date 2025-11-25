#pragma once
#include "../SpaceInvader/World.hpp"
#include "../../Core/Utils/Vec.hpp"
#include "../../Core/Graphic/Sprite.hpp"

namespace bullet_utils
{

inline void activateBullet(Bullet& bullet,
    const Player& player)
{
    const Vec2i playerSize = player.sprite.getSize();
            
    bullet.position = player.position;
    bullet.position.x += (playerSize.x / 2 - 1);
    bullet.isActive = true;
}

}