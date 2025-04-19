#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "raylib.h"
#include "State.h"
#include "StateTooltip.h"
#include "Button.h"
#include "Scenario.h"

enum GameState
{
	IN_MAIN_MENU,
	IN_GAME,
	IN_RESULTS
};

enum MenuState
{
	DEFAULT,
	IN_SCENARIO_SCREEN,
};

class Game
{
public:
	// Init Game
	Game();
	// De-Init Game
	~Game();
	// In Menu Functions
	void UpdateMenu();
	void RenderMenu();
	// In Game Functions
	void Update();
	void Render();
	// Game State
	GameState gameState{};
	// Menu State
	MenuState menuState{};
	// Game Functions
	void UpdateRepublicanElectoralVotes();
	void UpdateDemocraticElectoralVotes();
	int EVCalculator(std::string nameOfParty);
private:
	// Party EVs
	int democraticEVCount{};
	int republicanEVCount{};
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
	State* nevada{};
	State* alaska{};
	State* hawaii{};
	State* oregon{};
	State* washington{};
	// Reference State Vertex Points
	std::vector<Vector2> nevadaVertexPoints{};
	// Map Offset
	float mapOffsetX{ 10.0f };
	float mapOffsetY{ 70.0f };
	// Menu 
	Texture2D gameLogo{};
	// Create Buttons
	Button* buttonScenario2024{};
	Button* buttonModernScenarios{};
	Button* buttonVisitState{};
	Button* buttonCancelVisitState{};
	// Scenarios
	Scenario* scenario{};
};

// Template Functions
template <typename T> void LogToConsole(T input)
{
	std::cout << input << "\n";
}