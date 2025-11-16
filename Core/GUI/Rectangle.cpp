#include "Rectangle.hpp"

namespace gui
{
Rectangle::Rectangle(const size_t width,
    const size_t height,
    const Color& color)
    : mWidth(width),
    mHeight(height),
    mColor(color)
{}

Vec2ull Rectangle::getSize() const
{
    return {mWidth, mHeight};
}

void Rectangle::setSize(const Vec2ull& size)
{
    mWidth = size.x;
    mHeight = size.y;
}

void Rectangle::draw(Window& renderTarger, 
        const Vec2i& position)
{
    const Vec2i offset = getPosition();

    for(int i = 0; i < mWidth; i++)
    {
        for(int j = 0; j < mHeight; j++)
        {
            renderTarger.setColor(Vec2i{i, j} + offset, mColor);
        }
    }
}
}