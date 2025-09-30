#pragma once

#include <SDL3/SDL.h>

namespace lfd {

/// Processes SDL3 events and determines application state
class EventHandler {
public:
	EventHandler();
	~EventHandler() = default;

	/// Polls and processes all pending events
	/// Returns true if application should continue running
	[[nodiscard]] bool processEvents();

private:
	SDL_Event event;
};

}
