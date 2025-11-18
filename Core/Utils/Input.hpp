#pragma once
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <optional>

namespace Input
{
    inline termios setNewSettings()
    {
        termios oldSettings;
        termios newSettings;

        tcgetattr(STDIN_FILENO, &oldSettings);
        newSettings = oldSettings;
        newSettings.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

        return oldSettings;
    }

    inline void restoreSettings(termios& oldSettings)
    {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
    }

    inline std::optional<char> getKey()
    {
        termios oldSettings = setNewSettings();

        int flags = fcntl(STDIN_FILENO, F_GETFL);
        fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

        char buffor = 0;
        int n = read(STDIN_FILENO, &buffor, sizeof(buffor));

        fcntl(STDIN_FILENO, F_SETFL, flags);

        if(n > 0){ return buffor; }
        else{ return std::nullopt; }
    }
}
