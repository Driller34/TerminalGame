#include "Sprite.hpp"

Sprite::Sprite(const Image& image,
    const Vec2i& position)
    : mImage(image),
    mPosition(position)
{}

void Sprite::setImage(const Image& image)
{
    mImage = image;
}

void Sprite::setPosition(const Vec2i& position)
{
    mPosition = position;
}

void Sprite::move(const Vec2i& offset)
{
    setPosition(mPosition + offset);
}

void Sprite::draw(Window& window,
    const Vec2i& position)
{
    window.draw(mImage, mPosition + position);
}