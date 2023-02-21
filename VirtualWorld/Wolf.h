#pragma once
#include "Animal.h"

#define WOLF_POWER 9
#define WOLF_INITIATIVE 5
#define WOLF_SYMBOL 'W'	

class Wolf : public Animal {
public:
	Wolf(World& world, Point point, int turnOfBirth, OrganismType organismType);
	Organism* CreateNewOrganism(Point point) override;
	~Wolf();
};