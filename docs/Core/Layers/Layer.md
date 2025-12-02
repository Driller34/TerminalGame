# Layer

## Header
```
#include "../Graphic/Window.hpp"
```

## Declaration
```
class Layer
```

## Description
Layer is a base class for layers that can be stored in a LayerManager.

## Member functions
- [destructor](#destructor)
- [init](#init)
- [update](#update)
- [draw](#draw)
- [activateState](#activatestate)
- [inputHandler](#inputhandler)

## destructor

### Description
Virtual destructor to allow proper cleanup of derived classes.

### Declaration
```
virtual ~Layer() = default;
```

## init

### Description
Pure virtual method that initializes the layer.

### Declaration
```
virtual void init() = 0;
```

## update

### Description
Pure virtual method that updates the layer logic. Called each frame or update cycle while the layer is active.

### Declaration
```
virtual void update() = 0;
```

## draw

### Description
Pure virtual method that renders the layer to the given window.

### Declaration
```
virtual void draw(Window& window) = 0;
```

### Parameters
- Window& window – reference to the window where the layer should be drawn

## activateState

### Description
Pure virtual method called when the layer becomes the top layer on the stack. Used to perform actions when the layer gains focus or control.

### Declaration
```
virtual void activateState() = 0;
```

## inputHandler

### Description
Pure virtual method to handle key input for the layer.

### Declaration
```
virtual void inputHandler(const char pressedKey) = 0;
```

### Parameters
- const char pressedKey – the key that was pressed