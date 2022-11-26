#pragma once

#include <vector>
#include <string>
#include <queue>

using namespace std;

class nAry
{
	public:
		int gunViolence, underagedDeaths;
		string state;
		nAry* children[5];
		nAry() {};
		nAry(int gunViolence, int underagedDeaths, string state);
		//nAry* SetData(nAry* root, int gunViolence, int underagedDeaths, string state);

        
};

