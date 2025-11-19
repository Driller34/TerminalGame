#include "Window.hpp"
#include <stdio.h>

Window::Window(const size_t width,
    const size_t height)
    : mWidth(width),
    mHeight(height),
    mViewImage(width, height)
{

}

void Window::clear()
{
    mViewImage.clear();
}

void Window::displayPoint(const Vec2i& position,
    const Color& color)
{
    if(color.alpha != 255){ return; }
    if(position.y >= mHeight || position.x >= mWidth){ return; }
    if(position.y < 0 || position.x < 0){ return; }

    std::cout<<"\033["<<position.y + 1<<";"<<(position.x * 2) + 1<<"H";
    std::cout<<"\033[48;2;"<<color.toString()<<"m  \033[0m";
}

void Window::display()
{
    std::cout<<"\033[?25l";
    for(size_t y = 0ULL; y < mViewImage.height; y++)
    {
        for(size_t x = 0ULL; x < mViewImage.width; x++)
        {
            const Vec2i currentPosition{static_cast<int>(x), static_cast<int>(y)};
            displayPoint(currentPosition, mViewImage.getColor(currentPosition));
        }
    }
}

void Window::setColor(const Vec2i& position,
    const Color& color)
{
    if(color.alpha != 255){ return; }   
    mViewImage.setPixel(position, color);
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