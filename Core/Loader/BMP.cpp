#include "BMP.hpp"

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