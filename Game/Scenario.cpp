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
		std::cout << "2024";

		for (int i = 0; i < states.size(); i++)
		{
			states[i]->Enable();

			if (states[i]->GetName() == "California")
			{
				states[i]->SetElectoralVotes(51);
			}
		}
	}
	else if (id == SCENARIO_1860)
	{
		std::cout << "1860";

		for (int i = 0; i < states.size(); i++)
		{
			if (states[i]->GetName() == "California")
			{
				states[i]->SetPartyPopularity(100, 0);
			}
		}
	}
}

