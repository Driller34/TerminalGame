#include <memory>
#include "Game.hpp"

int main()
{
    Game game({100, 80, {42, 70}, 
        100, 50, 10, 10, 
        std::chrono::milliseconds(500),
        90, {10, 90}, {10, 100}});
    game.run();
    
    return 0;
}
