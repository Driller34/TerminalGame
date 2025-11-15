#include <memory>
#include <iostream>
#include "Game.hpp"

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    Game game(GameSettings{Width{100}, 
        Height{80}, 
        Position{42, 70}, 
        HP{100}, HP{50}, HP{10}, 10ULL, 
        std::chrono::milliseconds(500),
        FinishPoint{90}, 
        SpawnRange{10, 90}, 
        SpawnRange{10, 100}
    });

    game.run();
    
    return 0;
}
