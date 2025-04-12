#include "Game.h"

// Init
Game::Game()
{
	selectedState = nullptr;

	// Init State Borders
	stateBorders = LoadTexture("assets/StateBorders.png");
	
	// Init California
	californiaTexture = LoadTexture("assets/states/california.png");
	california = new State("California", 54, 15357876, californiaTexture, Vector2{ 25, 150 });
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

	california->SetPartyPopularity(38.33, 58.47);
	california->CalculatePartyPopularity();
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
	// Check What The Current Selected State Is (Whatever State The Mouse Pointer Is Currently Over)
	if (selectedState != nullptr)
	{
		LogToConsole(selectedState->GetName());
	}
}

// Draw
void Game::Render()
{
	// Render State Borders
	DrawTextureEx(stateBorders, Vector2{ mapOffsetX, mapOffsetY }, 0, 1, WHITE);

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
