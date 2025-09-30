#pragma once

#include "window.h"
#include "eventhandler.h"
#include "gameloop.h"
#include <memory>

namespace lfd {

/// Main application orchestrator
class Application {
public:
	Application();
	~Application();

	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;

	[[nodiscard]] int run();

private:
	bool initializeSDL();
	void shutdown();

	std::unique_ptr<Window> window;
	std::unique_ptr<EventHandler> eventHandler;
	std::unique_ptr<GameLoop> gameLoop;
};

}
