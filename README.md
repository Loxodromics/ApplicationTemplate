# Application Template

Base project skeleton for graphical, interactive C++20 applications using SDL3, glm, and spdlog.

## Architecture

The application follows a component-based architecture:
- **Application**: Main orchestrator that owns and coordinates all subsystems
- **Window**: SDL3 window management with RAII resource handling
- **EventHandler**: SDL3 event processing and application state management
- **GameLoop**: Frame timing, delta time calculation, and FPS tracking

## Requirements

- CMake 3.20 or later
- Conan 2
- C++20 compatible compiler (GCC 11+, Clang 13+, or MSVC 2019+)

## Platform Support

- Linux (X11 and Wayland)
- macOS

## Build Instructions

```bash
# Install dependencies
conan install . --output-folder=build --build=missing

# Configure project
cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug

# Build project
cmake --build build

# Run application
./build/ApplicationTemplate
```

## Dependencies

- **SDL3** 3.2.20: Windowing, input, and audio
- **glm** 1.0.1: OpenGL mathematics library
- **spdlog** 1.14.1: Fast logging library