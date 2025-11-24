#pragma once
#include "../Base/Drawable.hpp"
#include "../Base/Transformable.hpp"
#include "../Utils/Vec.hpp"
#include "../Utils/Color.hpp"
#include "../Graphic/Window.hpp"

namespace gui
{
class Rectangle : public Drawable,
                  public Transformable
{
public:
    Rectangle(const size_t width,
        const size_t height,
        const Color& color);

    virtual ~Rectangle() = default;

    Vec2ull getSize() const;

    void setSize(const Vec2ull& size);

    virtual void draw(Window& renderTarget, 
        const Vec2i& position) override;

private:
    size_t mWidth;
    size_t mHeight;
    Color mColor;
};
}