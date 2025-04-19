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
			if (states[i] != nullptr)
			{
				// Create Unique Party Objects for each state
				Party* republican = new Party("Republican", Color{ 119, 31, 31, 255 }, Color{ 176, 64, 64, 255 }, Color{ 233, 115, 115, 255 }, Color{ 207, 137, 128, 255 });
				Party* democrat = new Party("Democrat", Color{ 37, 53, 128, 255 }, Color{ 50, 69, 163, 255 }, Color{ 100, 124, 237, 255 }, Color{ 171, 184, 246, 255 });
				Party* independent = new Party("Independent", Color{ 170, 165, 52, 255 }, Color{ 197, 190, 57, 255 }, Color{ 228, 222, 86, 255 }, Color{ 233, 229, 162, 255 });
				//Party* american = new Party("American", Color{ 170, 165, 52, 255 }, Color{ 197, 190, 57, 255 }, Color{ 228, 222, 86, 255 }, Color{ 233, 229, 162, 255 });

				states[i]->AddParty(republican);
				states[i]->AddParty(democrat);
				states[i]->AddParty(independent);
				//states[i]->AddParty(american);
			}
			
			// Init State
			if (states[i]->GetName() == "California")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(54);
				// Set Popular Votes
				states[i]->SetPopularVotes(15357876);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 40);
				states[i]->SetPartyPopularityIndex("Democrat", 60);
			}

			// Init State
			if (states[i]->GetName() == "Oregon")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(8);
				// Set Popular Votes
				states[i]->SetPopularVotes(2160080);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 40);
				states[i]->SetPartyPopularityIndex("Democrat", 60);
			}

			// Init State
			if (states[i]->GetName() == "Washington")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(12);
				// Set Popular Votes
				states[i]->SetPopularVotes(3776772);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 40);
				states[i]->SetPartyPopularityIndex("Democrat", 60);
			}

			// Init State
			if (states[i]->GetName() == "Hawaii")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(506705);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 40);
				states[i]->SetPartyPopularityIndex("Democrat", 60);
			}

			// Init State
			if (states[i]->GetName() == "Nevada")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(6);
				// Set Popular Votes
				states[i]->SetPopularVotes(1456402);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 49);
				states[i]->SetPartyPopularityIndex("Democrat", 51);
			}

			// Init State
			if (states[i]->GetName() == "Alaska")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(324484);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 55);
				states[i]->SetPartyPopularityIndex("Democrat", 45);
			}
		}
	}
	else if (id == SCENARIO_1860)
	{
		for (int i = 0; i < states.size(); i++)
		{
			if (states[i]->GetName() == "California")
			{
				
			}
		}
	}
}

