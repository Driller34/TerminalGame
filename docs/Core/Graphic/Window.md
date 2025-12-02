# Window

## Header
```
#include "Core/Graphic/Window.hpp"
```

## Declaration
```
class Window
```

## Description
Window is a high-level rendering interface used to draw `Drawable` objects, raw `Image` objects,  
and individual pixels onto a terminal-rendered screen using ANSI escape sequences.  
Internally, it uses `WindowBuffer` to accumulate and display rendered content.

## Private attributes
- `size_t mWidth` – window width in pixels  
- `size_t mHeight` – window height in pixels  
- `WindowBuffer mWindowBuffer` – buffer responsible for pixel storage and ANSI formatting  

## Member functions
- [constructor](#constructor)  
- [draw (template)](#draw-template)  
- [draw (image)](#draw-image)  
- [setColor](#setcolor)  
- [clear](#clear)  
- [display](#display)


## constructor

### Description
Creates a window with specified dimensions.

### Declaration
```
Window(const size_t width,
    const size_t height);
```

### Parameters
- `size_t width` – window width  
- `size_t height` – window height  

## draw (template)

### Description
Draws any object derived from `Drawable`.  
If the object is also `Transformable`, its internal position is added to the provided position.

### Declaration
```
template<IsDrawable T>  
void draw(T& object,
          const Vec2i& position = {0, 0});
```

### Parameters
- `T& object` – drawable object  
- `const Vec2i& position` – base position offset  

## draw (image)

### Description
Draws the entire image at a given position inside the window.

### Declaration
```
void draw(const Image& image,
    const Vec2i& position = {0, 0});
```

### Parameters
- `const Image& image` – image to draw  
- `const Vec2i& position` – destination position  

## setColor

### Description
Sets the color of a single pixel in the window.

### Declaration
```
void setColor(const Vec2i& position,
    const Color& color);
```

### Parameters
- `const Vec2i& position` – pixel coordinates  
- `const Color& color` – color to apply  

## clear

### Description
Clears the window’s buffer and prepares it for the next frame.

### Declaration
```
void clear();
```

## display

### Description
Converts the internal buffer to ANSI escape sequences and prints them to the terminal.

### Declaration
```
void display();
```
