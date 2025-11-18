#include <iostream>
#include <termios.h>
#include "../Utils/InputHandler.hpp"

void printMode()
{
    termios settings;
    tcgetattr(STDIN_FILENO, &settings);

    std::cout<<"ICANON="<<((settings.c_lflag & ICANON) ? 1 : 0)<<std::endl;
    std::cout<<"ECHO="<<((settings.c_lflag & ECHO)   ? 1 : 0)<<std::endl;
}

void f()
{
    std::cout << "INPUT" << std::endl;

    InputHandler handler;

    while(true)
    {
        const std::optional<char> c = handler.getKey();

        if(c)
        {
            std::cout << c.value() << std::endl;
            if(c.value() == 'e'){ return; }
        }
    }
}

int main()
{
    //InputHandler handler;

    f();

    //auto c = handler.getKey();

    printMode();

    std::cout << "Podaj a: " << std::endl;
    int a;
    std::cin >> a;
    std::cout << a << std::endl;

    return 0;
}
