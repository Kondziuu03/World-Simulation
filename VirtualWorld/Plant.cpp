#include <iostream>
#include "Plant.h"

Plant::Plant(World& world, Point point, int turnOfBirth, OrganismType organismType, char symbol) :
	Organism(world, point, turnOfBirth, organismType, symbol, PLANT_POWER, PLANT_INITIATIVE) {}

void Plant::Action() {
	int number = rand() % 100;
	if(number < PROBABILITY) this->CreateChild(NULL);
}

void Plant::Collision(Organism* attacker) {
	this->KillLoser(attacker, this);
	this->PrintFightResult(attacker, this);
	this->MoveAttackerToLoserField(attacker, this);
}

void Plant::PrintCreateChildResult(Organism* otherOrganism, Organism* newOrganism) {
	this->Print();
	cout << " zasial nowa rosline: ";
	newOrganism->Print();
	cout << endl;
}

Plant::~Plant() {}