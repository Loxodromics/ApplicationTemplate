#include <SDL3/SDL.h>
#include <spdlog/spdlog.h>

namespace lfd {

constexpr int kWindowWidth = 800;
constexpr int kWindowHeight = 600;

int run()
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		spdlog::error("SDL initialization failed: {}", SDL_GetError());
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow(
		"Application Template",
		kWindowWidth,
		kWindowHeight,
		SDL_WINDOW_RESIZABLE
	);

	if (!window) {
		spdlog::error("Window creation failed: {}", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	spdlog::info("Window created successfully");

	bool running = true;
	SDL_Event event;

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
		}

		SDL_Delay(16);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

}

int main(int argc, char* argv[])
{
	return lfd::run();
}