#include "State.h"

State::State(const char* stateName, Texture2D stateBorder, Texture2D stateFill, Vector2 position)
{
	this->stateName = stateName;
	this->stateBorder = stateBorder;
	this->stateFill = stateFill;
	this->position = position;
}

State::~State()
{
	// Unload State Textures
	UnloadTexture(stateBorder);
	UnloadTexture(stateFill);
}

void State::AddVertexPoint(Vector2 vertexPoint)
{
	vertexPoints.push_back(vertexPoint);
}

Vector2 State::GetPosition()
{
	return position;
}

const char* State::GetName()
{
	return stateName;
}

void State::Render()
{
	// Draw The Border Over The State Fill So That The Fill Does Not Overlap The Border.
	DrawTexture(stateFill, position.x, position.y, WHITE);
	DrawTexture(stateBorder, position.x, position.y, WHITE);
}

void State::RenderVertexPoints()
{
	for (int i = 0; i < vertexPoints.size(); i++)
	{
		DrawCircle(vertexPoints[i].x, vertexPoints[i].y, 3, RED);
	}
}

bool State::IsMouseOverState(Vector2 mousePosition)
{
	if (CheckCollisionPointPoly(mousePosition, vertexPoints.data(), vertexPoints.size()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
