# TerminalGame 🎮

TerminalGame is a **Space Invaders–style game** created as a **student project at the University of Wrocław**, running entirely in the terminal using ANSI escape codes.  
Built with modern **C++23** and **CMake** for cross‑platform compatibility.

## ✨ Features
- 🕹️ Classic Space Invaders gameplay in the terminal
- 🌈 Graphics loaded from custom BMP files (hand‑crafted assets)
- 🧩 Layered rendering system for menus, gameplay, and pause screen
- ⏸️ Pause functionality with ESC
- 📋 Main menu system to start or exit the game
- 🎚️ Three difficulty levels: Easy, Medium, Hard
- ⚡ Fully self‑implemented rendering — no external graphics libraries

## 🛠Technologies Used
- ⚡C++ 23
-  🏗CMake for cross-platform building
- 📊 [Google Benchmark](https://github.com/google/benchmark)

## 🖥️ Tested Platforms
- 🐧 Linux (Manjaro 25.0, Arch Linux)
- 🪟 Windows 11

## Getting Started

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Driller34/TerminalGame
   cd TerminalGame
   ```

2. **Build the project:**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ./bin/Game
   ```

## 🎮Controls
- ⬆️ **W** → move up
- ⬇️ **S** → move down
- ➡️ **D** → move right
- ⬅️ **A** → move left
- 🔫 **SPACE** → accept / fire
- ⏸️ **ESC** → Pause game

## Optional Build Targets

The project includes additional executables that are disabled by default:

### Benchmarks
To build Google Benchmark performance tests:

```
cmake -DBUILD_BENCHMARKS=ON ..
make
```

### Sandbox Programs
To build sandbox testing executables:

```
cmake -DBUILD_SANDBOX=ON ..
make
```

## 📄Licence
MIT
