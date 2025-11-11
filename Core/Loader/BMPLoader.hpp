#pragma once
#include <filesystem>
#include <fstream>
#include <cstdint>
#include "BMP.hpp"
#include "../Utils/Color.hpp"
#include "../Utils/Vec.hpp"

namespace BMPLoader
{
    Color getColor(const Vec2i& position,
        const BMP& bmp)
    {
        const size_t width = bmp.DIBHeader.width;
        const size_t height = std::abs(bmp.DIBHeader.height);

        if(position.x < 0 
           || position.x >= width 
           || position.y < 0 
           || position.y >= height)
        { return {0, 0, 0, 0}; }

        const bool topDown = bmp.DIBHeader.height < 0;
        const size_t bytesPerPixel = bmp.DIBHeader.bitCount / 8;
        const size_t rowSize = ((width * bytesPerPixel) / 4) * 4;
        const int row = topDown ? position.y : (height - 1 - position.y);
        const size_t index = row * rowSize + (position.x * bytesPerPixel);

        const uint8_t b = bmp.colorArray[index];
        const uint8_t g = bmp.colorArray[index + 1];
        const uint8_t r = bmp.colorArray[index + 2];
        const uint8_t a = bytesPerPixel == 4 ? bmp.colorArray[index + 3] : 255;

        return {r, g, b, a};
    }

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
                image.setPixel(position, getColor(position, bmp));
            }
        }

        return image;
    }

    Image loadBMP(const std::filesystem::path& path)
    {
        std::ifstream file(path, std::ios::binary);
        if(!file.is_open()){ throw std::runtime_error("Unable to open BMP file"); }

        BMP bmp;

        file>>bmp;

        return bmpToImage(bmp);
    }
}