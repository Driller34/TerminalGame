#pragma once
#include <iostream>
#include "../Drawable.hpp"
#include "Image.hpp"
#include "../Utils/Vec.hpp"
#include "../Utils/Color.hpp"

class Window
{
public:
    Window(const size_t width,
        const size_t height);

    template<IsDrawable T>
    void draw(T& object,
        const Vec2i& position = {0, 0})
    {
        object.draw(*this, position);
    }

    void draw(const Image& image, 
        const Vec2i& position = {0, 0});

    void setColor(const Vec2i& position,
        const Color& color);

    void clear();
    void display();

private:
    void displayPoint(const Vec2i& position,
        const Color& color);

private:
    size_t mWidth;
    size_t mHeight;

    Image mViewImage;
};