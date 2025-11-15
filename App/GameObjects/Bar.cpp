#include "Bar.hpp"

Bar::Bar(const size_t width,
        const size_t height,
        const int maxValue)
    : mMaxValue(maxValue)
{

}

void Bar::setValue(const int value)
{
    mValue = value;
}

int Bar::getValue() const
{
    return mValue;
}

int Bar::getMaxValue() const
{
    return mMaxValue;
}

void Bar::apply()
{
    
}