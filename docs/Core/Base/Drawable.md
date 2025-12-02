# Drawable

## Header
```
#include "Core/Base/Drawable.hpp"
```

## Declaration
```
class Drawable
```

## Description
Drawable is an abstract base class representing any object that can be drawn onto a Window.  
Classes inheriting from Drawable must implement the draw method, which defines how the object is rendered at a given position.

## Member functions
- [destructor](#destructor)
- [draw](#draw)

## destructor

### Description
Default virtual destructor allowing safe polymorphic deletion of derived drawable objects.

### Declaration
```
virtual ~Drawable() = default;
```

## draw

### Description
Pure virtual method that must be implemented by all drawable objects.  
Defines how the object is drawn onto the render target at a specified position.

### Declaration
```
virtual void draw(Window& renderTarget, const Vec2i& position) = 0;
```

### Parameters
- `Window& renderTarget` – reference to the target window where the object will be drawn  
- `const Vec2i& position` – position at which the object should be rendered


# IsDrawable

## Declaration
```
template<typename T>
concept IsDrawable = std::derived_from<T, Drawable>;
```

## Description
Concept used to constrain templates to types derived from Drawable.  
Ensures that the provided type implements drawable behavior and can be safely used in rendering systems.
