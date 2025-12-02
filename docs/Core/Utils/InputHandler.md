# InputHandler

## Header
```
#include "Core/Utils/InputHandler.hpp"
```

## Declaration
```
class InputHandler
```

## Priivate Attributes
- (Windows) none visible  
- (Non-Windows)
  - static bool sIsRawModeEnabled – tracks if terminal raw mode is enabled
  - termios mSavedTerminal – stores original terminal settings for restoration

## Member functions
- [constructor]
- [destructor]
- [getKey]
- [enableRawMode (Non-Windows)]
- [disableRawMode (Non-Windows)]
- [makeRaw (Non-Windows)]
- [applyTerminalSettings (Non-Windows)]

## example
InputHandler input;

while (true)
{
    auto key = input.getKey();
    if (key.has_value())
    {
        std::cout << "Pressed: " << key.value() << std::endl;
        if (key.value() == 'q') break;
    }
}

```
int main()
{
    InputHandler handler;

    while(true)
    {
        const std::optional<char> c = handler.getKey();

        if(c)
        {
            std::cout<<c.value()<<std::endl;
            if(c.value() == 'e'){ break; }
        }
    }

    return 0;
}
```

## constructor

### Description
Constructor that initializes the input handler and prepares the terminal or console for key input.

### Declaration
```
InputHandler();
```

## destructor

### Description
Destructor that restores terminal settings if modified (Non-Windows).

### Declaration
```
~InputHandler();
```

## getKey

### Description
Returns the last pressed key if available. On Windows uses `_kbhit` and `_getch`, on Non-Windows uses raw terminal mode. Returns an empty optional if no key was pressed.

### Declaration
```
std::optional<char> getKey();
```

### Return type
```
std::optional<char>
```

## enableRawMode (Non-Windows)

### Description
Enables raw mode in the terminal to allow non-blocking and unbuffered key input.

### Declaration
```
void enableRawMode();
```

## disableRawMode (Non-Windows)

### Description
Disables raw mode and restores previous terminal settings.

### Declaration
```
void disableRawMode();
```

## makeRaw (Non-Windows)

### Description
Converts a given termios configuration into raw mode settings.

### Declaration
```
termios makeRaw(const termios& current) const;
```

### Return type
```
termios
```

## applyTerminalSettings (Non-Windows)

### Description
Applies the given termios settings to the terminal.

### Declaration
```
void applyTerminalSettings(const termios& settings);
```
