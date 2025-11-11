#include "LayerManager.hpp"

LayerManager::LayerManager(){}

void LayerManager::push(std::unique_ptr<Layer> layer)
{
    layers.push(std::move(layer));
    layers.top()->activateState();
}

void LayerManager::pop()
{
    if(!layers.empty()){ layers.pop(); }
    if(!layers.empty()){ layers.top()->activateState(); }
}

void LayerManager::change(std::unique_ptr<Layer> layer)
{
    while(!layers.empty())
    {
        layers.pop();
    }
    layers.push(std::move(layer));
}

bool LayerManager::empty() const
{
    return layers.empty();
}

Layer* LayerManager::top() const
{
    return layers.empty() ? nullptr : layers.top().get();
}

void LayerManager::update()
{
    if(layers.empty()){ return; }
    layers.top()->update();
}

void LayerManager::render(Window& window)
{
    if(layers.empty()){ return; }
    layers.top()->draw(window);
}

void LayerManager::inputHandler(const char pressedKey)
{
    if(layers.empty()){ return; }
    layers.top()->inputHandler(pressedKey);
}