#pragma once
#include "Plant.h"

#define DANDELION_SYMBOL 'D'	

class Dandelion : public Plant {
public:
	Dandelion(World& world, Point point, int turnOfBirth, OrganismType organismType);
	Organism* CreateNewOrganism(Point point) override;
	~Dandelion();
};