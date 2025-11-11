#include <filesystem>
#include "../Graphic/Window.hpp"
#include "../Graphic/Sprite.hpp"
#include "../Loader/BMPLoader.hpp"

int main()
{
    Window window(20ULL, 20ULL);

    std::filesystem::path path = std::filesystem::path(PROJECT_ROOT_DIR) / "Resources/Images/spaceship.bmp";
    std::vector<std::vector<Color>> b1(20, std::vector<Color>(20, {0, 255, 0, 255}));
    Image s1(20, 20);
    s1.setImage(b1);

    Sprite sp1(s1);
    Sprite sp(BMPLoader::loadBMP(path));

    window.draw(sp1);
    window.draw(sp);

    window.display();

    return 0;
}