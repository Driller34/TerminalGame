#pragma once
#include <functional>
#include "../Graphic/Image.hpp"
#include "../Utils/Vec.hpp"
#include "LayerManager.hpp"
#include "Layer.hpp"

struct MenuOption
{
    Image image;
    Image selectedBackground;
    std::function<void(LayerManager&)> onAction;

    MenuOption(const Image& f,
        const Image& b,
        std::function<void(LayerManager&)> callback = nullptr)
        : image(f),
        selectedBackground(b),
        onAction(callback)
    {}

    void action(LayerManager& layersManager)
    {
        if(onAction){ onAction(layersManager); }
    }
};

class MenuLayer : public Layer
{
public:
    MenuLayer(LayerManager& layerManager,
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
    Vec2i mOptionsPosition;
    size_t mSelectedOption;
    std::vector<MenuOption> mMenuOptions;
};