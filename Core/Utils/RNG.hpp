#pragma once
#include <random>
#include <ctime>
#include "Vec.hpp"

namespace rng
{
static auto _seed = [](){
    std::srand(std::time(nullptr));
    return 0;
}();

int randomInt(const Vec2i& range);

}