#include "Game.h"

// Init
Game::Game()
{
	// Init States
	california = new State("California", LoadTexture("assets/states/cal/cal_b.png"), LoadTexture("assets/states/cal/cal_f.png"), Vector2{ 25, 150 });

	// Plot Out The Vertex Points Of The State For Poly Collision
	Vector2 calVp1{ california->GetPosition().x + 4, california->GetPosition().y };
	Vector2 calVp2{ california->GetPosition().x + 45, california->GetPosition().y };
	Vector2 calVp3{ california->GetPosition().x + 45, california->GetPosition().y + 36 };
	Vector2 calVp4{ california->GetPosition().x + 106, california->GetPosition().y + 91 };
	Vector2 calVp5{ california->GetPosition().x + 103, california->GetPosition().y + 107 };
	Vector2 calVp6{ california->GetPosition().x + 73, california->GetPosition().y + 110 };
	Vector2 calVp7{ california->GetPosition().x + 36, california->GetPosition().y + 87 };
	Vector2 calVp8{ california->GetPosition().x + 0, california->GetPosition().y + 18 };

	// Push Points Into Vector
	california->AddVertexPoint(calVp1);
	california->AddVertexPoint(calVp2);
	california->AddVertexPoint(calVp3);
	california->AddVertexPoint(calVp4);
	california->AddVertexPoint(calVp5);
	california->AddVertexPoint(calVp6);
	california->AddVertexPoint(calVp7);
	california->AddVertexPoint(calVp8);
}

// De-Init
Game::~Game()
{
	// Clean Up States
	delete(california);
}

// Update Variables
void Game::Update()
{
	if (california->IsMouseOverState(GetMousePosition()))
	{
		LogToConsole("Mouse Is Over California");
	}
}

// Draw
void Game::Render()
{
	california->Render();
	california->RenderVertexPoints();
}
