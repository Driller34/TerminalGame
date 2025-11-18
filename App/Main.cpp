#include <memory>
#include <iostream>
#include <termios.h>
#include "Game.hpp"
#include "../Core/Utils/Input.hpp"

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    termios s = Input::setNewSettings();
    
    Game game(100ULL, 80ULL);

    game.run();

    Input::restoreSettings(s);
    
    return 0;
}
