#pragma once

#include <iostream>
#include "raylib.h"

class Party
{
public:
	Party(std::string name, Color safe, Color likely, Color lean, Color tilt);
private:
	std::string name{};
	// Party Colors On Map
	Color safe{};
	Color likely{};
	Color lean{};
	Color tilt{};
};

