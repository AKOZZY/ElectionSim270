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
	california = new State("California", LoadTexture("assets/states/california.png"));
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
	nevada = new State("Nevada", LoadTexture("assets/states/nevada.png"));
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
	alaska = new State("Alaska", LoadTexture("assets/states/alaska.png"));
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
	hawaii = new State("Hawaii", LoadTexture("assets/states/hawaii.png"));
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
	oregon = new State("Oregon", LoadTexture("assets/states/oregon.png"));
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
	washington = new State("Washington", LoadTexture("assets/states/washington.png"));
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

	////////////////////////////////
	//         ARIZONA		      //
	////////////////////////////////
	arizona = new State("Arizona", LoadTexture("assets/states/arizona.png"));
	std::vector<Vector2> arizonaVertexPoints
	{
		Vector2{94 + mapOffsetX, 212 + mapOffsetY},
		Vector2{98 + mapOffsetX, 208 + mapOffsetY},
		Vector2{95 + mapOffsetX, 202 + mapOffsetY},
		Vector2{101 + mapOffsetX, 192 + mapOffsetY},
		Vector2{96 + mapOffsetX, 184 + mapOffsetY},
		Vector2{96 + mapOffsetX, 172 + mapOffsetY},
		Vector2{101 + mapOffsetX, 172 + mapOffsetY},
		Vector2{101 + mapOffsetX, 162 + mapOffsetY},
		Vector2{149 + mapOffsetX, 162 + mapOffsetY},
		Vector2{149 + mapOffsetX, 226 + mapOffsetY},
		Vector2{128 + mapOffsetX, 226 + mapOffsetY},
	};
	for (int i = 0; i < arizonaVertexPoints.size(); i++)
	{
		arizona->AddVertexPoint(arizonaVertexPoints[i]);
	}
	states.push_back(arizona);

	////////////////////////////////
	//         UTAH				  //
	////////////////////////////////
	utah = new State("Utah", LoadTexture("assets/states/utah.png"));
	std::vector<Vector2> utahVertexPoints
	{
		Vector2{101 + mapOffsetX, 99 + mapOffsetY},
		Vector2{101 + mapOffsetX, 162 + mapOffsetY},
		Vector2{149 + mapOffsetX, 162 + mapOffsetY},
		Vector2{149 + mapOffsetX, 112 + mapOffsetY},
		Vector2{130 + mapOffsetX, 112 + mapOffsetY},
		Vector2{130 + mapOffsetX, 99 + mapOffsetY},
	};
	for (int i = 0; i < utahVertexPoints.size(); i++)
	{
		utah->AddVertexPoint(utahVertexPoints[i]);
	}
	states.push_back(utah);

	////////////////////////////////
	//         IDAHO			  //
	////////////////////////////////
	idaho = new State("Idaho", LoadTexture("assets/states/idaho.png"));
	std::vector<Vector2> idahoVertexPoints
	{
		Vector2{74 + mapOffsetX, 99 + mapOffsetY},
		Vector2{130 + mapOffsetX, 99 + mapOffsetY},
		Vector2{130 + mapOffsetX, 66 + mapOffsetY},
		Vector2{126 + mapOffsetX, 64 + mapOffsetY},
		Vector2{112 + mapOffsetX, 68 + mapOffsetY},
		Vector2{102 + mapOffsetX, 52 + mapOffsetY},
		Vector2{97 + mapOffsetX, 54 + mapOffsetY},
		Vector2{96 + mapOffsetX, 43 + mapOffsetY},
		Vector2{99 + mapOffsetX, 39 + mapOffsetY},
		Vector2{86 + mapOffsetX, 27 + mapOffsetY},
		Vector2{126 + mapOffsetX, 64 + mapOffsetY},
		Vector2{82 + mapOffsetX, 17 + mapOffsetY},
		Vector2{82 + mapOffsetX, 4 + mapOffsetY},
		Vector2{73 + mapOffsetX, 4 + mapOffsetY},
		Vector2{73 + mapOffsetX, 46 + mapOffsetY},
		Vector2{79 + mapOffsetX, 57 + mapOffsetY},
		Vector2{72 + mapOffsetX, 69 + mapOffsetY},
	};
	for (int i = 0; i < idahoVertexPoints.size(); i++)
	{
		idaho->AddVertexPoint(idahoVertexPoints[i]);
	}
	states.push_back(idaho);

	////////////////////////////////
	//         MONTANA			  //
	////////////////////////////////
	montana = new State("Montana", LoadTexture("assets/states/montana.png"));
	std::vector<Vector2> montanaVertexPoints
	{
		Vector2{82 + mapOffsetX, 4 + mapOffsetY},
		Vector2{82 + mapOffsetX, 19 + mapOffsetY},
		Vector2{99 + mapOffsetX, 39 + mapOffsetY},
		Vector2{98 + mapOffsetX, 54 + mapOffsetY},
		Vector2{103 + mapOffsetX, 54 + mapOffsetY},
		Vector2{113 + mapOffsetX, 68 + mapOffsetY},
		Vector2{130 + mapOffsetX, 66 + mapOffsetY},
		Vector2{130 + mapOffsetX, 60 + mapOffsetY},
		Vector2{196 + mapOffsetX, 60 + mapOffsetY},
		Vector2{196 + mapOffsetX, 5 + mapOffsetY},
	};
	for (int i = 0; i < montanaVertexPoints.size(); i++)
	{
		montana->AddVertexPoint(montanaVertexPoints[i]);
	}
	states.push_back(montana);
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
		selectedState->UpdatePartyPopularity("Independent", (float)GetRandomValue(1, 10), 2);
	}

	// Update Party Popularity
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->CalculateStateColor();
	}
}

// Draw
void Game::Render()
{
	// Draw Buttons
	buttonVisitState->Draw();

	// Render State Borders
	DrawTextureEx(stateBorders, Vector2{ mapOffsetX, mapOffsetY }, 0, 1, WHITE);

	// Draw MenuBox
	DrawRectangle(570, 0, 300, 800, Color{ 0, 0, 0, 200 });

	// Candidate Portraits
	DrawRectangle(600, 20, 80, 112, WHITE);
	DrawRectangle(700, 20, 80, 112, WHITE);

	// Render EV's For Each Party
	for (int i = 0; i < states[0]->partiesRunning.size(); i++)
	{
		float y = i * 20;
		DrawText(states[0]->partiesRunning[i]->GetName().c_str(), 600, 350 + y, 20, states[0]->partiesRunning[i]->safe);
		DrawText(TextFormat(" - %i", EVCalculator(states[0]->partiesRunning[i]->GetName())), 720, 350 + y, 20, WHITE);
		//DrawText(TextFormat("Republican - %i", EVCalculator("Republican")), 300, 350 + y, 20, WHITE);
	}

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

int Game::EVCalculator(std::string nameOfParty)
{
	int sum{};
	for (int i = 0; i < states.size(); i++)
	{
		if (nameOfParty == states[i]->partiesRunning[0]->GetName())
		{
			sum += states[i]->GetElectoralVotes();
		}
	}
	return sum;
}
