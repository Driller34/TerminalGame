# rng Namespace

## Header
```
#include "Core/Utils/RNG.hpp"
```

## Declaration
```
namespace rng
```

## Member functions
- [randomInt](#randomint)

## example
```
int main()
{
    Vec2i range{5, 10};
    int value = rng::randomInt(range);
    std::cout<<value<<std::endl; // output: some integer between 5 and 10

    return 0;
}
```

## randomInt

### Description
This function generates a random integer between the two values specified in the given Vec2i range. 
The order of range.x and range.y does not matter.

### Declaration
```
int randomInt(const Vec2i& range);
```

### Parameters
- const Vec2i& range – a vector specifying the range; x and y are the bounds (inclusive)

### Return type
```
int
```
