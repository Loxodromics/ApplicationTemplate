#include "eventhandler.h"
#include <spdlog/spdlog.h>

namespace lfd {

EventHandler::EventHandler()
	: event{}
{
}

bool EventHandler::processEvents()
{
	while (SDL_PollEvent(&this->event)) {
		switch (this->event.type) {
		case SDL_EVENT_QUIT:
			spdlog::info("Quit event received");
			return false;

		default:
			break;
		}
	}

	return true;
}

}
