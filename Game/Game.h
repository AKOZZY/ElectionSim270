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
	State* arizona{};
	State* utah{};
	State* idaho{};
	State* montana{};
	State* wyoming{};
	State* colorado{};
	State* new_mexico{};
	State* texas{};
	State* oklahoma{};
	State* kansas{};
	State* nebraska{};
	State* south_dakota{};
	State* north_dakota{};
	State* minnesota{};
	State* iowa{};
	State* missouri{};
	State* arkansas{};
	State* louisiana{};
	State* wisconsin{};
	State* illinois{};
	State* michigan{};
	State* indiana{};
	State* ohio{}; // lol
	State* pennsylvania{};
	State* new_york{};
	State* new_jersey{};
	State* vermont{};
	State* new_hampshire{};
	State* maine{};
	State* massachusetts{};
	State* connecticut{};
	State* rhode_island{};
	State* delaware{};
	State* maryland{};
	State* florida{};
	State* mississippi{};
	State* alabama{};
	State* georgia{};
	State* south_carolina{};
	State* tennessee{};
	State* kentucky{};
	State* west_virginia{};
	State* virginia{};
	State* north_carolina{};
	State* dc{};
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