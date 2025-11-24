#include "ProgressBar.hpp"

namespace gui
{

ProgressBar::ProgressBar(const size_t width,
    const size_t height,
    const int maxValue,
    const Color& valueColor,
    const Color& emptyColor)
    : mWidth(width),
    mHeight(height),
    mMaxValue(maxValue),
    mValue(mMaxValue),
    mValueColor(valueColor),
    mEmptyColor(emptyColor)
{}

void ProgressBar::setValue(const int value)
{
    mValue = value;
}

int ProgressBar::getValue() const
{
    return mValue;
}

int ProgressBar::getMaxValue() const
{
    return mMaxValue;
}

int ProgressBar::getValueWidth() const
{
    const int answer = (mWidth * mValue) / mMaxValue;
    return answer > 0 ? answer : 0;
}

void ProgressBar::draw(Window& renderTarget, 
    const Vec2i& position)
{
    const int valueWidth = getValueWidth();

    gui::Rectangle valueRectangle(valueWidth, mHeight, mValueColor);
    gui::Rectangle emptyRectangle(mWidth - valueWidth, mHeight, mEmptyColor);
    
    emptyRectangle.setPosition(Vec2i{valueWidth, 0});

    renderTarget.draw(valueRectangle, position);
    renderTarget.draw(emptyRectangle, position);
}

}