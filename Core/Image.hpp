#pragma once
#include <vector>
#include <iostream>
#include "Color.hpp"
#include "Point.hpp"

struct Image
{   
    Image(const size_t w, 
        const size_t h,
        const Color backgroundColor = Color{255, 255, 255})
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

    size_t getIndex(const Point& position) const 
    {
        if(position.x >= width || position.y >= height){ return 0ULL;}
        return position.y * width + position.x;
    }

    Color getColor(const Point& point) const
    {
        return grid[getIndex(point)];
    }

    void setPixel(const Point& position, 
        const Color& c) 
    {
        if(position.x >= width || position.y >= height){ return;}
        grid[getIndex(position)] = c;
    }

    void setImage(const std::vector<std::vector<Color>>& image)
    {
        const size_t w = image.size();
        const size_t h = image[0].size();

        if(w > width || h > height){ return; }

        for(size_t y = 0ULL; y < h; y++)
        {
            for(size_t x = 0ULL; x < w; x++)
            {
                grid[getIndex({x, y})] = image[x][y];
            }
        }
    }

    size_t width;
    size_t height;

    std::vector<Color> grid;
};