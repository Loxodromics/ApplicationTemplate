#include "window.h"
#include <spdlog/spdlog.h>

namespace lfd {

Window::Window(const std::string& title, int width, int height)
	: window(nullptr)
{
	this->window = SDL_CreateWindow(
		title.c_str(),
		width,
		height,
		SDL_WINDOW_RESIZABLE
	);

	if (!this->window) {
		spdlog::error("Window creation failed: {}", SDL_GetError());
		throw std::runtime_error("Failed to create window");
	}

	spdlog::info("Window created: {}x{}", width, height);
}

Window::~Window()
{
	if (this->window) {
		SDL_DestroyWindow(this->window);
		spdlog::debug("Window destroyed");
	}
}

bool Window::isOpen() const
{
	return this->window != nullptr;
}

SDL_Window* Window::getHandle() const
{
	return this->window;
}

}
