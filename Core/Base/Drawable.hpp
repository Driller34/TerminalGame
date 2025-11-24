#pragma once
#include <concepts>
#include "../Utils/Vec.hpp"

class Window;

class Drawable
{
public:
    virtual ~Drawable() = default;

    virtual void draw(Window& renderTarget, 
        const Vec2i& position) = 0;
};

template<typename T>
concept IsDrawable = std::derived_from<T, Drawable>;