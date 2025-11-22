#include "InputHandler.hpp"

#ifndef _WIN32
    bool InputHandler::sIsRawModeEnabled = false;
#endif

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
#ifndef _WIN32
    disableRawMode();
#endif
}

#ifdef _WIN32
    std::optional<char> InputHandler::getKey()
    {
        if(_kbhit())
        {
            return _getch();
        }
        return std::nullopt;
    }

#else
    std::optional<char> InputHandler::getKey()
    {
        if(!sIsRawModeEnabled){ enableRawMode(); }

        const int flags = fcntl(STDIN_FILENO, F_GETFL);
        fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

        char buffer = 0;
        const int n = read(STDIN_FILENO, &buffer, 1);

        fcntl(STDIN_FILENO, F_SETFL, flags);

        if(n > 0){ return buffer; }

        return std::nullopt;
    }

    void InputHandler::enableRawMode()
    {
        sIsRawModeEnabled = true;

        tcgetattr(STDIN_FILENO, &mSavedTerminal);

        termios raw = makeRaw(mSavedTerminal);
        applyTerminalSettings(raw);
    }

    void InputHandler::disableRawMode()
    {
        if(!sIsRawModeEnabled){ return; }

        sIsRawModeEnabled = false;

        applyTerminalSettings(mSavedTerminal);
    }

    void InputHandler::applyTerminalSettings(const termios& settings)
    {
        tcsetattr(STDIN_FILENO, TCSANOW, &settings);
    }

    termios InputHandler::makeRaw(const termios& current) const
    {
        termios newSettings = current;
        
        newSettings.c_lflag &= ~(ICANON | ECHO);
        newSettings.c_cc[VMIN] = 0;
        newSettings.c_cc[VTIME] = 0;
        
        return newSettings;
    }
#endif