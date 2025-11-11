#pragma once
#include "../Utils/Vec.hpp"
#include "../Drawable.hpp"
#include "Window.hpp"


class Sprite : public Drawable
{
public:
    Sprite(const Image& image,
        const Vec2i& position = {0, 0});

    void setImage(const Image& image);

    void move(const Vec2i& offset);

    void setPosition(const Vec2i& position);

    virtual void draw(Window& window,
        const Vec2i& position) override;
    
private:
    Image mImage;
    Vec2i mPosition;
};