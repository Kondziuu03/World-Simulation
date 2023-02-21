#pragma once
#include "Animal.h"

#define SHEEP_POWER 4
#define SHEEP_INITIATIVE 4
#define SHEEP_SYMBOL 'O'	

class Sheep : public Animal {
public:
	Sheep(World& world, Point point, int turnOfBirth, OrganismType organismType);
	Organism* CreateNewOrganism(Point point) override;
	~Sheep();
};