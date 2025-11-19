#pragma once
#include <string>
#include <cstdint>

struct Color
{
    uint8_t red = 0;
    uint8_t green = 0;
    uint8_t blue = 0;
    uint8_t alpha = 255;

    std::string toString() const
    {
        return std::to_string(red) + ";" +
               std::to_string(green) + ";" +
               std::to_string(blue);
    }

    Color operator*(const double n) const
    {
        return {
            static_cast<uint8_t>(red * n),
            static_cast<uint8_t>(green * n),
            static_cast<uint8_t>(blue * n),
            static_cast<uint8_t>(alpha * n)
        };
    }

    Color operator+(const Color& color) const
    {
        return {
            static_cast<uint8_t>(std::min(255, red + color.red)),
            static_cast<uint8_t>(std::min(255, green + color.green)),
            static_cast<uint8_t>(std::min(255, blue + color.blue)),
            static_cast<uint8_t>(std::min(255, alpha + color.alpha))
        };
    }
};
