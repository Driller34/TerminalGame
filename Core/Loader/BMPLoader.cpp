#include "BMPLoader.hpp"

namespace BMPLoader
{
    Image bmpToImage(const BMP& bmp) 
    {
        const size_t width = bmp.DIBHeader.width;
        const size_t height = std::abs(bmp.DIBHeader.height);

        Image image(width, height);
        
        for(int y = 0; y < height; y++) 
        {
            for(int x = 0; x < width; x++) 
            {
                Vec2i position{x, y};
                image.setPixel(position, bmp.getColor(position));
            }
        }

        return image;
    }

    Image loadBMP(const std::filesystem::path& path)
    {
        std::ifstream file(path, std::ios::binary);
        if(!file.is_open())
        { 
            throw std::runtime_error(std::format("Unable to open BMP file : {}", path.string())); 
        }

        BMP bmp;

        file>>bmp;

        return bmpToImage(bmp);
    }
}