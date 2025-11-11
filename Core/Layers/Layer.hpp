#pragma once
#include "../Graphic/Window.hpp"

class Layer
{
public:
    virtual ~Layer() = default;
    
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw(Window& window) = 0;
    virtual void activateState() = 0;
    virtual void inputHandler(const char pressedKey) = 0;
};