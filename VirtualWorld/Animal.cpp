#include <iostream>
#include "Animal.h"

using namespace std;

Animal::Animal(World& world, Point point,int turnOfBirth,OrganismType organismType ,char symbol, int power, int initiative) :
	Organism(world, point, turnOfBirth,organismType,symbol, power, initiative) {}

void Animal::Action() {
	this->MakeMove(false,BASIC_MOVEMENT_RANGE);
}

void Animal::Collision(Organism* attacker) {
	if (this->GetOrganismType() != attacker->GetOrganismType()) {
		if (this->IsAttackDefended(attacker) == false) {
			if (attacker->GetPower() >= this->GetPower()) {
				this->KillLoser(attacker,this);
				this->PrintFightResult(attacker, this);
				this->MoveAttackerToLoserField(attacker, this);
			}
			else {
				this->KillLoser(this,attacker);
				this->PrintFightResult(this, attacker);
			}
		}
	}
	else CreateChild(attacker);
}

void Animal::PrintCreateChildResult(Organism* otherOrganism, Organism* newOrganism) {
	this->Print();
	cout << " i ";
	otherOrganism->Print();
	cout << " stworzyli potomka ";
	newOrganism->Print();
	cout << endl;
}


Animal::~Animal(){}