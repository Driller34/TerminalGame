#include <iostream>
#include "../Utils/Input.hpp"


int main() 
{
    char c;
    while(true) 
    {
        auto c = Input::getKey();
        if(c) 
        {
            std::cout << "Key: " << c.value() << std::endl;
        }
        else
        {
            std::cout<<"No press"<<std::endl;
        }
        usleep(10000);
    }
    return 0;
}
