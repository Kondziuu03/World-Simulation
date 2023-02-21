#include <iostream>
#include "Dandelion.h"

using namespace std;

Dandelion::Dandelion(World& world, Point point, int turnOfBirth, OrganismType organismType)
	: Plant(world, point, turnOfBirth, organismType, DANDELION_SYMBOL) {}

Organism* Dandelion::CreateNewOrganism(Point point) {
	return new Dandelion(this->world, point, this->world.GetTurn(), OrganismType::GRASS);
}

Dandelion::~Dandelion() {}