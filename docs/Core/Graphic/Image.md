# Image

## Header
```
#include "Core/Graphic/Image.hpp"
```

## Declaration
```
struct Image
```

## Description
Image represents a 2D pixel surface stored as a 1D array of Color values.  
It provides functionality for manipulating individual pixels, clearing the image, and copying external pixel data into its grid.

## Attributes
- `size_t width` – width of the image in pixels  
- `size_t height` – height of the image in pixels  
- `std::vector<Color> grid` – linear array storing the image’s pixel data row-by-row

## Member functions
- [constructor](#constructor)
- [clear](#clear)
- [getIndex](#getindex)
- [getColor](#getcolor)
- [setPixel](#setpixel)
- [setImage](#setimage)

## constructor

### Description
Initializes an image with the specified width and height, filling all pixels with the provided background color.

### Declaration
```
Image(const size_t w,
    const size_t h,
    const Color backgroundColor = Color{255, 255, 255, 255});
```

### Parameters
- `size_t w` – image width  
- `size_t h` – image height  
- `Color backgroundColor` – optional background color (default: white)

## clear

### Description
Clears the image by removing all pixel data and reinitializing the grid to its original size with default-constructed colors.

### Declaration
```
void clear();
```

## getIndex

### Description
Returns the linear index in the grid corresponding to the given 2D pixel position.  
If the position is outside image bounds, returns 0.

### Declaration
```
size_t getIndex(const Vec2i& position) const;
```

### Parameters
- `const Vec2i& position` – pixel coordinate

### Return type
```
size_t
```

## getColor

### Description
Returns the color of the pixel located at the given position.

### Declaration
```
Color getColor(const Vec2i& position) const;
```

### Parameters
- `const Vec2i& position` – pixel coordinate

### Return type
```
Color
```

## setPixel

### Description
Sets the pixel at the given position to the specified color.  
If the position is out of bounds, the operation is ignored.

### Declaration
```
void setPixel(const Vec2i& position, const Color& c);
```

### Parameters
- `const Vec2i& position` – target pixel  
- `const Color& c` – color to set

## setImage

### Description
Copies an external 2D array of colors into the image starting from position (0, 0).  
If the provided image exceeds the current image’s size, the operation is ignored.

### Declaration
```
void setImage(const std::vector<std::vector<Color>>& image);
```

### Parameters
- `const std::vector<std::vector<Color>>& image` – 2D color array to copy
