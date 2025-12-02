#include "RNG.hpp"

namespace rng
{


int randomInt(const Vec2i& range)
{
    srand(time(NULL));
    
    const int minVal = std::min(range.x, range.y);
    const int maxVal = std::max(range.x, range.y);

    const int span = maxVal - minVal + 1;

    return minVal + rand() % span;
}

}