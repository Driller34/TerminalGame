#pragma once

class Bar : public Sprite
{
public:
    Bar(const size_t width,
        const size_t height,
        const int maxValue);

    void setValue(const int value);

    int getValue() const;
    int getMaxValue() const;

private:
    void apply();

    const int mMaxValue;
    int mValue;
};  