#pragma once
#include "Plant.h"

#define GUARANA_SYMBOL 'G'	
#define EXTRA_POWER 3

class Guarana : public Plant {
public:
	Guarana(World& world, Point point, int turnOfBirth, OrganismType organismType);
	Organism* CreateNewOrganism(Point point) override;
	void SpecialMoveAfterDeath(Organism* killer) override;
	~Guarana();
};