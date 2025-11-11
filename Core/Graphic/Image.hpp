#pragma once
#include <vector>
#include <iostream>
#include "../Utils/Color.hpp"
#include "../Utils/Vec.hpp"

struct Image
{   
    Image(const size_t w, 
        const size_t h,
        const Color backgroundColor = Color{255, 255, 255, 255})
        : width(w),
        height(h),
        grid(width * height, backgroundColor)
    {
    }

    void clear()
    {
        grid.clear();
        grid.resize(width * height);
    }

    size_t getIndex(const Vec2i& position) const 
    {
        if(position.x >= width 
            || position.y >= height 
            || position.x < 0 
            || position.y < 0){ return 0ULL;}

        return position.y * width + position.x;
    }

    Color getColor(const Vec2i& position) const
    {
        return grid[getIndex(position)];
    }

    void setPixel(const Vec2i& position, 
        const Color& c) 
    {
        if(position.x >= width || position.y >= height){ return; }
        grid[getIndex(position)] = c;
    }

    void setImage(const std::vector<std::vector<Color>>& image)
    {
        const size_t w = image[0].size();
        const size_t h = image.size();

        if(w > width || h > height){ return; }

        for(int y = 0; y < h; y++)
        {
            for(int x = 0; x < w; x++)
            {
                grid[getIndex({x, y})] = image[y][x];
            }
        }
    }

    size_t width;
    size_t height;

    std::vector<Color> grid;
};