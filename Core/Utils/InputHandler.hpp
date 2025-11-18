#pragma once
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <optional>

class InputHandler
{
public:
    InputHandler();
    ~InputHandler();

    std::optional<char> getKey();

private:
    void enableRawMode();
    void disableRawMode();

    termios makeRaw(const termios& current) const;
    void applyTerminalSettings(const termios& settings);

private:
    static bool sIsRawModeEnabled;

    termios mSavedTerminal;
    int mSavedFlags;
};
