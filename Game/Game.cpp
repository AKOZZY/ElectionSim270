#include "Game.h"

// Init
Game::Game()
{
	// Create Scenario Object
	scenario = new Scenario();

	// Load Game Logo
	gameLogo = LoadTexture("assets/ElectionSim270Logo.png");

	// Init Game Buttons
	buttonVisitState = new Button("Visit State", 20, 120, 20, Vector2{ 0, 0 });
	buttonCancelVisitState = new Button("Cancel", 20, 120, 20, Vector2{ 0, 20 });

	// Init Menu Buttons
	buttonModernScenarios = new Button("Modern (1960-2024)", 20, 200, 20, Vector2{ 0, 200 });

	// Play Scenario Buttons
	buttonScenario2024 = new Button("2024", 20, 120, 20, Vector2{ 475, 20 });

	// Set Selected State To Null
	selectedState = nullptr;

	// Init State Borders
	stateBorders = LoadTexture("assets/StateBorders.png");
	
	// Init States
	////////////////////////////////
	//         CALIFORNIA         //
	////////////////////////////////
	california = new State("California", LoadTexture("assets/states/california.png"));
	// Plot Out The Vertex Points Of The State For Poly Collision
	std::vector<Vector2> californiaVertexPoints
	{
		Vector2{ 5 + mapOffsetX, 99 + mapOffsetY },
		Vector2{ 16 + mapOffsetX, 153 + mapOffsetY },
		Vector2{ 41 + mapOffsetX, 191 + mapOffsetY },
		Vector2{ 71 + mapOffsetX, 212 + mapOffsetY },
		Vector2{ 94 + mapOffsetX, 212 + mapOffsetY },
		Vector2{ 101 + mapOffsetX, 192 + mapOffsetY },
		Vector2{ 44 + mapOffsetX, 137 + mapOffsetY },
		Vector2{ 44 + mapOffsetX, 99 + mapOffsetY },
	};
	// Push Points Into Vector
	for (int i = 0; i < californiaVertexPoints.size(); i++)
	{
		california->AddVertexPoint(californiaVertexPoints[i]);
	}
	// Add To Active States
	states.push_back(california);
	
	////////////////////////////////
	//         NEVADA	          //
	////////////////////////////////
	nevada = new State("Nevada", LoadTexture("assets/states/nevada.png"));
	std::vector<Vector2> nevadaVertexPoints
	{
		Vector2{44 + mapOffsetX, 99 + mapOffsetY},
		Vector2{44 + mapOffsetX, 137 + mapOffsetY},
		Vector2{96 + mapOffsetX, 186 + mapOffsetY},
		Vector2{97 + mapOffsetX, 180 + mapOffsetY},
		Vector2{85 + mapOffsetX, 173 + mapOffsetY},
		Vector2{101 + mapOffsetX, 172 + mapOffsetY},
		Vector2{101 + mapOffsetX, 99 + mapOffsetY},
	};
	for (int i = 0; i < nevadaVertexPoints.size(); i++)
	{
		nevada->AddVertexPoint(nevadaVertexPoints[i]);
	}
	states.push_back(nevada);

	////////////////////////////////
	//         ALASKA	          //
	////////////////////////////////
	alaska = new State("Alaska", LoadTexture("assets/states/alaska.png"));
	std::vector<Vector2> alaskaVertexPoints
	{
		Vector2{87 + mapOffsetX, 263 + mapOffsetY},
		Vector2{87 + mapOffsetX, 335 + mapOffsetY},
		Vector2{168 + mapOffsetX, 335 + mapOffsetY},
		Vector2{168 + mapOffsetX, 263 + mapOffsetY},
	};
	for (int i = 0; i < alaskaVertexPoints.size(); i++)
	{
		alaska->AddVertexPoint(alaskaVertexPoints[i]);
	}
	states.push_back(alaska);

	////////////////////////////////
	//         HAWAII	          //
	////////////////////////////////
	hawaii = new State("Hawaii", LoadTexture("assets/states/hawaii.png"));
	std::vector<Vector2> hawaiiVertexPoints
	{
		Vector2{7 + mapOffsetX, 243 + mapOffsetY},
		Vector2{7 + mapOffsetX, 282 + mapOffsetY},
		Vector2{66 + mapOffsetX, 282 + mapOffsetY},
		Vector2{66 + mapOffsetX, 243 + mapOffsetY},
	};
	for (int i = 0; i < hawaiiVertexPoints.size(); i++)
	{
		hawaii->AddVertexPoint(hawaiiVertexPoints[i]);
	}
	states.push_back(hawaii);

	////////////////////////////////
	//         OREGON	          //
	////////////////////////////////
	oregon = new State("Oregon", LoadTexture("assets/states/oregon.png"));
	std::vector<Vector2> oregonVertexPoints
	{
		Vector2{7 + mapOffsetX, 45 + mapOffsetY},
		Vector2{4 + mapOffsetX, 98 + mapOffsetY},
		Vector2{74 + mapOffsetX, 98 + mapOffsetY},
		Vector2{72 + mapOffsetX, 68 + mapOffsetY},
		Vector2{79 + mapOffsetX, 55 + mapOffsetY},
		Vector2{74 + mapOffsetX, 47 + mapOffsetY},
	};
	for (int i = 0; i < oregonVertexPoints.size(); i++)
	{
		oregon->AddVertexPoint(oregonVertexPoints[i]);
	}
	states.push_back(oregon);

	////////////////////////////////
	//         WASHINGTON	      //
	////////////////////////////////
	washington = new State("Washington", LoadTexture("assets/states/washington.png"));
	std::vector<Vector2> washingtonVertexPoints
	{
		Vector2{mapOffsetX, 4 + mapOffsetY},
		Vector2{7 + mapOffsetX, 44 + mapOffsetY},
		Vector2{23 + mapOffsetX, 53 + mapOffsetY},
		Vector2{70 + mapOffsetX, 46 + mapOffsetY},
		Vector2{74 + mapOffsetX, 47 + mapOffsetY},
		Vector2{73 + mapOffsetX, 4 + mapOffsetY},
	};
	for (int i = 0; i < washingtonVertexPoints.size(); i++)
	{
		washington->AddVertexPoint(washingtonVertexPoints[i]);
	}
	states.push_back(washington);

	////////////////////////////////
	//         ARIZONA		      //
	////////////////////////////////
	arizona = new State("Arizona", LoadTexture("assets/states/arizona.png"));
	std::vector<Vector2> arizonaVertexPoints
	{
		Vector2{94 + mapOffsetX, 212 + mapOffsetY},
		Vector2{98 + mapOffsetX, 208 + mapOffsetY},
		Vector2{95 + mapOffsetX, 202 + mapOffsetY},
		Vector2{101 + mapOffsetX, 192 + mapOffsetY},
		Vector2{96 + mapOffsetX, 184 + mapOffsetY},
		Vector2{96 + mapOffsetX, 172 + mapOffsetY},
		Vector2{101 + mapOffsetX, 172 + mapOffsetY},
		Vector2{101 + mapOffsetX, 162 + mapOffsetY},
		Vector2{149 + mapOffsetX, 162 + mapOffsetY},
		Vector2{149 + mapOffsetX, 226 + mapOffsetY},
		Vector2{128 + mapOffsetX, 226 + mapOffsetY},
	};
	for (int i = 0; i < arizonaVertexPoints.size(); i++)
	{
		arizona->AddVertexPoint(arizonaVertexPoints[i]);
	}
	states.push_back(arizona);

	////////////////////////////////
	//         UTAH				  //
	////////////////////////////////
	utah = new State("Utah", LoadTexture("assets/states/utah.png"));
	std::vector<Vector2> utahVertexPoints
	{
		Vector2{101 + mapOffsetX, 99 + mapOffsetY},
		Vector2{101 + mapOffsetX, 162 + mapOffsetY},
		Vector2{149 + mapOffsetX, 162 + mapOffsetY},
		Vector2{149 + mapOffsetX, 112 + mapOffsetY},
		Vector2{130 + mapOffsetX, 112 + mapOffsetY},
		Vector2{130 + mapOffsetX, 99 + mapOffsetY},
	};
	for (int i = 0; i < utahVertexPoints.size(); i++)
	{
		utah->AddVertexPoint(utahVertexPoints[i]);
	}
	states.push_back(utah);

	////////////////////////////////
	//         IDAHO			  //
	////////////////////////////////
	idaho = new State("Idaho", LoadTexture("assets/states/idaho.png"));
	std::vector<Vector2> idahoVertexPoints
	{
		Vector2{74 + mapOffsetX, 99 + mapOffsetY},
		Vector2{130 + mapOffsetX, 99 + mapOffsetY},
		Vector2{130 + mapOffsetX, 66 + mapOffsetY},
		Vector2{126 + mapOffsetX, 64 + mapOffsetY},
		Vector2{112 + mapOffsetX, 68 + mapOffsetY},
		Vector2{102 + mapOffsetX, 52 + mapOffsetY},
		Vector2{97 + mapOffsetX, 54 + mapOffsetY},
		Vector2{96 + mapOffsetX, 43 + mapOffsetY},
		Vector2{99 + mapOffsetX, 39 + mapOffsetY},
		Vector2{86 + mapOffsetX, 27 + mapOffsetY},
		Vector2{126 + mapOffsetX, 64 + mapOffsetY},
		Vector2{82 + mapOffsetX, 17 + mapOffsetY},
		Vector2{82 + mapOffsetX, 4 + mapOffsetY},
		Vector2{73 + mapOffsetX, 4 + mapOffsetY},
		Vector2{73 + mapOffsetX, 46 + mapOffsetY},
		Vector2{79 + mapOffsetX, 57 + mapOffsetY},
		Vector2{72 + mapOffsetX, 69 + mapOffsetY},
	};
	for (int i = 0; i < idahoVertexPoints.size(); i++)
	{
		idaho->AddVertexPoint(idahoVertexPoints[i]);
	}
	states.push_back(idaho);

	////////////////////////////////
	//         MONTANA			  //
	////////////////////////////////
	montana = new State("Montana", LoadTexture("assets/states/montana.png"));
	std::vector<Vector2> montanaVertexPoints
	{
		Vector2{82 + mapOffsetX, 4 + mapOffsetY},
		Vector2{82 + mapOffsetX, 19 + mapOffsetY},
		Vector2{99 + mapOffsetX, 39 + mapOffsetY},
		Vector2{98 + mapOffsetX, 54 + mapOffsetY},
		Vector2{103 + mapOffsetX, 54 + mapOffsetY},
		Vector2{113 + mapOffsetX, 68 + mapOffsetY},
		Vector2{130 + mapOffsetX, 66 + mapOffsetY},
		Vector2{130 + mapOffsetX, 60 + mapOffsetY},
		Vector2{196 + mapOffsetX, 60 + mapOffsetY},
		Vector2{196 + mapOffsetX, 5 + mapOffsetY},
	};
	for (int i = 0; i < montanaVertexPoints.size(); i++)
	{
		montana->AddVertexPoint(montanaVertexPoints[i]);
	}
	states.push_back(montana);

	////////////////////////////////
	//         WYOMING			  //
	////////////////////////////////
	wyoming = new State("Wyoming", LoadTexture("assets/states/wyoming.png"));
	std::vector<Vector2> wyomingVertexPoints
	{
		Vector2{130 + mapOffsetX, 112 + mapOffsetY},
		Vector2{196 + mapOffsetX, 112 + mapOffsetY},
		Vector2{196 + mapOffsetX, 60 + mapOffsetY},
		Vector2{130 + mapOffsetX, 60 + mapOffsetY},
	};
	for (int i = 0; i < wyomingVertexPoints.size(); i++)
	{
		wyoming->AddVertexPoint(wyomingVertexPoints[i]);
	}
	states.push_back(wyoming);

	////////////////////////////////
	//         COLORADO			  //
	////////////////////////////////
	colorado = new State("Colorado", LoadTexture("assets/states/colorado.png"));
	std::vector<Vector2> coloradoVertexPoints
	{
		Vector2{149 + mapOffsetX, 162 + mapOffsetY},
		Vector2{216 + mapOffsetX, 162 + mapOffsetY},
		Vector2{216 + mapOffsetX, 112 + mapOffsetY},
		Vector2{149 + mapOffsetX, 112 + mapOffsetY},
	};
	for (int i = 0; i < coloradoVertexPoints.size(); i++)
	{
		colorado->AddVertexPoint(coloradoVertexPoints[i]);
	}
	states.push_back(colorado);

	////////////////////////////////
	//         NEW MEXICO		  //
	////////////////////////////////
	new_mexico = new State("New Mexico", LoadTexture("assets/states/newmexico.png"));
	std::vector<Vector2> new_mexicoVertexPoints
	{
		Vector2{149 + mapOffsetX, 226 + mapOffsetY},
		Vector2{157 + mapOffsetX, 226 + mapOffsetY},
		Vector2{161 + mapOffsetX, 221 + mapOffsetY},
		Vector2{173 + mapOffsetX, 220 + mapOffsetY},
		Vector2{207 + mapOffsetX, 220 + mapOffsetY},
		Vector2{207 + mapOffsetX, 162 + mapOffsetY},
		Vector2{149 + mapOffsetX, 162 + mapOffsetY},
	};
	for (int i = 0; i < new_mexicoVertexPoints.size(); i++)
	{
		new_mexico->AddVertexPoint(new_mexicoVertexPoints[i]);
	}
	states.push_back(new_mexico);

	////////////////////////////////
	//         TEXAS		      //
	////////////////////////////////
	texas = new State("Texas", LoadTexture("assets/states/texas.png"));
	std::vector<Vector2> texasVertexPoints
	{
		Vector2{174 + mapOffsetX, 221 + mapOffsetY},
		Vector2{200 + mapOffsetX, 250 + mapOffsetY},
		Vector2{206 + mapOffsetX, 250 + mapOffsetY},
		Vector2{215 + mapOffsetX, 243 + mapOffsetY},
		Vector2{223 + mapOffsetX, 245 + mapOffsetY},
		Vector2{243 + mapOffsetX, 274 + mapOffsetY},
		Vector2{260 + mapOffsetX, 284 + mapOffsetY},
		Vector2{260 + mapOffsetX, 263 + mapOffsetY},
		Vector2{294 + mapOffsetX, 244 + mapOffsetY},
		Vector2{291 + mapOffsetX, 202 + mapOffsetY},
		Vector2{236 + mapOffsetX, 190 + mapOffsetY},
		Vector2{236 + mapOffsetX, 168 + mapOffsetY},
		Vector2{208 + mapOffsetX, 168 + mapOffsetY},
		Vector2{208 + mapOffsetX, 220 + mapOffsetY},
	};
	for (int i = 0; i < texasVertexPoints.size(); i++)
	{
		texas->AddVertexPoint(texasVertexPoints[i]);
	}
	states.push_back(texas);

	////////////////////////////////
	//         OKLAHOMA		      //
	////////////////////////////////
	oklahoma = new State("Oklahoma", LoadTexture("assets/states/oklahoma.png"));
	std::vector<Vector2> oklahomaVertexPoints
	{
		Vector2{208 + mapOffsetX, 166 + mapOffsetY},
		Vector2{237 + mapOffsetX, 166 + mapOffsetY},
		Vector2{208 + mapOffsetX, 189 + mapOffsetY},
		Vector2{262 + mapOffsetX, 198 + mapOffsetY},
		Vector2{285 + mapOffsetX, 199 + mapOffsetY},
		Vector2{285 + mapOffsetX, 163 + mapOffsetY},
		Vector2{208 + mapOffsetX, 163 + mapOffsetY},
	};
	for (int i = 0; i < oklahomaVertexPoints.size(); i++)
	{
		oklahoma->AddVertexPoint(oklahomaVertexPoints[i]);
	}
	states.push_back(oklahoma);

	////////////////////////////////
	//         KANSAS		      //
	////////////////////////////////
	kansas = new State("Kansas", LoadTexture("assets/states/kansas.png"));
	std::vector<Vector2> kansasVertexPoints
	{
		Vector2{217 + mapOffsetX, 161 + mapOffsetY},
		Vector2{285 + mapOffsetX, 161 + mapOffsetY},
		Vector2{285 + mapOffsetX, 136 + mapOffsetY},
		Vector2{280 + mapOffsetX, 126 + mapOffsetY},
		Vector2{217 + mapOffsetX, 126 + mapOffsetY},
	};
	for (int i = 0; i < kansasVertexPoints.size(); i++)
	{
		kansas->AddVertexPoint(kansasVertexPoints[i]);
	}
	states.push_back(kansas);

	////////////////////////////////
	//         NEBRASKA		      //
	////////////////////////////////
	nebraska = new State("Nebraska", LoadTexture("assets/states/nebraska.png"));
	std::vector<Vector2> nebraskaVertexPoints
	{
		Vector2{197 + mapOffsetX, 111 + mapOffsetY},
		Vector2{217 + mapOffsetX, 111 + mapOffsetY},
		Vector2{217 + mapOffsetX, 124 + mapOffsetY},
		Vector2{279 + mapOffsetX, 124 + mapOffsetY},
		Vector2{260 + mapOffsetX, 89 + mapOffsetY},
		Vector2{250 + mapOffsetX, 88 + mapOffsetY},
		Vector2{197 + mapOffsetX, 88 + mapOffsetY},
	};
	for (int i = 0; i < nebraskaVertexPoints.size(); i++)
	{
		nebraska->AddVertexPoint(nebraskaVertexPoints[i]);
	}
	states.push_back(nebraska);

	////////////////////////////////
	//         SOUTH DAKOTA		  //
	////////////////////////////////
	south_dakota = new State("South Dakota", LoadTexture("assets/states/southdakota.png"));
	std::vector<Vector2> south_dakotaVertexPoints
	{
		Vector2{197 + mapOffsetX, 86 + mapOffsetY},
		Vector2{250 + mapOffsetX, 86 + mapOffsetY},
		Vector2{268 + mapOffsetX, 93 + mapOffsetY},
		Vector2{268 + mapOffsetX, 49 + mapOffsetY},
		Vector2{197 + mapOffsetX, 49 + mapOffsetY},
	};
	for (int i = 0; i < south_dakotaVertexPoints.size(); i++)
	{
		south_dakota->AddVertexPoint(south_dakotaVertexPoints[i]);
	}
	states.push_back(south_dakota);

	////////////////////////////////
	//         NORTH DAKOTA		  //
	////////////////////////////////
	north_dakota = new State("North Dakota", LoadTexture("assets/states/northdakota.png"));
	std::vector<Vector2> north_dakotaVertexPoints
	{
		Vector2{197 + mapOffsetX, 47 + mapOffsetY},
		Vector2{197 + mapOffsetX, 267 + mapOffsetY},
		Vector2{261 + mapOffsetX, 6 + mapOffsetY},
		Vector2{197 + mapOffsetX, 6 + mapOffsetY},
	};
	for (int i = 0; i < north_dakotaVertexPoints.size(); i++)
	{
		north_dakota->AddVertexPoint(north_dakotaVertexPoints[i]);
	}
	states.push_back(north_dakota);

	////////////////////////////////
	//         MINNESOTA		  //
	////////////////////////////////
	minnesota = new State("Minnesota", LoadTexture("assets/states/minnesota.png"));
	std::vector<Vector2> minnesotaVertexPoints
	{
		Vector2{270 + mapOffsetX, 79 + mapOffsetY},
		Vector2{318 + mapOffsetX, 79 + mapOffsetY},
		Vector2{304 + mapOffsetX, 65 + mapOffsetY},
		Vector2{309 + mapOffsetX, 39 + mapOffsetY},
		Vector2{332 + mapOffsetX, 20 + mapOffsetY},
		Vector2{284 + mapOffsetX, 1 + mapOffsetY},
		Vector2{263 + mapOffsetX, 6 + mapOffsetY},
	};
	for (int i = 0; i < minnesotaVertexPoints.size(); i++)
	{
		minnesota->AddVertexPoint(minnesotaVertexPoints[i]);
	}
	states.push_back(minnesota);

	////////////////////////////////
	//         IOWA				  //
	////////////////////////////////
	iowa = new State("Iowa", LoadTexture("assets/states/iowa.png"));
	std::vector<Vector2> iowaVertexPoints
	{
		Vector2{277 + mapOffsetX, 117 + mapOffsetY},
		Vector2{316 + mapOffsetX, 119 + mapOffsetY},
		Vector2{328 + mapOffsetX, 101 + mapOffsetY},
		Vector2{320 + mapOffsetX, 90 + mapOffsetY},
		Vector2{318 + mapOffsetX, 81 + mapOffsetY},
		Vector2{269 + mapOffsetX, 81 + mapOffsetY},
	};
	for (int i = 0; i < iowaVertexPoints.size(); i++)
	{
		iowa->AddVertexPoint(iowaVertexPoints[i]);
	}
	states.push_back(iowa);

	////////////////////////////////
	//         MISSOURI			  //
	////////////////////////////////
	missouri = new State("Missouri", LoadTexture("assets/states/missouri.png"));
	std::vector<Vector2> missouriVertexPoints
	{
		Vector2{287 + mapOffsetX, 166 + mapOffsetY},
		Vector2{329 + mapOffsetX, 166 + mapOffsetY},
		Vector2{329 + mapOffsetX, 172 + mapOffsetY},
		Vector2{334 + mapOffsetX, 172 + mapOffsetY},
		Vector2{338 + mapOffsetX, 161 + mapOffsetY},
		Vector2{327 + mapOffsetX, 146 + mapOffsetY},
		Vector2{328 + mapOffsetX, 138 + mapOffsetY},
		Vector2{316 + mapOffsetX, 126 + mapOffsetY},
		Vector2{315 + mapOffsetX, 119 + mapOffsetY},
		Vector2{278 + mapOffsetX, 119 + mapOffsetY},
	};
	for (int i = 0; i < missouriVertexPoints.size(); i++)
	{
		missouri->AddVertexPoint(missouriVertexPoints[i]);
	}
	states.push_back(missouri);

	////////////////////////////////
	//         ARKANSAS			  //
	////////////////////////////////
	arkansas = new State("Arkansas", LoadTexture("assets/states/arkansas.png"));
	std::vector<Vector2> arkansasVertexPoints
	{
		Vector2{287 + mapOffsetX, 200 + mapOffsetY},
		Vector2{293 + mapOffsetX, 206 + mapOffsetY},
		Vector2{319 + mapOffsetX, 206 + mapOffsetY},
		Vector2{320 + mapOffsetX, 197 + mapOffsetY},
		Vector2{332 + mapOffsetX, 174 + mapOffsetY},
		Vector2{330 + mapOffsetX, 168 + mapOffsetY},
		Vector2{287 + mapOffsetX, 168 + mapOffsetY},
	};
	for (int i = 0; i < arkansasVertexPoints.size(); i++)
	{
		arkansas->AddVertexPoint(arkansasVertexPoints[i]);
	}
	states.push_back(arkansas);

	////////////////////////////////
	//         LOUISIANA		  //
	////////////////////////////////
	louisiana = new State("Louisiana", LoadTexture("assets/states/louisiana.png"));
	std::vector<Vector2> louisianaVertexPoints
	{
		Vector2{296 + mapOffsetX, 244 + mapOffsetY},
		Vector2{339 + mapOffsetX, 249 + mapOffsetY},
		Vector2{333 + mapOffsetX, 230 + mapOffsetY},
		Vector2{315 + mapOffsetX, 230 + mapOffsetY},
		Vector2{320 + mapOffsetX, 208 + mapOffsetY},
		Vector2{293 + mapOffsetX, 208 + mapOffsetY},
	};
	for (int i = 0; i < louisianaVertexPoints.size(); i++)
	{
		louisiana->AddVertexPoint(louisianaVertexPoints[i]);
	}
	states.push_back(louisiana);

	////////////////////////////////
	//         WISCONSIN		  //
	////////////////////////////////
	wisconsin = new State("Wisconsin", LoadTexture("assets/states/wisconsin.png"));
	std::vector<Vector2> wisconsinVertexPoints
	{
		Vector2{305 + mapOffsetX, 65 + mapOffsetY},
		Vector2{323 + mapOffsetX, 92 + mapOffsetY},
		Vector2{351 + mapOffsetX, 92 + mapOffsetY},
		Vector2{358 + mapOffsetX, 59 + mapOffsetY},
		Vector2{332 + mapOffsetX, 45 + mapOffsetY},
		Vector2{318 + mapOffsetX, 37 + mapOffsetY},
		Vector2{305 + mapOffsetX, 52 + mapOffsetY},
	};
	for (int i = 0; i < wisconsinVertexPoints.size(); i++)
	{
		wisconsin->AddVertexPoint(wisconsinVertexPoints[i]);
	}
	states.push_back(wisconsin);

	////////////////////////////////
	//         ILLINOIS		      //
	////////////////////////////////
	illinois = new State("Illinois", LoadTexture("assets/states/illinois.png"));
	std::vector<Vector2> illinoisVertexPoints
	{
		Vector2{317 + mapOffsetX, 123 + mapOffsetY},
		Vector2{338 + mapOffsetX, 160 + mapOffsetY},
		Vector2{349 + mapOffsetX, 154 + mapOffsetY},
		Vector2{353 + mapOffsetX, 143 + mapOffsetY},
		Vector2{353 + mapOffsetX, 94 + mapOffsetY},
		Vector2{326 + mapOffsetX, 94 + mapOffsetY},
		Vector2{322 + mapOffsetX, 114 + mapOffsetY},
	};
	for (int i = 0; i < illinoisVertexPoints.size(); i++)
	{
		illinois->AddVertexPoint(illinoisVertexPoints[i]);
	}
	states.push_back(illinois);

	////////////////////////////////
	//         MICHIGAN		      //
	////////////////////////////////
	michigan = new State("Michigan", LoadTexture("assets/states/michigan.png"));
	std::vector<Vector2> michiganVertexPoints
	{
		Vector2{360 + mapOffsetX, 102 + mapOffsetY},
		Vector2{393 + mapOffsetX, 102 + mapOffsetY},
		Vector2{402 + mapOffsetX, 87 + mapOffsetY},
		Vector2{399 + mapOffsetX, 75 + mapOffsetY},
		Vector2{391 + mapOffsetX, 54 + mapOffsetY},
		Vector2{379 + mapOffsetX, 39 + mapOffsetY},
		Vector2{351 + mapOffsetX, 36 + mapOffsetY},
		Vector2{351 + mapOffsetX, 28 + mapOffsetY},
		Vector2{330 + mapOffsetX, 39 + mapOffsetY},
		Vector2{355 + mapOffsetX, 55 + mapOffsetY},
		Vector2{365 + mapOffsetX, 71 + mapOffsetY},
		Vector2{368 + mapOffsetX, 94 + mapOffsetY},
	};
	for (int i = 0; i < michiganVertexPoints.size(); i++)
	{
		michigan->AddVertexPoint(michiganVertexPoints[i]);
	}
	states.push_back(michigan);

	////////////////////////////////
	//         INDIANA		      //
	////////////////////////////////
	indiana = new State("Indiana", LoadTexture("assets/states/indiana.png"));
	std::vector<Vector2> indianaVertexPoints
	{
		Vector2{351 + mapOffsetX, 150 + mapOffsetY},
		Vector2{369 + mapOffsetX, 148 + mapOffsetY},
		Vector2{379 + mapOffsetX, 138 + mapOffsetY},
		Vector2{379 + mapOffsetX, 104 + mapOffsetY},
		Vector2{355 + mapOffsetX, 103 + mapOffsetY},
		Vector2{355 + mapOffsetX, 143 + mapOffsetY},
	};
	for (int i = 0; i < indianaVertexPoints.size(); i++)
	{
		indiana->AddVertexPoint(indianaVertexPoints[i]);
	}
	states.push_back(indiana);

	////////////////////////////////
	//         OHIO		          //
	////////////////////////////////
	ohio = new State("Ohio", LoadTexture("assets/states/ohio.png"));
	std::vector<Vector2> ohioVertexPoints
	{
		Vector2{381 + mapOffsetX, 135 + mapOffsetY},
		Vector2{403 + mapOffsetX, 143 + mapOffsetY},
		Vector2{419 + mapOffsetX, 127 + mapOffsetY},
		Vector2{419 + mapOffsetX, 100 + mapOffsetY},
		Vector2{399 + mapOffsetX, 107 + mapOffsetY},
		Vector2{381 + mapOffsetX, 104 + mapOffsetY},
	};
	for (int i = 0; i < ohioVertexPoints.size(); i++)
	{
		ohio->AddVertexPoint(ohioVertexPoints[i]);
	}
	states.push_back(ohio);

	////////////////////////////////
	//         PENNSYLVANIA		  //
	////////////////////////////////
	pennsylvania = new State("Pennsylvania", LoadTexture("assets/states/pennsylvania.png"));
	std::vector<Vector2> pennsylvaniaVertexPoints
	{
		Vector2{421 + mapOffsetX, 128 + mapOffsetY},
		Vector2{468 + mapOffsetX, 128 + mapOffsetY},
		Vector2{475 + mapOffsetX, 123 + mapOffsetY},
		Vector2{471 + mapOffsetX, 114 + mapOffsetY},
		Vector2{475 + mapOffsetX, 107 + mapOffsetY},
		Vector2{470 + mapOffsetX, 101 + mapOffsetY},
		Vector2{428 + mapOffsetX, 101 + mapOffsetY},
		Vector2{428 + mapOffsetX, 95 + mapOffsetY},
		Vector2{421 + mapOffsetX, 98 + mapOffsetY},

	};
	for (int i = 0; i < pennsylvaniaVertexPoints.size(); i++)
	{
		pennsylvania->AddVertexPoint(pennsylvaniaVertexPoints[i]);
	}
	states.push_back(pennsylvania);

	////////////////////////////////
	//         NEW YORK 		  //
	////////////////////////////////
	new_york = new State("New York", LoadTexture("assets/states/newyork.png"));
	std::vector<Vector2> new_yorkVertexPoints
	{
		Vector2{429 + mapOffsetX, 99 + mapOffsetY},
		Vector2{470 + mapOffsetX, 99 + mapOffsetY},
		Vector2{485 + mapOffsetX, 117 + mapOffsetY},
		Vector2{500 + mapOffsetX, 115 + mapOffsetY},
		Vector2{500 + mapOffsetX, 113 + mapOffsetY},
		Vector2{488 + mapOffsetX, 113 + mapOffsetY},
		Vector2{488 + mapOffsetX, 60 + mapOffsetY},
		Vector2{475 + mapOffsetX, 61 + mapOffsetY},
		Vector2{463 + mapOffsetX, 72 + mapOffsetY},
		Vector2{463 + mapOffsetX, 80 + mapOffsetY},
		Vector2{437 + mapOffsetX, 83 + mapOffsetY},
	};
	for (int i = 0; i < new_yorkVertexPoints.size(); i++)
	{
		new_york->AddVertexPoint(new_yorkVertexPoints[i]);
	}
	states.push_back(new_york);

	////////////////////////////////
	//         NEW JERSEY 		  //
	////////////////////////////////
	new_jersey = new State("New Jersey", LoadTexture("assets/states/newjersey.png"));
	std::vector<Vector2> new_jerseyVertexPoints
	{
		Vector2{469 + mapOffsetX, 129 + mapOffsetY},
		Vector2{475 + mapOffsetX, 136 + mapOffsetY},
		Vector2{481 + mapOffsetX, 126 + mapOffsetY},
		Vector2{483 + mapOffsetX, 114 + mapOffsetY},
		Vector2{476 + mapOffsetX, 110 + mapOffsetY},
		Vector2{473 + mapOffsetX, 118 + mapOffsetY},
		Vector2{476 + mapOffsetX, 123 + mapOffsetY},
	};
	for (int i = 0; i < new_jerseyVertexPoints.size(); i++)
	{
		new_jersey->AddVertexPoint(new_jerseyVertexPoints[i]);
	}
	states.push_back(new_jersey);

	////////////////////////////////
	//         VERMONT		      //
	////////////////////////////////
	vermont = new State("Vermont", LoadTexture("assets/states/vermont.png"));
	std::vector<Vector2> vermontVertexPoints
	{
		Vector2{491 + mapOffsetX, 90 + mapOffsetY},
		Vector2{496 + mapOffsetX, 90 + mapOffsetY},
		Vector2{506 + mapOffsetX, 65 + mapOffsetY},
		Vector2{506 + mapOffsetX, 59 + mapOffsetY},
		Vector2{492 + mapOffsetX, 60 + mapOffsetY},
	};
	for (int i = 0; i < vermontVertexPoints.size(); i++)
	{
		vermont->AddVertexPoint(vermontVertexPoints[i]);
	}
	states.push_back(vermont);

	////////////////////////////////
	//         NEW HAMPSHIRE	  //
	////////////////////////////////
	new_hampshire = new State("New Hampshire", LoadTexture("assets/states/newhampshire.png"));
	std::vector<Vector2> new_hampshireVertexPoints
	{
		Vector2{498 + mapOffsetX, 90 + mapOffsetY},
		Vector2{513 + mapOffsetX, 88 + mapOffsetY},
		Vector2{511 + mapOffsetX, 56 + mapOffsetY},
		Vector2{508 + mapOffsetX, 58 + mapOffsetY},
		Vector2{503 + mapOffsetX, 72 + mapOffsetY},
	};
	for (int i = 0; i < new_hampshireVertexPoints.size(); i++)
	{
		new_hampshire->AddVertexPoint(new_hampshireVertexPoints[i]);
	}
	states.push_back(new_hampshire);

	////////////////////////////////
	//         MAINE	          //
	////////////////////////////////
	maine = new State("Maine", LoadTexture("assets/states/maine.png"));
	std::vector<Vector2> maineVertexPoints
	{
		Vector2{514 + mapOffsetX, 83 + mapOffsetY},
		Vector2{548 + mapOffsetX, 63 + mapOffsetY},
		Vector2{543 + mapOffsetX, 32 + mapOffsetY},
		Vector2{522 + mapOffsetX, 32 + mapOffsetY},
		Vector2{513 + mapOffsetX, 55 + mapOffsetY},
	};
	for (int i = 0; i < maineVertexPoints.size(); i++)
	{
		maine->AddVertexPoint(maineVertexPoints[i]);
	}
	states.push_back(maine);

	////////////////////////////////
	//         MASSACHUSETTS      //
	////////////////////////////////
	massachusetts = new State("Massachusetts", LoadTexture("assets/states/massachusetts.png"));
	std::vector<Vector2> massachusettsVertexPoints
	{
		Vector2{490 + mapOffsetX, 99 + mapOffsetY},
		Vector2{509 + mapOffsetX, 99 + mapOffsetY},
		Vector2{512 + mapOffsetX, 109 + mapOffsetY},
		Vector2{522 + mapOffsetX, 105 + mapOffsetY},
		Vector2{513 + mapOffsetX, 90 + mapOffsetY},
		Vector2{492 + mapOffsetX, 92 + mapOffsetY},
	};
	for (int i = 0; i < massachusettsVertexPoints.size(); i++)
	{
		massachusetts->AddVertexPoint(massachusettsVertexPoints[i]);
	}
	states.push_back(massachusetts);

	////////////////////////////////
	//         CONNECTICUT        //
	////////////////////////////////
	connecticut = new State("Connecticut", LoadTexture("assets/states/connecticut.png"));
	std::vector<Vector2> connecticutVertexPoints
	{
		Vector2{488 + mapOffsetX, 112 + mapOffsetY},
		Vector2{504 + mapOffsetX, 109 + mapOffsetY},
		Vector2{504 + mapOffsetX, 101 + mapOffsetY},
		Vector2{489 + mapOffsetX, 101 + mapOffsetY},
	};
	for (int i = 0; i < connecticutVertexPoints.size(); i++)
	{
		connecticut->AddVertexPoint(connecticutVertexPoints[i]);
	}
	states.push_back(connecticut);

	////////////////////////////////
	//         RHODE ISLAND       //
	////////////////////////////////
	rhode_island = new State("Rhode Island", LoadTexture("assets/states/rhodeisland.png"));
	std::vector<Vector2> rhode_islandVertexPoints
	{
		Vector2{506 + mapOffsetX, 107 + mapOffsetY},
		Vector2{510 + mapOffsetX, 107 + mapOffsetY},
		Vector2{510 + mapOffsetX, 101 + mapOffsetY},
		Vector2{506 + mapOffsetX, 101 + mapOffsetY},
	};
	for (int i = 0; i < rhode_islandVertexPoints.size(); i++)
	{
		rhode_island->AddVertexPoint(rhode_islandVertexPoints[i]);
	}
	states.push_back(rhode_island);

	////////////////////////////////
	//         DELAWARE           //
	////////////////////////////////
	delaware = new State("Delaware", LoadTexture("assets/states/delaware.png"));
	std::vector<Vector2> delawareVertexPoints
	{
		Vector2{467 + mapOffsetX, 143 + mapOffsetY},
		Vector2{472 + mapOffsetX, 143 + mapOffsetY},
		Vector2{472 + mapOffsetX, 131 + mapOffsetY},
		Vector2{467 + mapOffsetX, 131 + mapOffsetY},
	};
	for (int i = 0; i < delawareVertexPoints.size(); i++)
	{
		delaware->AddVertexPoint(delawareVertexPoints[i]);
	}
	states.push_back(delaware);

	////////////////////////////////
	//         MARYLAND           //
	////////////////////////////////
	maryland = new State("Maryland", LoadTexture("assets/states/maryland.png"));
	std::vector<Vector2> marylandVertexPoints
	{
		Vector2{431 + mapOffsetX, 134 + mapOffsetY},
		Vector2{450 + mapOffsetX, 134 + mapOffsetY},
		Vector2{459 + mapOffsetX, 147 + mapOffsetY},
		Vector2{467 + mapOffsetX, 155 + mapOffsetY},
		Vector2{472 + mapOffsetX, 145 + mapOffsetY},
		Vector2{466 + mapOffsetX, 144 + mapOffsetY},
		Vector2{466 + mapOffsetX, 130 + mapOffsetY},
		Vector2{431 + mapOffsetX, 130 + mapOffsetY},
	};
	for (int i = 0; i < marylandVertexPoints.size(); i++)
	{
		maryland->AddVertexPoint(marylandVertexPoints[i]);
	}
	states.push_back(maryland);

	////////////////////////////////
	//         FLORIDA            //
	////////////////////////////////
	florida = new State("Florida", LoadTexture("assets/states/florida.png"));
	std::vector<Vector2> floridaVertexPoints
	{
		Vector2{355 + mapOffsetX, 235 + mapOffsetY},
		Vector2{418 + mapOffsetX, 292 + mapOffsetY},
		Vector2{424 + mapOffsetX, 292 + mapOffsetY},
		Vector2{422 + mapOffsetX, 234 + mapOffsetY},
		Vector2{355 + mapOffsetX, 231 + mapOffsetY},
	};
	for (int i = 0; i < floridaVertexPoints.size(); i++)
	{
		florida->AddVertexPoint(floridaVertexPoints[i]);
	}
	states.push_back(florida);

	////////////////////////////////
	//         MISSISSIPPI        //
	////////////////////////////////
	mississippi = new State("Mississippi", LoadTexture("assets/states/mississippi.png"));
	std::vector<Vector2> mississippiVertexPoints
	{
		Vector2{316 + mapOffsetX, 236 + mapOffsetY},
		Vector2{346 + mapOffsetX, 236 + mapOffsetY},
		Vector2{346 + mapOffsetX, 185 + mapOffsetY},
		Vector2{328 + mapOffsetX, 185 + mapOffsetY},
		Vector2{321 + mapOffsetX, 198 + mapOffsetY},
	};
	for (int i = 0; i < mississippiVertexPoints.size(); i++)
	{
		mississippi->AddVertexPoint(mississippiVertexPoints[i]);
	}
	states.push_back(mississippi);

	////////////////////////////////
	//         ALABAMA            //
	////////////////////////////////
	alabama = new State("Alabama", LoadTexture("assets/states/alabama.png"));
	std::vector<Vector2> alabamaVertexPoints
	{
		Vector2{347 + mapOffsetX, 236 + mapOffsetY},
		Vector2{379 + mapOffsetX, 236 + mapOffsetY},
		Vector2{379 + mapOffsetX, 185 + mapOffsetY},
		Vector2{347 + mapOffsetX, 185 + mapOffsetY},
	};
	for (int i = 0; i < alabamaVertexPoints.size(); i++)
	{
		alabama->AddVertexPoint(alabamaVertexPoints[i]);
	}
	states.push_back(alabama);

	////////////////////////////////
	//         GEORGIA            //
	////////////////////////////////
	georgia = new State("Georgia", LoadTexture("assets/states/georgia.png"));
	std::vector<Vector2> georgiaVertexPoints
	{
		Vector2{376 + mapOffsetX, 235 + mapOffsetY},
		Vector2{416 + mapOffsetX, 235 + mapOffsetY},
		Vector2{405 + mapOffsetX, 200 + mapOffsetY},
		Vector2{396 + mapOffsetX, 185 + mapOffsetY},
		Vector2{373 + mapOffsetX, 185 + mapOffsetY},
	};
	for (int i = 0; i < georgiaVertexPoints.size(); i++)
	{
		georgia->AddVertexPoint(georgiaVertexPoints[i]);
	}
	states.push_back(georgia);

	////////////////////////////////
	//         SOUTH CAROLINA     //
	////////////////////////////////
	south_carolina = new State("South Carolina", LoadTexture("assets/states/southcarolina.png"));
	std::vector<Vector2> south_carolinaVertexPoints
	{
		Vector2{395 + mapOffsetX, 188 + mapOffsetY},
		Vector2{417 + mapOffsetX, 218 + mapOffsetY},
		Vector2{439 + mapOffsetX, 198 + mapOffsetY},
		Vector2{427 + mapOffsetX, 188 + mapOffsetY},
		Vector2{416 + mapOffsetX, 184 + mapOffsetY},
		Vector2{399 + mapOffsetX, 184 + mapOffsetY},
	};
	for (int i = 0; i < south_carolinaVertexPoints.size(); i++)
	{
		south_carolina->AddVertexPoint(south_carolinaVertexPoints[i]);
	}
	states.push_back(south_carolina);

	////////////////////////////////
	//         TENNESSEE          //
	////////////////////////////////
	tennessee = new State("Tennessee", LoadTexture("assets/states/tennessee.png"));
	std::vector<Vector2> tennesseeVertexPoints
	{
		Vector2{329 + mapOffsetX, 183 + mapOffsetY},
		Vector2{384 + mapOffsetX, 183 + mapOffsetY},
		Vector2{410 + mapOffsetX, 167 + mapOffsetY},
		Vector2{337 + mapOffsetX, 167 + mapOffsetY},
	};
	for (int i = 0; i < tennesseeVertexPoints.size(); i++)
	{
		tennessee->AddVertexPoint(tennesseeVertexPoints[i]);
	}
	states.push_back(tennessee);

	////////////////////////////////
	//         KENTUCKY           //
	////////////////////////////////
	kentucky = new State("Kentucky", LoadTexture("assets/states/kentucky.png"));
	std::vector<Vector2> kentuckyVertexPoints
	{
		Vector2{338 + mapOffsetX, 166 + mapOffsetY},
		Vector2{405 + mapOffsetX, 166 + mapOffsetY},
		Vector2{405 + mapOffsetX, 140 + mapOffsetY},
		Vector2{381 + mapOffsetX, 137 + mapOffsetY},
		Vector2{351 + mapOffsetX, 152 + mapOffsetY},
	};
	for (int i = 0; i < kentuckyVertexPoints.size(); i++)
	{
		kentucky->AddVertexPoint(kentuckyVertexPoints[i]);
	}
	states.push_back(kentucky);

	////////////////////////////////
	//         WEST VIRGINIA      //
	////////////////////////////////
	west_virginia = new State("West Virginia", LoadTexture("assets/states/westvirginia.png"));
	std::vector<Vector2> west_virginiaVertexPoints
	{
		Vector2{402 + mapOffsetX, 145 + mapOffsetY},
		Vector2{412 + mapOffsetX, 158 + mapOffsetY},
		Vector2{441 + mapOffsetX, 133 + mapOffsetY},
		Vector2{420 + mapOffsetX, 127 + mapOffsetY},
	};
	for (int i = 0; i < west_virginiaVertexPoints.size(); i++)
	{
		west_virginia->AddVertexPoint(west_virginiaVertexPoints[i]);
	}
	states.push_back(west_virginia);

	////////////////////////////////
	//         VIRGINIA           //
	////////////////////////////////
	virginia = new State("Virginia", LoadTexture("assets/states/virginia.png"));
	std::vector<Vector2> virginiaVertexPoints
	{
		Vector2{396 + mapOffsetX, 165 + mapOffsetY},
		Vector2{464 + mapOffsetX, 165 + mapOffsetY},
		Vector2{449 + mapOffsetX, 134 + mapOffsetY},
		Vector2{443 + mapOffsetX, 134 + mapOffsetY},
		Vector2{417 + mapOffsetX, 158 + mapOffsetY},
		Vector2{405 + mapOffsetX, 158 + mapOffsetY},
	};
	for (int i = 0; i < virginiaVertexPoints.size(); i++)
	{
		virginia->AddVertexPoint(virginiaVertexPoints[i]);
	}
	states.push_back(virginia);

	////////////////////////////////
	//         VIRGINIA           //
	////////////////////////////////
	north_carolina = new State("North Carolina", LoadTexture("assets/states/northcarolina.png"));
	std::vector<Vector2> north_carolinaVertexPoints
	{
		Vector2{386 + mapOffsetX, 183 + mapOffsetY},
		Vector2{417 + mapOffsetX, 183 + mapOffsetY},
		Vector2{442 + mapOffsetX, 198 + mapOffsetY},
		Vector2{466 + mapOffsetX, 176 + mapOffsetY},
		Vector2{466 + mapOffsetX, 167 + mapOffsetY},
		Vector2{412 + mapOffsetX, 167 + mapOffsetY},
	};
	for (int i = 0; i < north_carolinaVertexPoints.size(); i++)
	{
		north_carolina->AddVertexPoint(north_carolinaVertexPoints[i]);
	}
	states.push_back(north_carolina);

	////////////////////////////////
	//     District Of Columbia   //
	////////////////////////////////
	dc = new State("D. C", LoadTexture("assets/states/dc.png"));
	std::vector<Vector2> dcVertexPoints
	{
		Vector2{480 + mapOffsetX, 175 + mapOffsetY},
		Vector2{511 + mapOffsetX, 175 + mapOffsetY},
		Vector2{511 + mapOffsetX, 152 + mapOffsetY},
		Vector2{480 + mapOffsetX, 152 + mapOffsetY},
	};
	for (int i = 0; i < dcVertexPoints.size(); i++)
	{
		dc->AddVertexPoint(dcVertexPoints[i]);
	}
	states.push_back(dc);
}

// De-Init
Game::~Game()
{
	// Unload Textures
	UnloadTexture(stateBorders);
	// Clean Up States
	for (int i = 0; i < states.size(); i++)
	{
		delete(states[i]);
	}
	// Delete Objects
	delete(scenario);
	delete(buttonVisitState);
	delete(buttonCancelVisitState);
	delete(buttonModernScenarios);
	delete(buttonScenario2024);
}

void Game::UpdateMenu()
{
	buttonModernScenarios->MouseHover(GetMousePosition());
	if (buttonModernScenarios->isMouseOverButton && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		menuState = IN_SCENARIO_SCREEN;
	}

	if (menuState == IN_SCENARIO_SCREEN)
	{
		buttonScenario2024->MouseHover(GetMousePosition());
		if (buttonScenario2024->isMouseOverButton && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			scenario->LoadScenario(SCENARIO_2024, states);
			gameState = IN_GAME;
		}
	}
}

void Game::RenderMenu()
{
	// Draw Menu Logo
	//DrawTexture(gameLogo, 25, 25, WHITE);
	DrawTextureEx(gameLogo, Vector2{ 25 , 0 }, 0, 2, WHITE);
	buttonModernScenarios->Draw();

	DrawRectangle(450, 0, 300, 900, Color{0, 0, 0, 200});

	if (menuState == IN_SCENARIO_SCREEN)
	{
		buttonScenario2024->Draw();
	}
}

// Update Variables
void Game::Update()
{
	// Determine Which State The Mouse Is Over 
	// Set Back To NULL When Mouse Exits Off State
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i]->IsMouseOverState(GetMousePosition()))
		{
			selectedState = states[i];
			break;
		}
		else
		{
			selectedState = nullptr;
		}
	}

	// Check If Mouse Is Over Buttons
	buttonVisitState->MouseHover(GetMousePosition());
	if (buttonVisitState->isMouseOverButton && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		hasClickedStateVisit = true;
	}
	buttonCancelVisitState->MouseHover(GetMousePosition());
	if (buttonCancelVisitState->isMouseOverButton && IsMouseButtonDown(MOUSE_BUTTON_LEFT) && hasClickedStateVisit)
	{
		hasClickedStateVisit = false;
	}

	// Visit State
	if (hasClickedStateVisit && selectedState != nullptr && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		hasClickedStateVisit = false;
		selectedState->UpdatePartyPopularity("Independent", (float)GetRandomValue(1, 10), 2);
	}

	// Update Party Popularity
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->CalculateStateColor();
	}
}

// Draw
void Game::Render()
{
	// Draw Buttons
	buttonVisitState->Draw();

	// Render State Borders
	DrawTextureEx(stateBorders, Vector2{ mapOffsetX, mapOffsetY }, 0, 1, WHITE);

	// Draw MenuBox
	DrawRectangle(570, 0, 300, 800, Color{ 0, 0, 0, 200 });

	// Candidate Portraits
	DrawRectangle(600, 20, 80, 112, WHITE);
	DrawRectangle(700, 20, 80, 112, WHITE);

	// Render EV's For Each Party
	for (int i = 0; i < scenario->parties.size(); i++)
	{
		float y = i * 20;
		DrawText(scenario->parties[i]->GetName().c_str(), 600, 350 + y, 20, scenario->parties[i]->safe);
		DrawText(TextFormat(" - %i", EVCalculator(scenario->parties[i]->GetName())), 720, 350 + y, 20, WHITE);
	}
	

	// Click A State To Visit It (Boosts Popularity Of Your Party In That State)
	if (hasClickedStateVisit)
	{
		buttonCancelVisitState->Draw();
		DrawText("Click A State To Visit! (Costs 2 Points)", 0, 50, 19, BLACK);
	}

	// Render States
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->Render(Vector2{ mapOffsetX , mapOffsetY });
	}

	// Show State Tooltips
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i]->IsMouseOverState(GetMousePosition()))
		{
			if (selectedState != nullptr)
			{
				stateTooltip.Show(selectedState, GetMousePosition());
			}
		}
	}
}

int Game::EVCalculator(std::string nameOfParty)
{
	int sum{};
	for (int i = 0; i < states.size(); i++)
	{
		if (nameOfParty == states[i]->partiesRunning[0]->GetName())
		{
			sum += states[i]->GetElectoralVotes();
		}
	}
	return sum;
}
