#include <iostream>
#include "Koka.h"

using namespace std;

Koka::Koka(World& world, Point point, int turnOfBirth, OrganismType organismType)
	: Plant(world, point, turnOfBirth, organismType, KOKA_SYMBOL) {}

Organism* Koka::CreateNewOrganism(Point point) {
	return new Koka(this->world, point, this->world.GetTurn(), OrganismType::KOKA);
}

void Koka::SpecialMoveAfterDeath(Organism* killer) {
	killer->SetExtraMoves(killer->GetExtraMoves() + EXTRA_MOVES);
	killer->Print();
	cout << " uzyskal "<< EXTRA_MOVES <<" dodatkowy ruch w nastepnej turze po zjedzeniu ";
	this->Print();
	cout << endl;
}

Koka::~Koka() {}