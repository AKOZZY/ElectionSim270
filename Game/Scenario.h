#pragma once

#include <vector>
#include <iostream>
#include "raylib.h"
#include "State.h"
#include "Party.h"

enum ScenarioID
{
	SCENARIO_2024,
	SCENARIO_1860,
};

struct Candidate
{
	std::string firstName{};
	std::string lastName{};
	std::string homeState{};
	std::string party{};
	Texture2D portrait{};
	bool isRunningMate{};
};

class Scenario
{
public:
	void LoadScenario(ScenarioID id, std::vector<State*> states);
	std::vector<Party*> parties{};
	Texture2D bordersSprite{};
private:
	// Scenario Year
	std::string year{};
	// Candidates
	std::vector<Candidate> candidates{};
	
	// Number Of Candidates Running
	int numOfCandidates{};
};

