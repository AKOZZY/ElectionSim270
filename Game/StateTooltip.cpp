#include "StateTooltip.h"

void StateTooltip::Show(const char* stateName, Vector2 mousePosition)
{
	DrawRectangle(mousePosition.x, mousePosition.y - 60, 200, 50, Color{0, 0, 0, 200});
	DrawText(stateName, mousePosition.x + 5, mousePosition.y - 60, 32, WHITE);
}
