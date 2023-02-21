#pragma once
#include "Organism.h"

#define PLANT_INITIATIVE 0
#define PLANT_POWER 0
#define PROBABILITY 25

class Plant : public Organism {
private:
	virtual void PrintCreateChildResult(Organism* otherOrganism, Organism* newOrganism) override;
public:
	Plant(World& world, Point point, int turnOfBirth, OrganismType organismType, char symbol);
	virtual void Action() override;
	virtual void Collision(Organism* attacker) override;
	virtual ~Plant();
};