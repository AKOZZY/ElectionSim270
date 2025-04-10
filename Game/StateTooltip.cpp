#include "StateTooltip.h"

void StateTooltip::Show(const char* stateName, Vector2 mousePosition)
{
	DrawRectangle(mousePosition.x, mousePosition.y - 60, 200, 50, WHITE);
	DrawText(stateName, mousePosition.x, mousePosition.y - 60, 32, BLACK);
}
