# Sprite

## Header
```
#include "Core/Graphic/Sprite.hpp"
```

## Declaration
```
class Sprite : public Drawable, public Transformable
```

## Description
Sprite represents a drawable 2D image that can be positioned and rendered onto a Window.  
It inherits from `Drawable` and `Transformable`, allowing it to be drawn and moved within the scene.

## Private attributes
- `Image mImage` – the image data rendered by the sprite

## Member functions
- [constructor](#constructor)
- [setImage](#setimage)
- [getSize](#getsize)
- [draw](#draw)

## constructor

### Description
Initializes the sprite with an image and an optional starting position.

### Declaration
```
Sprite(const Image& image,
    const Vec2i& position = {0, 0});
```

### Parameters
- `const Image& image` – the image used for rendering  
- `const Vec2i& position` – initial position of the sprite (default: {0, 0})

## setImage

### Description
Replaces the sprite’s current image with a new one.

### Declaration
```
void setImage(const Image& image);
```

### Parameters
- `const Image& image` – new image to assign to the sprite

## getSize

### Description
Returns the dimensions of the sprite’s image.

### Declaration
```
Vec2i getSize() const;
```

### Return type
```
Vec2i
```

## draw

### Description
Draws the sprite onto the specified window at the given position.

### Declaration
```
virtual void draw(Window& renderTarget,
    const Vec2i& position) override;
```

### Parameters
- `Window& renderTarget` – the window used for rendering  
- `const Vec2i& position` – the position at which to draw the sprite
