#include "nAry.h"

//nAry* nAry::SetData(nAry* root, int gunViolence, int underagedDeaths, string state) {
//	
//	if (root == nullptr) return new nAry(gunViolence, underagedDeaths, state);
//
//	if (children.size() != 5) {
//		children.push_back(new nAry(gunViolence, underagedDeaths, state));
//		trackPos.push(children.back());
//	}
//	else SetData(trackPos.front(), gunViolence, underagedDeaths, state);
//
//	return root;
//}

nAry::nAry(int gunViolence, int underagedDeaths, string state) {
	this->gunViolence = gunViolence;
	this->underagedDeaths = underagedDeaths;
	this->state = state;
}