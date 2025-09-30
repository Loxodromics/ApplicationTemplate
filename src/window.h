#pragma once

#include <SDL3/SDL.h>
#include <string>

namespace lfd {

/// Manages SDL3 window creation and lifecycle
class Window {
public:
	Window(const std::string& title, int width, int height);
	~Window();

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	[[nodiscard]] bool isOpen() const;
	[[nodiscard]] SDL_Window* getHandle() const;

private:
	/// Using raw pointer with manual RAII for clarity in skeleton code
	/// Could use std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> for more idiomatic C++
	SDL_Window* window;
};

}
