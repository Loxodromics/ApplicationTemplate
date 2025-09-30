#include "gameloop.h"
#include <SDL3/SDL.h>
#include <spdlog/spdlog.h>

namespace lfd {

GameLoop::GameLoop()
	: lastFrameTime(SDL_GetPerformanceCounter())
	, currentFrameTime(lastFrameTime)
	, deltaTime(0.0f)
	, fps(0.0f)
	, frameCount(0)
	, fpsLastTime(lastFrameTime)
{
}

void GameLoop::beginFrame()
{
	this->currentFrameTime = SDL_GetPerformanceCounter();

	uint64_t elapsed = this->currentFrameTime - this->lastFrameTime;
	this->deltaTime = static_cast<float>(elapsed) / static_cast<float>(SDL_GetPerformanceFrequency());
}

void GameLoop::endFrame()
{
	this->lastFrameTime = this->currentFrameTime;
	this->frameCount++;

	/// Calculate FPS every second
	uint64_t elapsedSinceLastFPS = this->currentFrameTime - this->fpsLastTime;
	float elapsedSeconds = static_cast<float>(elapsedSinceLastFPS) / static_cast<float>(SDL_GetPerformanceFrequency());

	if (elapsedSeconds >= 1.0f) {
		this->fps = static_cast<float>(this->frameCount) / elapsedSeconds;
		spdlog::info("FPS: {:.1f}", this->fps);

		this->frameCount = 0;
		this->fpsLastTime = this->currentFrameTime;
	}
}

float GameLoop::getDeltaTime() const
{
	return this->deltaTime;
}

float GameLoop::getFPS() const
{
	return this->fps;
}

}
