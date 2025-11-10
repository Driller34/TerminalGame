#pragma once
#include <string>

struct Color
{
    size_t red;
    size_t green;
    size_t blue;

    std::string toString() const
    {
        return std::to_string(red)+";"+std::to_string(green)+";"+std::to_string(blue);
    }

    Color operator*(const size_t n) const
    {
        return { (red * n) % 256, 
            (green * n) % 256, 
            (blue * n) % 256 };
    }

    Color operator*(const double n) const
    {
        return { static_cast<size_t>(red * n) % 256, 
            static_cast<size_t>(green * n) % 256, 
            static_cast<size_t>(blue * n) % 256 };
    }

    Color operator+(const Color& color) const
    {
        return { (red + color.red) % 256, 
            (green + color.green) % 256, 
            (blue + color.blue) % 256 };
    }
};