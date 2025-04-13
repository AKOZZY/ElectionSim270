#include "Game.h"

// Init
Game::Game()
{
	// Init Game Buttons
	buttonVisitState = new Button("Visit State", 20, 120, 20, Vector2{ 0, 0 });
	buttonCancelVisitState = new Button("Cancel", 20, 120, 20, Vector2{ 0, 20 });

	// Set Selected State To Null
	selectedState = nullptr;

	// Init State Borders
	stateBorders = LoadTexture("assets/StateBorders.png");
	
	// Init California
	californiaTexture = LoadTexture("assets/states/california.png");
	california = new State("California", 54, 15357876, californiaTexture, Vector2{ 25, 150 });
	california->SetPartyPopularity(41.53, 58.47);
	california->CalculatePartyPopularity();
	california->ideology = california->PROGRESSIVE;

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

	
}

// De-Init
Game::~Game()
{
	// Unload Textures
	UnloadTexture(stateBorders);
	// Clean Up States
	delete(california);
}

// Update Variables
void Game::Update()
{
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
		selectedState->BoostRepublicanPopularity((float)GetRandomValue(1, 10), 0.1);
	}

	california->CalculatePartyPopularity();
	if (IsKeyPressed(KEY_C)) california->BoostRepublicanPopularity((float)GetRandomValue(1, 10), 0.03);
	if (IsKeyPressed(KEY_V)) california->BoostDemocraticPopularity((float)GetRandomValue(1, 10), 0.03);
}

// Draw
void Game::Render()
{
	// Draw Buttons
	buttonVisitState->Draw();

	// Render State Borders
	DrawTextureEx(stateBorders, Vector2{ mapOffsetX, mapOffsetY }, 0, 1, WHITE);

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
			selectedState = states[i];
			stateTooltip.Show(selectedState, GetMousePosition());
		}
		else
		{
			selectedState = nullptr;
		}
	}
}
