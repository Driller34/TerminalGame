#include "BMP.hpp"

Color BMP::getColor(const Vec2i& position) const
{
    const size_t width = DIBHeader.width;
    const size_t height = std::abs(DIBHeader.height);

    if(position.x < 0 
       || position.x >= width 
       || position.y < 0 
       || position.y >= height)
    { 
        return {0, 0, 0, 0}; 
    }

    const bool topDown = DIBHeader.height < 0;
    const size_t bytesPerPixel = DIBHeader.bitCount / 8;
    const size_t rowSize = ((width * bytesPerPixel + 3) / 4) * 4;
    const int row = topDown ? position.y : (height - 1 - position.y);
    const size_t index = row * rowSize + (position.x * bytesPerPixel);

    const uint8_t b = colorArray[index];
    const uint8_t g = colorArray[index + 1];
    const uint8_t r = colorArray[index + 2];
    const uint8_t a = bytesPerPixel == 4 ? colorArray[index + 3] : 255;

    return {r, g, b, a};
}

std::istream& operator>>(std::istream& is, 
    BMP& bmp)
{
    is.read(reinterpret_cast<char*>(&bmp.header), sizeof(BMPHeader));
    is.read(reinterpret_cast<char*>(&bmp.DIBHeader), sizeof(BMPDIBHeader));

    const size_t pixelDataSize = bmp.header.fileSize - bmp.header.offsetData;

    bmp.colorArray.resize(pixelDataSize);
    is.seekg(bmp.header.offsetData, std::ios::beg);
    is.read(reinterpret_cast<char*>(bmp.colorArray.data()), pixelDataSize);

    return is;
}