# Option

## Header
```
#include "Core/GUI/OptionList.hpp"
```

## Declaration
```
struct gui::Option
```

## Description
Represents a single menu option. It contains a visual representation, a color, and a callback function to execute when selected.  
Belongs to the `gui` namespace.

## Attributes
- `Image image` – the visual representation of the option
- `Color color` – the color of the option when it is selected
- `std::function<void()> onAction` – callback function executed when the option is selected

---

# OptionList

## Header
```
#include "Core/GUI/OptionList.hpp"
```

## Declaration
```
class gui::OptionList : public Drawable, public Transformable
```

## Description
A container for multiple `Option` objects. Allows selecting options, executing callbacks, and rendering the list.  
Belongs to the `gui` namespace.

## Private attributes
- `size_t mSelectedOption` – index of the currently selected option
- `size_t mMargin` – space between options
- `gui::Rectangle mHighlight` – rectangle used to highlight the selected option
- `std::vector<Option> mOptions` – list of available options

## Member functions
- [constructor](#constructor)
- [addOption](#addoption)
- [selectNext](#selectnext)
- [selectPrev](#selectprev)
- [executeSelectedOption](#executeselectedoption)
- [draw](#draw)

## constructor

### Description
Initializes the OptionList with an optional margin between options. The first option is selected by default.

### Declaration
```
OptionList(const size_t margin = 0);
```

### Parameters
- `const size_t margin` – optional margin between options (default 0)

## addOption

### Description
Adds a new `Option` to the list.

### Declaration
```
void addOption(const Option& option);
```

### Parameters
- `const Option& option` – the option to add

## selectNext

### Description
Selects the next option in the list, wrapping around to the first option if currently at the last one.

### Declaration
```
void selectNext();
```

## selectPrev

### Description
Selects the previous option in the list, wrapping around to the last option if currently at the first one.

### Declaration
```
void selectPrev();
```

## executeSelectedOption

### Description
Executes the callback function of the currently selected option.

### Declaration
```
void executeSelectedOption();
```

## draw

### Description
Draws all options to the given render target at the specified position, highlighting the selected option.

### Declaration
```
virtual void draw(Window& renderTarget, const Vec2i& position) override;
```

### Parameters
- `Window& renderTarget` – the window where the options will be drawn
- `const Vec2i& position` – position on the render target where the list should be rendered
