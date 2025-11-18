#pragma once
#include <filesystem>
#include <fstream>
#include <cstdint>
#include <format>
#include "BMP.hpp"
#include "../Utils/Color.hpp"
#include "../Utils/Vec.hpp"
#include "../Graphic/Image.hpp"

namespace BMPLoader
{
    Image bmpToImage(const BMP& bmp);

    Image loadBMP(const std::filesystem::path& path);
}