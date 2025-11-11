#pragma once
#include <stack>
#include <memory>
#include "Layer.hpp"
#include "../Graphic/Window.hpp"

class LayerManager
{
public:
    LayerManager();

    void update();
    void render(Window& window);
    void inputHandler(const char pressedKey);

    void push(std::unique_ptr<Layer> layer);
    void pop();
    void change(std::unique_ptr<Layer> layer);
    Layer* top() const;
    bool empty() const;

private:
    std::stack<std::unique_ptr<Layer>> layers;
};