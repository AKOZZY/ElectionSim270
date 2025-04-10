#pragma once
#include <vector>
#include "raylib.h"

class State
{
public:
	// Create State
	State(const char* stateName, Texture2D stateBorder, Texture2D stateFill, Vector2 position);
	~State();

	void AddVertexPoint(Vector2 vertexPoint);
	Vector2 GetPosition();

	void Render();
	void RenderVertexPoints();

	bool IsMouseOverState(Vector2 mousePosition);
private:
	// State Charactoristics
	const char* stateName{};
	Texture2D stateBorder{};
	Texture2D stateFill{};
	Vector2 position{};
	std::vector<Vector2> vertexPoints{};
};

