#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "State.h"

class Game
{
public:
	// Init Game
	Game();
	// De-Init Game
	~Game();

	// Game Loop Functions
	void Update();
	void Render();
private:
	// Reference States
	State* california{};
	std::vector<Vector2> californiaVertexPoints{};
};

// Template Functions
template <typename T> void LogToConsole(T input)
{
	std::cout << input << "\n";
}