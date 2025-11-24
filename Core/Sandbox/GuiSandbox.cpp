#include "../Graphic/Window.hpp"
#include "../GUI/OptionList.hpp"
#include "../ResourceManager.hpp"
#include "../Utils/InputHandler.hpp"

int main()
{   
    ResourceManager resourceManager(
        std::filesystem::path(PROJECT_ROOT_DIR ) / "Resources/Images");

    Window window(40, 40);
    InputHandler handler;

    gui::OptionList l;

    l.setPosition({5, 5});

    l.addOption({resourceManager.getImage("exit.bmp"), 
        {0, 0, 255, 255},
        [](){
            return;
    }});

    l.addOption({resourceManager.getImage("start.bmp"), 
        {0, 0, 255, 255},
        [](){
            return;
    }});

    while(true)
    {
        window.clear();
        int a = 0;

        const auto c = handler.getKey();

        if(c)
        {
            if(c.value() == 'w'){ l.selectNext(); }
            if(c.value() == 's'){ l.selectPrev(); }
            if(c.value() == 'e'){ break; }
        }

        window.draw(l);

        window.display();
    }

    return 0;
}