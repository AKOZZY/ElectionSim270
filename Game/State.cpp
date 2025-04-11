#include "State.h"

State::State(const char* stateName, Texture2D stateTexture, Vector2 position)
{
	this->stateName = stateName;
	this->stateTexture = stateTexture;
	this->position = position;
}

State::~State()
{
	// Unload State Textures
	UnloadTexture(stateTexture);
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
	DrawTexture(stateTexture, position.x, position.y, likelyGOP);
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
