# collision Namespace

## Header
```
#include "Core/Utils/Collision.hpp"
```

## Declaration
```
namespace collision
```

## Member functions
- [isPointInRect]
- [isEntityInRect]
- [isColliding]

## example
```
int main()
{
    Vec2i topLeft{0, 0};
    Vec2i bottomRight{10, 10};

    bool inside = collision::isPointInRect(Vec2i{5, 5}, topLeft, bottomRight);
    std::cout<<inside<<std::endl; // output: true

    return 0;
}
```

## isPointInRect

### Description
This function checks if a given point lies within a rectangle defined by top-left and bottom-right coordinates.

### Declaration
```
bool isPointInRect(const Vec2i& point,
    const Vec2i& topLeft,
    const Vec2i& bottomRight);
```

### Parameters
- const Vec2i& point – the point to check
- const Vec2i& topLeft – the top-left corner of the rectangle
- const Vec2i& bottomRight – the bottom-right corner of the rectangle

### Return type
```
bool
```

## isEntityInRect

### Description
This function checks if the position of a given entity lies within a rectangle defined by top-left and bottom-right coordinates.

### Declaration
```
bool isEntityInRect(const Entity* a,
    const Vec2i& topLeft,
    const Vec2i& bottomRight);
```

### Parameters
- const Entity* a – pointer to the entity
- const Vec2i& topLeft – the top-left corner of the rectangle
- const Vec2i& bottomRight – the bottom-right corner of the rectangle

### Return type
```
bool
```

## isColliding

### Description
This function checks whether two entities are colliding based on their positions and sizes.

### Declaration
```
bool isColliding(const Entity* a, const Entity* b);
```

### Parameters
- const Entity* a – pointer to the first entity
- const Entity* b – pointer to the second entity

### Return type
```
bool
```