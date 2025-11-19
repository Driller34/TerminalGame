#include "WindowBuffer.hpp"

WindowBuffer::WindowBuffer(const size_t width,
	const size_t height,
	const Color& backgroundColor)
	: mViewImage(width, height, backgroundColor),
	mBuffer("")
{
	
}

void WindowBuffer::setColor(const Vec2i& position,
	const Color& color)
{
	if(color.alpha != 255){ return; }
	mViewImage.setPixel(position, color);
}

void WindowBuffer::clear()
{
    mBuffer.clear();
    mViewImage.clear();
}

void WindowBuffer::updateBuffer()
{
    for(size_t y = 0ULL; y < mViewImage.height; y++)
    {
        for(size_t x = 0ULL; x < mViewImage.width; x++)
        {
            const Vec2i position{ static_cast<int>(x), static_cast<int>(y) };
            const Color color = mViewImage.getColor(position);

            if(color.alpha != 255){ continue; }

            setInBuffer(position, color);
        }
    }
}

void WindowBuffer::setInBuffer(const Vec2i& position,
    const Color& color)
{
    mBuffer += std::format("\033[{};{}H\033[48;2;{}m  \033[0m",
        position.y + 1,
        (position.x * 2) + 1,
        color.toString());
}

std::string WindowBuffer::toString() const
{
	return mBuffer;
}