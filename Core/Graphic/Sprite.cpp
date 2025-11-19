#include "Sprite.hpp"

Sprite::Sprite(const Image& image,
    const Vec2i& position)
    : mImage(image)
{}

void Sprite::setImage(const Image& image)
{
    mImage = image;
}

Vec2i Sprite::getSize() const
{
    return {
        static_cast<int>(mImage.width),
        static_cast<int>(mImage.height)
    };
}

void Sprite::draw(Window& window,
    const Vec2i& position)
{
    window.draw(mImage, position);
}