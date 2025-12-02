# LayerManager

## Header
```
#include "Core/Layers/LayerManager.hpp"
```

## Declaration
```
class LayerManager
```

## Private attributes
- `std::stack<std::unique_ptr\<Layer>> layers` – stack of layers managed by the LayerManager

## Member functions
- [constructor](#constructor)
- [update](#update)
- [render](#render)
- [inputHandler](#inputhandler)
- [push](#push)
- [pop](#pop)
- [change](#change)
- [top](#top)
- [empty](#empty)

## constructor

### Description
Constructor that initializes the LayerManager with an empty stack of layers.

### Declaration
```
LayerManager();
```

## update

### Description
Updates the top layer in the stack by calling its `update` method.

### Declaration
```
void update();
```

## render

### Description
Renders top layer in the stack to the given Window object.

### Declaration
```
void render(Window& window);
```

### Parameters
- Window& - refference to the window object

## inputHandler

### Description
Forwards a key press to the top layer in the stack to handle input.

### Declaration
```
void inputHandler(const char pressedKey);
```

### Parameters
- const char pressedKey – the key that was pressed

## push

### Description
Adds a new layer to the top of the stack.

### Declaration
```
void push(std::unique_ptr<Layer> layer);
```

### Parameters
- std::unique_ptr\<Layer> layer – the layer to push onto the stack

## pop

### Description
Removes one or more layers from the top of the stack.

### Declaration
```
void pop(const size_t n = 1ULL);
```

### Parameters
- const size_t n – the number of layers to remove (default is 1)

## change

### Description
Pop all the layers and push a new layer onto the stack.

### Declaration
```
void change(std::unique_ptr<Layer> layer);
```

### Parameters
- std::unique_ptr\<Layer> layer – the new layer to replace the top layer

## top

### Description
Returns a pointer to the top layer in the stack without removing it.

### Declaration
```
Layer* top() const;
```

### Return type
```
Layer*
```

## empty

### Description
Checks if the layer stack is empty.

### Declaration
```
bool empty() const;
```

### Return type
```
bool
```