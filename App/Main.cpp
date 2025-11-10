#include <iostream>
#include "../Core/Window.hpp"

int main()
{
    Window window(50ULL, 90ULL);

    Image sprite(4, 4);

    sprite.setImage({
        {{0, 255, 0}, {0, 200, 0}, {0, 155, 0}, {0, 100, 0}},
        {{0, 255, 0}, {0, 200, 0}, {0, 155, 0}, {0, 100, 0}},
        {{0, 255, 0}, {0, 200, 0}, {0, 155, 0}, {0, 100, 0}},
        {{0, 255, 0}, {0, 200, 0}, {0, 155, 0}, {0, 100, 0}}
    });

    window.draw(sprite, {10, 10});

    Image img(2, 4, {0, 255, 0});

    window.draw(img, {5, 5});

    window.setPoint({0, 0}, {0, 0, 0});

    window.display();
    
    return 0;
}