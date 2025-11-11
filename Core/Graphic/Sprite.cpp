#include "Sprite.hpp"

Sprite::Sprite(const Image& image,
    const Vec2i& position)
    : mImage(image)
{}

void Sprite::setImage(const Image& image)
{
    mImage = image;
}

void Sprite::draw(Window& window,
    const Vec2i& position)
{
    window.draw(mImage, position);
}