#pragma once
#include <vector>
#include "raylib.h"
#include "State.h"


class StateManager
{
public:
	StateManager();
	~StateManager();
	float GetMapOffsetX();
	float GetMapOffsetY();
	// Vector Array To Hold The States.
	std::vector<State*> states{};
private:
	// Reference States
	State* california{};
	State* nevada{};
	State* alaska{};
	State* hawaii{};
	State* oregon{};
	State* washington{};
	State* arizona{};
	State* utah{};
	State* idaho{};
	State* montana{};
	State* wyoming{};
	State* colorado{};
	State* new_mexico{};
	State* texas{};
	State* oklahoma{};
	State* kansas{};
	State* nebraska{};
	State* south_dakota{};
	State* north_dakota{};
	State* minnesota{};
	State* iowa{};
	State* missouri{};
	State* arkansas{};
	State* louisiana{};
	State* wisconsin{};
	State* illinois{};
	State* michigan{};
	State* indiana{};
	State* ohio{};
	State* pennsylvania{};
	State* new_york{};
	State* new_jersey{};
	State* vermont{};
	State* new_hampshire{};
	State* maine{};
	State* massachusetts{};
	State* connecticut{};
	State* rhode_island{};
	State* delaware{};
	State* maryland{};
	State* florida{};
	State* mississippi{};
	State* alabama{};
	State* georgia{};
	State* south_carolina{};
	State* tennessee{};
	State* kentucky{};
	State* west_virginia{};
	State* virginia{};
	State* north_carolina{};
	State* dc{};
	// Offsets
	float mapOffsetX{ 10.0f };
	float mapOffsetY{ 70.0f };
};

