#pragma once
#include <vector>
#include <iostream>
#include "raylib.h"
#include "Party.h"



class State
{
public:
	// Create State
	State(const char* stateName, int electoralVotes, int popularVotes, Texture2D stateTexture);
	~State();

	void AddVertexPoint(Vector2 vertexPoint);
	void AddParty(Party* party);

	void SetPartyPopularity(float republican, float democrat);
	void CalculatePartyPopularity();

	void SetPartyPopularityIndex(int partyIndex, float percentage);
	void UpdatePartyPopularity(int partyIndex, float percentage, float modifier);

	const char* GetName();
	void SetElectoralVotes(int ev);
	int GetElectoralVotes();
	void SetPopularVotes(int pv);
	int GetPopularVotes();

	void BoostRepublicanPopularity(float percentage, float modifier);
	void BoostDemocraticPopularity(float percentage, float modifier);
	float GetRepublicanPopularity();
	float GetDemocraticPopularity();

	void Render(Vector2 position);
	void RenderVertexPoints();

	void UpdateStateColor(float sum);

	void Enable();
	void Disable();

	bool IsMouseOverState(Vector2 mousePosition);

	bool isDemocraticAhead{};
	bool isRepublicanAhead{};

	std::vector<Party*> partiesRunning{};
private:
	// State Charactoristics
	const char* stateName{};
	int electoralVotes{};
	int popularVotes{};

	float republicanPopularity{};
	float democraticPopularity{};

	bool isEnabled{};

	Texture2D stateTexture{};
	std::vector<Vector2> vertexPoints{};

	// State Colors
	Color currentColor{};
	// Republican
	Color safeGOP{ 119, 31, 31, 255 };
	Color likelyGOP{ 176, 64, 64, 255 };
	Color leanGOP{ 233, 115, 115, 255 };
	Color tiltGOP{ 207, 137, 128, 255 };
	// Democrat
	Color safeDEM{ 37, 53, 128, 255 };
	Color likelyDEM{ 50, 69, 163, 255 };
	Color leanDEM{ 100, 124, 237, 255 };
	Color tiltDEM{ 171, 184, 246, 255 };
};

