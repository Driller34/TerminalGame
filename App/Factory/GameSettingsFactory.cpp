#include "GameSettingsFactory.hpp"

namespace factory
{
GameSettings createEasySettings()
{
    return GameSettings{
        Position{42, 70},
        HP{100}, HP{50}, HP{10}, 10ULL,
        std::chrono::milliseconds(500),
        FinishPoint{90},
        FinishPoint{-1}, 
        Width{2},
        Height{2},
        SpawnRange{10, 80}, 
        SpawnRange{-10, -100}
    };
}

GameSettings createMediumSettings()
{
    return GameSettings{
        Position{42, 70},
        HP{100}, HP{50}, HP{10}, 10ULL,
        std::chrono::milliseconds(200),
        FinishPoint{90},
        FinishPoint{-1}, 
        Width{2},
        Height{2},
        SpawnRange{10, 80}, 
        SpawnRange{-10, -100}
    };
}

GameSettings createHardSettings()
{
    return GameSettings{
        Position{42, 70},
        HP{100}, HP{100}, HP{40}, 10ULL,
        std::chrono::milliseconds(200),
        FinishPoint{90},
        FinishPoint{-1}, 
        Width{1},
        Height{1},
        SpawnRange{10, 80}, 
        SpawnRange{-10, -100}
    };
}
}