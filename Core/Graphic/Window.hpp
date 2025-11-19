#pragma once
#include <iostream>
#include <concepts>
#include <string>
#include "../Base/Drawable.hpp"
#include "../Base/Transformable.hpp"
#include "Image.hpp"
#include "WindowBuffer.hpp"
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
        Vec2i finalPosition = position;

        if constexpr (std::derived_from<T, Transformable>)
        {
            finalPosition += object.getPosition();
        }

        object.draw(*this, finalPosition);
    }

    void draw(const Image& image, 
        const Vec2i& position = {0, 0});

    void setColor(const Vec2i& position,
        const Color& color);

    void clear();
    void display();

private:
    size_t mWidth;
    size_t mHeight;

    WindowBuffer mWindowBuffer;
};