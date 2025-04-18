#include "Party.h"

Party::Party(std::string name, Color safe, Color likely, Color lean, Color tilt)
{
	// Party Identity
	this->name = name;

	// Colors
	this->safe = safe;
	this->likely = likely;
	this->lean = lean;
	this->tilt = tilt;
}

std::string Party::GetName()
{
	return name;
}
