#pragma once
#include "Animal.h"

#define HEDGEHOG_POWER 2
#define HEDGEHOG_INITIATIVE 3
#define HEDGEHOG_SYMBOL 'J'	
#define PAUSE_TURNS 2	

class Hedgehog : public Animal {
public:
	Hedgehog(World& world, Point point, int turnOfBirth, OrganismType organismType);
	Organism* CreateNewOrganism(Point point) override;
	void SpecialMoveAfterDeath(Organism* killer) override;
	~Hedgehog();
};
