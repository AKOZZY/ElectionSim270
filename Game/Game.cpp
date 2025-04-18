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

	// Init Menu Buttons
	buttonModernScenarios = new Button("Modern (1960-2024)", 20, 200, 20, Vector2{ 0, 200 });

	// Play Scenario Buttons
	buttonScenario2024 = new Button("2024", 20, 120, 20, Vector2{ 475, 20 });

	// Set Selected State To Null
	selectedState = nullptr;

	// Init State Borders
	stateBorders = LoadTexture("assets/StateBorders.png");
	
	// Init States
	////////////////////////////////
	//         CALIFORNIA         //
	////////////////////////////////
	california = new State("California", 54, 15357876, LoadTexture("assets/states/california.png"));
	california->SetPartyPopularity(40, 60);
	// Plot Out The Vertex Points Of The State For Poly Collision
	std::vector<Vector2> californiaVertexPoints
	{
		Vector2{ 5 + mapOffsetX, 99 + mapOffsetY },
		Vector2{ 16 + mapOffsetX, 153 + mapOffsetY },
		Vector2{ 41 + mapOffsetX, 191 + mapOffsetY },
		Vector2{ 71 + mapOffsetX, 212 + mapOffsetY },
		Vector2{ 94 + mapOffsetX, 212 + mapOffsetY },
		Vector2{ 101 + mapOffsetX, 192 + mapOffsetY },
		Vector2{ 44 + mapOffsetX, 137 + mapOffsetY },
		Vector2{ 44 + mapOffsetX, 99 + mapOffsetY },
	};
	// Push Points Into Vector
	for (int i = 0; i < californiaVertexPoints.size(); i++)
	{
		california->AddVertexPoint(californiaVertexPoints[i]);
	}
	// Add To Active States
	states.push_back(california);
	
	////////////////////////////////
	//         NEVADA	          //
	////////////////////////////////
	nevada = new State("Nevada", 6, 1456402, LoadTexture("assets/states/nevada.png"));
	nevada->SetPartyPopularity(45, 55);
	std::vector<Vector2> nevadaVertexPoints
	{
		Vector2{44 + mapOffsetX, 99 + mapOffsetY},
		Vector2{44 + mapOffsetX, 137 + mapOffsetY},
		Vector2{96 + mapOffsetX, 186 + mapOffsetY},
		Vector2{97 + mapOffsetX, 180 + mapOffsetY},
		Vector2{85 + mapOffsetX, 173 + mapOffsetY},
		Vector2{101 + mapOffsetX, 172 + mapOffsetY},
		Vector2{101 + mapOffsetX, 99 + mapOffsetY},
	};
	for (int i = 0; i < nevadaVertexPoints.size(); i++)
	{
		nevada->AddVertexPoint(nevadaVertexPoints[i]);
	}
	states.push_back(nevada);

	////////////////////////////////
	//         ALASKA	          //
	////////////////////////////////
	alaska = new State("Alaska", 3, 324484, LoadTexture("assets/states/alaska.png"));
	alaska->SetPartyPopularity(55, 45);
	std::vector<Vector2> alaskaVertexPoints
	{
		Vector2{87 + mapOffsetX, 263 + mapOffsetY},
		Vector2{87 + mapOffsetX, 335 + mapOffsetY},
		Vector2{168 + mapOffsetX, 335 + mapOffsetY},
		Vector2{168 + mapOffsetX, 263 + mapOffsetY},
	};
	for (int i = 0; i < alaskaVertexPoints.size(); i++)
	{
		alaska->AddVertexPoint(alaskaVertexPoints[i]);
	}
	states.push_back(alaska);

	////////////////////////////////
	//         HAWAII	          //
	////////////////////////////////
	hawaii = new State("Hawaii", 3, 506705, LoadTexture("assets/states/hawaii.png"));
	hawaii->SetPartyPopularity(40, 60);
	std::vector<Vector2> hawaiiVertexPoints
	{
		Vector2{7 + mapOffsetX, 243 + mapOffsetY},
		Vector2{7 + mapOffsetX, 282 + mapOffsetY},
		Vector2{66 + mapOffsetX, 282 + mapOffsetY},
		Vector2{66 + mapOffsetX, 243 + mapOffsetY},
	};
	for (int i = 0; i < hawaiiVertexPoints.size(); i++)
	{
		hawaii->AddVertexPoint(hawaiiVertexPoints[i]);
	}
	states.push_back(hawaii);

	////////////////////////////////
	//         OREGON	          //
	////////////////////////////////
	oregon = new State("Oregon", 3, 506705, LoadTexture("assets/states/oregon.png"));
	oregon->SetPartyPopularity(40, 60);
	std::vector<Vector2> oregonVertexPoints
	{
		Vector2{7 + mapOffsetX, 45 + mapOffsetY},
		Vector2{4 + mapOffsetX, 98 + mapOffsetY},
		Vector2{74 + mapOffsetX, 98 + mapOffsetY},
		Vector2{72 + mapOffsetX, 68 + mapOffsetY},
		Vector2{79 + mapOffsetX, 55 + mapOffsetY},
		Vector2{74 + mapOffsetX, 47 + mapOffsetY},
	};
	for (int i = 0; i < oregonVertexPoints.size(); i++)
	{
		oregon->AddVertexPoint(oregonVertexPoints[i]);
	}
	states.push_back(oregon);

	////////////////////////////////
	//         WASHINGTON	      //
	////////////////////////////////
	washington = new State("Washington", 12, 506705, LoadTexture("assets/states/washington.png"));
	washington->SetPartyPopularity(40, 60);
	std::vector<Vector2> washingtonVertexPoints
	{
		Vector2{mapOffsetX, 4 + mapOffsetY},
		Vector2{7 + mapOffsetX, 44 + mapOffsetY},
		Vector2{23 + mapOffsetX, 53 + mapOffsetY},
		Vector2{70 + mapOffsetX, 46 + mapOffsetY},
		Vector2{74 + mapOffsetX, 47 + mapOffsetY},
		Vector2{73 + mapOffsetX, 4 + mapOffsetY},
	};
	for (int i = 0; i < washingtonVertexPoints.size(); i++)
	{
		washington->AddVertexPoint(washingtonVertexPoints[i]);
	}
	states.push_back(washington);
}

// De-Init
Game::~Game()
{
	// Unload Textures
	UnloadTexture(stateBorders);
	// Clean Up States
	for (int i = 0; i < states.size(); i++)
	{
		delete(states[i]);
	}
	// Delete Objects
	delete(scenario);
	delete(buttonVisitState);
	delete(buttonCancelVisitState);
	delete(buttonModernScenarios);
	delete(buttonScenario2024);
}

void Game::UpdateMenu()
{
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
			scenario->LoadScenario(SCENARIO_2024, states);
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
		buttonScenario2024->Draw();
	}
}

// Update Variables
void Game::Update()
{
	// Determine Which State The Mouse Is Over 
	// Set Back To NULL When Mouse Exits Off State
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i]->IsMouseOverState(GetMousePosition()))
		{
			selectedState = states[i];
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
		selectedState->UpdatePartyPopularity("Independent", (float)GetRandomValue(1, 10), 0.1);
		LogToConsole(selectedState->partiesRunning[1]->GetName());
	}

	// Update Party Popularity
	for (int i = 0; i < states.size(); i++)
	{
		california->CalculateStateColor();
	}

	

	if (IsKeyPressed(KEY_C))
	{
		for (int i = 0; i < states.size(); i++)
		{
			if (GetRandomValue(1, 2) == 1)
			{
				states[i]->BoostRepublicanPopularity((float)GetRandomValue(1, 10), 0.1);
			}
			else
			{
				states[i]->BoostDemocraticPopularity((float)GetRandomValue(1, 10), 0.1);
			}
		}
	}

	UpdateRepublicanElectoralVotes();
	UpdateDemocraticElectoralVotes();
}

// Draw
void Game::Render()
{
	// Draw Buttons
	buttonVisitState->Draw();

	// Render State Borders
	DrawTextureEx(stateBorders, Vector2{ mapOffsetX, mapOffsetY }, 0, 1, WHITE);

	// Render EV's For Each Party
	DrawText(TextFormat("Republican - %i", republicanEVCount), 600, 30, 20, BLACK);
	DrawText(TextFormat("Democratic - %i", democraticEVCount), 600, 60, 20, BLACK);

	// Click A State To Visit It (Boosts Popularity Of Your Party In That State)
	if (hasClickedStateVisit)
	{
		buttonCancelVisitState->Draw();
		DrawText("Click A State To Visit! (Costs 2 Points)", 0, 50, 19, BLACK);
	}

	// Render States
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->Render(Vector2{ mapOffsetX , mapOffsetY });
		//states[i]->RenderVertexPoints();
	}

	// Show State Tooltips
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i]->IsMouseOverState(GetMousePosition()))
		{
			if (selectedState != nullptr)
			{
				stateTooltip.Show(selectedState, GetMousePosition());
			}
		}
	}
}

void Game::UpdateRepublicanElectoralVotes()
{
	int sumOfRepublicanEV = 0;
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i]->isRepublicanAhead)
		{
			sumOfRepublicanEV += states[i]->GetElectoralVotes();
		}
	}
	republicanEVCount = sumOfRepublicanEV;
}

void Game::UpdateDemocraticElectoralVotes()
{
	int sumOfDemocratEV = 0;
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i]->isDemocraticAhead)
		{
			sumOfDemocratEV += states[i]->GetElectoralVotes();
		}
	}
	democraticEVCount = sumOfDemocratEV;
}
