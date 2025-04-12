#pragma once

#include "raylib.h"
#include "State.h"

class StateTooltip
{
public:
	// Show And Hide State Tooltip
	void Show(State* selectedState, Vector2 mousePosition);
};

