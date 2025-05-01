#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "raylib.h"
#include "State.h"
#include "StateTooltip.h"
#include "Button.h"
#include "Scenario.h"
#include "StateManager.h"

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
	void RandomizeSupport();
	// Game State
	GameState gameState{};
	// Menu State
	MenuState menuState{};
	// Game Functions
	int EVCalculator(std::string nameOfParty);
private:
	// Timers
	float timer{};
	float updateInterval{ 1 };
	// States Vector
	StateManager* stateManager{};
	// State Tooltip
	StateTooltip stateTooltip{};
	State* selectedState{};
	// State Visit
	bool hasClickedStateVisit{};
	bool hasClickedSimulate{};
	// Reference State Vertex Points
	std::vector<Vector2> nevadaVertexPoints{};
	// Menu 
	Texture2D gameLogo{};
	// Create Buttons
	std::vector<Button*> scenarioButtons{};
	Button* buttonScenario2024{};
	Button* buttonScenario1860{};
	Button* buttonModernScenarios{};
	Button* buttonVisitState{};
	Button* buttonCancelVisitState{};
	Button* buttonSimulate{};
	Button* buttonCancelSimulate{};
	Button* buttonExitToMenu{};
	// Scenarios
	Scenario* scenario{};
};

// Template Functions
template <typename T> void LogToConsole(T input)
{
	std::cout << input << "\n";
}