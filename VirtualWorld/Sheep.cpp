#include <iostream>
#include "Sheep.h"

using namespace std;

Sheep::Sheep(World& world, Point point, int turnOfBirth, OrganismType organismType) 
	: Animal(world, point,turnOfBirth, organismType ,SHEEP_SYMBOL, SHEEP_POWER, SHEEP_INITIATIVE) {}

Organism* Sheep::CreateNewOrganism(Point point) {
	return new Sheep(this->world, point, this->world.GetTurn(), OrganismType::SHEEP);
}

Sheep::~Sheep() {}