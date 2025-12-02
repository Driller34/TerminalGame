# Color

## Header
```
#include "Core/Utils/Color.hpp"
```

## Declaration
```
struct Color
```

## Attributes
- `uint8_t red` – red channel (default 0)
- `uint8_t green` – green channel (default 0)
- `uint8_t blue` – blue channel (default 0)
- `uint8_t alpha` – alpha channel (default 255)

## Member functions
- [toString](#tostring)
- [operator*](#operator)
- [operator+](#operator-1)

## example
```
int main()
{
    Color c1{255, 100, 50};
    Color c2{50, 50, 50};

    Color c3 = c1 + c2;
    Color c4 = c1 * 0.5;

    std::cout<<c3.toString()<<std::endl; // output: "255;150;100"
    std::cout<<c4.toString()<<std::endl; // output: "127;50;25"

    return 0;
}
```

## toString

### Description
This method returns a string representation of the color in the format "red;green;blue".

### Declaration
```
std::string toString() const;
```

### Return type
```
std::string
```

## operator*

### Description
This method multiplies each color channel (including alpha) by the given scalar value and returns a new Color.

### Declaration
```
Color operator*(const double n) const;
```

### Return type
```
Color
```

## operator+

### Description
This method adds the channels of another Color to the current Color, clamping each channel to a maximum of 255, and returns a new Color.

### Declaration
```
Color operator+(const Color& color) const;
```

### Return type
```
Color
```