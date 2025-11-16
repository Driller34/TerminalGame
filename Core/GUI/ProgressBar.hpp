#pragma once

class ProgressBar : public Drawable,
                    public Transformable
{
public:
    ProgressBar(const size_t width,
        const size_t height,
        const int maxValue);

    void setValue(const int value);

    int getValue() const;
    int getMaxValue() const;

    virtual void draw(Window& renderTarger, 
        const Vec2i& position) override;

private:
    const size_t mWidth;
    const size_t mHeight;
    
    const int mMaxValue;
    int mValue;
};  