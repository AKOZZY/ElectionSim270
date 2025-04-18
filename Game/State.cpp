#include "State.h"

State::State(const char* stateName, int electoralVotes, int popularVotes, Texture2D stateTexture)
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

	// Delete Parties
	for (int i = 0; i < partiesRunning.size(); i++)
	{
		delete(partiesRunning[i]);
	}
}

void State::AddVertexPoint(Vector2 vertexPoint)
{
	vertexPoints.push_back(vertexPoint);
}

void State::AddParty(Party* party)
{
	if (party != nullptr)
	{
		partiesRunning.push_back(party);
	}
}

void State::SetPartyPopularity(float republican, float democrat)
{
	this->republicanPopularity = republican;
	this->democraticPopularity = democrat;
}

void State::CalculatePartyPopularity()
{
	// Keep Popularity Percentages From Going Over 100% For Both Parties
	if (republicanPopularity >= 100)
	{
		republicanPopularity = 100;
		democraticPopularity = 0;
	}
	if (democraticPopularity >= 100)
	{
		democraticPopularity = 100;
		republicanPopularity = 0;
	}

	// Calculate Which Party Is Ahead In The State
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
	UpdateStateColor(sum);
}

void State::SetPartyPopularityIndex(std::string partyName, float percentage)
{
	for (int i = 0; i < partiesRunning.size(); i++)
	{
		if (partyName == partiesRunning[i]->GetName())
		{
			partiesRunning[i]->partySupport = percentage;
		}
	}
}

void State::UpdatePartyPopularity(std::string partyName, float percentage, float modifier)
{
	float sum = percentage * modifier;
	for (int i = 0; i < partiesRunning.size(); i++)
	{
		if (partyName == partiesRunning[i]->GetName()) 
		{
			partiesRunning[i]->partySupport += sum;
		}
	}
	float total{};
	for (int i = 0; i < partiesRunning.size(); i++)
	{
		total += partiesRunning[i]->partySupport;
	}
	for (int i = 0; i < partiesRunning.size(); i++)
	{
		partiesRunning[i]->partySupport = (partiesRunning[i]->partySupport / total) * 100.0f;
	}
}

const char* State::GetName()
{
	return stateName;
}

void State::SetElectoralVotes(int ev)
{
	this->electoralVotes = ev;
}

int State::GetElectoralVotes()
{
	return electoralVotes;
}

void State::SetPopularVotes(int pv)
{
	this->popularVotes = pv;
}

int State::GetPopularVotes()
{
	return popularVotes;
}

void State::BoostRepublicanPopularity(float percentage, float modifier)
{
	percentage *= modifier;
	republicanPopularity += percentage;
	democraticPopularity = 100.0 - republicanPopularity;
}

void State::BoostDemocraticPopularity(float percentage, float modifier)
{
	percentage *= modifier;
	democraticPopularity += percentage;
	republicanPopularity = 100.0 - democraticPopularity;
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
	if (isEnabled)
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
	else
	{
		currentColor = Color{ 101, 101, 101, 255 };
	}
	
}

void State::CalculateStateColor()
{
	// Sort States From Lowest To Highest Support
	std::sort(partiesRunning.begin(), partiesRunning.end(), [](const Party* a, const Party* b) 
	{
		return a->partySupport > b->partySupport;
	});

	std::cout << "Most popular parties:\n";
	for (int i = 0; i < 2; ++i) {
		std::cout << partiesRunning[i]->GetName() << " with popularity " << partiesRunning[i]->partySupport << "\n";
	}

	if (isEnabled)
	{
		float sum{};
		// Sum Of The Most Popular Party And The 2nd Most Popular Party
		sum = partiesRunning[0]->partySupport - partiesRunning[1]->partySupport;

		// Check If Party Popularity Is Greater Than 15
		if (sum >= 15)
		{
			currentColor = partiesRunning[0]->safe;
		}
		// Check If Party Popularity Is Less Than 15 But Greater Than 10
		else if (sum <= 15 && sum > 10)
		{
			currentColor = partiesRunning[0]->likely;
		}
		// Check If Party Popularity Is Less Than 10 But Greater Than 5
		else if (sum <= 10 && sum > 5)
		{
			currentColor = partiesRunning[0]->lean;;
		}
		// Check If Party Popularity Is Less Than 5
		else if (sum <= 5)
		{
			currentColor = partiesRunning[0]->tilt;;
		}
	}
	else
	{
		currentColor = Color{ 101, 101, 101, 255 };
	}
}

void State::Enable()
{
	isEnabled = true;
}

void State::Disable()
{
	isEnabled = false;
}

bool State::IsMouseOverState(Vector2 mousePosition)
{
	if (isEnabled)
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
}
