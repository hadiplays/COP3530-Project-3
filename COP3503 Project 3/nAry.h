#pragma once

#include <vector>
#include <string>

using namespace std;

class nAry
{
	public:
		int gunViolence, underagedDeaths;
		string state;
		vector<nAry*> children;
		void SetData();
};

