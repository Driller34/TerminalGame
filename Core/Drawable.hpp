#pragma once
#include "Window.hpp"
#include "Point.hpp"

class Drawable
{
public:
    virtual ~Drawable() = default;

    virtual void draw() = 0;
};

template<typename T>
concept IsDrawable = std::derived_from<T, Drawable>;