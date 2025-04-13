#include "StateTooltip.h"

void StateTooltip::Show(State* selectedState, Vector2 mousePosition)
{
	// Draw Tooltip Box
	DrawRectangle(mousePosition.x + 50, mousePosition.y - 60, 260, 125, Color{ 0, 0, 0, 200 });
	// Draw State Name
	DrawText(selectedState->GetName(), mousePosition.x + 55, mousePosition.y - 60, 20, WHITE);
	// Draw State Electoral Votes
	DrawText(TextFormat("Electoral Votes: %i", selectedState->GetElectoralVotes()), mousePosition.x + 55, mousePosition.y - 40, 20, WHITE);
	// Draw State Popular Votes
	DrawText(TextFormat("Popular Votes: %i", selectedState->GetPopularVotes()), mousePosition.x + 55, mousePosition.y - 20, 20, WHITE);
	// Draw State Ideology
	if (selectedState->ideology == selectedState->PROGRESSIVE)
	{
		DrawText("Progressive", mousePosition.x + 55, mousePosition.y, 20, WHITE);
	}
	else if (selectedState->ideology == selectedState->CENTERLEFT)
	{
		DrawText("Center-Left", mousePosition.x + 55, mousePosition.y, 20, WHITE);
	}
	else if (selectedState->ideology == selectedState->CENTER)
	{
		DrawText("Center", mousePosition.x + 55, mousePosition.y, 20, WHITE);
	}
	else if (selectedState->ideology == selectedState->CENTERRIGHT)
	{
		DrawText("Center-Right", mousePosition.x + 55, mousePosition.y, 20, WHITE);
	}
	else if (selectedState->ideology == selectedState->CONSERVATIVE)
	{
		DrawText("Conservative", mousePosition.x + 55, mousePosition.y, 20, WHITE);
	}
	// Draw Republican Percentage
	DrawText(TextFormat("Republican: %0.2f", selectedState->GetRepublicanPopularity()), mousePosition.x + 55, mousePosition.y + 20, 20, WHITE);
	// Draw Democratic Percentage
	DrawText(TextFormat("Democratic: %0.2f", selectedState->GetDemocraticPopularity()), mousePosition.x + 55, mousePosition.y + 40, 20, WHITE);
}
