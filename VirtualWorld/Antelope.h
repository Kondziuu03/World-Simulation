#pragma once
#include "Animal.h"

#define	ANTELOPE_POWER 4
#define ANTELOPE_INITIATIVE 4
#define ANTELOPE_SYMBOL 'A'	
#define ANTELOPE_MOVEMENT_RANGE 2

class Antelope : public Animal {
public:
	Antelope(World& world, Point point, int turnOfBirth, OrganismType organismType);
	Organism* CreateNewOrganism(Point point) override;
	bool IsAttackDefended(Organism* attacker) override;
	void Action() override;
	~Antelope();
};
