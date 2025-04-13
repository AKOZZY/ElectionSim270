#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "raylib.h"
#include "State.h"
#include "StateTooltip.h"
#include "Button.h"

enum GameState
{
	IN_MAIN_MENU,
	IN_GAME,
	IN_RESULTS
};

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
	// Game State
	GameState gameState{};
private:
	// State Borders
	Texture2D stateBorders{};
	// States Vector
	std::vector<State*> states{};
	// State Tooltip
	StateTooltip stateTooltip{};
	State* selectedState{};
	// State Visit
	bool hasClickedStateVisit{};
	// Reference States
	State* california{};
	Texture2D californiaTexture{};
	// Reference State Vertex Points
	std::vector<Vector2> nevadaVertexPoints{};
	// Map Offset
	float mapOffsetX{ 10.0f };
	float mapOffsetY{ 80.0f };
	// Create Buttons
	Button* buttonVisitState{};
	Button* buttonCancelVisitState{};
};

// Template Functions
template <typename T> void LogToConsole(T input)
{
	std::cout << input << "\n";
}