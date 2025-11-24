#include "MenuLayer.hpp"

MenuLayer::MenuLayer(LayerManager& layerManager,
    const Image& backgroundImage,
    const Vec2i& optionsPosition)
    : mLayerManager(layerManager),
    mBackgroundImage(backgroundImage),
    mMenuOptions()
{
    mMenuOptions.setPosition(optionsPosition);
}

void MenuLayer::init()
{

}

void MenuLayer::update()
{

}

void MenuLayer::draw(Window& window)
{
    window.draw(mBackgroundImage);

    window.draw(mMenuOptions);
}

void MenuLayer::activateState() 
{}

void MenuLayer::addOption(const gui::Option& option)
{
    mMenuOptions.addOption(option);
}

void MenuLayer::inputHandler(const char pressedKey)
{
    switch(pressedKey)
    {
        case 'w': mMenuOptions.selectNext(); break;
        case 's': mMenuOptions.selectPrev(); break;
        case ' ': mMenuOptions.executeSelectedOption(); break;
    }
}