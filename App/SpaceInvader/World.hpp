#pragma once
#include <vector>
#include "Entities/Player.hpp"

using Asteroid = Entity;
using Bullet = Entity;

struct World
{
    Player player;
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;

    template<typename Function>
    void forEach(Function func)
    {
        func(&player);

        for(Asteroid& asteroid : asteroids)
        {
            func(&asteroid);
        }

        for(Bullet& bullet : bullets)
        {
            func(&bullet);
        }
    }

    World(const Player& player)
        : player(player)
    {}
};