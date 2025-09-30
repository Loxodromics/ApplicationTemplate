#include "application.h"
#include <spdlog/spdlog.h>
#include <exception>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	try {
		spdlog::set_level(spdlog::level::info);
		spdlog::info("Starting application");

		lfd::Application app;
		return app.run();

	} catch (const std::exception& e) {
		spdlog::critical("Unhandled exception: {}", e.what());
		return 1;
	} catch (...) {
		spdlog::critical("Unknown exception occurred");
		return 1;
	}
}