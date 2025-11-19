#pragma once
#include <optional>

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>

#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

class InputHandler
{
public:
    InputHandler();
    ~InputHandler();

    std::optional<char> getKey();

private:
#ifdef _WIN32
    void enableRawMode();
    void disableRawMode();

    bool mIsRawModeEnabled{false};
    HANDLE mInputHandle{nullptr};
    DWORD mSavedConsoleMode{0};
#endif
#ifndef _WIN32
    void enableRawMode();
    void disableRawMode();

    termios makeRaw(const termios& current) const;
    void applyTerminalSettings(const termios& settings);
#endif

private:
#ifndef _WIN32
    static bool sIsRawModeEnabled;

    termios mSavedTerminal;
#endif
};
