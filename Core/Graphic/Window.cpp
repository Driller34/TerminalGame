#include "Window.hpp"

Window::Window(const size_t width,
    const size_t height)
    : mWidth(width),
    mHeight(height),
    mWindowBuffer(mWidth, mHeight)
{

}

void Window::clear()
{
    mWindowBuffer.clear();
}

void Window::display()
{
    std::cout<<"\033[?25l";

    mWindowBuffer.updateBuffer();

    std::cout<<mWindowBuffer.toString();
}

void Window::setColor(const Vec2i& position,
    const Color& color)
{
    mWindowBuffer.setColor(position, color);
}

void Window::draw(const Image& image, 
    const Vec2i& position)
{
    for(size_t y = 0ULL; y < image.height; y++)
    {
        for(size_t x = 0ULL; x < image.width; x++)
        {
            Vec2i currentPosition{static_cast<int>(x), static_cast<int>(y)};
            currentPosition += position;
            setColor(currentPosition, image.getColor(Vec2i{static_cast<int>(x), static_cast<int>(y)}));
        }
    }
}