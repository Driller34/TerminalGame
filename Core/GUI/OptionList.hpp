#pragma once
#include <functional>
#include <vector>
#include "../GUI/Rectangle.hpp"
#include "../Graphic/Window.hpp"
#include "../Graphic/Image.hpp"
#include "../Utils/Color.hpp"
#include "../Utils/Vec.hpp"
#include "../Base/Drawable.hpp"
#include "../Base/Transformable.hpp"

namespace gui
{

struct Option
{
    Image image;
    Color color;
    std::function<void()> onAction;
};

class OptionList : public Drawable,
                   public Transformable
{
public:
    OptionList(const size_t margin = 0);

    void addOption(const Option& option);

    void selectNext();
    void selectPrev();

    void executeSelectedOption();

    virtual void draw(Window& renderTarget, 
        const Vec2i& position) override;

private:
    void setHighlight(const Option& option);

private:
    size_t mSelectedOption;
    size_t mMargin;
    gui::Rectangle mHighlight;
    std::vector<Option> mOptions;
};  

}