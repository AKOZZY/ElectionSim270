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
	// States Vector
	std::vector<State*> states{};
	// State Tooltip
	StateTooltip stateTooltip{};
	// Reference States
	State* california{};
	State* nevada{};
	// Reference State Vertex Points
	std::vector<Vector2> californiaVertexPoints{};
	std::vector<Vector2> nevadaVertexPoints{};
};

// Template Functions
template <typename T> void LogToConsole(T input)
{
	std::cout << input << "\n";
}