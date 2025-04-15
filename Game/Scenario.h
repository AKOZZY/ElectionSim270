#pragma once

#include <vector>
#include <iostream>
#include "State.h"

struct Candidate
{
	std::string name{};
	std::string homeState{};
	std::string party{};
	bool isRunningMate{};
};

struct Party
{
	std::string name{};
	bool leftLeaning{};
	bool rightLeaning{};
};

class Scenario
{
public:
	Scenario(std::string year, std::vector<State> states, std::vector<Candidate> candidates, int numOfCandidates);
	void LoadScenario();
private:
	std::string year{};
	std::vector<State> states{};
	std::vector<Candidate> candidates{};
	int numOfCandidates{};
};

