#include "../Graphic/Window.hpp"
#include "../Utils/Color.hpp"
#include "../GUI/Rectangle.hpp"

int main()
{
    Window window(50ULL, 90ULL);

    gui::Rectangle rec(10, 10, Color{255, 0, 0, 255});

    window.draw(rec);

    window.display();
}