#include "MenuLayer.hpp"

MenuLayer::MenuLayer(LayerManager& layerManager,
    const Vec2i& optionsPosition)
    : mLayerManager(layerManager),
    mOptionsPosition(optionsPosition),
    mSelectedOption(0ULL)
{

}

void MenuLayer::init()
{

}

void MenuLayer::update()
{

}

void MenuLayer::draw(Window& window)
{
    const size_t n = mMenuOptions.size();
    Vec2i currentPosition = mOptionsPosition;
    for(size_t i = 0ULL; i < n; i++)
    {
        if(i == mSelectedOption)
        {
            window.draw(mMenuOptions[i].selectedBackground, currentPosition);
        }
        window.draw(mMenuOptions[i].image, currentPosition);
        currentPosition.y += mMenuOptions[i].image.height + 2;
    }
}

void MenuLayer::activateState() 
{
    mSelectedOption = 0ULL;
}

void MenuLayer::addOption(const MenuOption& option)
{
    mMenuOptions.push_back(option);
}

void MenuLayer::inputHandler(const char pressedKey)
{
    switch(pressedKey)
    {
        case 'w': select(mSelectedOption - 1); break;
        case 's': select(mSelectedOption + 1); break;
        case ' ': executeMenuOption(); break;
    }
}

void MenuLayer::select(const size_t n)
{
    if(n >= mMenuOptions.size() || n < 0){ return; }
    mSelectedOption = n;
}

void MenuLayer::executeMenuOption()
{
    mMenuOptions[mSelectedOption].action(mLayerManager);
}
