#pragma once
#include <cstdint>
#include <vector>
#include <istream>

#pragma pack(push, 1)
struct BMPHeader
{
    uint16_t fileType;
    uint32_t fileSize;
    uint16_t reserved1{0};
    uint16_t reserved2{0};            
    uint32_t offsetData{0};
};

struct BMPDIBHeader
{
    uint32_t headerSize;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;

    uint32_t redMask;
    uint32_t greenMask;
    uint32_t blueMask;
    uint32_t alphaMask;

    uint32_t csType;
    uint32_t endpoints[9];
    uint32_t gammaRed;
    uint32_t gammaGreen;
    uint32_t gammaBlue;
};
#pragma pack(pop)

struct BMP
{
    BMPHeader header;
    BMPDIBHeader DIBHeader;
    std::vector<uint8_t> colorArray;
};

std::istream& operator>>(std::istream& is, 
    BMP& bmp);