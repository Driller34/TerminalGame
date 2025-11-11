#include <filesystem>
#include "../Graphic/Window.hpp"
#include "../Graphic/Sprite.hpp"
#include "../Loader/BMPLoader.hpp"
#include "../ResourceManager.hpp"

int main()
{
    Window window(20ULL, 20ULL);

    ResourceManager manager(std::filesystem::path(PROJECT_ROOT_DIR));
    manager.addResource(std::filesystem::path("Resources/Images/spaceship.bmp"));
    Sprite sp(manager.getImage(std::filesystem::path("Resources/Images/spaceship.bmp")));

    window.draw(sp);

    window.display();

    return 0;
}