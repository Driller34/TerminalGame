#include "Window.hpp"

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
    display();
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
    for(size_t y = 0ULL; y < mViewImage.height; y++)
    {
        for(size_t x = 0ULL; x < mViewImage.width; x++)
        {
            Vec2i current{x, y};
            displayPoint(current, mViewImage.getColor(current));
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
            const Vec2i currentPosition = Vec2i{x, y} + position;
            setColor(currentPosition, image.getColor(Vec2i{x, y}));
        }
    }
}