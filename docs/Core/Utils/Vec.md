# Vec2\<T>

## Header
```
#include "Core/Utils/Vec.hpp"
```

## Declaration
```
template<typename T>
struct Vec2
```

## Aliases
```
Vec2i = Vec2<int>
```

```
Vec2ull = Vec2<size_t>
```

## Attributes
- T x - x coordinate of vec2 
- T y - y coordinate of vec2 

## Member functions
- [operator*](#operator)
- [operator+](#operator-1)
- [operator-](#operator-2)
- [operator+=](#operator-3)
- [operator-=](#operator-4)

## example
```
int main()
{
    Vec2<int> v{2, 3};

    std::cout<<v.x<<std::endl; // output: 2
    std::cout<<v.y<<std::endl; // output: 3

    return 0;
}
```

## operator*

### Description
this method multiply all vec2 coordinates by n and return new vec2 type

### Declaration
```
Vec2 operator*(const T n) const
```

### Return type
```
Vec2<T>
```

## operator+

### Description
this method add coordinates from other vec2 to coordinates from current vec2 and return new vec2 type

### Declaration
```
Vec2 operator+(const Vec2& other) const
```

### Return type
```
Vec2<T>
```

## operator-

### Description
This method returns a new vector created by subtracting either:

- the coordinates of another Vec2 from the current vector, or

- a scalar value n from both coordinates of the current vector.

### Declaration
```
Vec2 operator-(const Vec2& other) const
```

```
Vec2 operator-(const T n) const
```

### Return type
```
Vec2<T>
```

## operator+=

### Description
This method modifies the current vector by adding:

- a scalar value n to both coordinates, or

- the corresponding coordinates of another Vec2.

### Declaration
```
Vec2& operator+=(const T n)
```

```
Vec2& operator+=(const Vec2<T>& other)
```

### Return type
```
Vec2<T>&
```

## operator-=

### Description
This method modifies the current vector by subtracting:

- the coordinates of another Vec2, or

- a scalar value n from both coordinates.

### Declaration
```
Vec2& operator-=(const Vec2<T>& other)
```

```
Vec2& operator-=(const T n)
```

### Return type
```
Vec2<T>&
```

