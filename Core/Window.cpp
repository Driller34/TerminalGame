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
}

void Window::setColor(const Color& color,
    const Point& position)
{
    std::cout<<"\033["<<position.x + 1ULL<<";"<<position.y + 1ULL<<"H";
    std::cout<<"\033[48;2;"<<color.toString()<<"m \033[0m";
}

void Window::display()
{
    for(size_t y = 0ULL; y < mViewImage.height; y++)
    {
        for(size_t x = 0ULL; x < mViewImage.width; x++)
        {
            Point current{x, y};
            setColor(mViewImage.getColor(current), current);
        }
    }
}

void Window::setPoint(const Point& position,
    const Color& color)
{
    mViewImage.setPixel(position, color);
}

template<IsDrawable T>
void Window::draw(const T& object,
    const Point& position)
{
    
}

void Window::draw(const Image& image, 
    const Point& position)
{
    for(size_t y = 0ULL; y < image.height; y++)
    {
        for(size_t x = 0ULL; x < image.width; x++)
        {
            const Point currentPosition = Point{x, y} + position;
            setPoint(currentPosition, image.getColor({x, y}));
        }
    }
}