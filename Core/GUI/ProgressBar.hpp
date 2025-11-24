#pragma once
#include "../Base/Drawable.hpp"
#include "../Base/Transformable.hpp"
#include "../Utils/Vec.hpp"
#include "../Utils/Color.hpp"
#include "../Graphic/Window.hpp"
#include "Rectangle.hpp"

namespace gui
{
class ProgressBar : public Drawable,
                    public Transformable
{
public:
    ProgressBar(const size_t width,
        const size_t height,
        const int maxValue,
        const Color& valueColor = {255, 0, 0, 255},
        const Color& emptyColor = {92, 92, 91, 255});

    void setValue(const int value);

    int getValue() const;
    int getMaxValue() const;

    virtual void draw(Window& renderTarget, 
        const Vec2i& position) override;

private:
    int getValueWidth() const;

private:
    const size_t mWidth;
    const size_t mHeight;
    
    const int mMaxValue;
    int mValue;

    const Color mValueColor;
    const Color mEmptyColor;
}; 
}