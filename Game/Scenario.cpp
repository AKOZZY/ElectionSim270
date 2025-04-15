#include "Scenario.h"

Scenario::Scenario(std::string year, std::vector<State> states, std::vector<Candidate> candidates, int numOfCandidates)
{
	this->year = year;
	this->states = states;
	this->candidates = candidates;
	this->numOfCandidates = numOfCandidates;
}

void Scenario::LoadScenario()
{

}
