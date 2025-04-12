#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "State.h"
#include "StateTooltip.h"

class Game
{
public:
	// Init Game
	Game();
	// De-Init Game
	~Game();
	// Game Loop Functions
	void Update();
	void Render();
private:
	// State Borders
	Texture2D stateBorders{};
	// States Vector
	std::vector<State*> states{};
	// State Tooltip
	StateTooltip stateTooltip{};
	State* selectedState{};
	// Reference States
	State* california{};
	Texture2D californiaTexture{};
	// Reference State Vertex Points
	std::vector<Vector2> nevadaVertexPoints{};
	// Map Offset
	float mapOffsetX{ 120.0f };
	float mapOffsetY{ 50.0f };
};

// Template Functions
template <typename T> void LogToConsole(T input)
{
	std::cout << input << "\n";
}