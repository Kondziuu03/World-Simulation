#include <iostream>
#include "Grass.h"

using namespace std;

Grass::Grass(World& world, Point point, int turnOfBirth, OrganismType organismType)
	: Plant(world, point, turnOfBirth, organismType, GRASS_SYMBOL) {}

Organism* Grass::CreateNewOrganism(Point point) {
	return new Grass(this->world, point, this->world.GetTurn(), OrganismType::GRASS);
}

Grass::~Grass() {}