# BMP / BMPHeader / BMPDIBHeader

## Header
```
#include "Core/Loader/BMP.hpp"
```

## Description
This module defines data structures for reading and storing BMP image files.  
It includes:

- `BMPHeader` – the file header containing general information about the BMP file  
- `BMPDIBHeader` – the DIB (Device Independent Bitmap) header containing detailed image metadata  
- `BMP` – a structure holding both headers and raw pixel data, together with a helper method for retrieving the color of a specific pixel  
- an overloaded extraction operator `operator>>` for reading BMP data from an input stream  

All structures are tightly packed (`#pragma pack(push, 1)`) to match the binary BMP file layout.


## Important 
This implementation supports only **uncompressed BMP images**
(compression field must be set to 0).
Compressed BMP formats are **not handled**.


## Example
```
int main()
{
    std::filesystem::path path = std::filesystem::path("Resources/Images/spaceship.bmp");

    std::ifstream file(path, std::ios::binary);

    BMP bmp;

    file>>bmp; //load bmp file

    return 0;
}
```

---

# BMPHeader

## Declaration
```
struct BMPHeader
```

## Description
Represents the standard 14-byte BMP file header.  
Contains general information such as file type, file size, and offset to pixel data.

## Members
- `uint16_t fileType` – BMP signature, typically `'BM'` (0x4D42)  
- `uint32_t fileSize` – size of the entire BMP file in bytes  
- `uint16_t reserved1` – reserved field, typically set to 0  
- `uint16_t reserved2` – reserved field, typically set to 0  
- `uint32_t offsetData` – offset from the beginning of the file to the start of the pixel array  

---

# BMPDIBHeader

## Declaration
```
struct BMPDIBHeader
```

## Description
Represents the DIB header (also known as BITMAPINFOHEADER or later versions).  
Provides detailed information about the image, including dimensions, bit depth, compression method, color masks, and color calibration data.

## Members
- `uint32_t headerSize` – size of the DIB header  
- `int32_t width` – image width in pixels  
- `int32_t height` – image height in pixels  
- `uint16_t planes` – number of color planes (always 1)  
- `uint16_t bitCount` – number of bits per pixel (e.g., 24, 32)  
- `uint32_t compression` – compression method used  
- `uint32_t imageSize` – size of raw pixel data  
- `int32_t xPixelsPerMeter` – horizontal resolution  
- `int32_t yPixelsPerMeter` – vertical resolution  
- `uint32_t colorsUsed` – number of colors used (0 = default)  
- `uint32_t colorsImportant` – number of important colors  

### Color masks
- `uint32_t redMask` – bit mask for the red channel  
- `uint32_t greenMask` – bit mask for the green channel  
- `uint32_t blueMask` – bit mask for the blue channel  
- `uint32_t alphaMask` – bit mask for the alpha channel  

### Color space & gamma
- `uint32_t csType` – color space type  
- `uint32_t endpoints[9]` – color space endpoints  
- `uint32_t gammaRed` – red gamma correction  
- `uint32_t gammaGreen` – green gamma correction  
- `uint32_t gammaBlue` – blue gamma correction  

---

# BMP

## Declaration
```
struct BMP
```

## Description
Represents a loaded BMP image, containing both headers and the raw pixel array.  
Provides a method to extract a color at a given pixel coordinate.

## Members
- `BMPHeader header` – the BMP file header  
- `BMPDIBHeader DIBHeader` – the DIB header containing image metadata  
- `std::vector<uint8_t> colorArray` – raw pixel data stored in row-major order  

---

## getColor

### Description
Returns the color at a given pixel position using the internal pixel array and the color masks specified in the DIB header.

### Declaration
```
Color getColor(const Vec2i& position) const;
```

### Parameters
- `const Vec2i& position` – pixel coordinates (x, y)  

### Return type
```
Color
```

---

# operator>>

## Description
Reads BMP header data and pixel array from the given input stream into a `BMP` structure.  
Assumes the stream contains a valid BMP file in binary form.

## Declaration
```
std::istream& operator>>(std::istream& is, BMP& bmp);
```

### Parameters
- `std::istream& is` – input stream containing BMP file data  
- `BMP& bmp` – output structure where the data will be stored  

### Return type
- ``std::istream&` – reference to the stream after extraction
