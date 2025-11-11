#pragma once
#include "../Utils/Vec.hpp"
#include "../Drawable.hpp"
#include "../Transformable.hpp"
#include "Window.hpp"


class Sprite : public Drawable,
               public Transformable
{
public:
    Sprite(const Image& image,
        const Vec2i& position = {0, 0});

    void setImage(const Image& image);

    virtual void draw(Window& window,
        const Vec2i& position) override;
    
private:
    Image mImage;
};