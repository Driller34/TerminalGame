#pragma once
#include <chrono>
#include "../Utils/GameSettings.hpp"
#include "../../Core/Utils/Vec.hpp"

namespace factory
{
    GameSettings createEasySettings();
    GameSettings createMediumSettings();
    GameSettings createHardSettings();
}