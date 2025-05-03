#include "Game.h"

// Init
Game::Game()
{
	// Create Scenario Object
	scenario = new Scenario();

	// Load Game Logo
	gameLogo = LoadTexture("assets/ElectionSim270Logo.png");

	// Init Game Buttons
	buttonVisitState = new Button("Visit State", 20, 120, 20, Vector2{ 0, 0 });
	buttonCancelVisitState = new Button("Cancel", 20, 120, 20, Vector2{ 0, 20 });
	buttonSimulate = new Button("Simulate", 20, 120, 20, Vector2{ 650, 200 });
	buttonCancelSimulate = new Button("Stop", 20, 120, 20, Vector2{ 650, 220 });
	buttonExitToMenu = new Button("Exit To Menu", 20, 140, 20, Vector2{ 0, 430 });

	// Init Menu Buttons
	buttonModernScenarios = new Button("Select Year", 20, 200, 20, Vector2{ 0, 200 });

	// Play Scenario Buttons
	buttonScenario2024 = new Button("2024", 20, 120, 20, Vector2{ 475, 20 });
	buttonScenario1860 = new Button("1860", 20, 120, 20, Vector2{ 475, 40 });
	scenarioButtons.push_back(buttonScenario2024);
	scenarioButtons.push_back(buttonScenario1860);
	for (int i = 0; i < scenarioButtons.size(); i++)
	{
		float y = i * 20;
		scenarioButtons[i]->SetPosition(Vector2{ 450, y });
	}

	// Set Selected State To Null
	selectedState = nullptr;

	stateManager = new StateManager();
}

// De-Init
Game::~Game()
{
	// Delete Objects
	delete(scenario);
	delete(stateManager);
	delete(buttonVisitState);
	delete(buttonCancelVisitState);
	delete(buttonModernScenarios);
	delete(buttonScenario2024);
}

void Game::UpdateMenu()
{
	scenario->Reset(stateManager->states);

	// SCENARIO 2024
	buttonModernScenarios->MouseHover(GetMousePosition());
	if (buttonModernScenarios->isMouseOverButton && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		menuState = IN_SCENARIO_SCREEN;
	}

	if (menuState == IN_SCENARIO_SCREEN)
	{
		buttonScenario2024->MouseHover(GetMousePosition());
		if (buttonScenario2024->isMouseOverButton && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			scenario->LoadScenario(SCENARIO_2024, stateManager->states);
			gameState = IN_GAME;
		}

		buttonScenario1860->MouseHover(GetMousePosition());
		if (buttonScenario1860->isMouseOverButton && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			scenario->LoadScenario(SCENARIO_1860, stateManager->states);
			gameState = IN_GAME;
		}
	}
}

void Game::RenderMenu()
{
	// Draw Menu Logo
	//DrawTexture(gameLogo, 25, 25, WHITE);
	DrawTextureEx(gameLogo, Vector2{ 25 , 0 }, 0, 2, WHITE);
	buttonModernScenarios->Draw();

	DrawRectangle(450, 0, 300, 900, Color{0, 0, 0, 200});

	if (menuState == IN_SCENARIO_SCREEN)
	{
		for (int i = 0; i < scenarioButtons.size(); i++)
		{
			scenarioButtons[i]->Draw();
		}
	}
}

// Update Variables
void Game::Update()
{
	// Determine Which State The Mouse Is Over 
	// Set Back To NULL When Mouse Exits Off State
	for (int i = 0; i < stateManager->states.size(); i++)
	{
		if (stateManager->states[i]->IsMouseOverState(GetMousePosition()))
		{
			selectedState = stateManager->states[i];
			break;
		}
		else
		{
			selectedState = nullptr;
		}
	}

	// Check If Mouse Is Over Buttons
	buttonVisitState->MouseHover(GetMousePosition());
	if (buttonVisitState->isMouseOverButton && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		hasClickedStateVisit = true;
	}
	buttonCancelVisitState->MouseHover(GetMousePosition());
	if (buttonCancelVisitState->isMouseOverButton && IsMouseButtonDown(MOUSE_BUTTON_LEFT) && hasClickedStateVisit)
	{
		hasClickedStateVisit = false;
	}

	// Visit State
	if (hasClickedStateVisit && selectedState != nullptr && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		hasClickedStateVisit = false;
		selectedState->UpdatePartyPopularity("Independent", (float)GetRandomValue(1, 10), 2);
	}

	buttonSimulate->MouseHover(GetMousePosition());
	if (buttonSimulate->isMouseOverButton && !hasClickedSimulate && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		hasClickedSimulate = true;
	}
	if (hasClickedSimulate)
	{
		RandomizeSupport();
	}

	buttonCancelSimulate->MouseHover(GetMousePosition());
	if (buttonCancelSimulate->isMouseOverButton && hasClickedSimulate && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		hasClickedSimulate = false;
	}

	// Update Party Popularity
	for (int i = 0; i < stateManager->states.size(); i++)
	{
		stateManager->states[i]->CalculateStateColor();
	}

	buttonExitToMenu->MouseHover(GetMousePosition());
	if (buttonExitToMenu->isMouseOverButton && IsMouseButtonDown(MOUSE_BUTTON_LEFT) && gameState == IN_GAME)
	{
		gameState = IN_MAIN_MENU;
	}

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		std::cout << "X: " << GetMousePosition().x << "Y: " << GetMousePosition().y << "\n";
	}
}

// Draw
void Game::Render()
{
	// Draw Buttons
	buttonVisitState->Draw();

	// Render State Borders
	DrawTextureEx(scenario->bordersSprite, Vector2{ stateManager->GetMapOffsetX(),  stateManager->GetMapOffsetY()}, 0, 1, WHITE);

	// Draw MenuBox
	DrawRectangle(1280 - 400, 0, 400, 800, Color{ 0, 0, 0, 200 });

	// Candidate Portraits (Placeholders)
	DrawRectangle(890, 10, 176, 250, WHITE);
	DrawRectangle(1090, 10, 176, 250, WHITE);

	// Render EV's For Each Party
	for (int i = 0; i < scenario->parties.size(); i++)
	{
		float y = i * 20;
		DrawText(scenario->parties[i]->GetName().c_str(), 985, 300 + y, 20, scenario->parties[i]->safe);
		DrawText(TextFormat(" - %i", EVCalculator(scenario->parties[i]->GetName())), 1100, 300 + y, 20, WHITE);
	}
	
	// Click A State To Visit It (Boosts Popularity Of Your Party In That State)
	if (hasClickedStateVisit)
	{
		buttonCancelVisitState->Draw();
		DrawText("Click A State To Visit! (Costs 2 Points)", 0, 50, 20, BLACK);
	}

	if (hasClickedSimulate)
	{
		buttonCancelSimulate->Draw();
		DrawText("Currently Simulating!", 625, 260, 20, WHITE);
	}
	else
	{
		buttonSimulate->Draw();
	}

	// Render States
	for (int i = 0; i < stateManager->states.size(); i++)
	{
		if (stateManager->states[i]->isHidden == false)
		{
			stateManager->states[i]->Render(Vector2{ stateManager->GetMapOffsetX() ,  stateManager->GetMapOffsetY() });
		}
	}

	// Show State Tooltips
	for (int i = 0; i < stateManager->states.size(); i++)
	{
		if (stateManager->states[i]->IsMouseOverState(GetMousePosition()))
		{
			if (selectedState != nullptr)
			{
				stateTooltip.Show(selectedState, GetMousePosition());
			}
		}
	}

	if (IN_GAME)
	{
		buttonExitToMenu->Draw();
	}
}

void Game::RandomizeSupport()
{
	if (timer < updateInterval)
	{
		timer += GetFrameTime();
	}
	else
	{
		timer = 0;
		for (int i = 0; i < stateManager->states.size(); i++)
		{
			int rand = GetRandomValue(0, scenario->parties.size());
			stateManager->states[i]->UpdatePartyPopularityIndex(rand, GetRandomValue(1, 10), 0.3);
		}
	}
}

int Game::EVCalculator(std::string nameOfParty)
{
	int sum{};
	for (int i = 0; i < stateManager->states.size(); i++)
	{
		if (nameOfParty == stateManager->states[i]->partiesRunning[0]->GetName())
		{
			sum += stateManager->states[i]->GetElectoralVotes();
		}
	}
	return sum;
}
