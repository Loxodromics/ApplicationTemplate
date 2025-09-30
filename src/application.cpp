#include "application.h"
#include <spdlog/spdlog.h>
#include <SDL3/SDL.h>

namespace lfd {

constexpr int kWindowWidth = 800;
constexpr int kWindowHeight = 600;

Application::Application()
	: window(nullptr)
	, eventHandler(nullptr)
	, gameLoop(nullptr)
{
}

Application::~Application()
{
	this->shutdown();
}

bool Application::initializeSDL()
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		spdlog::error("SDL initialization failed: {}", SDL_GetError());
		return false;
	}

	spdlog::info("SDL initialized successfully");
	return true;
}

void Application::shutdown()
{
	/// RAII handles cleanup of window, eventHandler, and gameLoop
	this->window.reset();
	this->eventHandler.reset();
	this->gameLoop.reset();

	SDL_Quit();
	spdlog::info("Application shutdown complete");
}

int Application::run()
{
	try {
		if (!this->initializeSDL()) {
			return 1;
		}

		this->window = std::make_unique<Window>("Application Template", kWindowWidth, kWindowHeight);
		this->eventHandler = std::make_unique<EventHandler>();
		this->gameLoop = std::make_unique<GameLoop>();

		spdlog::info("Application started");

		bool running = true;
		while (running) {
			this->gameLoop->beginFrame();

			running = this->eventHandler->processEvents();

			/// Update logic would go here

			/// Render would go here

			this->gameLoop->endFrame();

			/// Basic frame rate limiting (~60 FPS)
			/// Production code should account for processing time and use delta time for timing
			SDL_Delay(16);
		}

		spdlog::info("Application exiting normally");
		return 0;

	} catch (const std::exception& e) {
		spdlog::error("Application error: {}", e.what());
		return 1;
	}
}

}
