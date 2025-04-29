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
		// Create Parties For Scenario
		Party* republican = new Party("Republican", Color{ 191, 29, 41, 255 }, Color{ 255, 88, 101, 255 }, Color{ 233, 139, 152, 255 }, Color{ 207, 137, 128, 255 });
		Party* democrat = new Party("Democrat", Color{ 28, 64, 140, 255 }, Color{ 87, 124, 204, 255 }, Color{ 138, 175, 255, 255 }, Color{ 148, 155, 179, 255 });
		Party* independent = new Party("Independent", Color{ 195, 169, 41, 255 }, Color{ 208, 190, 98, 255 }, Color{ 255, 234, 131, 255 }, Color{ 204, 196, 158, 255 });

		parties.push_back(republican);
		parties.push_back(democrat);
		parties.push_back(independent);

		for (int i = 0; i < states.size(); i++)
		{
			// Create Parties For States
			Party* republican = new Party("Republican", Color{ 191, 29, 41, 255 }, Color{ 255, 88, 101, 255 }, Color{ 233, 139, 152, 255 }, Color{ 207, 137, 128, 255 });
			Party* democrat = new Party("Democrat", Color{ 28, 64, 140, 255 }, Color{ 87, 124, 204, 255 }, Color{ 138, 175, 255, 255 }, Color{ 148, 155, 179, 255 });
			Party* independent = new Party("Independent", Color{ 195, 169, 41, 255 }, Color{ 208, 190, 98, 255 }, Color{ 255, 234, 131, 255 }, Color{ 204, 196, 158, 255 });

			states[i]->AddParty(republican);
			states[i]->AddParty(democrat);
			states[i]->AddParty(independent);

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
				states[i]->SetPartyPopularityIndex("Republican", 44);
				states[i]->SetPartyPopularityIndex("Democrat", 56);
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
				states[i]->SetPartyPopularityIndex("Republican", 47);
				states[i]->SetPartyPopularityIndex("Democrat", 53);
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

			// Init State
			if (states[i]->GetName() == "Wyoming")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(262160);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 60);
				states[i]->SetPartyPopularityIndex("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Colorado")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(10);
				// Set Popular Votes
				states[i]->SetPopularVotes(3105600);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 44);
				states[i]->SetPartyPopularityIndex("Democrat", 56);
			}

			// Init State
			if (states[i]->GetName() == "New Mexico")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(5);
				// Set Popular Votes
				states[i]->SetPopularVotes(902193);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 45);
				states[i]->SetPartyPopularityIndex("Democrat", 55);
			}

			// Init State
			if (states[i]->GetName() == "Texas")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(40);
				// Set Popular Votes
				states[i]->SetPopularVotes(11228847);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 56);
				states[i]->SetPartyPopularityIndex("Democrat", 44);
			}

			// Init State
			if (states[i]->GetName() == "Oklahoma")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(7);
				// Set Popular Votes
				states[i]->SetPopularVotes(1535812);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 60);
				states[i]->SetPartyPopularityIndex("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Kansas")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(6);
				// Set Popular Votes
				states[i]->SetPopularVotes(1303655);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 60);
				states[i]->SetPartyPopularityIndex("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Nebraska")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(5);
				// Set Popular Votes
				states[i]->SetPopularVotes(934811);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 60);
				states[i]->SetPartyPopularityIndex("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "South Dakota")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(418940);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 60);
				states[i]->SetPartyPopularityIndex("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "North Dakota")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(358832);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 60);
				states[i]->SetPartyPopularityIndex("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Minnesota")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(10);
				// Set Popular Votes
				states[i]->SetPopularVotes(3176011);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 50);
				states[i]->SetPartyPopularityIndex("Democrat", 60);
			}

			// Init State
			if (states[i]->GetName() == "Iowa")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(6);
				// Set Popular Votes
				states[i]->SetPopularVotes(1634297);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 56);
				states[i]->SetPartyPopularityIndex("Democrat", 44);
			}

			// Init State
			if (states[i]->GetName() == "Missouri")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(10);
				// Set Popular Votes
				states[i]->SetPopularVotes(2952585);
				// Set Party Popularity In State
				states[i]->SetPartyPopularityIndex("Republican", 60);
				states[i]->SetPartyPopularityIndex("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Arkansas")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(6);
				// Set Popular Votes
				states[i]->SetPopularVotes(1156146);
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

