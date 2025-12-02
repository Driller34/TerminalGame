# BMPLoader

## Header
```
#include "Core/Graphic/BMPLoader.hpp"
```

## Namespace
All functions are contained in the BMPLoader namespace.

## Member functions
- [bmpToImage](#bmptoimage)
- [loadBMP](#loadbmp)

## bmpToImage

### Description
Converts a loaded BMP structure into an Image object. This function interprets pixel data stored in the BMP and reconstructs a usable image representation.

Note: Only uncompressed BMP files are supported. BMP formats using compression are not handled.

### Declaration
```
Image bmpToImage(const BMP& bmp);
```

### Parameters
- `const BMP& bmp` – a parsed BMP structure containing header, DIB header, and raw pixel data

### Return type
```
Image
```

## loadBMP

### Description
Loads a BMP file from the given filesystem path, parses its header information, converts raw pixel data into an Image object, and returns the final result.

Note: The loader supports only uncompressed BMP files (compression field in DIB header must be 0).

### Declaration
```
Image loadBMP(const std::filesystem::path& path);
```

### Parameters
- `const std::filesystem::path& path` – path to the BMP file to be loaded

### Return type
```
Image
```