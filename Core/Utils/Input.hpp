#pragma once

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <optional>

namespace Input
{
    inline std::optional<char> getKey()
    {
        termios oldSettings;
        termios newSettings;

        tcgetattr(STDIN_FILENO, &oldSettings);
        newSettings = oldSettings;
        newSettings.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

        int flags = fcntl(STDIN_FILENO, F_GETFL);
        fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

        char buffor = 0;
        int n = read(STDIN_FILENO, &buffor, 1);

        tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
        fcntl(STDIN_FILENO, F_SETFL, flags);

        if(n > 0){ return buffor; }
        else{ return std::nullopt; }
    }
}
