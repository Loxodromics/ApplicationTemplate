# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

C++20 application template for graphical, interactive applications using SDL3, glm, and spdlog. Targets Linux (X11/Wayland) and macOS.

The application follows a component-based architecture:
- **Application**: Main orchestrator that owns and coordinates all subsystems
- **Window**: SDL3 window management with RAII resource handling
- **EventHandler**: SDL3 event processing and application state management
- **GameLoop**: Frame timing, delta time calculation, and FPS tracking

## 
Coding Style Guidelines
* Use camelCase for methods and variables, PascalCase for classes and enums
* Use kPascalCase for constants
* Use all lowercase letters for filenames without underscores or hyphens
* Use lowercase with underscores for namespaces
* Follow Qt's coding style guidelines, but access all members via this-> instead of prefixing with m_
* Use "pointer-to-type" style
* Use K&R brace placement
* Place implementation (.cpp) and header (.h) files next to each other in the src directory
* Use three slashes (///) for comments to differentiate from commented code
* Use tabs for indentation with 4-space tab stops
* Comments should explain complex algorithms, business decisions, and non-obvious code patterns. Do not comment self-explanatory code like simple getters, setters, or obvious operations. Focus on WHY the code exists, not WHAT it does. If a function name clearly describes what it does, additional comments are usually unnecessary
* Comments are written saying 'we' instead of 'I' or passive voice
* Use descriptive names for classes, variables, and functions
* Use const and constexpr for variables and methods where applicable
* Write modern C++ code (C++20) with modern features
* Discourage auto usage except where it genuinely improves readability
* Prefer std::unique_ptr by default for managed pointers. Use std::shared_ptr only when you genuinely need shared ownership semantics
* Use [[nodiscard]] for functions where ignoring the return value would be an error (validation functions, resource acquisition). Avoid for simple getters or functions where the return value is commonly ignored


## Build System

- **Build tool**: CMake 3.20+ with Ninja generator
- **Dependency management**: Conan 2
- **Standard**: C++20 (required, no extensions)

### Build Commands

```bash
# Install dependencies
conan install . --output-folder=build --build=missing

# Configure project
cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug

# Build project
cmake --build build

# Clean build
rm -rf build
```

## Code Organization

- **Namespace**: `lfd` (base namespace for all project code)
- **File naming**: All lowercase, no underscores or hyphens (e.g., `myfile.cpp`, `myfile.h`)
- **Namespace naming**: Lowercase with underscores (e.g., `my_namespace`)
- **Header/implementation**: Place `.h` and `.cpp` files side-by-side in `src/`
- **CMake modules**: Place in `cmake/` directory

## Dependencies

- **SDL**: 3.2.20 (windowing, input, audio)
- **glm**: 1.0.1 (OpenGL mathematics)
- **spdlog**: 1.14.1 (logging)

## Requirements

- CMake 3.20+
- Conan 2
- C++20 compiler (GCC 11+, Clang 13+, MSVC 2019+)
