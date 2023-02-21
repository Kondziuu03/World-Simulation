#include <iostream>
#include "Turtle.h"

using namespace std;

Turtle::Turtle(World& world, Point point, int turnOfBirth, OrganismType organismType)
	: Animal(world, point, turnOfBirth, organismType,TURTLE_SYMBOL, TURTLE_POWER, TURTLE_INITIATIVE) {}

Organism* Turtle::CreateNewOrganism(Point point) {
	return new Turtle(this->world, point, this->world.GetTurn(), OrganismType::TURTLE);
}



bool Turtle::IsAttackDefended(Organism* attacker) {
	if (attacker->GetPower() > 5) return false;
	else {
		this->Print();
		cout << " odparl atak ";
		attacker->Print();
		cout << endl;
		return true;
	}
}

void Turtle::Action() {
	int moveChance = rand() % 100;
	if (moveChance < 25) {
		this->MakeMove(false, BASIC_MOVEMENT_RANGE);
		this->Print();
		cout << " zmienil swoja pozycje " << endl;
	}
}

Turtle::~Turtle() {}