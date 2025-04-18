#include "Scenario.h"

Scenario::Scenario()
{

}

Scenario::~Scenario()
{

}

void Scenario::LoadScenario(ScenarioID id, std::vector<State*> states)
{
	if (id == SCENARIO_2024)
	{
		for (int i = 0; i < states.size(); i++)
		{
			states[i]->Enable();

			if (states[i] != nullptr)
			{
				// Create Unique Party Objects for each state
				republican = new Party("Republican", Color{ 119, 31, 31, 255 }, Color{ 176, 64, 64, 255 }, Color{ 233, 115, 115, 255 }, Color{ 207, 137, 128, 255 });
				democrat = new Party("Democrat", Color{ 37, 53, 128, 255 }, Color{ 50, 69, 163, 255 }, Color{ 100, 124, 237, 255 }, Color{ 171, 184, 246, 255 });
				independent = new Party("Independent", Color{ 170, 165, 52, 255 }, Color{ 197, 190, 57, 255 }, Color{ 228, 222, 86, 255 }, Color{ 233, 229, 162, 255 });

				states[i]->AddParty(republican);
				states[i]->AddParty(democrat);
				states[i]->AddParty(independent);
			}
			
			if (states[i]->GetName() == "California")
			{
				states[i]->SetElectoralVotes(69);
				states[i]->SetPartyPopularityIndex(0, 40);
				states[i]->SetPartyPopularityIndex(1, 59);
				states[i]->SetPartyPopularityIndex(2, 1);
			}
		}
	}
	else if (id == SCENARIO_1860)
	{
		for (int i = 0; i < states.size(); i++)
		{
			if (states[i]->GetName() == "California")
			{
				states[i]->SetPartyPopularity(100, 0);
			}
		}
	}
}

