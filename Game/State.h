#pragma once
#include <vector>
#include "raylib.h"

class State
{
public:
	// Create State
	State(const char* stateName, Texture2D stateTexture, Vector2 position);
	~State();

	void AddVertexPoint(Vector2 vertexPoint);

	Vector2 GetPosition();
	const char* GetName();

	void Render();
	void RenderVertexPoints();

	bool IsMouseOverState(Vector2 mousePosition);
private:
	// State Charactoristics
	const char* stateName{};
	Texture2D stateTexture{};
	Vector2 position{};
	std::vector<Vector2> vertexPoints{};

	// State Colors
	Color tossup{ WHITE };
	// Republican
	Color safeGOP{ 119, 31, 31, 255 };
	Color likelyGOP{ 176, 64, 64, 255 };
	Color leanGOP{ 233, 115, 115, 255 };
	Color tiltGOP{ 207, 137, 128, 255 };
	// Democrat
	Color safeDEM{ 59, 83, 162, 255 };
};

