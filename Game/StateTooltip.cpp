#include "StateTooltip.h"

void StateTooltip::Show(State* selectedState, Vector2 mousePosition)
{
	// Draw Tooltip Box
	DrawRectangle(mousePosition.x + 50, mousePosition.y - 60, 260, 150, Color{ 0, 0, 0, 200 });
	// Draw State Name
	DrawText(selectedState->GetName(), mousePosition.x + 55, mousePosition.y - 60, 20, WHITE);
	// Draw State Electoral Votes
	DrawText(TextFormat("Electoral Votes: %i", selectedState->GetElectoralVotes()), mousePosition.x + 55, mousePosition.y - 40, 20, WHITE);
	// Draw State Popular Votes
	DrawText(TextFormat("Popular Votes: %i", selectedState->GetPopularVotes()), mousePosition.x + 55, mousePosition.y - 20, 20, WHITE);
	// Draw Republican Percentage
	DrawText(TextFormat("Republican: %02.02f", selectedState->GetRepublicanPopularity()), mousePosition.x + 55, mousePosition.y + 50, 20, WHITE);
	// Draw Democratic Percentage
	DrawText(TextFormat("Democratic: %02.02f", selectedState->GetDemocraticPopularity()), mousePosition.x + 55, mousePosition.y + 70, 20, WHITE);
}
