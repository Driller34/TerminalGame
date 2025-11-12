#include <memory>
#include <filesystem>
#include "../Graphic/Window.hpp"
#include "../Graphic/Sprite.hpp"
#include "../Utils/Input.hpp"
#include "../Utils/Vec.hpp"
#include "../Layers/Layer.hpp"
#include "../Layers/LayerManager.hpp"
#include "../Loader/BMPLoader.hpp"

class SandboxLayer : public Layer
{
public:
    SandboxLayer(LayerManager& manager)
        : mManager(manager),
        mPlayer(BMPLoader::loadBMP(std::filesystem::path(PROJECT_ROOT_DIR) / "Resources/Images/spaceship.bmp"))
    {

    }

    virtual void init() override
    {

    }

    virtual void update() override
    {

    }

    virtual void draw(Window& window) override
    {
        window.draw(mPlayer);
    }

    virtual void activateState() override
    {
        mPlayer.setPosition({10, 10});
    }

    virtual void inputHandler(const char pressedKey) override
    {
        switch(pressedKey)
        {
            case 'd': mPlayer.move({1, 0}); break;
            case 'a': mPlayer.move({-1, 0}); break;
            case 'w': mPlayer.move({0, -1}); break;
            case 's': mPlayer.move({0, 1}); break;
            case 'e': mManager.pop(); break;
            default: break;
        }
    }

private:
    Sprite mPlayer;
    LayerManager& mManager;
};

int main()
{
    Window window(100, 80);
    LayerManager manager;

    manager.push(std::make_unique<SandboxLayer>(manager));

    while(!manager.empty())
    {
        window.clear();

        auto input = Input::getKey();
        if(input)
        {
            manager.inputHandler(input.value());
        }
        manager.update();
        manager.render(window);

        window.display();
    }

    return 0;
}