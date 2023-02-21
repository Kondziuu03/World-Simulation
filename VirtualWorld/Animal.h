#pragma once
#include "Organism.h"

#define DIRECTIONS 4
#define DIRECTION_BLOCKED 1
#define DIRECTION_OPEN 0

class Animal : public Organism {
private:
	virtual void PrintCreateChildResult(Organism* otherOrganism, Organism* newOrganism) override;
public:
	Animal(World& world, Point point,int turnOfBirth,OrganismType organismType ,char symbol, int power, int initiative);
	virtual void Action() override;
	virtual void Collision(Organism* attacker) override;
	virtual ~Animal();
};