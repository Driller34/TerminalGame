#include "../Graphic/Window.hpp"
#include "../Utils/Color.hpp"
#include "../GUI/Rectangle.hpp"
#include "../GUI/ProgressBar.hpp"

int main()
{
    Window window(50ULL, 90ULL);

    gui::Rectangle rec(10, 10, Color{255, 0, 0, 255});

    gui::ProgressBar bar(20ULL, 2ULL, 100);
    bar.setPosition({5, 5});
    bar.setValue(20);

    window.draw(rec, {20, 20});

    window.draw(bar, {10, 10});

    window.display();
}