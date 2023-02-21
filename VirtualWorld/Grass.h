#pragma once
#include "Plant.h"

#define GRASS_SYMBOL 'T'	

class Grass : public Plant {
public:
	Grass(World& world, Point point, int turnOfBirth, OrganismType organismType);
	Organism* CreateNewOrganism(Point point) override;
	~Grass();
};