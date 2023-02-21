#include <iostream>
#include "Hedgehog.h"

using namespace std;

Hedgehog::Hedgehog(World& world, Point point, int turnOfBirth, OrganismType organismType) 
	: Animal(world, point, turnOfBirth, organismType ,HEDGEHOG_SYMBOL, HEDGEHOG_POWER, HEDGEHOG_INITIATIVE) {}

Organism* Hedgehog::CreateNewOrganism(Point point) {
	return new Hedgehog(this->world, point, this->world.GetTurn(),OrganismType::HEDGEHOG);
}

void Hedgehog::SpecialMoveAfterDeath(Organism* killer) {
	killer->SetPause(killer->GetPause() + PAUSE_TURNS);
	killer->Print();
	cout << " zostal skaleczony i unieruchomiony na 2 tury przez ";
	this->Print();
	cout << endl;
}



Hedgehog::~Hedgehog() {}