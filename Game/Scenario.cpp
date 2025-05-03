#include "Scenario.h"

void Scenario::LoadScenario(ScenarioID id, std::vector<State*> states)
{
	if (id == SCENARIO_2024)
	{
		// Load Borders Sprite
		bordersSprite = LoadTexture("assets/StateBorders.png");
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
				states[i]->SetPartyPopularity("Republican", 40);
				states[i]->SetPartyPopularity("Democrat", 60);
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
				states[i]->SetPartyPopularity("Republican", 44);
				states[i]->SetPartyPopularity("Democrat", 56);
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
				states[i]->SetPartyPopularity("Republican", 40);
				states[i]->SetPartyPopularity("Democrat", 60);
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
				states[i]->SetPartyPopularity("Republican", 40);
				states[i]->SetPartyPopularity("Democrat", 60);
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
				states[i]->SetPartyPopularity("Republican", 47);
				states[i]->SetPartyPopularity("Democrat", 53);
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
				states[i]->SetPartyPopularity("Republican", 55);
				states[i]->SetPartyPopularity("Democrat", 45);
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
				states[i]->SetPartyPopularity("Republican", 52);
				states[i]->SetPartyPopularity("Democrat", 48);
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
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
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
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
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
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
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
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
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
				states[i]->SetPartyPopularity("Republican", 44);
				states[i]->SetPartyPopularity("Democrat", 56);
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
				states[i]->SetPartyPopularity("Republican", 45);
				states[i]->SetPartyPopularity("Democrat", 55);
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
				states[i]->SetPartyPopularity("Republican", 56);
				states[i]->SetPartyPopularity("Democrat", 44);
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
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
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
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
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
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
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
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
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
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
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
				states[i]->SetPartyPopularity("Republican", 50);
				states[i]->SetPartyPopularity("Democrat", 60);
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
				states[i]->SetPartyPopularity("Republican", 56);
				states[i]->SetPartyPopularity("Democrat", 44);
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
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
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
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);

				//states[i]->SetName("Goobertown");
			}

			// Init State
			if (states[i]->GetName() == "Louisiana")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(8);
				// Set Popular Votes
				states[i]->SetPopularVotes(1975375);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 34);
				states[i]->SetPartyPopularity("Democrat", 31);
				states[i]->SetPartyPopularity("S. Democrat", 33);
				states[i]->SetPartyPopularity("C. Union", 2);
			}

			// Init State
			if (states[i]->GetName() == "Wisconsin")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(10);
				// Set Popular Votes
				states[i]->SetPopularVotes(3365855);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 52);
				states[i]->SetPartyPopularity("Democrat", 48);
			}

			// Init State
			if (states[i]->GetName() == "Illinois")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(19);
				// Set Popular Votes
				states[i]->SetPopularVotes(5511942);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 44);
				states[i]->SetPartyPopularity("Democrat", 56);
			}

			// Init State
			if (states[i]->GetName() == "Michigan")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(15);
				// Set Popular Votes
				states[i]->SetPopularVotes(5553169);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 48);
				states[i]->SetPartyPopularity("Democrat", 52);
			}

			// Init State
			if (states[i]->GetName() == "Indiana")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(11);
				// Set Popular Votes
				states[i]->SetPopularVotes(2883950);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Ohio")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(17);
				// Set Popular Votes
				states[i]->SetPopularVotes(5713815);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 56);
				states[i]->SetPartyPopularity("Democrat", 44);
			}

			// Init State
			if (states[i]->GetName() == "Pennsylvania")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(19);
				// Set Popular Votes
				states[i]->SetPopularVotes(6966350);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 51);
				states[i]->SetPartyPopularity("Democrat", 49);
			}

			// Init State
			if (states[i]->GetName() == "New York")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(28);
				// Set Popular Votes
				states[i]->SetPopularVotes(8198094);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 44);
				states[i]->SetPartyPopularity("Democrat", 56);
			}

			// Init State
			if (states[i]->GetName() == "New Jersey")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(14);
				// Set Popular Votes
				states[i]->SetPopularVotes(4188928);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 44);
				states[i]->SetPartyPopularity("Democrat", 56);
			}

			// Init State
			if (states[i]->GetName() == "Vermont")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(355186);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 40);
				states[i]->SetPartyPopularity("Democrat", 60);
			}

			// Init State
			if (states[i]->GetName() == "New Hampshire")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(814011);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 48);
				states[i]->SetPartyPopularity("Democrat", 52);
			}

			// Init State
			if (states[i]->GetName() == "Maine")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(813629);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 45);
				states[i]->SetPartyPopularity("Democrat", 55);
			}

			// Init State
			if (states[i]->GetName() == "Massachusetts")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(11);
				// Set Popular Votes
				states[i]->SetPopularVotes(3377821);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 30);
				states[i]->SetPartyPopularity("Democrat", 70);
			}

			// Init State
			if (states[i]->GetName() == "Connecticut")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(7);
				// Set Popular Votes
				states[i]->SetPopularVotes(1728971);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 30);
				states[i]->SetPartyPopularity("Democrat", 70);
			}

			// Init State
			if (states[i]->GetName() == "Rhode Island")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(499562);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 30);
				states[i]->SetPartyPopularity("Democrat", 70);
			}

			// Init State
			if (states[i]->GetName() == "Delaware")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(504109);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 40);
				states[i]->SetPartyPopularity("Democrat", 60);
			}

			// Init State
			if (states[i]->GetName() == "Maryland")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(10);
				// Set Popular Votes
				states[i]->SetPopularVotes(2938127);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 30);
				states[i]->SetPartyPopularity("Democrat", 70);
			}

			// Init State
			if (states[i]->GetName() == "Florida")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(30);
				// Set Popular Votes
				states[i]->SetPopularVotes(10793163);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 56);
				states[i]->SetPartyPopularity("Democrat", 44);
			}

			// Init State
			if (states[i]->GetName() == "Mississippi")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(6);
				// Set Popular Votes
				states[i]->SetPopularVotes(1214412);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Alabama")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(9);
				// Set Popular Votes
				states[i]->SetPopularVotes(2235028);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Georgia")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(16);
				// Set Popular Votes
				states[i]->SetPopularVotes(5211134);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 51);
				states[i]->SetPartyPopularity("Democrat", 49);
			}

			// Init State
			if (states[i]->GetName() == "South Carolina")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(9);
				// Set Popular Votes
				states[i]->SetPopularVotes(2512199);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 70);
				states[i]->SetPartyPopularity("Democrat", 30);
			}

			// Init State
			if (states[i]->GetName() == "Tennessee")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(11);
				// Set Popular Votes
				states[i]->SetPopularVotes(3023130);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 70);
				states[i]->SetPartyPopularity("Democrat", 30);
			}

			// Init State
			if (states[i]->GetName() == "Kentucky")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(8);
				// Set Popular Votes
				states[i]->SetPopularVotes(2041537);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 70);
				states[i]->SetPartyPopularity("Democrat", 30);
			}

			// Init State
			if (states[i]->GetName() == "West Virginia")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(747865);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 70);
				states[i]->SetPartyPopularity("Democrat", 30);
			}

			// Init State
			if (states[i]->GetName() == "Virginia")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(13);
				// Set Popular Votes
				states[i]->SetPopularVotes(4410480);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 45);
				states[i]->SetPartyPopularity("Democrat", 55);
				// Set Sprite
				states[i]->SetStateSprite(LoadTexture("assets/states/virginia.png"));
			}

			// Init State
			if (states[i]->GetName() == "North Carolina")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(16);
				// Set Popular Votes
				states[i]->SetPopularVotes(5613798);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 53);
				states[i]->SetPartyPopularity("Democrat", 47);
			}

			// Init State
			if (states[i]->GetName() == "D. C")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(315261);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 5);
				states[i]->SetPartyPopularity("Democrat", 95);
			}
		}
	}
	else if (id == SCENARIO_1860)
	{
		// Load Borders Sprite
		bordersSprite = LoadTexture("assets/StateBorders1788to1860.png");
		// Create Parties For Scenario
		Party* republican = new Party("Republican", Color{ 191, 29, 41, 255 }, Color{ 255, 88, 101, 255 }, Color{ 233, 139, 152, 255 }, Color{ 207, 137, 128, 255 });
		Party* democrat = new Party("Democrat", Color{ 28, 64, 140, 255 }, Color{ 87, 124, 204, 255 }, Color{ 138, 175, 255, 255 }, Color{ 148, 155, 179, 255 });
		Party* southernDemocrat = new Party("S. Democrat", Color{ 195, 169, 41, 255 }, Color{ 208, 190, 98, 255 }, Color{ 255, 234, 131, 255 }, Color{ 204, 196, 158, 255 });
		Party* constitutionalUnion = new Party("C. Union", Color{ 62, 101, 57, 255 }, Color{ 121, 163, 116, 255 }, Color{ 154, 226, 146, 255 }, Color{ 174, 204, 158, 255 });

		parties.push_back(republican);
		parties.push_back(democrat);
		parties.push_back(southernDemocrat);
		parties.push_back(constitutionalUnion);

		for (int i = 0; i < states.size(); i++)
		{
			// Create Parties For States
			Party* republican = new Party("Republican", Color{ 191, 29, 41, 255 }, Color{ 255, 88, 101, 255 }, Color{ 233, 139, 152, 255 }, Color{ 207, 137, 128, 255 });
			Party* democrat = new Party("Democrat", Color{ 28, 64, 140, 255 }, Color{ 87, 124, 204, 255 }, Color{ 138, 175, 255, 255 }, Color{ 148, 155, 179, 255 });
			Party* southernDemocrat = new Party("S. Democrat", Color{ 195, 169, 41, 255 }, Color{ 208, 190, 98, 255 }, Color{ 255, 234, 131, 255 }, Color{ 204, 196, 158, 255 });
			Party* constitutionalUnion = new Party("C. Union", Color{ 62, 101, 57, 255 }, Color{ 121, 163, 116, 255 }, Color{ 154, 226, 146, 255 }, Color{ 174, 204, 158, 255 });

			states[i]->AddParty(democrat);
			states[i]->AddParty(southernDemocrat);
			states[i]->AddParty(constitutionalUnion);

			// Init State
			if (states[i]->GetName() == "California")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(119885);
				// Add Parties Manually
				states[i]->AddParty(republican);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 32);
				states[i]->SetPartyPopularity("Democrat", 31);
				states[i]->SetPartyPopularity("S. Democrat", 30);
				states[i]->SetPartyPopularity("C. Union", 7);
			}

			// Init State
			if (states[i]->GetName() == "Oregon")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(14761);
				// Add Parties Manually
				states[i]->AddParty(republican);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 34);
				states[i]->SetPartyPopularity("Democrat", 31);
				states[i]->SetPartyPopularity("S. Democrat", 33);
				states[i]->SetPartyPopularity("C. Union", 2);
			}

			// Init State
			if (states[i]->GetName() == "Washington")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(12);
				// Set Popular Votes
				states[i]->SetPopularVotes(3776772);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 40);
				states[i]->SetPartyPopularity("Democrat", 60);
			}

			// Init State
			if (states[i]->GetName() == "Hawaii")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(506705);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 40);
				states[i]->SetPartyPopularity("Democrat", 60);
				// Hide State Completely
				states[i]->isHidden = true;
			}

			// Init State
			if (states[i]->GetName() == "Nevada")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(6);
				// Set Popular Votes
				states[i]->SetPopularVotes(1456402);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 47);
				states[i]->SetPartyPopularity("Democrat", 53);
			}

			// Init State
			if (states[i]->GetName() == "Alaska")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(324484);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 55);
				states[i]->SetPartyPopularity("Democrat", 45);
				// Hide State Completely
				states[i]->isHidden = true;
			}

			// Init State
			if (states[i]->GetName() == "Arizona")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(11);
				// Set Popular Votes
				states[i]->SetPopularVotes(3353102);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 52);
				states[i]->SetPartyPopularity("Democrat", 48);
			}

			// Init State
			if (states[i]->GetName() == "Utah")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(6);
				// Set Popular Votes
				states[i]->SetPopularVotes(1446384);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Idaho")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(880218);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Montana")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(583985);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Wyoming")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(262160);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Colorado")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(10);
				// Set Popular Votes
				states[i]->SetPopularVotes(3105600);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 44);
				states[i]->SetPartyPopularity("Democrat", 56);
			}

			// Init State
			if (states[i]->GetName() == "New Mexico")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(5);
				// Set Popular Votes
				states[i]->SetPopularVotes(902193);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 45);
				states[i]->SetPartyPopularity("Democrat", 55);
			}

			// Init State
			if (states[i]->GetName() == "Texas")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(62986);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Democrat", 10);
				states[i]->SetPartyPopularity("S. Democrat", 70);
				states[i]->SetPartyPopularity("C. Union", 20);
			}

			// Init State
			if (states[i]->GetName() == "Oklahoma")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(7);
				// Set Popular Votes
				states[i]->SetPopularVotes(1535812);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Kansas")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(6);
				// Set Popular Votes
				states[i]->SetPopularVotes(1303655);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Nebraska")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(5);
				// Set Popular Votes
				states[i]->SetPopularVotes(934811);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "South Dakota")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(418940);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "North Dakota")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(358832);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Minnesota")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(34787);
				// Add Parties Manually
				states[i]->AddParty(republican);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 70);
				states[i]->SetPartyPopularity("Democrat", 27);
				states[i]->SetPartyPopularity("S. Democrat", 2);
				states[i]->SetPartyPopularity("C. Union", 1);
			}

			// Init State
			if (states[i]->GetName() == "Iowa")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(128739);
				// Add Parties Manually
				states[i]->AddParty(republican);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 54);
				states[i]->SetPartyPopularity("Democrat", 42);
				states[i]->SetPartyPopularity("S. Democrat", 2);
				states[i]->SetPartyPopularity("C. Union", 2);
			}

			// Init State
			if (states[i]->GetName() == "Missouri")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(9);
				// Set Popular Votes
				states[i]->SetPopularVotes(165563);
				// Add Parties Manually
				states[i]->AddParty(republican);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 10);
				states[i]->SetPartyPopularity("Democrat", 35);
				states[i]->SetPartyPopularity("S. Democrat", 21);
				states[i]->SetPartyPopularity("C. Union", 34);
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
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);

				//states[i]->SetName("Goobertown");
			}

			// Init State
			if (states[i]->GetName() == "Louisiana")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(8);
				// Set Popular Votes
				states[i]->SetPopularVotes(1975375);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Wisconsin")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(10);
				// Set Popular Votes
				states[i]->SetPopularVotes(3365855);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 52);
				states[i]->SetPartyPopularity("Democrat", 48);
			}

			// Init State
			if (states[i]->GetName() == "Illinois")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(19);
				// Set Popular Votes
				states[i]->SetPopularVotes(5511942);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 44);
				states[i]->SetPartyPopularity("Democrat", 56);
			}

			// Init State
			if (states[i]->GetName() == "Michigan")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(15);
				// Set Popular Votes
				states[i]->SetPopularVotes(5553169);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 48);
				states[i]->SetPartyPopularity("Democrat", 52);
			}

			// Init State
			if (states[i]->GetName() == "Indiana")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(11);
				// Set Popular Votes
				states[i]->SetPopularVotes(2883950);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Ohio")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(17);
				// Set Popular Votes
				states[i]->SetPopularVotes(5713815);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 56);
				states[i]->SetPartyPopularity("Democrat", 44);
			}

			// Init State
			if (states[i]->GetName() == "Pennsylvania")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(19);
				// Set Popular Votes
				states[i]->SetPopularVotes(6966350);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 51);
				states[i]->SetPartyPopularity("Democrat", 49);
			}

			// Init State
			if (states[i]->GetName() == "New York")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(28);
				// Set Popular Votes
				states[i]->SetPopularVotes(8198094);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 44);
				states[i]->SetPartyPopularity("Democrat", 56);
			}

			// Init State
			if (states[i]->GetName() == "New Jersey")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(14);
				// Set Popular Votes
				states[i]->SetPopularVotes(4188928);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 44);
				states[i]->SetPartyPopularity("Democrat", 56);
			}

			// Init State
			if (states[i]->GetName() == "Vermont")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(355186);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 40);
				states[i]->SetPartyPopularity("Democrat", 60);
			}

			// Init State
			if (states[i]->GetName() == "New Hampshire")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(814011);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 48);
				states[i]->SetPartyPopularity("Democrat", 52);
			}

			// Init State
			if (states[i]->GetName() == "Maine")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(813629);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 45);
				states[i]->SetPartyPopularity("Democrat", 55);
			}

			// Init State
			if (states[i]->GetName() == "Massachusetts")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(11);
				// Set Popular Votes
				states[i]->SetPopularVotes(3377821);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 30);
				states[i]->SetPartyPopularity("Democrat", 70);
			}

			// Init State
			if (states[i]->GetName() == "Connecticut")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(7);
				// Set Popular Votes
				states[i]->SetPopularVotes(1728971);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 30);
				states[i]->SetPartyPopularity("Democrat", 70);
			}

			// Init State
			if (states[i]->GetName() == "Rhode Island")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(499562);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 30);
				states[i]->SetPartyPopularity("Democrat", 70);
			}

			// Init State
			if (states[i]->GetName() == "Delaware")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(504109);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 40);
				states[i]->SetPartyPopularity("Democrat", 60);
			}

			// Init State
			if (states[i]->GetName() == "Maryland")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(10);
				// Set Popular Votes
				states[i]->SetPopularVotes(2938127);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 30);
				states[i]->SetPartyPopularity("Democrat", 70);
			}

			// Init State
			if (states[i]->GetName() == "Florida")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(30);
				// Set Popular Votes
				states[i]->SetPopularVotes(10793163);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 56);
				states[i]->SetPartyPopularity("Democrat", 44);
			}

			// Init State
			if (states[i]->GetName() == "Mississippi")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(6);
				// Set Popular Votes
				states[i]->SetPopularVotes(1214412);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Alabama")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(9);
				// Set Popular Votes
				states[i]->SetPopularVotes(2235028);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 60);
				states[i]->SetPartyPopularity("Democrat", 40);
			}

			// Init State
			if (states[i]->GetName() == "Georgia")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(16);
				// Set Popular Votes
				states[i]->SetPopularVotes(5211134);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 51);
				states[i]->SetPartyPopularity("Democrat", 49);
			}

			// Init State
			if (states[i]->GetName() == "South Carolina")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(9);
				// Set Popular Votes
				states[i]->SetPopularVotes(2512199);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 70);
				states[i]->SetPartyPopularity("Democrat", 30);
			}

			// Init State
			if (states[i]->GetName() == "Tennessee")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(11);
				// Set Popular Votes
				states[i]->SetPopularVotes(3023130);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 70);
				states[i]->SetPartyPopularity("Democrat", 30);
			}

			// Init State
			if (states[i]->GetName() == "Kentucky")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(8);
				// Set Popular Votes
				states[i]->SetPopularVotes(2041537);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 70);
				states[i]->SetPartyPopularity("Democrat", 30);
			}

			// Init State
			if (states[i]->GetName() == "West Virginia")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(4);
				// Set Popular Votes
				states[i]->SetPopularVotes(747865);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 70);
				states[i]->SetPartyPopularity("Democrat", 30);
			}

			// Init State
			if (states[i]->GetName() == "Virginia")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(13);
				// Set Popular Votes
				states[i]->SetPopularVotes(4410480);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 45);
				states[i]->SetPartyPopularity("Democrat", 55);
				// Set Sprite
				states[i]->SetStateSprite(LoadTexture("assets/states/unifiedvirginia.png"));
			}

			// Init State
			if (states[i]->GetName() == "North Carolina")
			{
				// Enable
				states[i]->Enable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(16);
				// Set Popular Votes
				states[i]->SetPopularVotes(5613798);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 53);
				states[i]->SetPartyPopularity("Democrat", 47);
			}

			// Init State
			if (states[i]->GetName() == "D. C")
			{
				// Enable
				states[i]->Disable();
				// Set Electoral Votes
				states[i]->SetElectoralVotes(3);
				// Set Popular Votes
				states[i]->SetPopularVotes(315261);
				// Set Party Popularity In State
				states[i]->SetPartyPopularity("Republican", 5);
				states[i]->SetPartyPopularity("Democrat", 95);
				// Hide State Completely
				states[i]->isHidden = true;
			}
	}
}
}

void Scenario::Reset(std::vector<State*> &states)
{
	// Clear Parties
	parties.clear();
	// Clear Parties From Each State
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i] != nullptr)
		{
			states[i]->partiesRunning.clear();
		}
		
		// Reset State Properties
		states[i]->isHidden = false;
	}
}
