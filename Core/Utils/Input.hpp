#pragma once

#include <termios.h>
#include <unistd.h>


namespace Input
{
    char getKey() 
    {
        char buf = 0;
        struct termios old = {0};
        tcgetattr(STDIN_FILENO, &old);
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &old);
        read(STDIN_FILENO, &buf, 1);
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        tcsetattr(STDIN_FILENO, TCSADRAIN, &old);
        return buf;
    }
}