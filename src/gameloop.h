#pragma once

#include <cstdint>

namespace lfd {

/// Manages frame timing, delta time calculation, and FPS tracking
class GameLoop {
public:
	GameLoop();
	~GameLoop() = default;

	void beginFrame();
	void endFrame();

	[[nodiscard]] float getDeltaTime() const;
	[[nodiscard]] float getFPS() const;

private:
	uint64_t lastFrameTime;
	uint64_t currentFrameTime;
	float deltaTime;
	float fps;

	/// FPS calculation
	int frameCount;
	uint64_t fpsLastTime;
};

}
