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

	////////////////////////////////
	//         WYOMING			  //
	////////////////////////////////
	wyoming = new State("Wyoming", LoadTexture("assets/states/wyoming.png"));
	std::vector<Vector2> wyomingVertexPoints
	{
		Vector2{130 + mapOffsetX, 112 + mapOffsetY},
		Vector2{196 + mapOffsetX, 112 + mapOffsetY},
		Vector2{196 + mapOffsetX, 60 + mapOffsetY},
		Vector2{130 + mapOffsetX, 60 + mapOffsetY},
	};
	for (int i = 0; i < wyomingVertexPoints.size(); i++)
	{
		wyoming->AddVertexPoint(wyomingVertexPoints[i]);
	}
	states.push_back(wyoming);

	////////////////////////////////
	//         COLORADO			  //
	////////////////////////////////
	colorado = new State("Colorado", LoadTexture("assets/states/colorado.png"));
	std::vector<Vector2> coloradoVertexPoints
	{
		Vector2{149 + mapOffsetX, 162 + mapOffsetY},
		Vector2{216 + mapOffsetX, 162 + mapOffsetY},
		Vector2{216 + mapOffsetX, 112 + mapOffsetY},
		Vector2{149 + mapOffsetX, 112 + mapOffsetY},
	};
	for (int i = 0; i < coloradoVertexPoints.size(); i++)
	{
		colorado->AddVertexPoint(coloradoVertexPoints[i]);
	}
	states.push_back(colorado);

	////////////////////////////////
	//         NEW MEXICO		  //
	////////////////////////////////
	new_mexico = new State("New Mexico", LoadTexture("assets/states/newmexico.png"));
	std::vector<Vector2> new_mexicoVertexPoints
	{
		Vector2{149 + mapOffsetX, 226 + mapOffsetY},
		Vector2{157 + mapOffsetX, 226 + mapOffsetY},
		Vector2{161 + mapOffsetX, 221 + mapOffsetY},
		Vector2{173 + mapOffsetX, 220 + mapOffsetY},
		Vector2{207 + mapOffsetX, 220 + mapOffsetY},
		Vector2{207 + mapOffsetX, 162 + mapOffsetY},
		Vector2{149 + mapOffsetX, 162 + mapOffsetY},
	};
	for (int i = 0; i < new_mexicoVertexPoints.size(); i++)
	{
		new_mexico->AddVertexPoint(new_mexicoVertexPoints[i]);
	}
	states.push_back(new_mexico);

	////////////////////////////////
	//         TEXAS		      //
	////////////////////////////////
	texas = new State("Texas", LoadTexture("assets/states/texas.png"));
	std::vector<Vector2> texasVertexPoints
	{
		Vector2{174 + mapOffsetX, 221 + mapOffsetY},
		Vector2{200 + mapOffsetX, 250 + mapOffsetY},
		Vector2{206 + mapOffsetX, 250 + mapOffsetY},
		Vector2{215 + mapOffsetX, 243 + mapOffsetY},
		Vector2{223 + mapOffsetX, 245 + mapOffsetY},
		Vector2{243 + mapOffsetX, 274 + mapOffsetY},
		Vector2{260 + mapOffsetX, 284 + mapOffsetY},
		Vector2{260 + mapOffsetX, 263 + mapOffsetY},
		Vector2{294 + mapOffsetX, 244 + mapOffsetY},
		Vector2{291 + mapOffsetX, 202 + mapOffsetY},
		Vector2{236 + mapOffsetX, 190 + mapOffsetY},
		Vector2{236 + mapOffsetX, 168 + mapOffsetY},
		Vector2{208 + mapOffsetX, 168 + mapOffsetY},
		Vector2{208 + mapOffsetX, 220 + mapOffsetY},
	};
	for (int i = 0; i < texasVertexPoints.size(); i++)
	{
		texas->AddVertexPoint(texasVertexPoints[i]);
	}
	states.push_back(texas);

	////////////////////////////////
	//         OKLAHOMA		      //
	////////////////////////////////
	oklahoma = new State("Oklahoma", LoadTexture("assets/states/oklahoma.png"));
	std::vector<Vector2> oklahomaVertexPoints
	{
		Vector2{208 + mapOffsetX, 166 + mapOffsetY},
		Vector2{237 + mapOffsetX, 166 + mapOffsetY},
		Vector2{208 + mapOffsetX, 189 + mapOffsetY},
		Vector2{262 + mapOffsetX, 198 + mapOffsetY},
		Vector2{285 + mapOffsetX, 199 + mapOffsetY},
		Vector2{285 + mapOffsetX, 163 + mapOffsetY},
		Vector2{208 + mapOffsetX, 163 + mapOffsetY},
	};
	for (int i = 0; i < oklahomaVertexPoints.size(); i++)
	{
		oklahoma->AddVertexPoint(oklahomaVertexPoints[i]);
	}
	states.push_back(oklahoma);

	////////////////////////////////
	//         KANSAS		      //
	////////////////////////////////
	kansas = new State("Kansas", LoadTexture("assets/states/kansas.png"));
	std::vector<Vector2> kansasVertexPoints
	{
		Vector2{217 + mapOffsetX, 161 + mapOffsetY},
		Vector2{285 + mapOffsetX, 161 + mapOffsetY},
		Vector2{285 + mapOffsetX, 136 + mapOffsetY},
		Vector2{280 + mapOffsetX, 126 + mapOffsetY},
		Vector2{217 + mapOffsetX, 126 + mapOffsetY},
	};
	for (int i = 0; i < kansasVertexPoints.size(); i++)
	{
		kansas->AddVertexPoint(kansasVertexPoints[i]);
	}
	states.push_back(kansas);

	////////////////////////////////
	//         NEBRASKA		      //
	////////////////////////////////
	nebraska = new State("Nebraska", LoadTexture("assets/states/nebraska.png"));
	std::vector<Vector2> nebraskaVertexPoints
	{
		Vector2{197 + mapOffsetX, 111 + mapOffsetY},
		Vector2{217 + mapOffsetX, 111 + mapOffsetY},
		Vector2{217 + mapOffsetX, 124 + mapOffsetY},
		Vector2{279 + mapOffsetX, 124 + mapOffsetY},
		Vector2{260 + mapOffsetX, 89 + mapOffsetY},
		Vector2{250 + mapOffsetX, 88 + mapOffsetY},
		Vector2{197 + mapOffsetX, 88 + mapOffsetY},
	};
	for (int i = 0; i < nebraskaVertexPoints.size(); i++)
	{
		nebraska->AddVertexPoint(nebraskaVertexPoints[i]);
	}
	states.push_back(nebraska);

	////////////////////////////////
	//         SOUTH DAKOTA		  //
	////////////////////////////////
	south_dakota = new State("South Dakota", LoadTexture("assets/states/southdakota.png"));
	std::vector<Vector2> south_dakotaVertexPoints
	{
		Vector2{197 + mapOffsetX, 86 + mapOffsetY},
		Vector2{250 + mapOffsetX, 86 + mapOffsetY},
		Vector2{268 + mapOffsetX, 93 + mapOffsetY},
		Vector2{268 + mapOffsetX, 49 + mapOffsetY},
		Vector2{197 + mapOffsetX, 49 + mapOffsetY},
	};
	for (int i = 0; i < south_dakotaVertexPoints.size(); i++)
	{
		south_dakota->AddVertexPoint(south_dakotaVertexPoints[i]);
	}
	states.push_back(south_dakota);

	////////////////////////////////
	//         NORTH DAKOTA		  //
	////////////////////////////////
	north_dakota = new State("North Dakota", LoadTexture("assets/states/northdakota.png"));
	std::vector<Vector2> north_dakotaVertexPoints
	{
		Vector2{197 + mapOffsetX, 47 + mapOffsetY},
		Vector2{197 + mapOffsetX, 267 + mapOffsetY},
		Vector2{261 + mapOffsetX, 6 + mapOffsetY},
		Vector2{197 + mapOffsetX, 6 + mapOffsetY},
	};
	for (int i = 0; i < north_dakotaVertexPoints.size(); i++)
	{
		north_dakota->AddVertexPoint(north_dakotaVertexPoints[i]);
	}
	states.push_back(north_dakota);

	////////////////////////////////
	//         MINNESOTA		  //
	////////////////////////////////
	minnesota = new State("Minnesota", LoadTexture("assets/states/minnesota.png"));
	std::vector<Vector2> minnesotaVertexPoints
	{
		Vector2{270 + mapOffsetX, 79 + mapOffsetY},
		Vector2{318 + mapOffsetX, 79 + mapOffsetY},
		Vector2{304 + mapOffsetX, 65 + mapOffsetY},
		Vector2{309 + mapOffsetX, 39 + mapOffsetY},
		Vector2{332 + mapOffsetX, 20 + mapOffsetY},
		Vector2{284 + mapOffsetX, 1 + mapOffsetY},
		Vector2{263 + mapOffsetX, 6 + mapOffsetY},
	};
	for (int i = 0; i < minnesotaVertexPoints.size(); i++)
	{
		minnesota->AddVertexPoint(minnesotaVertexPoints[i]);
	}
	states.push_back(minnesota);

	////////////////////////////////
	//         IOWA				  //
	////////////////////////////////
	iowa = new State("Iowa", LoadTexture("assets/states/iowa.png"));
	std::vector<Vector2> iowaVertexPoints
	{
		Vector2{277 + mapOffsetX, 117 + mapOffsetY},
		Vector2{316 + mapOffsetX, 119 + mapOffsetY},
		Vector2{328 + mapOffsetX, 101 + mapOffsetY},
		Vector2{320 + mapOffsetX, 90 + mapOffsetY},
		Vector2{318 + mapOffsetX, 81 + mapOffsetY},
		Vector2{269 + mapOffsetX, 81 + mapOffsetY},
	};
	for (int i = 0; i < iowaVertexPoints.size(); i++)
	{
		iowa->AddVertexPoint(iowaVertexPoints[i]);
	}
	states.push_back(iowa);

	////////////////////////////////
	//         MISSOURI			  //
	////////////////////////////////
	missouri = new State("Missouri", LoadTexture("assets/states/missouri.png"));
	std::vector<Vector2> missouriVertexPoints
	{
		Vector2{287 + mapOffsetX, 166 + mapOffsetY},
		Vector2{329 + mapOffsetX, 166 + mapOffsetY},
		Vector2{329 + mapOffsetX, 172 + mapOffsetY},
		Vector2{334 + mapOffsetX, 172 + mapOffsetY},
		Vector2{338 + mapOffsetX, 161 + mapOffsetY},
		Vector2{327 + mapOffsetX, 146 + mapOffsetY},
		Vector2{328 + mapOffsetX, 138 + mapOffsetY},
		Vector2{316 + mapOffsetX, 126 + mapOffsetY},
		Vector2{315 + mapOffsetX, 119 + mapOffsetY},
		Vector2{278 + mapOffsetX, 119 + mapOffsetY},
	};
	for (int i = 0; i < missouriVertexPoints.size(); i++)
	{
		missouri->AddVertexPoint(missouriVertexPoints[i]);
	}
	states.push_back(missouri);

	////////////////////////////////
	//         ARKANSAS			  //
	////////////////////////////////
	arkansas = new State("Arkansas", LoadTexture("assets/states/arkansas.png"));
	std::vector<Vector2> arkansasVertexPoints
	{
		Vector2{287 + mapOffsetX, 200 + mapOffsetY},
		Vector2{293 + mapOffsetX, 206 + mapOffsetY},
		Vector2{319 + mapOffsetX, 206 + mapOffsetY},
		Vector2{320 + mapOffsetX, 197 + mapOffsetY},
		Vector2{332 + mapOffsetX, 174 + mapOffsetY},
		Vector2{330 + mapOffsetX, 168 + mapOffsetY},
		Vector2{287 + mapOffsetX, 168 + mapOffsetY},
	};
	for (int i = 0; i < arkansasVertexPoints.size(); i++)
	{
		arkansas->AddVertexPoint(arkansasVertexPoints[i]);
	}
	states.push_back(arkansas);
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
	for (int i = 0; i < scenario->parties.size(); i++)
	{
		float y = i * 20;
		DrawText(scenario->parties[i]->GetName().c_str(), 600, 350 + y, 20, scenario->parties[i]->safe);
		DrawText(TextFormat(" - %i", EVCalculator(scenario->parties[i]->GetName())), 720, 350 + y, 20, WHITE);
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
