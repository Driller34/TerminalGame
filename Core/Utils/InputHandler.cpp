#include "InputHandler.hpp"

bool InputHandler::sIsRawModeEnabled = false;

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
    disableRawMode();
}

std::optional<char> InputHandler::getKey()
{
    if(!sIsRawModeEnabled){ enableRawMode(); }

    char buffer = 0;
    const int n = read(STDIN_FILENO, &buffer, 1);

    if(n > 0){ return buffer; }

    return std::nullopt;
}

void InputHandler::enableRawMode()
{
    sIsRawModeEnabled = true;

    tcgetattr(STDIN_FILENO, &mSavedTerminal);
    mSavedFlags = fcntl(STDIN_FILENO, F_GETFL);

    termios raw = makeRaw(mSavedTerminal);
    applyTerminalSettings(raw);

    fcntl(STDIN_FILENO, F_SETFL, mSavedFlags | O_NONBLOCK);
}

void InputHandler::disableRawMode()
{
    if(!sIsRawModeEnabled){ return; }

    sIsRawModeEnabled = false;

    applyTerminalSettings(mSavedTerminal);
    fcntl(STDIN_FILENO, F_SETFL, mSavedFlags);
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
