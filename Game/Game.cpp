#include "Game.h"

// Init
Game::Game()
{
	// Init California
	california = new State("California", LoadTexture("assets/states/cal/cal_b.png"), LoadTexture("assets/states/cal/cal_f.png"), Vector2{ 25, 150 });
	// Plot Out The Vertex Points Of The State For Poly Collision
	Vector2 calVp1{ california->GetPosition().x + 4, california->GetPosition().y };
	Vector2 calVp2{ california->GetPosition().x + 45, california->GetPosition().y };
	Vector2 calVp3{ california->GetPosition().x + 45, california->GetPosition().y + 36 };
	Vector2 calVp4{ california->GetPosition().x + 106, california->GetPosition().y + 91 };
	Vector2 calVp5{ california->GetPosition().x + 103, california->GetPosition().y + 107 };
	Vector2 calVp6{ california->GetPosition().x + 73, california->GetPosition().y + 110 };
	Vector2 calVp7{ california->GetPosition().x + 36, california->GetPosition().y + 87 };
	Vector2 calVp8{ california->GetPosition().x + 5, california->GetPosition().y + 28 };
	// Push Points Into Vector
	california->AddVertexPoint(calVp1);
	california->AddVertexPoint(calVp2);
	california->AddVertexPoint(calVp3);
	california->AddVertexPoint(calVp4);
	california->AddVertexPoint(calVp5);
	california->AddVertexPoint(calVp6);
	california->AddVertexPoint(calVp7);
	california->AddVertexPoint(calVp8);
	// Add To Active States
	states.push_back(california);

	// Init Nevada
	nevada = new State("Nevada", LoadTexture("assets/states/nev/nev_b.png"), LoadTexture("assets/states/nev/nev_f.png"), Vector2{ 70, 152 });
	// Plot Out The Vertex Points Of The State For Poly Collision
	Vector2 nevVp1{ nevada->GetPosition().x + 4, nevada->GetPosition().y };
	Vector2 nevVp2{ nevada->GetPosition().x + 61, nevada->GetPosition().y };
	Vector2 nevVp3{ nevada->GetPosition().x + 61, nevada->GetPosition().y + 86 };
	Vector2 nevVp4{ nevada->GetPosition().x, nevada->GetPosition().y + 34 };
	// Push Points Into Vector
	nevada->AddVertexPoint(nevVp1);
	nevada->AddVertexPoint(nevVp2);
	nevada->AddVertexPoint(nevVp3);
	nevada->AddVertexPoint(nevVp4);
	// Add To Active States
	states.push_back(nevada);
}

// De-Init
Game::~Game()
{
	// Clean Up States
	delete(california);
	delete(nevada);
}

// Update Variables
void Game::Update()
{
	
}

// Draw
void Game::Render()
{
	// Render States
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->Render();
	}

	// Show State Tooltips
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i]->IsMouseOverState(GetMousePosition()))
		{
			stateTooltip.Show(states[i]->GetName(), GetMousePosition());
		}
	}
}
