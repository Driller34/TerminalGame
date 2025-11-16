#include "ProgressBar.hpp"

ProgressBar::ProgressBar(const size_t width,
    const size_t height,
    const int maxValue)
    : mWidth(width),
    mHeight(height),
    mMaxValue(maxValue),
    mValue(mMaxValue)
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