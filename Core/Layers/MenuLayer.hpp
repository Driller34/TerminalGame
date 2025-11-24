#pragma once
#include <functional>
#include "../GUI/OptionList.hpp"
#include "../Graphic/Image.hpp"
#include "../GUI/Rectangle.hpp"
#include "../Utils/Vec.hpp"
#include "../Utils/Color.hpp"
#include "LayerManager.hpp"
#include "Layer.hpp"

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

    void addOption(const gui::Option& option);

private:
    LayerManager& mLayerManager;
    Image mBackgroundImage;

    gui::OptionList mMenuOptions;
};