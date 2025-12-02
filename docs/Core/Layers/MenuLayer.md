# MenuLayer

## Header
```
#include "Core/Layers/MenuLayer.hpp"
```


## Declaration
```
class MenuLayer : public Layer
```

### Description
MenuLayer is a layer that displays a menu with options.  
It **inherits from `Layer`**, so it can be managed by `LayerManager` and overrides all virtual methods from the base class.


## Private attributes
- `LayerManager& mLayerManager` – reference to the LayerManager handling this layer
- `Image mBackgroundImage` – the background image for the menu
- `gui::OptionList mMenuOptions` – list of menu options displayed in this layer

## Member functions
- [constructor](#constructor)
- [init](#init)
- [update](#update)
- [draw](#draw)
- [activateState](#activatestate)
- [inputHandler](#inputhandler)
- [addOption](#addoption)

## constructor

### Description
Initializes the MenuLayer with a reference to the LayerManager, a background image, and the position where menu options will be displayed.

### Declaration
```
MenuLayer(LayerManager& layerManager,
    const Image& backgroundImage,
    const Vec2i& optionsPosition);
```

### Parameters
- `LayerManager& layerManager` – reference to the LayerManager
- `const Image& backgroundImage` – background image for the menu
- `const Vec2i& optionsPosition` – position where menu options will be displayed

## init

### Description
Initializes the menu layer, setting up internal structures and preparing menu options for display.

### Declaration
```
virtual void init() override;
```

## update

### Description
Updates the menu layer, including the state of menu options and any internal animations.

### Declaration
```
virtual void update() override;
```

## draw

### Description
Renders the background and menu options onto the given window.

### Declaration
```
virtual void draw(Window& window) override;
```

### Parameters
- Window& window – reference to the window where the menu will be drawn


## activateState

### Description
This method is called when the layer becomes the top layer on the stack

### Declaration
```
virtual void activateState() override;
```

## inputHandler

### Description
Handles user input by forwarding key presses to the menu options for navigation or selection.

### Declaration
```
virtual void inputHandler(const char pressedKey) override;
```

### Parameters
- const char pressedKey – the key that was pressed

## addOption

### Description
Adds a new option to the menu with an associated callback.

### Declaration
```
void addOption(const gui::Option& option);
```

### Parameters
- const gui::Option& option – the menu option to add