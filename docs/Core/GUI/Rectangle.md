# Rectangle

## Header
```
#include "Core/GUI/Rectangle.hpp"
```

## Declaration
```
class gui::Rectangle : public Drawable, public Transformable
```

## Description
Represents a drawable rectangle with a specific size and color.  
Belongs to the `gui` namespace.  
Inherits from `Drawable` and `Transformable`, so it can be rendered and transformed.

## Private attributes
- `size_t mWidth` – width of the rectangle
- `size_t mHeight` – height of the rectangle
- `Color mColor` – color of the rectangle

## Member functions
- [constructor](#constructor)
- [constructor with parameters](#constructor-with-parameters)
- [destructor](#destructor)
- [getSize](#getsize)
- [setSize](#setsize)
- [setColor](#setcolor)
- [draw](#draw)

## constructor

### Description
Default constructor that initializes the rectangle with zero size and default color.

### Declaration
```
Rectangle();
```

## constructor with parameters

### Description
Initializes the rectangle with a specific width, height, and color.

### Declaration
```
Rectangle(const size_t width,
    const size_t height,
    const Color& color);
```

### Parameters
- `const size_t width` – width of the rectangle
- `const size_t height` – height of the rectangle
- `const Color& color` – color of the rectangle

## destructor

### Description
Default virtual destructor to allow proper cleanup of derived classes.

### Declaration
```
virtual ~Rectangle() = default;
```

## getSize

### Description
Returns the size of the rectangle as a `Vec2ull` (width, height).

### Declaration
```
Vec2ull getSize() const;
```

### Return type
```
Vec2ull
```
[Vec2ull](../Utils/Vec.md)

## setSize

### Description
Sets the size of the rectangle.

### Declaration
```
void setSize(const Vec2ull& size);
```

### Parameters
- `const Vec2ull& size` – new size of the rectangle (width, height)

## setColor

### Description
Sets the color of the rectangle.

### Declaration
```
void setColor(const Color& color);
```

### Parameters
- `const Color& color` – new color of the rectangle

## draw

### Description
Draws the rectangle on the given render target at the specified position.

### Declaration
```
virtual void draw(Window& renderTarget,
    const Vec2i& position) override;
```

### Parameters
- `Window& renderTarget` – the window where the rectangle will be drawn
- `const Vec2i& position` – position on the render target
