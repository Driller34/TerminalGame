# Clock

## Header
```
#include "Core/Utils/Clock.hpp"
```

## Declaration
```
class Clock
```

## Member functions
- [constructor](#constructor)
- [restart](#restart)
- [elapsedTime](#elapsedtime)

## example
```
int main()
{
    Clock clock;
    usleep(500'000);
    std::cout<<clock.elapsedTime().count()<<" ms"<<std::endl; // output: ~500 ms
    clock.restart();
    std::cout<<clock.elapsedTime().count()<<" ms"<<std::endl; // output: ~0 ms

    return 0;
}
```

## constructor

### Description
This is the constructor of the Clock class; it initializes the starting time to the current high-resolution clock time.

### Declaration
```
Clock();
```

## restart

### Description
This method resets the clock's starting point to the current time and returns the elapsed time since the previous start.

### Declaration
```
std::chrono::milliseconds restart();
```


### Return type
```
std::chrono::milliseconds
```

## elapsedTime

### Description
This method returns the elapsed time in milliseconds since the clock was started or last restarted, without modifying the starting point.

### Declaration

```
std::chrono::milliseconds elapsedTime() const;
```

### Return type
```
std::chrono::milliseconds
```