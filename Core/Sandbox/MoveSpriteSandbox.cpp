#include "../Graphic/Window.hpp"
#include "../Graphic/Sprite.hpp"
#include "../Utils/Input.hpp"

int main()
{
    Window window(50ULL, 90ULL);
    std::vector<std::vector<Color>> b1(4, std::vector<Color>(4, {0, 255, 0, 255}));
    Image s1(4, 4);
    s1.setImage(b1);

    Sprite sp1(s1);

    while(true)
    {
        window.clear();
        
        const auto event = Input::getKey();
        if(event)
        {
            if(event.value() == 'a')
            {
                sp1.move({0, -1});
            }

            if(event.value() == 'd')
            {
                sp1.move({0, 1});
            }

            if(event.value() == 'w')
            {
                sp1.move({-1, 0});
            }

            if(event.value() == 's')
            {
                sp1.move({1, 0});
            }
        }

        window.draw(sp1);

        window.display();
    }

    return 0;
}