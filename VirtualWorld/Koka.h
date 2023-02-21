#pragma once
#include "Plant.h"

#define KOKA_SYMBOL 'K'	
#define EXTRA_MOVES 1

class Koka : public Plant {
public:
	Koka(World& world, Point point, int turnOfBirth, OrganismType organismType);
	Organism* CreateNewOrganism(Point point) override;
	void SpecialMoveAfterDeath(Organism* killer) override;
	~Koka();
};