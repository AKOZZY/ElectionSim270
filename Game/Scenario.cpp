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
				Party* republican = new Party("Republican", Color{ 191, 29, 41, 255 }, Color{ 255, 88, 101, 255 }, Color{ 233, 139, 152, 255 }, Color{ 207, 137, 128, 255 });
				Party* democrat = new Party("Democrat", Color{ 28, 64, 140, 255 }, Color{ 87, 124, 204, 255 }, Color{ 138, 175, 255, 255 }, Color{ 148, 155, 179, 255 });
				Party* independent = new Party("Independent", Color{ 195, 169, 41, 255 }, Color{ 208, 190, 98, 255 }, Color{ 255, 234, 131, 255 }, Color{ 204, 196, 158, 255 });
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

			// Init State
			if (states[i]->GetName() == "Arizona")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(11);
				// Set Popular Votes
				states[i]->SetPopularVotes(3353102);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 52);
				states[i]->SetPartyPopularityIndex("Democrat", 48);
			}

			// Init State
			if (states[i]->GetName() == "Utah")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(6);
				// Set Popular Votes
				states[i]->SetPopularVotes(1446384);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 60);
				states[i]->SetPartyPopularityIndex("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Idaho")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(880218);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 60);
				states[i]->SetPartyPopularityIndex("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Montana")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(583985);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 60);
				states[i]->SetPartyPopularityIndex("Democrat", 40);
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

