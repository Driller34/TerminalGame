# Transformable

## Header
```
#include "Core/Base/Transformable.hpp"
```

## Declaration
```
class Transformable
```

## Description
Transformable is a base class providing positional data and movement utilities.  
Any class inheriting from Transformable gains the ability to store, modify, and move its position in 2D space using Vec2i.

## Private attributes
- `Vec2i mPosition` – the current position of the object in 2D space

## Member functions
- [constructor](#constructor)
- [destructor](#destructor)
- [setPosition](#setposition)
- [getPosition](#getposition)
- [move](#move)

## constructor

### Description
Initializes the object with a default position of (0, 0).

### Declaration
```
Transformable();
```

## destructor

### Description
Default virtual destructor allowing safe polymorphic cleanup for derived classes.

### Declaration
```
virtual ~Transformable() = default;
```

## setPosition

### Description
Sets the object's position to the given 2D coordinate.

### Declaration
```
void setPosition(const Vec2i& position);
```

### Parameters
- `const Vec2i& position` – the new position

## getPosition

### Description
Returns the current position of the object.

### Declaration
```
Vec2i getPosition() const;
```

### Return type
```
Vec2i
```

## move

### Description
Moves the object by adding the given offset to its current position.

### Declaration
```
void move(const Vec2i& offset);
```

### Parameters
- `const Vec2i& offset` – the displacement to apply

# IsTransformable

## Declaration
```
template<typename T>
concept IsTransformable = std::derived_from<T, Transformable>;
```

## Description
Concept restricting template parameters to types derived from Transformable.  
Ensures the type supports positional transformations.
