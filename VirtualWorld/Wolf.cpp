#include <iostream>
#include "Wolf.h"

using namespace std;

Wolf::Wolf(World& world, Point point, int turnOfBirth, OrganismType organismType) 
	: Animal(world, point,turnOfBirth, organismType ,WOLF_SYMBOL,WOLF_POWER,WOLF_INITIATIVE) {}

Organism* Wolf::CreateNewOrganism(Point point) {
	return new Wolf(this->world, point, this->world.GetTurn(), OrganismType::WOLF);
}

Wolf::~Wolf() {}