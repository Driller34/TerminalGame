# ProgressBar

## Header
```
#include "Core/GUI/ProgressBar.hpp"
```

## Declaration
```
class gui::ProgressBar : public Drawable, public Transformable
```

## Description
Represents a horizontal progress bar that can display a current value relative to a maximum value.  
Belongs to the `gui` namespace.  
Inherits from `Drawable` and `Transformable`, so it can be rendered and transformed.

## Private attributes
- `const size_t mWidth` – width of the progress bar
- `const size_t mHeight` – height of the progress bar
- `const int mMaxValue` – maximum value of the progress bar
- `int mValue` – current value of the progress bar
- `const Color mValueColor` – color representing the filled portion of the bar
- `const Color mEmptyColor` – color representing the empty portion of the bar

## Member functions
- [constructor](#constructor)
- [setValue](#setvalue)
- [getValue](#getvalue)
- [getMaxValue](#getmaxvalue)
- [draw](#draw)
- [getValueWidth(PRIVATE)](#getvaluewidth-private)

## constructor

### Description
Initializes the ProgressBar with a given size, maximum value, and optional colors for the filled and empty portions.

### Declaration
```
ProgressBar(const size_t width,
    const size_t height,
    const int maxValue,
    const Color& valueColor = {255, 0, 0, 255},
    const Color& emptyColor = {92, 92, 91, 255});
```

### Parameters
- `const size_t width` – width of the progress bar
- `const size_t height` – height of the progress bar
- `const int maxValue` – maximum value of the progress bar
- `const Color& valueColor` – color of the filled portion (default red)
- `const Color& emptyColor` – color of the empty portion (default gray)

## setValue

### Description
Sets the current value of the progress bar. Values outside the range [0, maxValue] should be clamped.

### Declaration
```
void setValue(const int value);
```

### Parameters
- `const int value` – new value to set

## getValue

### Description
Returns the current value of the progress bar.

### Declaration
```
int getValue() const;
```

### Return type
int

## getMaxValue

### Description
Returns the maximum value of the progress bar.

### Declaration
```
int getMaxValue() const;
```

### Return type
int

## draw

### Description
Draws the progress bar to the given render target at the specified position.

### Declaration
```
virtual void draw(Window& renderTarget,
    const Vec2i& position) override;
```

### Parameters
- `Window& renderTarget` – the window where the progress bar will be drawn
- `const Vec2i& position` – position on the render target

### Return type
void

## getValueWidth (PRIVATE)

### Description
Calculates the width in pixels of the filled portion of the progress bar based on the current value.

### Declaration
```
int getValueWidth() const;
```

### Return type
int
