#pragma once
#include <functional>
#include "../Graphic/Image.hpp"
#include "../GUI/Rectangle.hpp"
#include "../Utils/Vec.hpp"
#include "../Utils/Color.hpp"
#include "LayerManager.hpp"
#include "Layer.hpp"

struct MenuOption
{
    Image image;
    gui::Rectangle selectedBackground;
    std::function<void()> onAction;

    MenuOption(const Image& img,
        const Color& backgroundColor,
        std::function<void()> callback = nullptr)
        : image(img),
        selectedBackground(gui::Rectangle(img.width, img.height, backgroundColor)),
        onAction(callback)
    {}

    void action()
    {
        if(onAction){ onAction(); }
    }
};

class MenuLayer : public Layer
{
public:
    MenuLayer(LayerManager& layerManager,
        const Image& backgroundImage,
        const Vec2i& optionsPosition);

    virtual void init() override;
    virtual void update() override;
    virtual void draw(Window& window) override;
    virtual void activateState() override;
    virtual void inputHandler(const char pressedKey) override;

    void addOption(const MenuOption& option);

private:
    void select(const size_t n);
    void executeMenuOption();

private:
    LayerManager& mLayerManager;
    Image mBackgroundImage;
    Vec2i mOptionsPosition;
    size_t mSelectedOption;
    std::vector<MenuOption> mMenuOptions;
};