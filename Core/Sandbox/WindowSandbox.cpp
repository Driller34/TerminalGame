#include "../Graphic/Window.hpp"
#include "../Graphic/Sprite.hpp"

int main()
{
    Window window(50ULL, 90ULL);

    std::vector<std::vector<Color>> b1(4, std::vector<Color>(4, {0, 255, 0}));
    std::vector<std::vector<Color>> b2(10, std::vector<Color>(10, {0, 255, 255}));
    std::vector<std::vector<Color>> b3(2, std::vector<Color>(4, {155, 100, 0}));
    std::vector<std::vector<Color>> b4(10, std::vector<Color>(8, {255, 0, 0}));

    Image s1(4, 4);
    s1.setImage(b1);

    Image s2(10, 10);
    s2.setImage(b2);

    Image s3(4, 2);
    s3.setImage(b3);

    Image s4(8, 10);
    s4.setImage(b4);

    Sprite sp1(s1);
    Sprite sp2(s2, {10, 10});
    Sprite sp3(s3, {5, 5});
    Sprite sp4(s4, {20, 40});

    while(true)
    {
        window.clear();

        window.draw(sp1);
        window.draw(sp2);
        window.draw(sp3);
        window.draw(sp4);

        window.display();
    }
    
    return 0;
}