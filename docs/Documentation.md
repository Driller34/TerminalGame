# Documentation

## Architecture

This section describes the high-level structure of the application and its main components.

- **App** – the main application layer responsible for coordinating the program’s execution, managing the main loop, and integrating different modules.  

- **Core** – a collection of reusable utilities and fundamental systems, such as math structures, input handling, and basic helpers, which can be used across multiple projects.

## Core
- **Utils**
    - [Clock](Core/Utils/Clock.md)
    - [Collision](Core/Utils/Collision.md)
    - [Color](Core/Utils/Color.md)
    - [InputHandler](Core/Utils/InputHandler.md)
    - [RNG](Core/Utils/RNG.md)
    - [Vec](Core/Utils/Vec.md)
- **Layers**
    - [Layer](Core/Layers/Layer.md)
    - [LayerManager](Core/Layers/LayerManager.md)
    - [MenuLayer](Core/Layers/MenuLayer.md)