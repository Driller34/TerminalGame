#include <memory>
#include <iostream>
#include "Game.hpp"

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    Game game(100ULL, 80ULL);

    game.run();
    
    return 0;
}
