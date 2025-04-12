#include "State.h"

State::State(const char* stateName, int electoralVotes, int popularVotes, Texture2D stateTexture, Vector2 position)
{
	this->stateName = stateName;
	this->electoralVotes = electoralVotes;
	this->popularVotes = popularVotes;
	this->stateTexture = stateTexture;
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

void State::SetPartyPopularity(float republican, float democrat)
{
	this->republicanPopularity = republican;
	this->democraticPopularity = democrat;
}

void State::CalculatePartyPopularity()
{
	float sum{};
	if (republicanPopularity > democraticPopularity)
	{
		sum = republicanPopularity - democraticPopularity;
		isRepublicanAhead = true;
		isDemocraticAhead = false;
	}
	else
	{
		sum = democraticPopularity - republicanPopularity;
		isRepublicanAhead = false;
		isDemocraticAhead = true;
	}
	std::cout << sum << "\n";
	UpdateStateColor(sum);
}

const char* State::GetName()
{
	return stateName;
}

int State::GetElectoralVotes()
{
	return electoralVotes;
}

int State::GetPopularVotes()
{
	return popularVotes;
}

float State::GetRepublicanPopularity()
{
	return republicanPopularity;
}

float State::GetDemocraticPopularity()
{
	return democraticPopularity;
}

void State::Render(Vector2 position)
{
	DrawTexture(stateTexture, position.x, position.y, currentColor);
}

void State::RenderVertexPoints()
{
	for (int i = 0; i < vertexPoints.size(); i++)
	{
		DrawCircle(vertexPoints[i].x, vertexPoints[i].y, 3, RED);
	}
}

void State::UpdateStateColor(float sum)
{
	// Check Which Party Is Ahead In The State
	if (isDemocraticAhead)
	{
		// Check If Party Popularity Is Greater Than 15
		if (sum >= 15)
		{
			currentColor = safeDEM;
		}
		// Check If Party Popularity Is Less Than 15 But Greater Than 10
		else if (sum <= 15 && sum > 10)
		{
			currentColor = likelyDEM;
		}
		// Check If Party Popularity Is Less Than 10 But Greater Than 5
		else if (sum <= 10 && sum > 5)
		{
			currentColor = leanDEM;
		}
		// Check If Party Popularity Is Less Than 5
		else if (sum <= 5)
		{
			currentColor = tiltDEM;
		}
	}
	else if (isRepublicanAhead)
	{
		// Check If Party Popularity Is Greater Than 15
		if (sum >= 15)
		{
			currentColor = safeGOP;
		}
		// Check If Party Popularity Is Less Than 15 But Greater Than 10
		else if (sum <= 15 && sum > 10)
		{
			currentColor = likelyGOP;
		}
		// Check If Party Popularity Is Less Than 10 But Greater Than 5
		else if (sum <= 10 && sum > 5)
		{
			currentColor = leanGOP;
		}
		// Check If Party Popularity Is Less Than 5
		else if (sum <= 5)
		{
			currentColor = tiltGOP;
		}
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
