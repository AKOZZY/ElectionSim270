#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include "raylib.h"
#include "State.h"

class StateTooltip
{
public:
	// Show And Hide State Tooltip
	void Show(State* selectedState, Vector2 mousePosition);
	std::string FormatNumber(int number);
};

