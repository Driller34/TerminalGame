#pragma once
#include <iostream>
#include "Drawable.hpp"
#include "Image.hpp"
#include "Point.hpp"
#include "Color.hpp"

class Window
{
public:
    Window(const size_t width,
        const size_t height);

    template<IsDrawable T>
    void draw(const T& object,
        const Point& position = {0, 0});

    void draw(const Image& image, 
        const Point& position);

    void setPoint(const Point& position,
        const Color& color);

    void clear();
    void display();

private:
    void setColor(const Color& color,
        const Point& position);

private:
    size_t mWidth;
    size_t mHeight;

    Image mViewImage;
};