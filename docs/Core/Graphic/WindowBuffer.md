# WindowBuffer

## Header
```
#include "Core/Graphic/WindowBuffer.hpp"
```

## Declaration
```
class WindowBuffer
```

## Description
WindowBuffer is a text-based rendering buffer used for generating ANSI-colored output in a terminal.  
It stores an internal Image representing pixel colors and converts it into an ANSI string buffer that can be printed to render graphics in the console.

## Private attributes
- `Image mViewImage` – internal image storing pixel data
- `std::string mBuffer` – string buffer containing ANSI escape sequences used for rendering

## Member functions
- [constructor](#constructor)
- [setColor](#setcolor)
- [clear](#clear)
- [updateBuffer](#updatebuffer)
- [toString](#tostring)

## constructor

### Description
Initializes the window buffer with a given size and optional background color.

### Declaration
```
WindowBuffer(const size_t width,
    const size_t height,
    const Color& backgroundColor = {0, 0, 0, 255});
```

### Parameters
- `size_t width` – width of the buffer  
- `size_t height` – height of the buffer  
- `const Color& backgroundColor` – initial background color (default: black)


## setColor

### Description
Sets the color of a specific pixel inside the internal image.  
Only fully opaque pixels (alpha = 255) are applied.

### Declaration
```
void setColor(const Vec2i& position,
              const Color& color);
```

### Parameters
- `const Vec2i& position` – pixel coordinates  
- `const Color& color` – color to assign


## clear

### Description
Clears both the ANSI buffer and the internal image contents.

### Declaration
```
void clear();
```

## updateBuffer

### Description
Updates the ANSI text buffer by converting all opaque pixels of the internal image into ANSI escape codes.

### Declaration
```
void updateBuffer();
```

## toString

### Description
Returns the current ANSI buffer as a string.  
This string can be printed to render the graphical output in a terminal window.

### Declaration
```
std::string toString() const;
```

### Return type
```
std::string
```