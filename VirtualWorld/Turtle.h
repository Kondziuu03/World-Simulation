#pragma once
#include "Animal.h"

#define TURTLE_POWER 2
#define TURTLE_INITIATIVE 1
#define TURTLE_SYMBOL 'Z'	
#define TURTLE_MOVEMENT_RANGE 1

class Turtle : public Animal {
public:
	Turtle(World& world, Point point, int turnOfBirth, OrganismType organismType);
	Organism* CreateNewOrganism(Point point) override;
	void Action() override;
	bool IsAttackDefended(Organism* attacker) override;
	~Turtle();
};