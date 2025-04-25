#include "StateTooltip.h"

void StateTooltip::Show(State* selectedState, Vector2 mousePosition)
{
	// Draw Tooltip Box
	DrawRectangle(mousePosition.x + 50, mousePosition.y - 70, 280, 175, BLACK);
	// Draw State Name
	DrawText(selectedState->GetName(), mousePosition.x + 55, mousePosition.y - 60, 25, WHITE);
	// Draw State Electoral Votes
	DrawText(TextFormat("Electoral Votes: %i", selectedState->GetElectoralVotes()), mousePosition.x + 55, mousePosition.y - 20, 20, WHITE);
	// Draw State Popular Votes
	//DrawText(TextFormat("Popular Votes: %i", selectedState->GetPopularVotes()), mousePosition.x + 55, mousePosition.y, 20, WHITE);
	DrawText("Popular Votes:", mousePosition.x + 55, mousePosition.y, 20, WHITE);
	DrawText(FormatNumber(selectedState->GetPopularVotes()).c_str(), mousePosition.x + 220, mousePosition.y, 20, WHITE);

	// Draw States Running
	for (int i = 0; i < selectedState->partiesRunning.size(); i++)
	{
		float y{};
		y = i * 20;
		DrawText(selectedState->partiesRunning[i]->GetName().c_str(), mousePosition.x + 55, mousePosition.y + 30 + y, 20, selectedState->partiesRunning[i]->safe);
		DrawText(TextFormat(" - %0.2f", selectedState->partiesRunning[i]->partySupport), mousePosition.x + 180, mousePosition.y + 30 + y, 20, selectedState->partiesRunning[i]->safe);
	}
}

std::string StateTooltip::FormatNumber(int number)
{
	std::stringstream ss{};
	ss.imbue(std::locale(""));
	ss << std::fixed << number;
	return ss.str();
}
